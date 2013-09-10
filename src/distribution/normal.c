/*
 * normal.c
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
 * Normal distribution parameter structure.
 */
typedef struct {
  double mu;    /**< Mean (-inf < mu < inf) */
  double sigma; /**< Standard deviation (0.0 < sigma < inf) */
} normal;

static double sample(const void * params, const gmcmc_prng64 * r) {
  const normal * n = (const normal *)params;
  return n->mu + n->sigma * gmcmc_randn(r);
}

static double log_pdf(const void * params, double x) {
  const normal * n = (const normal *)params;
  if (isnan(x))
    return NAN;
  return (isinf(x)) ? -INFINITY : -M_HALFLOG2PI - log(n->sigma) -
                      ((x - n->mu) * (x - n->mu)) / (2.0 * n->sigma * n->sigma);
}

static double log_pdf_1st_order(const void * params, double x) {
  const normal * n = (const normal *)params;
  if (isnan(x))
    return NAN;
  if (isinf(x))
    return signbit(x) ? INFINITY : -INFINITY;
  return -(x - n->mu) / (n->sigma * n->sigma);
}

static double log_pdf_2nd_order(const void * params, double x) {
  const normal * n = (const normal *)params;
  if (isnan(x))
    return NAN;
  return -1.0 / (n->sigma * n->sigma);
}

static const gmcmc_distribution_type type = { "Normal",
                                              sample,
                                              log_pdf,
                                              log_pdf_1st_order,
                                              log_pdf_2nd_order,
                                              sizeof(normal) };

/**
 * Creates a new continuous real normal probability distribution.
 *
 * @param [out] dist   the distribution to create
 * @param [in]  mu     the mean of the distribution
 * @param [in]  sigma  the standard deviation of the distribution
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if mu or sigma are not finite or if sigma is less than
 *                        or equal to zero,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                        distribution or parameter vector.
 */
int gmcmc_distribution_create_normal(gmcmc_distribution ** dist, double mu,
                                     double sigma) {
  if (!isfinite(mu))
    GMCMC_ERROR("'mu' must be finite", GMCMC_EINVAL);
  else if (!isfinite(sigma))
    GMCMC_ERROR("'sigma' must be finite", GMCMC_EINVAL);
  else if (sigma <= 0.0)
    GMCMC_ERROR("'sigma' must be greater than zero", GMCMC_EINVAL);

  if ((*dist = malloc(sizeof(gmcmc_distribution))) == NULL)
    GMCMC_ERROR("Failed to allocate distribution", GMCMC_ENOMEM);
  if (((*dist)->params = malloc(sizeof(normal))) == NULL) {
    free(*dist);
    GMCMC_ERROR("Failed to allocate distribution parameters", GMCMC_ENOMEM);
  }

  (*dist)->type = &type;
  ((normal *)(*dist)->params)->mu = mu;
  ((normal *)(*dist)->params)->sigma = sigma;

  return 0;
}
