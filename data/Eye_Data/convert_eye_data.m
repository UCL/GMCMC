function convert_eye_data( filename )
%convert_eye_data Converts data for Stochatistic Eye models from a matfile
%to a txt file.
%   Converts data for Stochastic Eye models from a matfile to a txt file.
%   The matfile contains a variable "PH" which is a
%   num_microseconds*num_photoreceptors matrix containing a 1 when input is
%   detected for a particular photoreceptor at a particular time and 0
%   otherwise.  The output text file contains num_photoreceptors rows and
%   each row contains the times in milliseconds that input is detected
%   (i.e. the index of the non-zero elements per column in PH) separated by
%   a tab.
%   The filename argument is the name of the matfile without extension.
%   The output file is "filename.txt".

% Load the PH variable from the input file
load([filename, '.mat'], 'PH');

% Open the output file for writing
outfile = fopen([filename, '.txt'], 'w');


% Foreach photoreceptor p
num_photoreceptors = size(PH, 2);
for j=1:num_photoreceptors
  p = PH(:, j); % boolean column vector for photoreceptor j
  
  % Get the indices of non-zero elements
  ii = find(p);
  ii = ii'; % as a row vector
  
  % Print each element of ii to outfile separated by a tab
  for i=1:length(ii)
    fprintf(outfile, '%d', ii(i));
    if i < length(ii)
      fprintf(outfile, '\t');
    end
  end

  fprintf(outfile, '\n');
end

fclose(outfile);

end

