#include <gmcmc/gmcmc_ion_model.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>

/**
 * Ion Channel model-specific data.
 *
 * In addition to data common to all models, ion channel models have a Q matrix
 * which details the transitions between open and closed states.
 */
struct gmcmc_ion_model {
  unsigned int closed, open;                            /**< Number of closed and open states */
  void (*calculate_Q_matrix)(const double *, double *,  /**< Function to update Q matrix based*/
                             size_t);                   /* on current parameter values */
};

/**
 * Ion Channel model proposal function using Metropolis-Hastings.
 */
static int ion_proposal_mh(const gmcmc_likelihood * likelihood, size_t n,
                           const double * params, double temperature, double stepsize,
                           double * mean, double * covariance, size_t ldc) {

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
 */
static int ion_likelihood_mh(const gmcmc_model * model, size_t n,
                             const double * params, const gmcmc_dataset * data,
                             gmcmc_likelihood ** likelihood) {
  // Initialise error status
  int error = 0;

  // Allocate the likelihood object
  if ((*likelihood = malloc(sizeof(gmcmc_likelihood))) == NULL)
    GMCMC_ERROR("Unable to allocate likelihood object", GMCMC_ENOMEM);

  (*likelihood)->destroy = gmcmc_likelihood_destroy;

  // Get the model specific data
  gmcmc_ion_model * ion_model = (gmcmc_ion_model *)gmcmc_model_get_modelspecific(model);
  const unsigned int num_states = ion_model->closed + ion_model->open;

  // Allocate the Q matrix
  double * Q;
  size_t ldq = (num_states + 1u) & ~1u;
  if ((Q = malloc((num_states) * ldq * sizeof(double))) == NULL) {
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate Q matrix", GMCMC_ENOMEM);
  }

  // Calculate the Q matrix
  if ((error = ion_model->calculate_Q_matrix(params, n, Q, ldq)) != 0) {
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to calculate Q matrix", error);
  }

  // Split up the Q matrix into its component matrices
  double * Q_FF = Q;
  double * Q_FA = &Q[ion_model->closed * ldq];
  double * Q_AF = &Q[ion_model->closed];
  double * Q_AA = &Q[ion_model->closed * ldq + ion_model->closed];


  /* Calculate equilibrium state occupancies
   *
   * The original (Matlab) code does:
   *   u = ones(1, nstates);
   *   S = [ Q u' ];
   *   eqStates = u / (S * S');
   * This is equivalent to:
   *   S = ones(nstates);
   *   eq_states = ones(1, nstates);
   *   S += Q * Q';             // BLAS DGEMM
   *   eqstates *= inv(S);      // BLAS DGESV
   */
  double * S, * eq_states;
  size_t lds = (num_states + 1u) & ~1u;
  if ((S = malloc((num_states) * lds * sizeof(double))) == NULL) {
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate S", GMCMC_ENOMEM);
  }
  if ((eq_states = malloc((num_states) * sizeof(double))) == NULL) {
    free(S);
    free(Q);
    free(*likelihood);
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

  // Check for numerical instability in the inverse
  feclearexcept(FE_ALL_EXCEPT);
  cblas_dgesv(CblasColMajor, CblasUpper, CblasNoTrans, CblasNonUnit, num_states,
              S, lds, eq_states, 1);
  if (fetestexcept(FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INVALID) != 0)
    GMCMC_ERROR("Possible numerical instability", GMCMC_EFP);

  free(S);


  // Calculate spectral matrices and eigenvectors of current Q_FF
  // [ X V ] = eig(Q_FF)
  // Vqff = diag(X)
  double * Vqff, * X;
  size_t ldx = (model->closed + 1u) & ~1u;
  if ((Vqff = malloc(model->closed * sizeof(double))) == NULL) {
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate eigenvalues of Q_FF", GMCMC_ENOMEM);
  }
  if ((X = malloc(model->closed * ldx * sizeof(double))) == NULL) {
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate X", GMCMC_ENOMEM);
  }
  if ((error = eig(n, Q_FF, ldq, Vqff, X, ldx)) != 0) {
    free(X);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to calculate eigenvalues of Q_FF", GMCMC_ELINALG);
  }

  // Y = inv(X)
  double * Y;
  size_t ldy = (model->closed + 1u) & ~1u;
  if ((Y = malloc(model->closed * ldy * sizeof(double))) == NULL) {
    free(X);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate Y", GMCMC_ENOMEM);
  }
  if ((error = inv(model->closed, X, ldx, Y, ldy)) != 0) {
    free(Y);
    free(X);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to calculate inverse", GMCMC_ELINALG);
  }

  // for j = 1:ion_model->closed
  //   SpecMatqff[j] = X(:,j)*Y(j,:)    // Outer product
  double * SpecMatqff;
  size_t ldsqff = (ion_model->closed + 1u) & ~1u;
  if ((SpecMatqff = malloc(ion_model->closed * ion_model->closed * ldsqff * sizeof(double))) == NULL) {
    free(Y);
    free(X);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate spectral matrices for Q_FF", GMCMC_ENOMEM);
  }

  // This is O(N^4)
  for (size_t k = 0; k < ion_model->closed; k++) {
    double * S = &SpecMatqff[k * ion_model->closed * ldsqff];
    double * x = &X[j * ldx]; size_t incx = ldx;
    double * y = &Y[j]; size_t incy = 1;
    for (size_t j = 0; j < ion_model->closed; j++) {
      for (size_t i = 0; i < ion_model->closed; i++)
        S[j * lds + i] = cblas_ddot(ion_model->closed, x, incx, y, incy);
    }
  }

  free(X);
  free(Y);


  // Calculate spectral matrices and eigenvectors of current Q_AA
  // [ X V ] = eig(Q_AA)
  // Vqaa = diag(X)
  double * Vqaa;
  ldx = (model->open + 1u) & ~1u;
  if ((Vqaa = malloc(model->open * sizeof(double))) == NULL) {
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate eigenvalues of Q_AA", GMCMC_ENOMEM);
  }
  if ((X = malloc(model->open * ldx * sizeof(double))) == NULL) {
    free(Vqaa);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate X", GMCMC_ENOMEM);
  }
  if ((error = eig(n, Q_AA, ldq, Vqaa, X, ldx)) != 0) {
    free(X);
    free(Vqaa);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to calculate eigenvalues of Q_FF", GMCMC_ELINALG);
  }

  // Y = inv(X)
  ldy = (model->open + 1u) & ~1u;
  if ((Y = malloc(model->open * ldy * sizeof(double))) == NULL) {
    free(X);
    free(Vqaa);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate Y", GMCMC_ENOMEM);
  }
  if ((error = inv(model->open, X, ldx, Y, ldy)) != 0) {
    free(Y);
    free(X);
    free(Vqaa);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to calculate inverse", GMCMC_ELINALG);
  }

  // for j = 1:ion_model->open
  //   SpecMatqaa[j] = X(:,j)*Y(j,:)    // Outer product
  double * SpecMatqaa;
  size_t ldsqaa = (ion_model->open + 1u) & ~1u;
  if ((SpecMatqaa = malloc(ion_model->open * ion_model->open * ldsqaa * sizeof(double))) == NULL) {
    free(Y);
    free(X);
    free(Vqaa);
    free(Vqff);
    free(eq_states);
    free(Q);
    free(*likelihood);
    GMCMC_ERROR("Unable to allocate spectral matrices for Q_FF", GMCMC_ENOMEM);
  }

  // This is O(N^4)
  for (size_t k = 0; k < ion_model->open; k++) {
    double * S = &SpecMatqaa[k * ion_model->open * ldsqaa];
    double * x = &X[j * ldx]; size_t incx = ldx;
    double * y = &Y[j]; size_t incy = 1;
    for (size_t j = 0; j < ion_model->open; j++) {
      for (size_t i = 0; i < ion_model->open; i++)
        S[j * lds + i] = cblas_ddot(ion_model->open, x, incx, y, incy);
    }
  }

  free(X);
  free(Y);

  // Don't need Q any more (we've also overwritten it with shite from the eigenvalue calculation)
  free(Q);


  double * eq_statesf = eq_states, * eq_statesa = &eq_states[ion_model->closed];

  // Calculate initial vectors for current state
  if (gmcmc_dataset_y(dataset, 0) == 0.0) {     // If starts with a closed state
    // Equilibrium closed states
    if (((*likelihood)->ll = malloc(ion_model->closed * sizeof(double))) == NULL) {
      free(Vqaa);
      free(Vqff);
      free(eq_states);
      free(*likelihood);
      GMCMC_ERROR("Unable to allocate log likelihood", GMCMC_ENOMEM);
    }
    // Calculate in log space
    for (size_t i = 0; i < ion_model->closed; i++)
      (*likelihood)->ll[i] = log10(eq_statesf[i]);
  }
  else {
    // Equilibrium open states
    if (((*likelihood)->ll = malloc(ion_model->open * sizeof(double))) == NULL) {
      free(Vqaa);
      free(Vqff);
      free(eq_states);
      free(*likelihood);
      GMCMC_ERROR("Unable to allocate log likelihood", GMCMC_ENOMEM);
    }
    // Calculate in log space
    for (size_t i = 0; i < ion_model->open; i++)
      (*likelihood)->ll[i] = log(eq_statesa[i]);
  }

  // Don't need eq_states any more as we have copied the relevant parts into the log likelihood
  free(eq_states);


  // Do in a slow loop to begin with
  for (size_t i = 0; i < gmcmc_dataset_size(dataset) - 1; i++) {

    // Get time interval to next move
    double sojourn = gmcmc_dataset_x(dataset, i + 1) - gmcmc_dataset_x(dataset, i);

    // In closed state, moving to open state
    if (gmcmc_dataset_y(dataset, i) == 0) {

      // Calculate idealised transition probability from closed to open
      double * Gfa;
      size_t ldg = (ion_model->closed + 1u) & ~1u;
      if ((Gfa = malloc(ion_model->closed * ldg * sizeof(double))) == NULL) {
        free(Vqaa);
        free(Vqff);
        free(*likelihood);
        GMCMC_ERROR("Unable to allocate transition matrix", GMCMC_ENOMEM);
      }
      for (size_t j = 0; j < ion_model->closed; j++) {
        for (size_t i = 0; i < ion_model->closed; i++)
          Gfa[j * ldg + i] = 0.0;
      }

      for (size_t k = 0; k < ion_model->closed; k++) {
        double e = exp(Vqff[k] * sojourn);
        double * S = SpecMatqff[k * ion_model->closed * ldsqff];
        for (size_t j = 0; j < ion_model->closed; j++) {
          for (size_t i = 0; i < ion_model->closed; i++)
            Gfa[j * ldg + i] += e * S[j * ldsqff + i];
        }
      }

      double * LGfa;
      if ((LGfa = malloc(ion_model->closed * ldg * sizeof(double))) == NULL) {
        free(Gfa);
        free(Vqaa);
        free(Vqff);
        free(*likelihood);
        GMCMC_ERROR("Unable to allocate log transition matrix", GMCMC_ENOMEM);
      }
      for (size_t j = 0; j < ion_model->closed; j++) {
        for (size_t i = 0; i < ion_model->closed; i++)
          LGfa[j * ldg + i] = 0.0;
        for (size_t k = 0; k < ion_model->closed; k++) {
          double b = Q_FA[j * ldq + k];
          for (size_t i = 0; i < ion_model->closed; i++)
            LGfa[j * ldg + i] += Gfa[k * ldg + i] * b;
        }
        for (size_t i = 0; i < ion_model->closed; i++)
          LGfa[j * ldg + i] = log(LGfa[j * ldg + i]);
      }
      
    }
    // In open state, moving to closed state
    else {
    }

  }

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
 * Calculates real (right) eigenvectors and eigenvalues of X.
 *
 * @param [in]     n    the size of the matrix Q
 * @param [in,out] Q    the matrix to calculate the eigenvalues and eigenvectors of
 * @param [in]     ldq  the leading dimension of Q
 * @param [out]    V    the eigenvalues of Q
 * @param [out]    X    the (right) eigenvectors of Q stored column by column
 * @param [in]     ldx  the leading dimension of X
 *
 * @return 0 on success, non-zero on error.
 */
static int eig(size_t n, double * Q, size_t ldq, double * V, double * X, size_t ldx) {
  double * wi, * work, size;
  int ldvl = 1, lwork = -1, info = 0;

  // Calculate the workspace size needed to calculate the eigenvalues and eigenvectors
  dgeev("N", "V", (int *)&n, Q, (int *)&ldq, Vqff, NULL, NULL, &ldvl, X, (int *)&ldx, &size, &lwork, &info);
  if (info != 0)
    GMCMC_ERROR("Unable to calculate eig workspace size", GMCMC_ELINALG);
  lwork = size;

  // Allocate workspace and a temporary vector to store the (possible) imaginary parts of the eigenvalues
  if ((work = malloc((size_t)lwork * sizeof(double))) == NULL)
    GMCMC_ERROR("Unable to allocate eig workspace", GMCMC_ENOMEM);
  if ((wi = malloc(n * sizeof(double))) == NULL) {
    free(work);
    GMCMC_ERROR("Unable to allocate temporary vector", GMCMC_ENOMEM);
  }

  // Calculate the eigenvalues and (right) eigenvectors
  dgeev("N", "V", (int *)&n, Q, (int *)&ldq, V, wi, NULL, &ldvl, X, (int *)&ldx, work, &lwork, &info);

  free(wi);
  free(work);

  if (info != 0)
    GMCMC_ERROR("Failed to calculate eigenvalues", GMCMC_ELINALG);

  return 0;
}

static int inv(size_t n, const double * X, size_t ldx, double * Y, size_t ldy) {
  if (n == 0)
    return 0;

  // Copy X into Y as LAPACK is in place
  for (size_t j = 0; j < n; j++)
    memcpy(&Y[j * ldy], &X[j * ldx], n * sizeof(double));

  // Pivot array
  int * ipiv;
  if ((ipiv = malloc(n * sizeof(int))) == NULL)
    GMCMC_ERROR("Unable to allocate pivot array", GMCMC_ENOMEM);

  // Calculate the LU decomposition of Y
  int info;
  dgetrf_(&n, &n, Y, (int *)&ldy, ipiv, &info);

  if (info != 0) {
    free(ipiv);
    GMCMC_ERROR("Unable to calculate LU decomposition", GMCMC_ELINALG);
  }

  // Calling DGETRI with lwork = -1 causes it to return the optimal workspace size in work[0]
  double size;
  int lwork = -1;
  dgetri_(&n, NULL, &ldy, NULL, &size, &lwork, &info);
  if (info != 0) {
    free(ipiv);
    GMCMC_ERROR("Unable to calculate optimal workspace size", GMCMC_ELINALG);
  }

  // Allocate the workspace
  lwork = (int)size;
  double * work;
  if ((work = malloc((size_t)lwork * sizeof(double))) == NULL) {
    free(ipiv);
    GMCMC_ERROR("Unable to allocate workspace", ENOMEM);
  }

  // Calculate the inverse
  dgetri_(&n, Y, &ldy, ipiv, work, &lwork, &info);

  free(ipiv);
  free(work);

  if (info != 0)
    GMCMC_ERROR("Unable to calculate inverse", GMCMC_ELINALG);

  return 0;
}
