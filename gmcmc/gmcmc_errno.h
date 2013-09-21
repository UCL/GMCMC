/*
 * gmcmc_errno.h
 *
 * Defines error handling functions, macros and error codes.
 *
 *  Created on: 20 May 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_ERRNO_H
#define GMCMC_ERRNO_H

#include <stddef.h>
#include <stdbool.h>

/**
 * Geometric MCMC error codes.
 */
/** Out of memory. */
#define GMCMC_ENOMEM 1
/** Invalid argument passed to function. */
#define GMCMC_EINVAL 2
/** Input/Output error. */
#define GMCMC_EIO 3
/** IPC error. */
#define GMCMC_EIPC 4
/** BLAS/LAPACK error (non positive-definite matrix, singular matrix, etc.) */
#define GMCMC_ELINAL 5

/**
 * Maps Geometric MCMC error codes to textual descriptions.
 *
 * @param errno  a GMCMC error code
 * @return a textual description of the error code.
 */
const char * gmcmc_strerror(int);

/**
 * Geometric MCMC error handler type.
 *
 * @param [in] msg    error message
 * @param [in] errno  error code
 * @param [in] func   function containing the error
 * @param [in] file   source file containing the error
 * @param [in] line   source line number
 */
typedef void (*gmcmc_error_handler_t)(const char *, int, const char *,
    const char *, int);

/**
 * Geometric MCMC error handler.
 */
extern gmcmc_error_handler_t gmcmc_error_handler;

/**
 * Calls the error handler with the specified message then returns the error
 * code from the function.
 */
#define GMCMC_ERROR(msg, errno) \
  do { \
    if (gmcmc_error_handler != NULL) \
      gmcmc_error_handler(msg, errno, __func__, __FILE__, __LINE__); \
    return errno; \
  } while (false)

/**
 * Calls the error handler with the specified message and the negative of the
 * error code then returns the negative of the error code from the function.
 */
#define GMCMC_WARNING(msg, errno) \
  do { \
    if (gmcmc_error_handler != NULL) \
      gmcmc_error_handler(msg, -(errno), __func__, __FILE__, __LINE__); \
    return -(errno); \
  } while (false)

/**
 * Calls the error handler with the specified message then returns a specific
 * value from the function.
 */
#define GMCMC_ERROR_VAL(msg, errno, value) \
  do { \
    if (gmcmc_error_handler != NULL) \
      gmcmc_error_handler(msg, errno, __func__, __FILE__, __LINE__); \
    return value; \
  } while (false)

/**
 * Calls the error handler with the specified message then returns from the
 * function.
 */
#define GMCMC_ERROR_VOID(msg, errno) \
  do { \
    if (gmcmc_error_handler != NULL) \
      gmcmc_error_handler(msg, errno, __func__, __FILE__, __LINE__); \
    return; \
  } while (false)

#endif /* GMCMC_ERRNO_H */
