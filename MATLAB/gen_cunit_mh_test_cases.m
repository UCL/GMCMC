function gen_cunit_mh_test_cases(datafile, filename, name)
% Generate CUnit tests based on the outcome of a Matlab simulation.
% Parameters:
%  datafile           output from a Matlab simulation
%  filename           two files are output for inclusion in the CUnit test
%                       suite:
%                       filename.c contains the unit test functions and
%                       filename_main.c contains code which adds them to a
%                       test suite
%  name               the name of the suite to add the tests to

  % Seed the RNG
  state = rng;
  rng(0,'twister');

  % Open the output file to define the test functions
  testfile = fopen([filename '.c'], 'w');

  % Open the output file to add the tests to the suite
  mainfile = fopen([filename '_main.c'], 'w');
  
  % Open the results file
  load(datafile, 'Samples_Posterior', 'MCMC_Options');
  
  % For each temperature
  NumTemps = length(Samples_Posterior);
  for k=1:NumTemps
    % Get 10 random tests
    idx = datasample(1:size(Samples_Posterior{k}.Paras, 1), 10, 'Replace', false);
 
    % Print the test cases to the test file and add them to the main file
    for i=1:length(idx)
      
      % Print function definition to function file
      fprintf(testfile, '// Sample number %d\n', idx(i));
      fprintf(testfile, 'static void test_%s_likelihood_mh%d() {\n', name, (k - 1) * length(idx) + i);
      
      % Print input arguments
      fprintf(testfile, [ '  // Input argument\n'...
                          '  double params[] = {' ]);
      NumOfParas = size(Samples_Posterior{k}.Paras, 2);
      for j=1:NumOfParas
        fprintf(testfile, ' %.17f', Samples_Posterior{k}.Paras(idx(i), j));
        if j < NumOfParas
          fprintf(testfile, ',');
        end
      end
      fprintf(testfile, ' };\n');
      
      fprintf(testfile, ['  // Output arguments\n'...
                         '  double likelihood;\n\n' ]);
      
      fprintf(testfile, ['  // Call test function\n'...
                         '  int error = gmcmc_%s_likelihood_mh(data, model, params, &likelihood, NULL, NULL);\n\n' ], name);
      fprintf(testfile, ['  // Check return value\n'...
                         '  CU_ASSERT(error == 0);\n\n' ]);
        
      fprintf(testfile, ['  // Check log likelihood\n'...
                         '  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, %.17f, 1.0e-06);\n\n' ], Samples_Posterior{k}.LL(idx(i)));
        
      fprintf(testfile, '  }\n\n');
      
      % Add tests to main file
      fprintf(mainfile, '  CU_ADD_TEST(%s, test_%s_likelihood_mh%d);\n', name, name, (k - 1) * length(idx) + i);
      fprintf(mainfile, '  if (CU_get_error() != CUE_SUCCESS)\n    CUNIT_ERROR("Failed to add test to suite");\n\n');


      if ~isequal(MCMC_Options.Temperatures(k), 0)
        
        % Print function definition to function file
        fprintf(testfile, '// Sample number %d\n', idx(i));
        fprintf(testfile, 'static void test_%s_proposal_mh%d() {\n', name, (k - 1) * length(idx) + i);

        % Print input arguments
        fprintf(testfile, [ '  // Input arguments\n'...
                            '  double params[] = {' ]);
        for j=1:NumOfParas
          fprintf(testfile, ' %.17f', Samples_Posterior{k}.Paras(idx(i), j));
          if j < NumOfParas
            fprintf(testfile, ',');
          end
        end
        fprintf(testfile, ' };\n');
        fprintf(testfile, [ '  double likelihood = %.17f;\n'...
                            '  double temperature = %.17f;\n'...
                            '  double stepsize = %.17f;\n' ],...
                            Samples_Posterior{k}.LL(idx(i)),...
                            MCMC_Options.Temperatures(k),...
                            Samples_Posterior{k}.StepSize(idx(i)));

        % Print output arguments
        fprintf(testfile, ['  // Output arguments\n'...
                           '  size_t ldc = (%d + 1u) & ~1u;\n'...
                           '  double mean[%d], covariance[ldc * %d];\n\n' ], NumOfParas, NumOfParas, NumOfParas);

        % Call test function
        fprintf(testfile, ['  // Call test function\n'...
                           '  int error = gmcmc_proposal_mh(%d, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);\n\n' ], NumOfParas);
        fprintf(testfile, ['  // Check return value\n'...
                           '  CU_ASSERT(error == 0);\n\n' ]);

        % Generate outputs using matlab version
        Chain.StepSize = Samples_Posterior{k}.StepSize(idx(i));
        Chain.Paras = Samples_Posterior{k}.Paras(idx(i),:);
        Chain.NumOfParas = NumOfParas;
        Chain.Temp = MCMC_Options.Temperatures(k);

        [ Mean, Cov ] = ODE_Proposal_MH(Chain, Chain);

        fprintf(testfile, '  // Check mean\n');
        for j=1:NumOfParas;
          fprintf(testfile, '  CU_ASSERT_DOUBLE_EQUAL_REL(mean[%d], %.17f, 1.0e-06);\n', j - 1,Mean(j));
        end
        fprintf(testfile, '\n');

        fprintf(testfile, '  // Check covariance\n');
        for j=1:NumOfParas;
          for l=1:NumOfParas;
            fprintf(testfile, '  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[%d * ldc + %d], %.17f, 1.0e-06);\n', j - 1, l - 1, Cov(l, j));
          end
        end
        fprintf(testfile, '\n}\n\n');
        
        % Add tests to main file
        fprintf(mainfile, '  CU_ADD_TEST(%s, test_%s_proposal_mh%d);\n', name, name, (k - 1) * length(idx) + i);
        fprintf(mainfile, '  if (CU_get_error() != CUE_SUCCESS)\n    CUNIT_ERROR("Failed to add test to suite");\n\n');
      end
    end
  end
  
  % Close the output files
  fclose(testfile);
  fclose(mainfile);
  
  % Restore the RNG
  rng(state);
end
