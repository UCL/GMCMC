/**
 * Reads a vector from an HDF-5 file.
 *
 * @param [in]  file    the HDF-5 file handle,
 * @param [in]  name    the name of the HDF-5 dataset containing the vector,
 * @param [in]  type    the expected type of the data in the dataset,
 * @param [out] length  on return this is set to the number of elements in the
 *                        vector,
 * @param [out] data    a pointer to allocate and fill with data
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if the dataset cannot be found, or the data is the wrong
 *                        type,
 *         GMCMC_EIO    if there is a problem reading the file.
 */
static inline int hdf5_read_vector(hid_t file, const char * name, hid_t type,
                                   size_t * length, void ** data) {
  // Get a reference to the dataset
  hid_t dataset;
  if ((dataset = H5Dopen(file, name, H5P_DEFAULT)) < 0)
    GMCMC_ERROR("Unable to find dataset", GMCMC_EINVAL);

  // Check the data is stored in double precision
  hid_t datatype;
  if ((datatype = H5Dget_type(dataset)) < 0) {
    H5Dclose(dataset);
    GMCMC_ERROR("Unable to read data type", GMCMC_EIO);
  }
  if (H5Tequal(datatype, type) == 0) {
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Dataset is wrong type", GMCMC_EINVAL);
  }

  // Get a reference to the dataspace for the data (defines dimensionality and
  // dimensions)
  hid_t filespace;
  if ((filespace = H5Dget_space(dataset)) < 0) {
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Unable to read dataspace from file", GMCMC_EIO);
  }

  // Check the dimensionality of the dataspace
  int ndims;
  if ((ndims = H5Sget_simple_extent_ndims(filespace)) < 0) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Unable to read number of dimensions in file dataspace", GMCMC_EIO);
  }
  if (ndims != 1) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("File dataspace has the wrong number of dimensions", GMCMC_EINVAL);
  }

  // Check the dimensions of the dataspace
  hsize_t dim;
  if (H5Sget_simple_extent_dims(filespace, &dim, NULL) < 0) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Unable to read file dataspace dimensions", GMCMC_EIO);
  }
  if (dim < 1) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("File dataspace has the wrong dimensions", GMCMC_EINVAL);
  }

  // Allocate space for the data
  if ((*data = malloc(dim * H5Tget_size(type))) == NULL) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to allocate memory for vector", GMCMC_ENOMEM);
  }
  *length = dim;

  // Read the vector from the dataset
  if (H5Dread(dataset, H5T_IEEE_F64LE, H5S_ALL, H5S_ALL, H5P_DEFAULT, *data) < 0) {
    free(*data);
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to read vector", GMCMC_EIO);
  }

  // Close the dataspace, datatype and dataset
  H5Sclose(filespace);
  H5Tclose(datatype);
  H5Dclose(dataset);

  return 0;
}

/**
 * Reads a matrix from an HDF-5 file.  Matrices in HDF-5 are stored in row-major
 * order.  After reading, element (i, j) in the matrix can be accessed at
 * data[i * rows + j].
 *
 * @param [in]  file  the HDF-5 file handle,
 * @param [in]  name  the name of the HDF-5 dataset containing the matrix,
 * @param [in]  type  the expected type of the data in the dataset,
 * @param [out] rows  on return this is set to the number of rows in the
 *                      matrix,
 * @param [out] cols  on return this is set to the number of columns in the
 *                      matrix,
 * @param [out] data    a pointer to allocate and fill with data
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if the dataset cannot be found, or the data is the wrong
 *                        type,
 *         GMCMC_EIO    if there is a problem reading the file.
 */
static inline int hdf5_read_matrix(hid_t file, const char * name, hid_t type,
                                   size_t * rows, size_t * cols, void ** data) {
  // Get a reference to the dataset
  hid_t dataset;
  if ((dataset = H5Dopen(file, name, H5P_DEFAULT)) < 0)
    GMCMC_ERROR("Unable to find dataset", GMCMC_EINVAL);

  // Check the data is stored in double precision
  hid_t datatype;
  if ((datatype = H5Dget_type(dataset)) < 0) {
    H5Dclose(dataset);
    GMCMC_ERROR("Unable to read data type", GMCMC_EIO);
  }
  if (H5Tequal(datatype, type) == 0) {
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Dataset is wrong type", GMCMC_EINVAL);
  }

  // Get a reference to the dataspace for the data (defines dimensionality and
  // dimensions)
  hid_t filespace;
  if ((filespace = H5Dget_space(dataset)) < 0) {
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Unable to read dataspace from file", GMCMC_EIO);
  }

  // Check the dimensionality of the dataspace
  int ndims;
  if ((ndims = H5Sget_simple_extent_ndims(filespace)) < 0) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Unable to read number of dimensions in file dataspace", GMCMC_EIO);
  }
  if (ndims != 2) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("File dataspace has the wrong number of dimensions", GMCMC_EINVAL);
  }

  // Check the dimensions of the dataspace
  hsize_t dims[2];
  if (H5Sget_simple_extent_dims(filespace, dims, NULL) < 0) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Unable to read file dataspace dimensions", GMCMC_EIO);
  }
  if (dims[0] != 1 || dims[1] < 1) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("File dataspace has the wrong dimensions", GMCMC_EINVAL);
  }

  // Allocate space for the data
  if ((*data = malloc(dims[0] * dims[1] * H5Tget_size(type))) == NULL) {
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to allocate memory for matrix", GMCMC_ENOMEM);
  }
  *rows = dims[0];
  *cols = dims[0];

  // Read the matrix from the dataset
  if (H5Dread(dataset, H5T_IEEE_F64LE, H5S_ALL, H5S_ALL, H5P_DEFAULT, *data) < 0) {
    free(*data);
    H5Sclose(filespace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    GMCMC_ERROR("Failed to read matrix", GMCMC_EIO);
  }

  // Close the dataspace, datatype and dataset
  H5Sclose(filespace);
  H5Tclose(datatype);
  H5Dclose(dataset);

  return 0;
}
