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

typedef struct {
  double alpha, beta;
} gamma;

static double gmcmc_randg(const gmcmc_prng64 * r, double alpha, double beta) {
  // Algorithm from:
  // G. Marsaglia & W. W. Tsang (2000). `A simple method for generating gamma
  // variables'. ACM Trans. Math. Softw. 26(3):363-372.
  // Also used in GSL
  const double d = alpha - 1.0 / 3.0;
  const double c = (1.0 / 3.0) / sqrt (d);

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
  } while (u >= 1 - 0.0331 * x * x * x * x ||
      log(u) >= 0.5 * x * x + d * (1 - v + log(v)));

  return beta * d * v;
}

static double gammln(double x) {
  // Numerical Recipes in C++, 2nd edition (section 6.1, page 219)
  static const double cof[6] = { 76.18009172947146,      -86.50532032941677,
                                 24.01409824083091,       -1.231739572450155,
                                  0.1208650973866179e-2,  -0.5395239384953e-5 };

  double y = x;
  double tmp = x + 5.5;
  tmp -= (x + 0.5) * log(tmp);
  double ser = 1.000000000190015;
  for (int j = 0; j < 6; j++)
    ser += cof[j] / ++y;
  return -tmp + log(M_SQRT2PI * ser / x);
}

static double sample(const void * params, const gmcmc_prng64 * r) {
  const gamma * g = (const gamma *)params;
  return gmcmc_randg(r, g->alpha, g->beta);
}

static double pdf(const void * params, double x) {
  const gamma * g = (const gamma *)params;
  // Numerical Recipes in C++, 3rd edition (section 6.14, page 331)
  const double fac = g->alpha * log(g->beta) - gammln(g->alpha);
  return (x <= 0.0) ? 0.0 : exp(-g->beta * x + (g->alpha - 1.0) * log(x) + fac);
}

static double pdf_1st_order(const void * params, double x) {
  const gamma * g = (const gamma *)params;
  return (x <= 0.0) ? -INFINITY : (g->alpha - 1.0) / x - 1.0 / g->beta;
}

static double pdf_2nd_order(const void * params, double x) {
  const gamma * g = (const gamma *)params;
  return (x <= 0.0) ? -INFINITY : -(g->alpha - 1.0) / (x * x);
}

static const gmcmc_distribution_type type = { "Gamma", sample, pdf,
                                              pdf_1st_order, pdf_2nd_order, sizeof(gamma) };

/**
 * Creates a new continuous real gamma probability distribution.
 *
 * @param [out] dist   the distribution to create
 * @param [in]  alpha  the shape of the distribution
 * @param [in]  beta   the inverse scale of the distribution
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if alpha or beta are less than or equal to zero,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                      distribution or parameter vector.
 */
int gmcmc_distribution_create_gamma(gmcmc_distribution ** dist, double alpha, double beta) {
  if (islessequal(alpha, 0.0) || islessequal(beta, 0.0))
    return GMCMC_EINVAL;

  if ((*dist = malloc(sizeof(gmcmc_distribution))) == NULL)
    return GMCMC_ENOMEM;
  if (((*dist)->params = malloc(sizeof(gamma))) == NULL) {
    free(*dist);
    return GMCMC_ENOMEM;
  }

  (*dist)->type = &type;
  ((gamma *)(*dist)->params)->alpha = alpha;
  ((gamma *)(*dist)->params)->beta = beta;

  return 0;
}
