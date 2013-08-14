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

typedef struct {
  double lower, upper;
} uniform;

static double sample(const void * params, const gmcmc_prng64 * r) {
  uniform * u = (uniform *)params;
  double x;
  do { x = gmcmc_prng64_get_double(r); } while (x == 0.0);
  return u->lower + x * (u->upper - u->lower);
}

static double pdf(const void * params, double x) {
  uniform * u = (uniform *)params;
  return (isnan(x)) ? NAN : ((x <= u->lower || x >= u->upper) ? 0.0 :  1.0 / (u->upper - u->lower));
}

static double pdf_1st_order(const void * params, double x) {
  uniform * u = (uniform *)params;
  return (isnan(x)) ? NAN : ((x <= u->lower || x >= u->upper) ? -INFINITY : 0.0);
}

static double pdf_2nd_order(const void * params, double x) {
  uniform * u = (uniform *)params;
  return (isnan(x)) ? NAN : ((x <= u->lower || x >= u->upper) ? -INFINITY : 0.0);
}

static const gmcmc_distribution_type type = { "Uniform", sample, pdf,
                                              pdf_1st_order, pdf_2nd_order, sizeof(uniform) };

/**
 * Creates a new continuous real uniform probability distribution on (a,b).
 *
 * @param [out] dist  the distribution to create
 * @param [in]  a     the (exclusive) lower bound of the distribution
 * @param [in]  b     the (exclusive) upper bound of the distribution
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if a is greater than or equal to b or either is +/-
 *                        infinity or NaN,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                        distribution or parameter vector.
 */
int gmcmc_distribution_create_uniform(gmcmc_distribution ** dist, double a, double b) {
  if (!isfinite(a) || !isfinite(b) || a >= b)
    return GMCMC_EINVAL;

  if ((*dist = malloc(sizeof(gmcmc_distribution))) == NULL)
    return GMCMC_ENOMEM;
  if (((*dist)->params = malloc(sizeof(uniform))) == NULL) {
    free(*dist);
    return GMCMC_ENOMEM;
  }

  (*dist)->type = &type;
  ((uniform *)(*dist)->params)->lower = a;
  ((uniform *)(*dist)->params)->upper = b;

  return 0;
}
