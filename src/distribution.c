/*
 * gmcmc_distribution.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#include <gmcmc/gmcmc_distribution.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>

/**
 * Continuous double-precision real probability distribution.
 */
struct gmcmc_distribution {
  const gmcmc_distribution_type * type; /**< Distribution type */
  void * params;                        /**< Distribution parameters */
};

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
int gmcmc_distribution_create(gmcmc_distribution ** dist, const gmcmc_distribution_type * type, ...) {
  *dist = malloc(sizeof(gmcmc_distribution));
  if (*dist == NULL)
    GMCMC_ERROR("Unable to allocate distribution", GMCMC_ENOMEM);

  (*dist)->type = type;
  (*dist)->params = malloc(type->size);

  if ((*dist)->params == NULL) {
    free(*dist);
    GMCMC_ERROR("Unable to allocate parameter vector", GMCMC_ENOMEM);
  }

  va_list list;
  va_start(list, type);
  int error = type->parse_args((*dist)->params, list);
  va_end(list);

  if (error != 0) {
    free((*dist)->params);
    free(*dist);
    GMCMC_ERROR("Invalid parameters", GMCMC_EINVAL);
  }

  return 0;
}

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
int gmcmc_distribution_create_copy(gmcmc_distribution ** dest, const gmcmc_distribution * src) {
  *dest = malloc(sizeof(gmcmc_distribution));
  if (*dest == NULL)
    GMCMC_ERROR("Unable to allocate distribution", GMCMC_ENOMEM);

  (*dest)->type = src->type;
  (*dest)->params = malloc(src->type->size);

  if ((*dest)->params == NULL) {
    free(*dest);
    GMCMC_ERROR("Unable to allocate parameter vector", GMCMC_ENOMEM);
  }

  memcpy((*dest)->params, src->params, src->type->size);

  return 0;
}

/**
 * Copies the parameters of one probability distribution into another.  Both
 * distributions must be the same type.
 *
 * @param [out] dest  the destination of the copy
 * @param [in]  src   the source of the copy
 *
 * @return 0 on success, GMCMC_EINVAL if the RNGs are of different types.
 */
int gmcmc_distribution_memcpy(gmcmc_distribution * dest, const gmcmc_distribution * src) {
  if (dest->type != src->type)
    GMCMC_ERROR("Distribution types must match", GMCMC_EINVAL);
  memcpy(dest->params, src->params, src->type->size);
  return 0;
}

/**
 * Destroys a probability distribution.
 *
 * @param [in] dist  the probability distribution to destroy
 */
void gmcmc_distribution_destroy(gmcmc_distribution * dist) {
  free(dist->params);
  free(dist);
}

/**
 * Writes the parameters of a probability distribution to a file.
 *
 * @param [in]     dist  the probability distribution
 * @param [in,out] file  the file
 *
 * @return 0 on success, GMCMC_EIO on error.
 */
int gmcmc_distribution_fwrite(const gmcmc_distribution * dist, FILE * file) {
  if (fwrite(dist->params, dist->type->size, 1, file) != 1)
    GMCMC_ERROR("Unable to write distribution parameters", GMCMC_EIO);
  return 0;
}

/**
 * Reads the parameters of a probability distribution from a file.
 *
 * @param [out]     dist  the probability distribution
 * @param [in,out]  file  the file
 *
 * @return 0 on success, GMCMC_EIO on error.
 */
int gmcmc_distribution_fread(gmcmc_distribution * dist, FILE * file) {
  if (fread(dist->params, dist->type->size, 1, file) != 1)
    GMCMC_ERROR("Unable to read distribution parameters", GMCMC_EIO);
  return 0;
}

/**
 * Generates a sample from the distribution.
 *
 * @param [in] dist  the probability distribution
 * @param [in] rng   the random number generator to use to generate the sample
 *
 * @return a sample from the distribution.
 */
double gmcmc_distribution_sample(const gmcmc_distribution * dist, const gmcmc_prng64 * rng) {
  return dist->type->sample(rng, dist->params);
}

/**
 * Evaluates the probability density function of the distribution.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the PDF
 *
 * @return the value of the probability density function at x.
 */
double gmcmc_distribution_pdf(const gmcmc_distribution * dist, double x) {
  return dist->type->pdf(x, dist->params);
}

/**
 * Evaluates the 1st order derivative of the probability density function.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the PDF
 *
 * @return the value of the 1st order derivative of the probability density
 * function at x.
 */
double gmcmc_distribution_pdf_1st_order(const gmcmc_distribution * dist, double x) {
  return dist->type->pdf_1st_order(x, dist->params);
}

/**
 * Evaluates the 2nd order derivative of the probability density function.
 *
 * @param [in] dist  the probability distribution
 * @param [in] x     the point at which to evaluate the PDF
 *
 * @return the value of the 2nd order derivative of the probability density
 * function at x.
 */
double gmcmc_distribution_pdf_2nd_order(const gmcmc_distribution * dist, double x) {
  return dist->type->pdf_2nd_order(x, dist->params);
}
