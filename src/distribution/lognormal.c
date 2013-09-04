/*
 * lognormal.c
 *
 *  Created on: 28 May 2013
 *      Author: Gary Macindoe
 */
#include <gmcmc/gmcmc_distribution.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <math.h>
#include "randn.c"

/**
 * Lognormal distribution parameter structure.
 */
typedef struct {
  double mu;    /**< Mean (-inf < mu < inf) */
  double sigma; /**< Standard deviation (0.0 < sigma < inf) */
} lognormal;

static double sample(const void * params, const gmcmc_prng64 * r) {
  lognormal * l = (lognormal *)params;
  return exp(l->mu + l->sigma * gmcmc_randn(r));
}

static double log_pdf(const void * params, double x) {
  lognormal * l = (lognormal *)params;
  if (isnan(x))
    return NAN;
  if (islessequal(x, 0.0) || isinf(x))
    return -INFINITY;
  return -M_HALFLOG2PI - log(l->sigma) - log(x) -
         ((log(x) - l->mu) * (log(x) - l->mu)) / (2.0 * l->sigma * l->sigma);
}

static double log_pdf_1st_order(const void * params, double x) {
  lognormal * l = (lognormal *)params;
  if (isnan(x) || islessequal(x, 0.0) || isinf(x))
    return NAN;
  return -((log(x) - l->mu) / (l->sigma * l->sigma * x)) - (1.0 / x);
}

static double log_pdf_2nd_order(const void * params, double x) {
  lognormal * l = (lognormal *)params;
  if (isnan(x) || islessequal(x, 0.0) || isinf(x))
    return NAN;
  return (log(x) + l->sigma * l->sigma - l->mu - 1.0) / (l->sigma * l->sigma * x * x);
}

static const gmcmc_distribution_type type = { "Lognormal",
                                              sample,
                                              log_pdf,
                                              log_pdf_1st_order,
                                              log_pdf_2nd_order,
                                              sizeof(lognormal) };

/**
 * Creates a new continuous real lognormal probability distribution.
 *
 * @param [out] dist   the distribution to create
 * @param [in]  mu     the log scale of the distribution
 * @param [in]  sigma  the log standard deviation of the distribution
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if mu or sigma are not finite or if sigma is less than
 *                        or equal to zero,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                        distribution or parameter vector.
 */
int gmcmc_distribution_create_lognormal(gmcmc_distribution ** dist, double mu,
                                        double sigma) {
  if (!isfinite(mu))
    GMCMC_ERROR("'mu' must be finite", GMCMC_EINVAL);
  else if (!isfinite(sigma))
    GMCMC_ERROR("'sigma' must be finite", GMCMC_EINVAL);
  else if (sigma <= 0.0)
    GMCMC_ERROR("'sigma' must be greater than zero", GMCMC_EINVAL);

  if ((*dist = malloc(sizeof(gmcmc_distribution))) == NULL)
    GMCMC_ERROR("Failed to allocate distribution", GMCMC_ENOMEM);
  if (((*dist)->params = malloc(sizeof(lognormal))) == NULL) {
    free(*dist);
    GMCMC_ERROR("Failed to allocate distribution parameters", GMCMC_ENOMEM);
  }

  (*dist)->type = &type;
  ((lognormal *)(*dist)->params)->mu = mu;
  ((lognormal *)(*dist)->params)->sigma = sigma;

  return 0;
}
