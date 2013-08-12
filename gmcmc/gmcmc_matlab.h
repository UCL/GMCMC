/*
 * gmcmc_matlab.h
 *
 * Matlab integration for GMCMC library.
 *
 * Provides functions for reading and writing Matlab data files.
 *
 *  Created on: 30 July 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_MATLAB_H
#define GMCMC_MATLAB_H

#include <gmcmc/gmcmc_dataset.h>
#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_popmcmc.h>

#include <stdbool.h>

/**
 * Loads an ion channel dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "TimePoints" containing strictly increasing
 * timepoints and a vector of data points named "Data".
 * The dimensionality of the timepoints must match that of the data.
 *
 * @param [out] dataset     the dataset object to load data into
 * @param [in]  filename    the name of the Matlab .mat file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid ion channel
 *                        data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_dataset_create_matlab_ion(gmcmc_dataset **, const char *);

/**
 * Loads an ODE dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "TimePoints" containing strictly increasing
 * timepoints, a matrix of data points named "Data" and a column vector of noise
 * covariances names "NoiseVariance".
 * The length of the timepoints vector must match the length of the noise
 * covariances and the number of rows in the data.
 * The noise covariances will be available via gmcmc_dataset_get_auxdata.
 *
 * @param [out] dataset     the dataset object to load data into
 * @param [in]  filename    the name of the Matlab .mat file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid ODE data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_dataset_create_matlab_ode(gmcmc_dataset **, const char *);

/**
 * How often to save posterior samples.
 */
extern size_t gmcmc_matlab_posterior_save_size;

/**
 * Whether to save burn-in samples or not.
 */
extern bool gmcmc_matlab_save_burn_in;

/**
 * Where to write the samples to.
 */
extern const char * gmcmc_matlab_outputID;

/**
 * Stores a sample in a global array that is later written to a Matlab file.
 *
 * @param [in] options         the MCMC options
 * @param [in] model           the model
 * @param [in] i               the current iteration number
 * @param [in] j               the index on the temperature scale
 * @param [in] params          the current parameter values
 * @param [in] log_prior       the log prior of the sample
 * @param [in] log_likelihood  the log likelihood of the sample
 * @param [in] stepsize        the current stepsize
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM  if there was not enough memory to create the Matlab
 *                         structure array,
 *         GMCMC_EIO     if there was an error writing the Matlab structure
 *                         array to a file.
 */
int gmcmc_matlab_popmcmc_write(const gmcmc_popmcmc_options *, const gmcmc_model *,
                               size_t, size_t,
                               const double *, const double *, double, double);


#endif  /* GMCMC_MATLAB_H */
