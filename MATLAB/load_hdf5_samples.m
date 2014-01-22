function [ Samples ] = load_hdf5_samples( filename )
%load_hdf5_samples Loads samples from an HDF5 posterior/burnin file

structure = h5info(filename);


Samples = cell(1,length(structure.Groups));
for i = 1:length(Samples)
  group = structure.Groups(i);
  Samples{i}.LL = h5read(filename, [group.Name '/LL']);
  Samples{i}.LogPrior = h5read(filename, [group.Name '/LogPrior'])';
  Samples{i}.Params = h5read(filename, [group.Name '/Params'])';
  Samples{i}.StepSize = h5read(filename, [group.Name '/StepSize'])';
end

end

