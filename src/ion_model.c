#include <gmcmc/gmcmc_ion_model.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include "clapack.h"

// Forward declarations of utility functions
static int calculate_specmat_eigenvectors(size_t, const double *, size_t,
                                          double *, double *, size_t);
static int idealised_transition_probability(size_t, size_t, double,
                                            const double *,
                                            const double *, size_t,
                                            const double *, size_t,
                                            double *);
static double log_sum(size_t, double *);

/**
 * Ion Channel model-specific data.
 *
 * In addition to data common to all models, ion channel models have a Q matrix
 * which details the transitions between open and closed states.
 */
struct gmcmc_ion_model {
  /**
   * Number of closed and open states in the model.
   */
  unsigned int closed, open;

  /**
   * Function to update the Q matrix based on the current parameter values.
   */
  gmcmc_ion_calculate_Q_matrix calculate_Q_matrix;
};

/**
 * Ion Channel model proposal function using Metropolis-Hastings.
 */
static int ion_proposal_mh(size_t n, const double * params, double likelihood,
                           double temperature, double stepsize, const void * serdata,
                           double * mean, double * covariance, size_t ldc) {
  (void)likelihood;
  (void)serdata;
  (void)temperature;

  // Proposal_Mean    = Chain.Paras(Chain.CurrentBlock);
  memcpy(mean, params, n * sizeof(double));

  // Proposal_Covariance = eye(Chain.CurrentBlockSize)*(Chain.StepSize(Chain.CurrentBlockNum)^2);
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      covariance[j * ldc + i] = 0.0;
    covariance[j * ldc + j] = stepsize * stepsize;
    for (size_t i = j + 1; i < n; i++)
      covariance[j * ldc + i] = 0.0;
  }

  return 0;
}
const gmcmc_proposal_function gmcmc_ion_proposal_mh = &ion_proposal_mh;

/**
 * Ion Channel model likelihood function using Metropolis-Hastings.
 * Calculates p(D|M,params) (i.e. likelihood of seeing the data D given the
 * model M and parameters params)
 *
 * @param [in]  dataset     the data
 * @param [in]  model       the model
 * @param [in]  params      the parameter vector
 * @param [out] likelihood  the likelihood object to create and populate
 * @param [out] serdata     serialised data to be passed to the proposal function
 * @param [out] size        size of serialised data object, in bytes
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate temporary
 *                        variables,
 *         GMCMC_ELINAL if there was an error in an external linear algebra
 *                        routine,
 *         GMCMC_EFP    if there was a floating point exception indicating a
 *                        possible numerical inaccuracy.
 */
