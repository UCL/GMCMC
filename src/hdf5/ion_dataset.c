#include <gmcmc/gmcmc_ion.h>
#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>

#include <hdf5.h>

#include "hdf5_read.c"

/**
 * Ion channel dataset loaded from an HDF5 file.
 */
typedef struct {
  size_t num_timepoints;
  double * timepoints, * data;
} hdf5_ion_dataset;

static void destroy(void * data) {
  hdf5_ion_dataset * dataset = (hdf5_ion_dataset *)data;
  if (dataset != NULL) {
    free(dataset->timepoints);
    free(dataset->data);
    free(dataset);
  }
}

static const double * timepoints(const void * data) {
  const hdf5_ion_dataset * dataset = (const hdf5_ion_dataset *)data;
  return dataset->timepoints;
}

static const double * data(const void * data) {
  const hdf5_ion_dataset * dataset = (const hdf5_ion_dataset *)data;
  return dataset->data;
}

static size_t num_timepoints(const void * data) {
  const hdf5_ion_dataset * dataset = (const hdf5_ion_dataset *)data;
  return dataset->num_timepoints;
}

static const gmcmc_ion_dataset_type type = { destroy,
                                             num_timepoints,
                                             timepoints,
                                             data };

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
int gmcmc_ion_dataset_load_hdf5(gmcmc_ion_dataset ** ds, const char * filename) {
  // Allocate the HDF5 dataset structure
  hdf5_ion_dataset * hdf5;
  if ((hdf5 = calloc(1, sizeof(hdf5_ion_dataset))) == NULL)
    GMCMC_ERROR("Failed to allocate HDF5-specific dataset structure", GMCMC_ENOMEM);

  // Open the HDF5 data file
  hid_t file = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
  if (file < 0) {
    free(hdf5);
    GMCMC_ERROR("Unable to open HDF5 data file", GMCMC_EIO);
  }

  // Read the timepoints vector
  int error;
  if ((error = hdf5_read_vector(file, "TimePoints", H5T_IEEE_F64LE, &hdf5->num_timepoints, (void **)&hdf5->timepoints)) != 0) {
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Failed to read timepoints", error);
  }

  // Read the data vector
  size_t num_datapoints;
  if ((error = hdf5_read_vector(file, "Data", H5T_IEEE_F64LE, &num_datapoints, (void **)&hdf5->data)) != 0) {
    free(hdf5->timepoints);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Failed to read data", error);
  }

  // Check the data vector is the same size as the timepoints vector
  if (num_datapoints != hdf5->num_timepoints) {
    free(hdf5->data);
    free(hdf5->timepoints);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Data vector is wrong size", error);
  }

  // Close the file after loading the data
  if (H5Fclose(file) < 0) {
    free(hdf5->data);
    free(hdf5->timepoints);
    free(hdf5);
    GMCMC_ERROR("Failed to close HDF5 file", GMCMC_EIO);
  }

  // Allocate the dataset structure
  if ((*ds = malloc(sizeof(gmcmc_ion_dataset))) == NULL) {
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
