#include <gmcmc/gmcmc_popmcmc.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <hdf5.h>

#define PARAMS_NAME "Params"
#define LOG_PRIOR_NAME "LogPrior"
#define LOG_LIKELIHOOD_NAME "LL"
#define STEP_SIZE_NAME "StepSize"

typedef struct {
  hid_t file;           /**< HDF5 file pointer. */
  bool closed;          /**< Whether the file pointer has been closed or not. */
} hdf5_filewriter;

static int close(void * state) {
  hdf5_filewriter * fw = (hdf5_filewriter *)state;
  if (!fw->closed) {
    if (H5Fclose(fw->file) < 0)
      GMCMC_ERROR("Failed to close HDF5 file", GMCMC_EIO);
    fw->closed = true;
  }
  return 0;
}

static void destroy(void * state) {
  // Close the file pointer if not already done
  close(state);
  // Free memory occupied by filewriter state
  free(state);
}

static int hdf5_write_scalar(hid_t group, const char * name, size_t iteration, double data) {
  // Open the dataset
  hid_t dataset;
  if ((dataset = H5Dopen(group, name, H5P_DEFAULT)) < 0)
    GMCMC_ERROR("Failed to open dataset", GMCMC_EIO);

  // Read the dataspace from the dataset
  hid_t filespace;
  if ((filespace = H5Dget_space(dataset)) < 0) {
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to get dataspace from dataset", GMCMC_EIO);
  }

  // Use the dataspace from the file to define a subspace in memory for one sample vector
  hsize_t dim;
  if (H5Sget_simple_extent_dims(filespace, &dim, NULL) < 0) {
    H5Sclose(filespace);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to get dataspace dimensions", GMCMC_EIO);
  }

  // Create an in-memory 1-by-1 dataspace
  hsize_t count = 1;
  hid_t memspace;
  if ((memspace = H5Screate_simple(1, &count, NULL)) < 0) {
    H5Sclose(filespace);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to create in-memory dataspace", GMCMC_EIO);
  }

  // Define the region being written in the file dataspace
  hsize_t offset = iteration;
  if (H5Sselect_hyperslab(filespace, H5S_SELECT_SET, &offset, NULL, &count, NULL) < 0) {
    H5Sclose(memspace);
    H5Sclose(filespace);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to define hyperslab", GMCMC_EIO);
  }

  // Write the data
  if (H5Dwrite(dataset, H5T_IEEE_F64LE, memspace, filespace, H5P_DEFAULT, &data) < 0) {
    H5Sclose(memspace);
    H5Sclose(filespace);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to write parameters to dataset", GMCMC_EIO);
  }

  // Close the memory and file dataspaces, the dataset and the group
  H5Sclose(memspace);
  H5Sclose(filespace);
  H5Dclose(dataset);

  return 0;
}

static int hdf5_write_vector(hid_t group, const char * name, size_t iteration, const double * data) {
  // Open the dataset
  hid_t dataset;
  if ((dataset = H5Dopen(group, name, H5P_DEFAULT)) < 0)
    GMCMC_ERROR("Failed to open dataset", GMCMC_EIO);

  // Read the dataspace from the dataset
  hid_t filespace;
  if ((filespace = H5Dget_space(dataset)) < 0) {
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to get dataspace from dataset", GMCMC_EIO);
  }

  // Use the dataspace from the file to define a subspace in memory for one sample vector
  hsize_t dims[2];
  if (H5Sget_simple_extent_dims(filespace, dims, NULL) < 0) {
    H5Sclose(filespace);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to get dataspace dimensions", GMCMC_EIO);
  }

  // Create an in-memory dataspace describing the dimensions of the vector being written
  hsize_t count[2] = { 1, dims[1] };
  hid_t memspace;
  if ((memspace = H5Screate_simple(2, count, NULL)) < 0) {
    H5Sclose(filespace);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to create in-memory dataspace", GMCMC_EIO);
  }

  // Define the region being written in the file dataspace
  hsize_t offset[2] = { iteration, 0 };
  if (H5Sselect_hyperslab(filespace, H5S_SELECT_SET, offset, NULL, count, NULL) < 0) {
    H5Sclose(memspace);
    H5Sclose(filespace);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to define hyperslab", GMCMC_EIO);
  }

  // Write the data
  if (H5Dwrite(dataset, H5T_IEEE_F64LE, memspace, filespace, H5P_DEFAULT, data) < 0) {
    H5Sclose(memspace);
    H5Sclose(filespace);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to write parameters to dataset", GMCMC_EIO);
  }

  // Close the memory and file dataspaces, the dataset and the group
  H5Sclose(memspace);
  H5Sclose(filespace);
  H5Dclose(dataset);

  return 0;
}