static int ion_likelihood_mh(const gmcmc_dataset * dataset, const gmcmc_model * model,
                             const double * params,
                             double * likelihood, void ** serdata, size_t * size) {
  (void)serdata;
  (void)size;
  // Initialise error status
  int error = 0;

  // Get the model specific data
  gmcmc_ion_model * ion_model = (gmcmc_ion_model *)gmcmc_model_get_modelspecific(model);
  const unsigned int num_states = ion_model->closed + ion_model->open;

  // Allocate the Q matrix
  double * Q;
  size_t ldq = (num_states + 1u) & ~1u;
  if ((Q = calloc(num_states * ldq, sizeof(double))) == NULL)
    GMCMC_ERROR("Unable to allocate Q matrix", GMCMC_ENOMEM);

  // Calculate the Q matrix
  ion_model->calculate_Q_matrix(params, Q, ldq);


  /*
   * Calculate equilibrium state occupancies
   *
   * The original (Matlab) code does:
   *   u = ones(1, nstates);
   *   S = [ Q u' ];
   *   eqStates = u / (S * S');
   * This is equivalent to:
   *   S = ones(nstates);
   *   eq_states = ones(1, nstates);
   *   S = Q * Q' + S;                  // BLAS DGEMM (S is now symmetric positive-definite)
   *   eqstates = eq_states * inv(S);   // LAPACK DGESV
   */
  double * S, * eq_states;
  size_t lds = (num_states + 1u) & ~1u;
  if ((S = malloc(num_states * lds * sizeof(double))) == NULL) {
    free(Q);
    GMCMC_ERROR("Unable to allocate S", GMCMC_ENOMEM);
  }
  if ((eq_states = malloc(num_states * sizeof(double))) == NULL) {
    free(S);
    free(Q);
    GMCMC_ERROR("Unable to allocate eq_states", GMCMC_ENOMEM);
  }

  for (size_t j = 0; j < num_states; j++) {
    for (size_t i = 0; i < num_states; i++)
      S[j * lds + i] = 1.0;
    eq_states[j] = 1.0;
  }

  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans,
              num_states, num_states, num_states,
              1.0, Q, ldq, Q, ldq, 1.0, S, lds);

  long info = clapack_dgesv(num_states, 1, S, lds, eq_states, num_states);

  free(S);

  if (info != 0) {
    free(eq_states);
    free(Q);
    *likelihood = -INFINITY;
    return 0;
  }


  // Split up the Q matrix into its component matrices
  double * Q_FF = Q;
  double * Q_FA = &Q[ion_model->closed * ldq];
  double * Q_AF = &Q[ion_model->closed];
  double * Q_AA = &Q[ion_model->closed * ldq + ion_model->closed];
  double * eq_statesf = eq_states;
  double * eq_statesa = &eq_states[ion_model->closed];


  // Calculate spectral matrices and eigenvectors of current Q_FF

  double * Vqff, * SpecMatqff;
  size_t ldsqff = (ion_model->closed + 1u) & ~1u;
  if ((Vqff = malloc(ion_model->closed * sizeof(double))) == NULL) {
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Unable to allocate eigenvalues of Q_FF", GMCMC_ENOMEM);
  }
  if ((SpecMatqff = malloc(ion_model->closed * ion_model->closed * ldsqff * sizeof(double))) == NULL) {
    free(Vqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Unable to allocate spectral matrices of Q_FF", GMCMC_ENOMEM);
  }

  if ((error = calculate_specmat_eigenvectors(ion_model->closed, Q_FF, ldq, Vqff, SpecMatqff, ldsqff)) != 0) {
    free(Vqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Failed to calculate spectral matrices and eigenvectors of Q_FF", error);
  }

  // Calculate spectral matrices and eigenvectors of current Q_AA

  double * Vqaa, * SpecMatqaa;
  size_t ldsqaa = (ion_model->open + 1u) & ~1u;
  if ((Vqaa = malloc(ion_model->open * sizeof(double))) == NULL) {
    free(Vqff);
    free(SpecMatqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Unable to allocate eigenvalues of Q_AA", GMCMC_ENOMEM);
  }
  if ((SpecMatqaa = malloc(ion_model->open * ion_model->open * ldsqaa * sizeof(double))) == NULL) {
    free(Vqaa);
    free(Vqff);
    free(SpecMatqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Unable to allocate spectral matrices of Q_AA", GMCMC_ENOMEM);
  }

  if ((error = calculate_specmat_eigenvectors(ion_model->open, Q_AA, ldq, Vqaa, SpecMatqaa, ldsqaa)) != 0) {
    free(Vqaa);
    free(SpecMatqaa);
    free(Vqff);
    free(SpecMatqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Failed to calculate spectral matrices and eigenvectors of Q_AA", error);
  }

  const double * timepoints = gmcmc_dataset_get_timepoints(dataset);
  const double * data = gmcmc_dataset_get_data(dataset, 0);


  // Calculate initial vectors for current state
  double * ll;
  if (data[0] == 0.0) {     // If starts with a closed state
    // Equilibrium closed states
    if ((ll = malloc(ion_model->closed * sizeof(double))) == NULL) {
      free(Vqaa);
      free(SpecMatqaa);
      free(Vqff);
      free(SpecMatqff);
      free(eq_states);
      free(Q);
      GMCMC_ERROR("Unable to allocate log likelihood", GMCMC_ENOMEM);
    }
    // Calculate in log space
    for (size_t i = 0; i < ion_model->closed; i++)
      ll[i] = log(eq_statesf[i]);
  }
  else {
    // Equilibrium open states
    if ((ll = malloc(ion_model->open * sizeof(double))) == NULL) {
      free(Vqaa);
      free(SpecMatqaa);
      free(Vqff);
      free(SpecMatqff);
      free(eq_states);
      free(Q);
      GMCMC_ERROR("Unable to allocate log likelihood", GMCMC_ENOMEM);
    }
    // Calculate in log space
    for (size_t i = 0; i < ion_model->open; i++)
      ll[i] = log(eq_statesa[i]);
  }

  // Don't need eq_states any more as we have copied the relevant parts into the log likelihood
  free(eq_states);


  // Do in a slow loop to begin with
  size_t num_timepoints = gmcmc_dataset_get_num_timepoints(dataset) - 1;
  for (size_t i = 0; i < num_timepoints; i++) {

    // Get time interval to next move
    double sojourn = timepoints[i + 1] - timepoints[i];

    // In closed state, moving to open state
    if (data[i] == 0.0)
      error = idealised_transition_probability(ion_model->closed, ion_model->open, sojourn, Vqff, Q_FA, ldq, SpecMatqff, ldsqff, ll);
    // In open state, moving to closed state
    else
      error = idealised_transition_probability(ion_model->open, ion_model->closed, sojourn, Vqaa, Q_AF, ldq, SpecMatqaa, ldsqaa, ll);

    if (error != 0) {
      free(Q);
      free(Vqaa);
      free(SpecMatqaa);
      free(Vqff);
      free(SpecMatqff);
      free(ll);
      GMCMC_ERROR("Unable to calculate idealised transition probability", error);
    }

  }

  // Don't need any of this stuff any more
  free(Vqaa);
  free(SpecMatqaa);
  free(Vqff);
  free(SpecMatqff);
  free(Q);

  // Actually all this unit vector multiplication does is sum the likelihood

  // Sum the log-likelihood terms
  if (data[num_timepoints] == 0.0)
    *likelihood = log_sum(ion_model->closed, ll);
  else
    *likelihood = log_sum(ion_model->open, ll);

  free(ll);

  return error;
}
const gmcmc_likelihood_function gmcmc_ion_likelihood_mh = &ion_likelihood_mh;

/**
 * Creates an Ion Channel model-specific data object.
 *
 * @param [out] ion_model           the Ion Channel model
 * @param [in]  closed              the number of closed states in the model
 * @param [in]  open                the number of open states in the model
 * @param [in]  calculate_Q_matrix  a function to calculate the Q matrix based
 *                                    on the current parameter values.  The
 *                                    closed states are presumed to be stored in
 *                                    the top-left of the matrix and the open
 *                                    states in the bottom-right
 *
 * @return 0 on success,
 *         EINVAL if calculate_Q_matrix is NULL, or
 *         ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_ion_model_create(gmcmc_ion_model ** ion_model,
                           unsigned int closed, unsigned int open,
                           void (*calculate_Q_matrix)(const double *, double *, size_t)) {
  if (calculate_Q_matrix == NULL)
    GMCMC_ERROR("calculate_Q_matrix is NULL", GMCMC_EINVAL);

  if ((*ion_model = malloc(sizeof(gmcmc_ion_model))) == NULL)
    GMCMC_ERROR("Unable to allocate Ion Channel model", GMCMC_ENOMEM);

  (*ion_model)->closed = closed;
  (*ion_model)->open = open;
  (*ion_model)->calculate_Q_matrix = calculate_Q_matrix;

  return 0;
}

/**
 * Destroys the Ion Channel model-specific data.
 *
 * @param [in] ion_model  the Ion Channel model-specific data object to destroy
 */
void gmcmc_ion_model_destroy(gmcmc_ion_model * ion_model) {
  free(ion_model);
}

/**
 * Gets the number of closed states in the model.
 *
 * @param [in] ion_model  the ion channel model
 *
 * @return the number of closed states in the model.
 */
unsigned int gmcmc_ion_model_get_num_closed_states(const gmcmc_ion_model * ion_model) {
  return ion_model->closed;
}

/**
 * Gets the number of open states in the model.
 *
 * @param [in] ion_model  the ion channel model
 *
 * @return the number of open states in the model.
 */
unsigned int gmcmc_ion_model_get_num_open_states(const gmcmc_ion_model * ion_model) {
  return ion_model->open;
}

/**
 * Calculates the Q matrix for an ion channel model.
 *
 * @param [in]  ion_model  the ion channel model
 * @param [in]  params     the parameter values to use to calculate the Q matrix
 * @param [out] Q          the Q matrix
 * @param [in]  ldq        leading dimension of the Q matrix
 */
void gmcmc_ion_model_calculate_Q_matrix(const gmcmc_ion_model * ion_model,
                                        const double * params, double * Q,
                                        size_t ldq) {
  ion_model->calculate_Q_matrix(params, Q, ldq);
}

/**
 * Calculates real-valued (right) eigenvectors and eigenvalues of X.
 *
 * @param [in]  n    the size of the matrix Q
 * @param [in]  Q    the matrix to calculate the eigenvalues and eigenvectors of
 * @param [in]  ldq  the leading dimension of Q
 * @param [out] V    the eigenvalues of Q
 * @param [out] X    the (right) eigenvectors of Q stored column by column
 * @param [in]  ldx  the leading dimension of X
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if temporary workspace variables could not be calculated,
 *         GMCMC_ELINAL if the eigenvectors of Q could not be calculated.
 */
static int eig(size_t n, const double * Q, size_t ldq, double * v, double * X, size_t ldx) {
  // Create a copy of Q so it is not overwritten by the dgeev routine
  double * A;
  size_t lda = (n + 1u) & ~1u;
  if ((A = malloc(lda * n * sizeof(double))) == NULL)
    GMCMC_ERROR("Unable to allocate A", GMCMC_ENOMEM);
  for (size_t j = 0; j < n; j++)
    memcpy(&A[j * lda], &Q[j * ldq], n * sizeof(double));

  // Allocate a vector for the non-existant imaginary parts of the eigenvalues
  double * wi;
  if ((wi = malloc(n * sizeof(double))) == NULL) {
    free(A);
    GMCMC_ERROR("Unable to allocate wi", GMCMC_ENOMEM);
  }

  // Calculate the eigenvalues and (right) eigenvectors using LAPACK
  long info = clapack_dgeev(false, true, n, A, lda, v, wi, NULL, 1, X, ldx);

  free(wi);
  free(A);

  if (info != 0)
    GMCMC_ERROR("Failed to calculate eigenvalues", GMCMC_ELINAL);

  return 0;
}

/**
 * Calculates the inverse of A.
 *
 * @param [in]  n    the size of the matrix
 * @param [in]  A    the matrix to invert
 * @param [in]  lda  the leading dimension of A
 * @param [out] B    the inverted matrix
 * @param [in]  ldb  the leading dimension of B
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if temporary workspace variables could not be allocated,
 *         GMCMC_ELINAL if the inverse could not be calculated (matrix is
 *                        singular to working precision)
 */
static int inv(size_t n, const double * A, size_t lda, double * B, size_t ldb) {
  if (n == 0)
    return 0;

  // Copy A into B as LAPACK is in place
  for (size_t j = 0; j < n; j++)
    memcpy(&B[j * ldb], &A[j * lda], n * sizeof(double));

  // Calculate the LU decomposition of B
  long * ipiv;
  long info = clapack_dgetrf(n, n, B, ldb, &ipiv);
  if (info != 0)
    GMCMC_ERROR("Unable to calculate LU decomposition", GMCMC_ELINAL);

  // Calculate the inverse
  info = clapack_dgetri(n, B, ldb, ipiv);

  free(ipiv);

  if (info != 0)
    GMCMC_ERROR("Unable to calculate inverse", GMCMC_ELINAL);

  return 0;
}

/**
 * Calculates the spectral matrices and eigenvectors of closed or open states.
 *
 * @param [in]  n    the number of states
 * @param [in]  Q    the Q (sub)matrix detailing the transitions between
 *                     closed or open states
 * @param [in]  ldq  the leading dimension of Q
 * @param [out] v    the eigenvalues of Q are placed in here (length n)
 * @param [out] S    an array of spectral matrices to populate (n * n * lds)
 * @param [in]  lds  the leading dimension of S
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory available to allocate
 *                      temporary matrices,
 *         GMCMC_ELINAL if there was an error calculating the eigenvectors or
 *                      inverse.
 */
static int calculate_specmat_eigenvectors(size_t n, const double * Q, size_t ldq,
                                          double * v, double * S, size_t lds) {
  // Calculate spectral matrices and eigenvectors of current Q

  // [ X V ] = eig(Q);
  // V_Q_AA = diag(X);  % Eigenvectors
  double * X;
  size_t ldx = (n + 1u) & ~1u;
  int error;
  if ((X = malloc(n * ldx * sizeof(double))) == NULL)
    GMCMC_ERROR("Unable to allocate temporary variable X", GMCMC_ENOMEM);
  if ((error = eig(n, Q, ldq, v, X, ldx)) != 0) {
    free(X);
    GMCMC_ERROR("Unable to calculate eigenvalues of Q", error);
  }

  // Y = inv(X);
  double * Y;
  size_t ldy = (n + 1u) & ~1u;
  if ((Y = malloc(n * ldy * sizeof(double))) == NULL) {
    free(X);
    GMCMC_ERROR("Unable to allocate temporary variable Y = inv(X)", GMCMC_ENOMEM);
  }
  if ((error = inv(n, X, ldx, Y, ldy)) != 0) {
    free(Y);
    free(X);
    GMCMC_ERROR("Unable to calculate inverse", error);
  }

  for (size_t k = 0; k < n; k++) {
    double * Spec = &S[k * n * lds];            // Current spectral matrix

    // Outer product
    // S(i,j) = X(k,j) * Y(i,k)
    for (size_t j = 0; j < n; j++) {
      for (size_t i = 0; i < n; i++)
        Spec[j * lds + i] = X[k * ldx + i] * Y[j * ldy + k];    // Calculate spectral matrices
    }
  }

  free(X);
  free(Y);

  return 0;
}

/**
 * Calculate the idealised transition probability from closed to open or
 * vice-versa.
 *
 * @param [in]     m        the number of equilibrium states in the current state
 * @param [in]     n        the number of equilibrium states in the new state
 * @param [in]     sojourn  the time difference between this data point and the next
 * @param [in]     v        the eigenvalues of the Q transition submatrix matrix (length m)
 * @param [in]     Q        the Q transition submatrix (m by n)
 * @param [in]     ldq      the leading dimension of Q
 * @param [in]     SpecMat  the spectral matrices (m of m by m)
 * @param [in]     lds      the leading dimension of the spectral matrices
 * @param [in,out] ll       the log likelihood (length m)
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enought memory to allocate temporary matrices,
 *         GMCMC_ELINAL if there was an error in a linear algebra library routine
 */
static int idealised_transition_probability(size_t m, size_t n,
                                            double sojourn, const double * v,
                                            const double * Q, size_t ldq,
                                            const double * SpecMat, size_t lds,
                                            double * ll) {
  // G_FA = zeros(length(EqStates_F));
  double * G;
  size_t ldg = (m + 1u) & ~1u;
  if ((G = calloc(m * ldg, sizeof(double))) == NULL)
    GMCMC_ERROR("Unable to allocate G", GMCMC_ENOMEM);

  // for j = 1:length(EqStates_F)
  //   G_FA = G_FA + exp( V_Q_FF(j)*Sojourn ).*SpecMat_Q_FF{j};
  // end
  for (size_t k = 0; k < m; k++) {
    const double * S = &SpecMat[k * m * lds]; // Current spectral matrix
    double alpha = exp(v[k] * sojourn);
    for (size_t j = 0; j < m; j++) {
      for (size_t i = 0; i < m; i++)
        G[j * ldg + i] += alpha * S[j * lds + i];
    }
  }

  // G_FA = G_FA*Q_FA
  // In-place matrix multiply: A = AB
  // Need temporary matrix T to hold G_FA*Q_FA without modifying G_FA so we can use
  // CBLAS DGEMM
  double * T;
  size_t ldt = (m + 1u) & ~1u;
  if ((T = malloc(n * ldt * sizeof(double))) == NULL) {
    free(G);
    GMCMC_ERROR("Unable to allocate temporary matrix", GMCMC_ENOMEM);
  }
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, n, m, 1.0, G, ldg, Q, ldq, 0.0, T, ldt);

  /*
   * Logarithmic update.
   */
  // Calculate log(L*G) in terms of LL = log(L) and G

  // Do element-wise logarithmic calculation
  double * temp, * new_ll;
  if ((temp = malloc(m * sizeof(double))) == NULL) {
    free(T);
    free(G);
    GMCMC_ERROR("Failed to allocate temporary array", GMCMC_ENOMEM);
  }
  if ((new_ll = malloc(n * sizeof(double))) == NULL) {
    free(temp);
    free(T);
    free(G);
    GMCMC_ERROR("Failed to allocate temporary array", GMCMC_ENOMEM);
  }

  for (size_t j = 0; j < n; j++) {
    /* Multiply row by column in log - i.e. sum! */
    for (size_t i = 0; i < m; i++)
      temp[i] = ll[i] + log(fabs(T[j * ldt + i]));    // T contains G_FA and we want log(G_FA) here

    new_ll[j] = log_sum(m, temp);
  }
  memcpy(ll, new_ll, n * sizeof(double));

  // Cleanup
  free(new_ll);
  free(temp);
  free(T);
  free(G);

  return 0;
}

/**
 * Compares x to y as doubles.  Used to sort double values into descending
 * order.
 *
 * @param x,y  two doubles to compare
 * @return -1 if x > y, 1 if x < y, 0 otherwise.
 */
static int comparator(const void * x, const void * y) {
  double a, b;

  a = *(double*)x;
  b = *(double*)y;

  return isless(a, b) ? 1 : ((a == b) ? 0 : -1);
}

/**
 * Computes the sum of x in log-space.
 *
 * @param [in]     n  the length of x
 * @param [in,out] x  a vector to sum
 *
 * @return the log of the sum.
 */
static double log_sum(size_t n, double * x) {
  // No sum
  if (n == 0)
    return 0.0;

  // Sort values in x into descending order
  qsort(x, n, sizeof(double), comparator);

  // If n is 1 then no need to sum - just return x[0]
  // If x[0] is -inf then return -inf - in x[0]
  if (n == 1 || isinf(x[0]) == -1)
    return x[0];

  // Do normal sum
  double sum = 0.0;
  for (size_t i = 1; i < n; i++)
    sum += exp(x[i] - x[0]);

  return x[0] + log(1.0 + sum);
}
