/*
 * gmcmc_distribution.h
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
 * Continuous double-precision real probability distribution.
 */
typedef struct gmcmc_distribution gmcmc_distribution;

/**
 * Continuous double-precision real probability distribution type.
 */
typedef struct {
  const char * name;                                    /**< The name of the distribution */
  int (*parse_args)(void *, va_list);                   /**< Function to initialise and check parameter values */
  double (*sample)(const gmcmc_prng64 *, const void *); /**< Sample generation function */
  double (*pdf)(double, const void *);                  /**< Probability density function */
  double (*pdf_1st_order)(double, const void *);        /**< 1st order derivative PDF */
  double (*pdf_2nd_order)(double, const void *);        /**< 2nd order derivative PDF */
  size_t size;                                          /**< Size of parameter vector in bytes */
} gmcmc_distribution_type;

/**
 * Creates a new probability distribution and allocates memory to store the
 * parameters.
 *
 * @param [out] dist    the distribution to create
 * @param [in]  type    the type of distribution to create
 * @param [in]  params  the distribution parameters
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if the distribution parameters are invalid,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the
 *                      distribution or parameter vector.
 */
int gmcmc_distribution_create(gmcmc_distribution **, const gmcmc_distribution_type *, ...);

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
double gmcmc_distribution_sample(const gmcmc_distribution *, const gmcmc_prng64 *);

/**
 * Evaluates the probability density function of the distribution.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the PDF
 *
 * @return the value of the probability density function at x.
 */
double gmcmc_distribution_pdf(const gmcmc_distribution *, double);

/**
 * Evaluates the 1st order derivative of the probability density function.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the PDF
 *
 * @return the value of the 1st order derivative of the probability density
 * function at x.
 */
double gmcmc_distribution_pdf_1st_order(const gmcmc_distribution *, double);

/**
 * Evaluates the 2nd order derivative of the probability density function.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the PDF
 *
 * @return the value of the 2nd order derivative of the probability density
 * function at x.
 */
double gmcmc_distribution_pdf_2nd_order(const gmcmc_distribution *, double);

/*
 * Built-in distribution types.
 */

/**
 * Continuous real uniform distribution on (a,b).
 *
 * @param a  the (exclusive) lower bound of the distribution
 * @param b  the (exclusive) upper bound of the distribution
 */
extern const gmcmc_distribution_type * gmcmc_distribution_uniform;

/**
 * Continuous real normal distribution.
 *
 * @param mean    the mean of the distribution
 * @param stddev  the standard deviation of the distribution
 */
extern const gmcmc_distribution_type * gmcmc_distribution_normal;

/**
 * Continuous real lognormal distribution.
 *
 * @param logscale  the log scale of the distribution
 * @param shape     the shape of the distribution
 */
extern const gmcmc_distribution_type * gmcmc_distribution_lognormal;

/**
 * Continuous real gamma distribution.
 *
 * @param alpha  the shape of the distribution
 * @param beta   the inverse scale of the distribution
 */
extern const gmcmc_distribution_type * gmcmc_distribution_gamma;

#endif /* GMCMC_DISTRIBUTION_H */