static int write(void * state, size_t iteration, size_t temperature,
                 const double * params, const double * log_prior,
                 double log_likelihood, const double * stepsize) {
  hdf5_filewriter * fw = (hdf5_filewriter *)state;
  if (fw->closed)
    GMCMC_ERROR("Filewriter is closed", GMCMC_EIO);

  char name[13 + temperature / 10];
  snprintf(name, 13 + temperature / 10, "Temperature%zu", temperature + 1);

  // Open the group corresponding to the current temperature
  hid_t group;
  if ((group = H5Gopen(fw->file, name, H5P_DEFAULT)) < 0)
    GMCMC_ERROR("Failed to open temperature group", GMCMC_EIO);

  int error;
  if ((error = hdf5_write_vector(group, PARAMS_NAME, iteration, params)) != 0) {
    H5Gclose(group);
    GMCMC_ERROR("Failed to write parameters", error);
  }
  if ((error = hdf5_write_scalar(group, LOG_LIKELIHOOD_NAME, iteration, log_likelihood)) != 0) {
    H5Gclose(group);
    GMCMC_ERROR("Failed to write log likelihood", error);
  }
  if ((error = hdf5_write_vector(group, LOG_PRIOR_NAME, iteration, log_prior)) != 0) {
    H5Gclose(group);
    GMCMC_ERROR("Failed to write log prior", error);
  }
  if ((error = hdf5_write_vector(group, STEP_SIZE_NAME, iteration, stepsize)) != 0) {
    H5Gclose(group);
    GMCMC_ERROR("Failed to write stepsize", error);
  }

  if (H5Gclose(group) < 0)
    GMCMC_ERROR("Failed to close temperature group after writing", GMCMC_EIO);

  return 0;
}

static gmcmc_filewriter_type type = { destroy, close, write };

static inline int create_dataset(hid_t root, const char * name, hsize_t rank, hsize_t * dims) {
  // Create a dataspace for the dataset
  hid_t dataspace;
  if ((dataspace = H5Screate_simple(rank, dims, NULL)) < 0)
    GMCMC_ERROR("Failed to create HDF5 dataspace", GMCMC_EIO);

  // Create the dataset relative to the root (file or group)
  hid_t dataset;
  if ((dataset = H5Dcreate(root, name, H5T_IEEE_F64LE, dataspace, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT)) < 0) {
    H5Sclose(dataspace);
    GMCMC_ERROR("Failed to create HDF5 dataset", GMCMC_EIO);
  }

  // TODO: Add dataset attributes for MATLAB compatibility

  if (H5Dclose(dataset) < 0) {
    H5Sclose(dataspace);
    GMCMC_ERROR("Failed to close HDF5 dataspace", GMCMC_EIO);
  }

  if (H5Sclose(dataspace) < 0)
    GMCMC_ERROR("Failed to close HDF5 dataspace", GMCMC_EIO);

  return 0;
}

/**
 * Creates a filewriter object that stores samples in HDF5 files.
 *
 * @param [out]  writer            the filewriter object to create,
 * @param [in]   name              the base filename for the files written,
 * @param [in]   num_params        the length of the parameter vectors to write,
 * @param [in]   num_params        the number of parameter blocks,
 * @param [in]   num_temperatures  the number of temperatures in the temperature scale,
 * @param [in]   num_iterations    the number of iterations to store in the file
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to create the filewriter object,
 *         GMCMC_EIO    if there was an error initialising the file structures.
 */
int gmcmc_filewriter_create_hdf5(gmcmc_filewriter ** writer, const char * name,
                                 size_t num_params, size_t num_blocks,
                                 size_t num_temperatures, size_t num_iterations) {

  // Allocate state
  hdf5_filewriter * state;
  if ((state = calloc(1, sizeof(hdf5_filewriter))) == NULL)
    GMCMC_ERROR("Failed to allocate HDF5 filewriter state", GMCMC_ENOMEM);

  // Initially the file pointer has not been closed
  state->closed = false;

  // Create file
  if ((state->file = H5Fcreate(name, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT)) < 0) {
    free(state);
    GMCMC_ERROR("Failed to create HDF5 file", GMCMC_EIO);
  }

  // Create the groups and datasets
  for (size_t i = 0; i < num_temperatures; i++) {
    char groupname[13 + num_temperatures / 10];
    snprintf(groupname, 13 + num_temperatures / 10, "Temperature%zu", i + 1);
    hid_t group;
    if ((group = H5Gcreate(state->file, groupname, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT)) < 0) {
      H5Fclose(state->file);
      free(state);
      GMCMC_ERROR("Failed to create HDF5 group", GMCMC_EIO);
    }

    // Create datasets in the group for parameters, log likelihood, log prior and step size
    hsize_t dims[2] = { num_iterations, num_params };
    int error;
    if ((error = create_dataset(group, PARAMS_NAME, 2, dims)) != 0) {
      H5Fclose(state->file);
      free(state);
      GMCMC_ERROR("Failed to create Params HDF5 dataset", error);
    }
    if ((error = create_dataset(group, LOG_LIKELIHOOD_NAME, 1, dims)) != 0) {
      H5Fclose(state->file);
      free(state);
      GMCMC_ERROR("Failed to create LL HDF5 dataset", error);
    }
    if ((error = create_dataset(group, LOG_PRIOR_NAME, 2, dims)) != 0) {
      H5Fclose(state->file);
      free(state);
      GMCMC_ERROR("Failed to create LogPrior HDF5 dataset", error);
    }
    dims[1] = num_blocks;
    if ((error = create_dataset(group, STEP_SIZE_NAME, 2, dims)) != 0) {
      H5Fclose(state->file);
      free(state);
      GMCMC_ERROR("Failed to create StepSize HDF5 dataset", error);
    }

    // TODO: Add group attributes for MATLAB compatibility

    // TODO: Add links for MATLAB compatibility

    if (H5Gclose(group) < 0) {
      H5Fclose(state->file);
      free(state);
      GMCMC_ERROR("Failed to close HDF5 group", GMCMC_EIO);
    }
  }

  if ((*writer = malloc(sizeof(gmcmc_filewriter))) == NULL) {
    H5Fclose(state->file);
    free(state);
    GMCMC_ERROR("Failed to allocate HDF5 file writer", GMCMC_ENOMEM);
  }

  (*writer)->type = &type;
  (*writer)->state = state;

  return 0;
}
