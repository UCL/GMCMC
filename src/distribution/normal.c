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
#include "util.c"

typedef struct {
  double mean, stddev;
} normal;

static double sample(const void * params, const gmcmc_prng64 * r) {
  normal * n = (normal *)params;
  return n->mean + n->stddev * gmcmc_randn(r);
}

static double pdf(const void * params, double x) {
  normal * n = (normal *)params;
  return 1.0 / (n->stddev * M_SQRT2PI) *
  exp(-((x - n->mean) * (x - n->mean)) / (2.0 * n->stddev * n->stddev));
}

static double pdf_1st_order(const void * params, double x) {
  normal * n = (normal *)params;
  return -(x - n->mean) / (n->stddev * n->stddev);
}

static double pdf_2nd_order(const void * params, double x) {
  (void)x;
  normal * n = (normal *)params;
  return -1.0 / (n->stddev * n->stddev);
}

static const gmcmc_distribution_type type = { "Normal", sample, pdf,
                                              pdf_1st_order, pdf_2nd_order, sizeof(normal) };

/**
 * Creates a new continuous real normal probability distribution.
 *
 * @param [out] dist    the distribution to create
 * @param [in]  mean    the mean of the distribution
 * @param [in]  stddev  the standard deviation of the distribution
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if stddev is less than or equal to zero,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                      distribution or parameter vector.
 */
int gmcmc_distribution_create_normal(gmcmc_distribution ** dist, double mean, double stddev) {
  if (islessequal(stddev, 0.0))
    return GMCMC_EINVAL;

  if ((*dist = malloc(sizeof(gmcmc_distribution))) == NULL)
    return GMCMC_ENOMEM;
  if (((*dist)->params = malloc(sizeof(normal))) == NULL) {
    free(*dist);
    return GMCMC_ENOMEM;
  }

  (*dist)->type = &type;
  ((normal *)(*dist)->params)->mean = mean;
  ((normal *)(*dist)->params)->stddev = stddev;

  return 0;
}
