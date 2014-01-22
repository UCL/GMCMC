function gen_cunit_simp_mmala_test_cases(datafile, filename, name)
% Generate CUnit tests based on the outcome of a Matlab simulation.
% Parameters:
%  datafile           output from a Matlab simulation
%  filename           two files are output for inclusion in the CUnit test
%                       suite:
%                       filename.c contains the unit test functions and
%                       filename_main.c contains code which adds them to a
%                       test suite
%  name               the name of the suite to add the tests to

  % Seed the fucking RNG
  state = rng;
  rng(0,'twister');

  % Open the output file to define the test functions
  testfile = fopen([filename '.c'], 'w');

  % Open the output file to add the tests to the suite
  mainfile = fopen([filename '_main.c'], 'w');
  
  % Open the results file
  data = open(datafile);
  
  % For each temperature
  NumTemps = length(data.Samples_Posterior);
  for k=1:NumTemps
    % Get 10 random tests
    idx = datasample(1:size(data.Samples_Posterior{k}.Paras, 1), 10, 'Replace', false);
 
    % Print the test cases to the test file and add them to the main file
    for i=1:length(idx)
      
      % Print function definition to function file
      fprintf(testfile, '// Sample number %d\n', idx(i));
      fprintf(testfile, 'static void test_ode_likelihood_%s%d() {\n', name, (k - 1) * length(idx) + i);
      
      % Print input arguments
      fprintf(testfile, [ '  // Input argument\n'...
                          '  double params[] = {' ]);
      NumOfParas = size(data.Samples_Posterior{k}.Paras, 2);
      for j=1:NumOfParas
        fprintf(testfile, ' %.17f', data.Samples_Posterior{k}.Paras(idx(i), j));
        if j < NumOfParas
          fprintf(testfile, ',');
        end
      end
      fprintf(testfile, ' };\n');
        
      fprintf(testfile, ['  // Output arguments\n'...
                         '  double likelihood;\n'...
                         '  double * serdata;\n'...
                         '  size_t size;\n\n' ]);
      
      fprintf(testfile, ['  // Call test function\n'...
                         '  int error = gmcmc_likelihood(data, model, params, &likelihood, (void **)&serdata, &size);\n\n' ]);
      fprintf(testfile, ['  // Check return value\n'...
                         '  CU_ASSERT(error == 0);\n\n' ]);
        
      fprintf(testfile, ['  // Check log likelihood\n'...
                         '  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, %.17f, 1.0e-06);\n\n' ], data.Samples_Posterior{k}.LL(idx(i)));
        
      fprintf(testfile, ['  // Check serialised data\n'...
                         '  CU_ASSERT_FATAL(serdata != NULL);\n'...
                         '  const size_t ldfi = (%du + 1u) & ~1u;\n'...
                         '  CU_ASSERT_EQUAL(size, (3 + %d) * ldfi * sizeof(double));\n\n' ], NumOfParas, NumOfParas);
        
      fprintf(testfile, ['  // Unpack serialised data\n'...
                         '  const double * grad_ll = &serdata[0];\n'...
                         '  const double * grad_log_prior = &grad_ll[ldfi];\n'...
                         '  const double * FI = &grad_log_prior[ldfi];\n'...
                         '  const double * hessian_log_prior = &FI[%d * ldfi];\n\n'], NumOfParas);
        
      fprintf(testfile, '  // Check gradient log likelihood\n');
      for j=1:NumOfParas;
        fprintf(testfile, '  CU_ASSERT_DOUBLE_EQUAL_REL(grad_ll[%d], %.17f, 1.0e-06);\n', j - 1, data.Samples_Posterior{k}.GradLL(idx(i),j));
      end
      fprintf(testfile, '\n');
        
      fprintf(testfile, '  // Check gradient log prior\n');
      for j=1:NumOfParas;
        fprintf(testfile, '  CU_ASSERT_DOUBLE_EQUAL_REL(grad_log_prior[%d], %.17f, 1.0e-06);\n', j - 1, data.Samples_Posterior{k}.GradLogPrior(idx(i),j));
      end
      fprintf(testfile, '\n');
        
      fprintf(testfile, '  // Check fisher information\n');
      for j=1:NumOfParas;
        for l=1:NumOfParas;
          fprintf(testfile, '  CU_ASSERT_DOUBLE_EQUAL_REL(FI[%d * ldfi + %d], %.17f, 1.0e-06);\n', j - 1, l - 1, data.Samples_Posterior{k}.FI{idx(i)}(l, j));
        end
      end
      fprintf(testfile, '\n');
        
      fprintf(testfile, '  // Check hessian log prior\n');
      for j=1:NumOfParas;
        fprintf(testfile, '  CU_ASSERT_DOUBLE_EQUAL_REL(hessian_log_prior[%d], %.17f, 1.0e-06);\n', j - 1, data.Samples_Posterior{k}.HessianLogPrior(idx(i),j));
      end
      fprintf(testfile, '\n');
        
      fprintf(testfile, '  free(serdata);\n}\n\n');
      
      % Add tests to main file
      fprintf(mainfile, '  CU_ADD_TEST(%s, test_ode_likelihood_%s%d);\n', name, name, (k - 1) * length(idx) + i);
      fprintf(mainfile, '  if (CU_get_error() != CUE_SUCCESS)\n    CUNIT_ERROR("Failed to add test to suite");\n\n');


      if ~isequal(data.MCMC_Options.Temperatures(k), 0)
        
        % Print function definition to function file
        fprintf(testfile, '// Sample number %d\n', idx(i));
        fprintf(testfile, 'static void test_ode_proposal_%s%d() {\n', name, (k - 1) * length(idx) + i);

        % Print input arguments
        fprintf(testfile, [ '  // Input arguments\n'...
                            '  double params[] = {' ]);
        for j=1:NumOfParas
          fprintf(testfile, ' %.17f', data.Samples_Posterior{k}.Paras(idx(i), j));
          if j < NumOfParas
            fprintf(testfile, ',');
          end
        end
        fprintf(testfile, ' };\n');
        fprintf(testfile, [ '  double likelihood = %.17f;\n'...
                            '  double temperature = %.17f;\n'...
                            '  double stepsize = %.17f;\n' ],...
                            data.Samples_Posterior{k}.LL(idx(i)),...
                            data.MCMC_Options.Temperatures(k),...
                            data.Samples_Posterior{k}.StepSize(idx(i)));

        fprintf(testfile, ['  const size_t ldfi = (%d + 1u) & ~1u;\n'...
                           '  double serdata[(3 + %d) * ldfi * sizeof(double)];\n' ], NumOfParas, NumOfParas);

        fprintf(testfile, ['  double * grad_ll = &serdata[0];\n'...
                           '  double * grad_log_prior = &grad_ll[ldfi];\n'...
                           '  double * FI = &grad_log_prior[ldfi];\n'...
                           '  double * hessian_log_prior = &FI[%d * ldfi];\n\n'], NumOfParas);

        for j=1:NumOfParas;
          fprintf(testfile, '  grad_ll[%d] = %.17f;\n', j - 1, data.Samples_Posterior{k}.GradLL(idx(i),j));
        end
        fprintf(testfile, '\n');

        for j=1:NumOfParas;
          fprintf(testfile, '  grad_log_prior[%d] = %.17f;\n', j - 1, data.Samples_Posterior{k}.GradLogPrior(idx(i),j));
        end
        fprintf(testfile, '\n');

        for j=1:NumOfParas;
          for l=1:NumOfParas;
            fprintf(testfile, '  FI[%d * ldfi + %d] = %.17f;\n', j - 1, l - 1, data.Samples_Posterior{k}.FI{idx(i)}(l, j));
          end
        end
        fprintf(testfile, '\n');

        for j=1:NumOfParas;
          fprintf(testfile, '  hessian_log_prior[%d] = %.17f;\n', j - 1, data.Samples_Posterior{k}.HessianLogPrior(idx(i),j));
        end
        fprintf(testfile, '\n');

        % Print output arguments
        fprintf(testfile, ['  // Output arguments\n'...
                           '  size_t ldc = (%d + 1u) & ~1u;\n'...
                           '  double mean[%d], covariance[ldc * %d];\n\n' ], NumOfParas, NumOfParas, NumOfParas);

        % Call test function
        fprintf(testfile, ['  // Call test function\n'...
                           '  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, serdata, mean, covariance, ldc);\n\n' ]);
        fprintf(testfile, ['  // Check return value\n'...
                           '  CU_ASSERT(error == 0);\n\n' ]);

        % Generate outputs using matlab version
        Chain.StepSize = data.Samples_Posterior{k}.StepSize(idx(i));
        Chain.Paras = data.Samples_Posterior{k}.Paras(idx(i),:);
        Chain.NumOfParas = NumOfParas;
        Chain.Temp = data.MCMC_Options.Temperatures(k);
        Chain.GradLL = data.Samples_Posterior{k}.GradLL(idx(i),:);
        Chain.GradLogPrior = data.Samples_Posterior{k}.GradLogPrior(idx(i),:);
        Chain.FI = data.Samples_Posterior{k}.FI{idx(i)};
        Chain.HessianLogPrior = data.Samples_Posterior{k}.HessianLogPrior(idx(i),:);

        [ Mean, Cov ] = ODE_Proposal_Simp_mMALA(Chain, Chain);

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
        fprintf(mainfile, '  CU_ADD_TEST(%s, test_ode_proposal_%s%d);\n', name, name, (k - 1) * length(idx) + i);
        fprintf(mainfile, '  if (CU_get_error() != CUE_SUCCESS)\n    CUNIT_ERROR("Failed to add test to suite");\n\n');
      end
    end
  end
  
  % Close the output files
  fclose(testfile);
  fclose(mainfile);
  
  % Restore the fucking RNG
  rng(state);
end
