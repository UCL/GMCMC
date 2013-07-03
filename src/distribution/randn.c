/*
 * util.c
 *
 * Generating standard normal random variables seems to be needed in a lot of
 * places, so define it once here.
 *
 *  Created on: 28 May 2013
 *      Author: Gary Macindoe
 */
#include <gmcmc/gmcmc_rng.h>

// sqrt(2.0 * M_PI)
#define M_SQRT2PI 2.50662827463100050241

/**
 * Generates a standard normal variate using the algorithm from J. L. Leva
 * (1992). `A fast normal random number generator'. ACM Trans. Math. Softw.
 * 18(4):449-453.
 *
 * @param [in] rng  a random number generator
 *
 * @return a standard normal variate.
 */
static double gmcmc_randn(const gmcmc_prng64 * rng) {
  double u, v, q;
  do {
    do { u = gmcmc_prng64_get_double(rng); } while (u == 0.0); // u ~ U(0,1)
    do { v = gmcmc_prng64_get_double(rng); } while (v == 0.0); // v ~ U(0,1)
    v = 1.7156 * (v - 0.5);
    double x = u - 0.449871;
    double y = fabs(v) + 0.386595;
    q = x * x + y * (0.19600 * y - 0.25472 * x);
  } while (q > 0.27597 && (q > 0.27846 || v * v > -4.0 * log(u) * u * u));

  return v / u;
}
