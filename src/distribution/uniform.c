/*
 * uniform.c
 *
 *  Created on: 28 May 2013
 *      Author: Gary Macindoe
 */
#include <gmcmc/gmcmc_distribution.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <math.h>

/**
 * Uniform distribution parameter structure.
 */
typedef struct {
  double lower; /**< Exclusive lower bound (-inf < lower < upper < inf) */
  double upper; /**< Exclusive upper bound (-inf < lower < upper < inf) */
} uniform;

static double sample(const void * params, const gmcmc_prng64 * r) {
  uniform * u = (uniform *)params;
  double x;
  do { x = gmcmc_prng64_get_double(r); } while (x == 0.0);
  return u->lower + x * (u->upper - u->lower);
}

static double log_pdf(const void * params, double x) {
  uniform * u = (uniform *)params;
  if (isnan(x))
    return NAN;
  return (islessequal(x, u->lower) || isgreaterequal(x, u->upper)) ? -INFINITY
                                                                   : -log(u->upper - u->lower);
}

static double log_pdf_1st_order(const void * params, double x) {
  uniform * u = (uniform *)params;
  if (isnan(x))
    return NAN;
  return (islessequal(x, u->lower) || isgreaterequal(x, u->upper)) ? NAN
                                                                   : 0.0;
}

static double log_pdf_2nd_order(const void * params, double x) {
  uniform * u = (uniform *)params;
  if (isnan(x))
    return NAN;
  return (islessequal(x, u->lower) || isgreaterequal(x, u->upper)) ? NAN
                                                                   : 0.0;
}

static const gmcmc_distribution_type type = { "Uniform",
                                              sample,
                                              log_pdf,
                                              log_pdf_1st_order,
                                              log_pdf_2nd_order,
                                              sizeof(uniform) };

/**
 * Creates a new continuous real uniform probability distribution on
 * (lower,upper).
 *
 * @param [out] dist   the distribution to create
 * @param [in]  lower  the (exclusive) lower bound of the distribution
 * @param [in]  upper  the (exclusive) upper bound of the distribution
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if lower or upper are not finite or lower is greater
 *                         than or equal to upper
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                        distribution or parameter vector.
 */
int gmcmc_distribution_create_uniform(gmcmc_distribution ** dist, double lower,
                                      double upper) {
  if (!isfinite(lower))
    GMCMC_ERROR("'lower' must be finite", GMCMC_EINVAL);
  else if (!isfinite(upper))
    GMCMC_ERROR("'upper' must be finite", GMCMC_EINVAL);
  else if (lower >= upper)
    GMCMC_ERROR("'lower' must be less than 'upper'", GMCMC_EINVAL);

  if ((*dist = malloc(sizeof(gmcmc_distribution))) == NULL)
    GMCMC_ERROR("Failed to allocate distribution", GMCMC_ENOMEM);
  if (((*dist)->params = malloc(sizeof(uniform))) == NULL) {
    free(*dist);
    GMCMC_ERROR("Failed to allocate distribution parameters", GMCMC_ENOMEM);
  }

  (*dist)->type = &type;
  ((uniform *)(*dist)->params)->lower = lower;
  ((uniform *)(*dist)->params)->upper = upper;

  return 0;
}
