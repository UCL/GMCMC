function ION_MAT_2_HDF5( MATfilename )
% Converts an ion channel MATLAB data file into an HDF5 file.


% Construct the HDF5 filename from the MATLAB filename by replacing the
% extention with .h5
[ pathstr, name, ~ ] = fileparts(MATfilename);
filename = fullfile(pathstr, [ name '.h5']);

% Open the MATLAB file
MATdata = open(MATfilename);

% Create the HDF5 file
fileID = H5F.create(filename, 'H5F_ACC_TRUNC', 'H5P_DEFAULT', 'H5P_DEFAULT');

% Data arrays in MATLAB ion channel files are stored in double precision
datatypeID = H5T.copy('H5T_NATIVE_DOUBLE');

% Get an array of variable names in the MATLAB file
vars = fieldnames(MATdata);

for i=1:length(vars)
  
  % Get the data from the MATLAB file
  val = MATdata.(vars{i});

  % Create a one-dimensional HDF5 dataspace for the TimePoints and Data
  % vectors
  dataspaceID = H5S.create_simple(1, length(val), []);

  % Create a dataset with the dataspace
  datasetID = H5D.create(fileID, vars{i}, datatypeID, dataspaceID, 'H5P_DEFAULT');

  % Write the data to the dataset
  H5D.write(datasetID, 'H5ML_DEFAULT', 'H5S_ALL', 'H5S_ALL', 'H5P_DEFAULT', val);
  
  % Close the dataset and dataspace
  H5D.close(datasetID);
  H5S.close(dataspaceID);
end

% Close the data type and file
H5T.close(datatypeID);
H5F.close(fileID);

end
