#ifndef GMCMC_GEOMETRY_H
#define GMCMC_GEOMETRY_H

#include <stddef.h>

/**
 * Geometry data type expected by Simplified mMALA proposal functions.
 */
typedef struct {
  double * gradient_log_prior;      /**< Gradient of the log prior */
  double * gradient_log_likelihood; /**< Gradient of the log likelihood */
  double * hessian_log_prior;       /**< Hessian of the log prior */
  double * FI;                      /**< Fisher information */
  size_t ldfi;                      /**< Leading dimension of the fisher information */
} gmcmc_geometry_simp_mmala;

#endif /* GMCMC_GEOMETRY_H */
