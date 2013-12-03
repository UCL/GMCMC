#include <gmcmc/gmcmc_eye.h>
#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>

#include <hdf5.h>

#include "hdf5_read.c"

/**
 * Stochastic eye dataset loaded from an HDF5 file.
 */
typedef struct {
  size_t num_timepoints;
  double * mean, * variance;
} hdf5_eye_dataset;

static void destroy(void * data) {
  hdf5_eye_dataset * dataset = (hdf5_eye_dataset *)data;
  if (dataset != NULL) {
    free(dataset->mean);
    free(dataset->variance);
    free(dataset);
  }
}

static const double * data(const void * data) {
  const hdf5_eye_dataset * dataset = (const hdf5_eye_dataset *)data;
  return dataset->mean;
}

static const double * noisevar(const void * data) {
  const hdf5_eye_dataset * dataset = (const hdf5_eye_dataset *)data;
  return dataset->variance;
}

static size_t num_timepoints(const void * data) {
  const hdf5_eye_dataset * dataset = (const hdf5_eye_dataset *)data;
  return dataset->num_timepoints;
}

static const gmcmc_eye_dataset_type type = { destroy,
                                             num_timepoints,
                                             data,
                                             noisevar };

int gmcmc_eye_dataset_load_hdf5(gmcmc_eye_dataset ** ds, const char * filename) {
  // Allocate the HDF5 dataset structure
  hdf5_eye_dataset * hdf5;
  if ((hdf5 = calloc(1, sizeof(hdf5_eye_dataset))) == NULL)
    GMCMC_ERROR("Failed to allocate HDF5-specific dataset structure", GMCMC_ENOMEM);

  // Open the HDF5 data file
  hid_t file = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
  if (file < 0) {
    free(hdf5);
    GMCMC_ERROR("Unable to open HDF5 data file", GMCMC_EIO);
  }

  // Read the Data_Mean vector
  int error;
  if ((error = hdf5_read_vector(file, "Data_Mean", H5T_IEEE_F64LE,
                                &hdf5->num_timepoints, (void **)&hdf5->mean)) != 0) {
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Failed to read timepoints", error);
  }

  // Read the Data_Var vector
  size_t length;
  if ((error = hdf5_read_vector(file, "Data_Var", H5T_IEEE_F64LE,
                                &length, (void **)&hdf5->variance)) != 0) {
    free(hdf5->mean);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Failed to read timepoints", error);
  }

  // Check the length of the vectors match
  if (length != hdf5->num_timepoints) {
    free(hdf5->mean);
    free(hdf5->variance);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Variance vector is wrong size", error);
  }

  // Allocate the dataset structure
  if ((*ds = malloc(sizeof(gmcmc_eye_dataset))) == NULL) {
    free(hdf5->mean);
    free(hdf5->variance);
    H5Fclose(file);
    free(hdf5);
    GMCMC_ERROR("Unable to allocate dataset", GMCMC_ENOMEM);
  }

  // Set the dataset type and dataset-specific structure
  (*ds)->type = &type;
  (*ds)->data = hdf5;

  return 0;
}
