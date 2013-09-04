/*
 * gmcmc_distribution.h
 *
 * Probability distributions for use as priors with GMCMC.
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_DISTRIBUTION_H
#define GMCMC_DISTRIBUTION_H

#include <stdio.h>
#include <stdarg.h>
#include <gmcmc/gmcmc_rng.h>

/**
 * Continuous double-precision real probability distribution type.
 */
typedef struct {
  const char * name;                                    /**< The name of the distribution */
  double (*sample)(const void *, const gmcmc_prng64 *); /**< Sample generation function */
  double (*log_pdf)(const void *, double);              /**< Log probability density function */
  double (*log_pdf_1st_order)(const void *, double);    /**< 1st derivative of log PDF w.r.t. x*/
  double (*log_pdf_2nd_order)(const void *, double);    /**< 2nd derivative of log PDF w.r.t. x*/
  size_t size;                                          /**< Size of parameter vector in bytes */
} gmcmc_distribution_type;

/**
 * Continuous double-precision real probability distribution.
 */
typedef struct {
  const gmcmc_distribution_type * type;                 /**< Distribution type */
  void * params;                                        /**< Distribution parameters */
} gmcmc_distribution;

/**
 * Creates a new probability distribution which is a copy of an existing
 * probability distribution.
 *
 * @param [out] dest  the distribution to create
 * @param [in]  src   the distribution to copy
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                      distribution or parameter vector.
 */
int gmcmc_distribution_create_copy(gmcmc_distribution **, const gmcmc_distribution *);

/**
 * Copies the parameters of one probability distribution into another.  Both
 * distributions must be the same type.
 *
 * @param [out] dest  the destination of the copy
 * @param [in]  src   the source of the copy
 *
 * @return 0 on success, GMCMC_EINVAL if the RNGs are of different types.
 */
int gmcmc_distribution_memcpy(gmcmc_distribution *, const gmcmc_distribution *);

/**
 * Destroys a probability distribution.
 *
 * @param [in] dist  the probability distribution to destroy
 */
void gmcmc_distribution_destroy(gmcmc_distribution *);

/**
 * Writes the parameters of a probability distribution to a file.
 *
 * @param [in]     dist  the probability distribution
 * @param [in,out] file  the file
 *
 * @return 0 on success, GMCMC_EIO on error.
 */
int gmcmc_distribution_fwrite(const gmcmc_distribution *, FILE *);

/**
 * Reads the parameters of a probability distribution from a file.
 *
 * @param [out]     dist  the probability distribution
 * @param [in,out]  file  the file
 *
 * @return 0 on success, GMCMC_EIO on error.
 */
int gmcmc_distribution_fread(gmcmc_distribution *, FILE *);

/**
 * Generates a sample from the distribution.
 *
 * @param [in] dist  the probability distribution
 * @param [in] rng   the random number generator to use to generate the sample
 *
 * @return a sample from the distribution.
 */
static inline double gmcmc_distribution_sample(const gmcmc_distribution * dist, const gmcmc_prng64 * rng) {
  return dist->type->sample(dist->params, rng);
}

/**
 * Evaluates the log probability density function of the distribution.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the log PDF
 *
 * @return the value of the log probability density function at x.
 */
static inline double gmcmc_distribution_log_pdf(const gmcmc_distribution * dist, double x) {
  return dist->type->log_pdf(dist->params, x);
}

/**
 * Evaluates the 1st order derivative of the log of the probability density
 * function with respect to x.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the 1st order derivative log
 *                     PDF
 *
 * @return the value of the 1st order derivative of the log probability density
 * function (with respect to x) at x.
 */
static inline double gmcmc_distribution_log_pdf_1st_order(const gmcmc_distribution * dist, double x) {
  return dist->type->log_pdf_1st_order(dist->params, x);
}

/**
 * Evaluates the 2nd order derivative of the log of the probability density
 * function with respect to x.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the 2nd order derivative log
 *                     PDF
 *
 * @return the value of the 2nd order derivative of the log probability density
 * function (with respect to x) at x.
 */
static inline double gmcmc_distribution_log_pdf_2nd_order(const gmcmc_distribution * dist, double x) {
  return dist->type->log_pdf_2nd_order(dist->params, x);
}

/*
 * Built-in distribution types.
 */

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
int gmcmc_distribution_create_uniform(gmcmc_distribution **, double, double);

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
int gmcmc_distribution_create_normal(gmcmc_distribution **, double, double);

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
int gmcmc_distribution_create_lognormal(gmcmc_distribution **, double, double);

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
int gmcmc_distribution_create_gamma(gmcmc_distribution **, double, double);

#endif /* GMCMC_DISTRIBUTION_H */
