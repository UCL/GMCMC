/*
 * gmcmc_errno.h
 *
 *  Created on: 20 May 2013
 *      Author: Gary Macindoe
 */
#include <gmcmc/gmcmc_errno.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Maps Geometric MCMC error codes to textual descriptions.
 *
 * @param errno  a GMCMC error code
 * @return a textual description of the error code.
 */
const char * gmcmc_strerror(int errno) {
  switch (abs(errno)) {
    case GMCMC_ENOMEM: return "Out of memory";
    case GMCMC_EINVAL: return "Invalid argument";
    case GMCMC_EIO:    return "Input/Output error";
    case GMCMC_EIPC:   return "IPC error";
    case GMCMC_ELINAL: return "BLAS/LAPACK error";
    default:           return "Unknown error";
  }
}

/**
 * Default error handler.
 *
 * @param [in] msg    error message
 * @param [in] errno  error code
 * @param [in] func   function containing the error
 * @param [in] file   source file containing the error
 * @param [in] line   source line number
 */
static void default_error_handler(const char * msg, int errno, const char * func,
    const char * file, int line) {
  if (errno < 0)
    fprintf(stderr, "GMCMC Warning \"%s\" in %s (%s:%d):\n\t\"%s\"\n",
            gmcmc_strerror(errno), func, file, line, msg);
  else
    fprintf(stderr, "GMCMC Error \"%s\" in %s (%s:%d):\n\t\"%s\"\n",
            gmcmc_strerror(errno), func, file, line, msg);
}

/**
 * Geometric MCMC error handler.
 */
gmcmc_error_handler_t gmcmc_error_handler = &default_error_handler;
