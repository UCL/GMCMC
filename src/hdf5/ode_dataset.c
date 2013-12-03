#include <gmcmc/gmcmc_ode.h>
#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>

#include <hdf5.h>

#include "hdf5_read.c"

/**
 * ODE dataset loaded from an HDF5 file.
 */
typedef struct {
  size_t num_timepoints, num_timepoint_vectors, num_data_vectors;
  double * timepoints, * data, * noisecov;
} hdf5_ode_dataset;

static void destroy(void * data) {
  hdf5_ode_dataset * dataset = (hdf5_ode_dataset *)data;
  if (dataset != NULL) {
    free(dataset->timepoints);
    free(dataset->data);
    free(dataset->noisecov);
    free(dataset);
  }
}

static const double * timepoints(const void * data, size_t i) {
  const hdf5_ode_dataset * dataset = (const hdf5_ode_dataset *)data;
  if (i >= dataset->num_timepoint_vectors)
    GMCMC_ERROR_VAL("index is out of range", GMCMC_EINVAL, NULL);
  return &dataset->timepoints[i * dataset->num_timepoints];
}

static const double * data(const void * data, size_t i) {
  const hdf5_ode_dataset * dataset = (const hdf5_ode_dataset *)data;
  if (i >= dataset->num_data_vectors)
    GMCMC_ERROR_VAL("index is out of range", GMCMC_EINVAL, NULL);
  return &dataset->data[i * dataset->num_timepoints];
}

static double noisecov(const void * data, size_t i) {
  const hdf5_ode_dataset * dataset = (const hdf5_ode_dataset *)data;
  return dataset->noisecov[i];
}

static size_t num_timepoints(const void * data) {
  const hdf5_ode_dataset * dataset = (const hdf5_ode_dataset *)data;
  return dataset->num_timepoints;
}

static size_t num_timepoint_vectors(const void * data) {
  const hdf5_ode_dataset * dataset = (const hdf5_ode_dataset *)data;
  return dataset->num_timepoint_vectors;
}

static size_t num_data_vectors(const void * data) {
  const hdf5_ode_dataset * dataset = (const hdf5_ode_dataset *)data;
  return dataset->num_data_vectors;
}

static const gmcmc_ode_dataset_type type = { destroy,
                                             num_timepoints,
                                             num_timepoint_vectors,
                                             num_data_vectors,
                                             timepoints,
                                             data,
                                             noisecov };

/**
 * Loads an ion channel dataset from an HDF5 file.  The file must contain a
 * m-by-n dataset of native double values named "TimePoints" and a corresponding
 * p-by-n dataset of the same type named "Data".  If m > 1 or p > 1 only the
 * first row is read.  (Note: HDF5 stores data in row-major format so the above
 * dimensions correspond to column vectors of length n.)
 *
 * @param [out] dataset     the dataset object to create
 * @param [in]  filename    the name of the HDF .h5 file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the HDF5 file does not contain the required datasets,
 *                         m, n or p are less than 1 or the datasets are not
 *                         stored in double precision,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_ode_dataset_load_hdf5(gmcmc_ode_dataset ** ds, const char * filename) {
  // Allocate the HDF5 dataset structure
  hdf5_ode_dataset * hdf5;
  if ((hdf5 = calloc(1, sizeof(hdf5_ode_dataset))) == NULL)
    GMCMC_ERROR("Failed to allocate HDF5-specific dataset structure", GMCMC_ENOMEM);

  // Open the HDF5 data file
  hid_t file = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
  if (file < 0) {
    free(hdf5);
    GMCMC_ERROR("Unable to open HDF5 data file", GMCMC_EIO);
  }

  // Read the timepoints matrix
  int error;
  if ((error = hdf5_read_matrix(file, "TimePoints", H5T_IEEE_F64LE,
                                &hdf5->num_timepoints, &hdf5->num_timepoint_vectors,
                                (void **)&hdf5->timepoints)) != 0) {
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Failed to read timepoints", error);
  }

  // Read the data matrix
  size_t num_datapoints;
  if ((error = hdf5_read_matrix(file, "Data", H5T_IEEE_F64LE, &num_datapoints, &hdf5->num_data_vectors, (void **)&hdf5->data)) != 0) {
    free(hdf5->timepoints);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Failed to read data", error);
  }

  // Check the data matrix has the same number of rows as the timepoints vector
  if (num_datapoints < hdf5->num_timepoints) {
    free(hdf5->data);
    free(hdf5->timepoints);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Data vector is too short", error);
  }

  // Read the data matrix
  size_t num_noisecovs;
  if ((error = hdf5_read_vector(file, "NoiseCov", H5T_IEEE_F64LE, &num_noisecovs, (void **)&hdf5->noisecov)) != 0) {
    free(hdf5->data);
    free(hdf5->timepoints);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Failed to read data", error);
  }

  // Check the noise covariance vector has an element for each data vector
  if (num_noisecovs != hdf5->num_data_vectors) {
    free(hdf5->noisecov);
    free(hdf5->data);
    free(hdf5->timepoints);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Data vector is too short", error);
  }

  // Allocate the dataset structure
  if ((*ds = malloc(sizeof(gmcmc_ode_dataset))) == NULL) {
    free(hdf5->noisecov);
    free(hdf5->data);
    free(hdf5->timepoints);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Unable to allocate dataset", GMCMC_ENOMEM);
  }

  // Set the dataset type and dataset-specific structure
  (*ds)->type = &type;
  (*ds)->data = hdf5;

  return 0;
}
