#include <gmcmc/gmcmc_ion.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>


// Forward declarations of utility functions
static int calculate_specmat_eigenvectors(size_t, double *, size_t,
                                          double *, double *, size_t);
static int idealised_transition_probability(size_t, size_t, double,
                                            const double *,
                                            const double *, size_t,
                                            const double *, size_t,
                                            double *);
static double log_sum(size_t, double *);

/**
 * Ion Channel model likelihood function using Metropolis-Hastings.
 * Calculates p(D|M,params) (i.e. likelihood of seeing the data D given the
 * model M and parameters params)
 *
 * @param [in]  dataset     dataset
 * @param [in]  model       model to evaluate
 * @param [in]  n           number of parameters in the current block
 * @param [in]  block       indices of the parameters in the current block (may
 *                            be NULL if there is no blocking)
 * @param [in]  params      current parameter values to evaluate the model
 * @param [out] likelihood  likelihood value
 * @param [out] geometry    geometry for the current parameter block (may be
 *                            NULL if no geometry is required by the current
 *                            stage of the algorithm)
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate temporary
 *                        variables,
 *         GMCMC_ELINAL if there was an unrecoverable error in an external
 *                        linear algebra routine.
 */
static int ion_likelihood_mh(const void * dataset, const gmcmc_model * model,
                             size_t n, const size_t * block, const double * params,
                             double * likelihood, void ** geometry) {
  // Metropolis-Hastings likelihood functions don't calculate geometry
  (void)geometry;
  (void)n;
  (void)block;

  // Initialise error status
  int error = 0;

  // Initialise log likelihood to negative infinity so that it is set on
  // non-fatal errors
  *likelihood = -INFINITY;

  // Get the model specific data
  const gmcmc_ion_model * ion_model = (const gmcmc_ion_model *)gmcmc_model_get_modelspecific(model);
  const gmcmc_ion_dataset * ion_dataset = (const gmcmc_ion_dataset *)dataset;

  // Get the number of open and closed states
  const unsigned int num_closed = gmcmc_ion_model_get_num_closed_states(ion_model);
  const unsigned int num_open = gmcmc_ion_model_get_num_open_states(ion_model);
  const unsigned int num_states = num_closed + num_open;

  // Allocate the Q matrix
  double * Q;
  size_t ldq = (num_states + 1u) & ~1u;
  if ((Q = calloc(num_states * ldq, sizeof(double))) == NULL)
    GMCMC_ERROR("Unable to allocate Q matrix", GMCMC_ENOMEM);

  // Calculate the Q matrix
  gmcmc_ion_model_calculate_Q_matrix(ion_model, params, Q, ldq);


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

  lapack_int * ipiv;
  if ((ipiv = malloc(num_states * sizeof(lapack_int))) == NULL) {
    free(eq_states);
    free(S);
    free(Q);
    GMCMC_ERROR("Failed to allocate LAPACK pivot array", GMCMC_ENOMEM);
  }
  long info = LAPACKE_dgesv(LAPACK_COL_MAJOR, num_states, 1, S, lds, ipiv, eq_states, num_states);

  free(ipiv);
  free(S);

  if (info != 0) {
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Matrix is singular to working precision", GMCMC_ELINAL);
  }


  // Split up the Q matrix into its component matrices
  double * Q_FF = Q;
  double * Q_FA = &Q[num_closed * ldq];
  double * Q_AF = &Q[num_closed];
  double * Q_AA = &Q[num_closed * ldq + num_closed];
  double * eq_statesf = eq_states;
  double * eq_statesa = &eq_states[num_closed];


  // Calculate spectral matrices and eigenvectors of current Q_FF

  double * Vqff = NULL, * SpecMatqff = NULL;
  size_t ldsqff = (num_closed + 1u) & ~1u;
  if ((Vqff = malloc(num_closed * sizeof(double))) == NULL ||
      (SpecMatqff = malloc(num_closed * num_closed * ldsqff * sizeof(double))) == NULL) {
    free(Vqff);
    free(SpecMatqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Unable to allocate eigenvalues and spectral matrices of Q_FF", GMCMC_ENOMEM);
  }

  if ((error = calculate_specmat_eigenvectors(num_closed, Q_FF, ldq, Vqff, SpecMatqff, ldsqff)) != 0) {
    free(Vqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Failed to calculate spectral matrices and eigenvectors of Q_FF", error);
  }

  // Calculate spectral matrices and eigenvectors of current Q_AA

  double * Vqaa = NULL, * SpecMatqaa = NULL;
  size_t ldsqaa = (num_open + 1u) & ~1u;
  if ((Vqaa = malloc(num_open * sizeof(double))) == NULL ||
      (SpecMatqaa = malloc(num_open * num_open * ldsqaa * sizeof(double))) == NULL) {
    free(Vqaa);
    free(SpecMatqaa);
    free(Vqff);
    free(SpecMatqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Unable to allocate eigenvalues of Q_AA", GMCMC_ENOMEM);
  }

  if ((error = calculate_specmat_eigenvectors(num_open, Q_AA, ldq, Vqaa, SpecMatqaa, ldsqaa)) != 0) {
    free(Vqaa);
    free(SpecMatqaa);
    free(Vqff);
    free(SpecMatqff);
    free(eq_states);
    free(Q);
    GMCMC_ERROR("Failed to calculate spectral matrices and eigenvectors of Q_AA", error);
  }


  // Calculate initial vectors for current state
  double * ll;
  const double * data = gmcmc_ion_dataset_data(ion_dataset);
  if (data[0] == 0.0) {     // If starts with a closed state
    // Equilibrium closed states
    if ((ll = malloc(num_closed * sizeof(double))) == NULL) {
      free(Vqaa);
      free(SpecMatqaa);
      free(Vqff);
      free(SpecMatqff);
      free(eq_states);
      free(Q);
      GMCMC_ERROR("Unable to allocate log likelihood", GMCMC_ENOMEM);
    }
    // Calculate in log space
    for (size_t i = 0; i < num_closed; i++)
      ll[i] = log(eq_statesf[i]);
  }
  else {
    // Equilibrium open states
    if ((ll = malloc(num_open * sizeof(double))) == NULL) {
      free(Vqaa);
      free(SpecMatqaa);
      free(Vqff);
      free(SpecMatqff);
      free(eq_states);
      free(Q);
      GMCMC_ERROR("Unable to allocate log likelihood", GMCMC_ENOMEM);
    }
    // Calculate in log space
    for (size_t i = 0; i < num_open; i++)
      ll[i] = log(eq_statesa[i]);
  }

  // Don't need eq_states any more as we have copied the relevant parts into the log likelihood
  free(eq_states);


  // Do in a slow loop to begin with
  size_t num_timepoints = gmcmc_ion_dataset_num_timepoints(ion_dataset) - 1;
  const double * timepoints = gmcmc_ion_dataset_timepoints(ion_dataset);
  for (size_t i = 0; i < num_timepoints; i++) {

    // Get time interval to next move
    double sojourn = timepoints[i + 1] - timepoints[i];

    // In closed state, moving to open state
    if (data[i] == 0.0)
      error = idealised_transition_probability(num_closed, num_open, sojourn,
                                               Vqff, Q_FA, ldq, SpecMatqff, ldsqff, ll);
    // In open state, moving to closed state
    else
      error = idealised_transition_probability(num_open, num_closed, sojourn,
                                               Vqaa, Q_AF, ldq, SpecMatqaa, ldsqaa, ll);

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
    *likelihood = log_sum(num_closed, ll);
  else
    *likelihood = log_sum(num_open, ll);

  free(ll);

  return error;
}
const gmcmc_likelihood_function gmcmc_ion_likelihood_mh = &ion_likelihood_mh;

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
 * @return = 0 on success,
 *         > 0 if a fatal error occurred,
 *         < 0 if a recoverable error occurred.
 *         The absolute of the return value will be
 *         GMCMC_ENOMEM if there is not enough memory available to allocate
 *                        temporary matrices,
 *         GMCMC_EINVAL if an invalid argument was passed to a LAPACK function,
 *         GMCMC_ELINAL if there was an error calculating the eigenvectors or
 *                        inverse.
 */
static int calculate_specmat_eigenvectors(size_t n, double * Q, size_t ldq,
                                          double * v, double * S, size_t lds) {
  // Calculate spectral matrices and eigenvectors of current Q

  // [ X V ] = eig(Q);
  // V_Q_AA = diag(X);  % Eigenvectors
  double * X = NULL, * Y = NULL, * wi = NULL;
  size_t ldx = (n + 1u) & ~1u, ldy = ldx;
  if ((X = malloc(n * ldx * sizeof(double))) == NULL ||
      (Y = malloc(n * ldx * sizeof(double))) == NULL ||
      (wi = malloc(n * sizeof(double))) == NULL)
    GMCMC_ERROR("Unable to allocate temporary variables", GMCMC_ENOMEM);

  // Calculate the eigenvalues and (right) eigenvectors using LAPACK
  long info = LAPACKE_dgeev(LAPACK_COL_MAJOR, 'N', 'V', n, Q, ldq, v, wi, NULL, 1, X, ldx);
  free(wi);
  if (info != 0) {
    free(X);
    free(Y);
    if (info < 0)
      GMCMC_ERROR("Invalid argument passed to LAPACK function", GMCMC_EINVAL);
    else
      GMCMC_WARNING("Unable to calculate eigenvalues of current Q matrix", GMCMC_ELINAL);
  }

  // Y = inv(X);
  // Calculate the inverse of Y via the LU decomposition
  lapack_int * ipiv;
  if ((ipiv = malloc(n * sizeof(lapack_int))) == NULL) {
    free(X);
    free(Y);
    GMCMC_ERROR("Failed to allocate LAPACK pivot array", GMCMC_ENOMEM);
  }
  for (size_t j = 0; j < n; j++)
    memcpy(&Y[j * ldy], &X[j * ldx], n * sizeof(double));
  if ((info = LAPACKE_dgetrf(LAPACK_COL_MAJOR, n, n, Y, ldy, ipiv)) != 0 ||
      (info = LAPACKE_dgetri(LAPACK_COL_MAJOR, n, Y, ldy, ipiv) != 0)) {
    free(ipiv);
    free(X);
    free(Y);
    if (info < 0)
      GMCMC_ERROR("Invalid argument passed to LAPACK function", GMCMC_EINVAL);
    else
      GMCMC_WARNING("Matrix is singular to working precision", GMCMC_ELINAL);
  }
  free(ipiv);

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
 *         GMCMC_ENOMEM if there is not enought memory to allocate temporary matrices.
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
  free(G);

  /*
   * Logarithmic update.
   */
  // Calculate log(L*G) in terms of LL = log(L) and G

  // Do element-wise logarithmic calculation
  double * temp = NULL, * new_ll = NULL;
  if ((temp = malloc(m * sizeof(double))) == NULL ||
      (new_ll = malloc(n * sizeof(double))) == NULL) {
    free(temp);
    free(new_ll);
    free(T);
    GMCMC_ERROR("Failed to allocate temporary arrays", GMCMC_ENOMEM);
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

  a = *(const double *)x;
  b = *(const double *)y;

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
