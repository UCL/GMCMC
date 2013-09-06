/*
 * gamma.c
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
 * Gamma distribution parameter structure.
 */
typedef struct {
  double alpha; /**< Shape (0 < alpha < inf) */
  double beta;  /**< Rate/Inverse scale (0 < beta < inf) */
} gamma;

static double gmcmc_randg(const gmcmc_prng64 * r, double alpha, double beta) {
  // G. Marsaglia & W. W. Tsang (2000). `A simple method for generating gamma
  // variables'. ACM Trans. Math. Softw. 26(3):363-372.
  const double d = alpha - 1.0 / 3.0;
  const double c = (1.0 / 3.0) / sqrt(d);

  if (alpha < 1.0) {
    double u;
    do { u = gmcmc_prng64_get_double(r); } while (u == 0.0);
    return gmcmc_randg(r, 1.0 + alpha, beta) * pow (u, 1.0 / alpha);
  }

  double u, v, x;
  do {
    do {
      x = gmcmc_randn(r);
      v = 1.0 + c * x;
    } while (v <= 0);

    v = v * v * v;
    do { u = gmcmc_prng64_get_double(r); } while (u == 0.0);

  } while (u >= 1 - 0.0331 * x * x * x * x &&
           log(u) >= 0.5 * x * x + d * (1 - v + log(v)));

  return beta * d * v;
}

static double sample(const void * params, const gmcmc_prng64 * r) {
  const gamma * g = (const gamma *)params;
  return gmcmc_randg(r, g->alpha, g->beta);
}

static double log_pdf(const void * params, double x) {
  const gamma * g = (const gamma *)params;
  if (isnan(x))
    return NAN;
  else if (isless(x, 0.0) || isinf(x))
    return -INFINITY;
  return -lgamma(g->alpha) - g->alpha * log(g->beta) + (g->alpha - 1.0) * log(x) - x / g->beta;
}

static double log_pdf_1st_order(const void * params, double x) {
  const gamma * g = (const gamma *)params;
  if (isnan(x) || isless(x, 0.0) || isinf(x))
    return NAN;
  return (g->alpha - 1.0) / x - 1.0 / g->beta;
}

static double log_pdf_2nd_order(const void * params, double x) {
  const gamma * g = (const gamma *)params;
  if (isnan(x) || isless(x, 0.0) || isinf(x))
    return NAN;
  return -(g->alpha - 1.0) / (x * x);
}

static const gmcmc_distribution_type type = { "Gamma",
                                              sample,
                                              log_pdf,
                                              log_pdf_1st_order,
                                              log_pdf_2nd_order,
                                              sizeof(gamma) };

/**
 * Creates a new continuous real gamma probability distribution.
 *
 * @param [out] dist   the distribution to create
 * @param [in]  alpha  the shape of the distribution
 * @param [in]  beta   the inverse scale of the distribution
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if alpha or beta are not finite or if alpha or beta are
 *                        less than or equal to zero,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                        distribution or parameter vector.
 */
int gmcmc_distribution_create_gamma(gmcmc_distribution ** dist, double alpha,
                                    double beta) {
  if (!isfinite(alpha))
    GMCMC_ERROR("'alpha' must be finite", GMCMC_EINVAL);
  else if (!isfinite(beta))
    GMCMC_ERROR("'beta' must be finite", GMCMC_EINVAL);
  else if (alpha <= 0.0)
    GMCMC_ERROR("'alpha' must be greater than zero", GMCMC_EINVAL);
  else if (beta <= 0.0)
    GMCMC_ERROR("'beta' must be greater than zero", GMCMC_EINVAL);

  if ((*dist = malloc(sizeof(gmcmc_distribution))) == NULL)
    GMCMC_ERROR("Failed to allocate distribution", GMCMC_ENOMEM);
  if (((*dist)->params = malloc(sizeof(gamma))) == NULL) {
    free(*dist);
    GMCMC_ERROR("Failed to allocate distribution parameters", GMCMC_ENOMEM);
  }

  (*dist)->type = &type;
  ((gamma *)(*dist)->params)->alpha = alpha;
  ((gamma *)(*dist)->params)->beta = beta;

  return 0;
}
