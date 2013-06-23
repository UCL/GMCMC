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
#include "util.c"

// sqrt(2.0 * M_PI)
#define M_SQRT2PI 2.50662827463100050241

typedef struct {
  double logscale, shape;
} lognormal;

static double sample(const void * params, const gmcmc_prng64 * r) {
  lognormal * l = (lognormal *)params;
  return exp(l->logscale + l->shape * gmcmc_randn(r));
}

static double pdf(const void * params, double x) {
  lognormal * l = (lognormal *)params;
  return (1.0 / (x * l->shape * M_SQRT2PI)) *
  exp(-((log(x) - l->logscale) * (log(x) - l->logscale)) / (2.0 * l->shape * l->shape));
}

static double pdf_1st_order(const void * params, double x) {
  lognormal * l = (lognormal *)params;
  return -(1.0 / x) - ((log(x) - l->logscale) / (l->shape * l->shape)) * (1.0 / x);
}

static double pdf_2nd_order(const void * params, double x) {
  (void)x;
  lognormal * l = (lognormal *)params;
  return (1.0 / (x * x)) + ((log(x) - l->logscale) / (l->shape * l->shape)) *
         (1.0 / (x * x)) - (1.0 / (l->shape * l->shape)) * (1.0 / (x * x));
}

static const gmcmc_distribution_type type = { "Lognormal", sample, pdf,
                                              pdf_1st_order, pdf_2nd_order, sizeof(lognormal) };

/**
 * Creates a new continuous real lognormal probability distribution.
 *
 * @param [out] dist      the distribution to create
 * @param [in]  logscale  the log scale of the distribution
 * @param [in]  shape     the shape of the distribution
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if shape is less than or equal to zero,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                      distribution or parameter vector.
 */
int gmcmc_distribution_create_lognormal(gmcmc_distribution ** dist, double logscale, double shape) {
  if (islessequal(shape, 0.0))
    return GMCMC_EINVAL;

  if ((*dist = malloc(sizeof(gmcmc_distribution))) == NULL)
    return GMCMC_ENOMEM;
  if (((*dist)->params = malloc(sizeof(lognormal))) == NULL) {
    free(*dist);
    return GMCMC_ENOMEM;
  }

  (*dist)->type = &type;
  ((lognormal *)(*dist)->params)->logscale = logscale;
  ((lognormal *)(*dist)->params)->shape = shape;

  return 0;
}
