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
  if (isnan(x))
    return NAN;
  return (islessequal(x, u->lower) || isgreaterequal(x, u->upper)) ? 0.0 : 1.0 / (u->upper - u->lower);
}

static double pdf_1st_order(const void * params, double x) {
  uniform * u = (uniform *)params;
  if (isnan(x))
    return NAN;
  return (islessequal(x, u->lower) || isgreaterequal(x, u->upper)) ? -INFINITY : 0.0;
}

static double pdf_2nd_order(const void * params, double x) {
  uniform * u = (uniform *)params;
  if (isnan(x))
    return NAN;
  return (islessequal(x, u->lower) || isgreaterequal(x, u->upper)) ? -INFINITY : 0.0;
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
 *         GMCMC_EINVAL if a or b are not finite or a is greater than or equal
 *                         to b
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                        distribution or parameter vector.
 */
int gmcmc_distribution_create_uniform(gmcmc_distribution ** dist, double a, double b) {
  if (!isfinite(a))
    GMCMC_ERROR("'a' must be finite", GMCMC_EINVAL);
  else if (!isfinite(b))
    GMCMC_ERROR("'b' must be finite", GMCMC_EINVAL);
  else if (a >= b)
    GMCMC_ERROR("'a' must be less than 'b'", GMCMC_EINVAL);

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
