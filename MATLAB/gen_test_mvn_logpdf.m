% Seed the RNG so that repeated runs give the same results
rng(0, 'twister');

% Generate 10 test cases
for i=0:9
    
    % Create distribution parameters
    Mu = randn(4,1);
    Sigma = randn(4,4);
    Sigma = Sigma * Sigma'; % Random positive definite covariance
    
    % Generate a multivariate random vector
    x = mvnrnd(Mu, Sigma);

    % Test standard MVN log PDF
    fprintf('static void test_mvn_logpdf%d() {\n', i*2);
    fprintf('  double mu[] = { %.15f, %.15f, %.15f, %.15f };\n', Mu(1), Mu(2), Mu(3), Mu(4));
    fprintf(['  double sigma[] = { %.15f, %.15f, %.15f, %.15f,\n',...
             '                     %.15f, %.15f, %.15f, %.15f,\n',...
             '                     %.15f, %.15f, %.15f, %.15f,\n',...
             '                     %.15f, %.15f, %.15f, %.15f };\n'],...
             Sigma(1,1), Sigma(2,1), Sigma(3,1), Sigma(4,1),...
             Sigma(1,2), Sigma(2,2), Sigma(3,2), Sigma(4,2),...
             Sigma(1,3), Sigma(2,3), Sigma(3,3), Sigma(4,3),...
             Sigma(1,4), Sigma(2,4), Sigma(3,4), Sigma(4,4));
    fprintf('  double x[] = { %.15f, %.15f, %.15f, %.15f };\n\n', x(1), x(2), x(3), x(4));
    fprintf('  double res;\n  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);\n\n');
    fprintf('  CU_ASSERT_DOUBLE_EQUAL(res, %.15f, 1.0e-07);\n}\n\n', log(mvnpdf(x', Mu, Sigma)));
    
    % Test with NULL (zero) mean
    fprintf('static void test_mvn_logpdf%d() {\n', i*2+1);
    fprintf(['  double sigma[] = { %.15f, %.15f, %.15f, %.15f,\n',...
             '                     %.15f, %.15f, %.15f, %.15f,\n',...
             '                     %.15f, %.15f, %.15f, %.15f,\n',...
             '                     %.15f, %.15f, %.15f, %.15f };\n'],...
             Sigma(1,1), Sigma(2,1), Sigma(3,1), Sigma(4,1),...
             Sigma(1,2), Sigma(2,2), Sigma(3,2), Sigma(4,2),...
             Sigma(1,3), Sigma(2,3), Sigma(3,3), Sigma(4,3),...
             Sigma(1,4), Sigma(2,4), Sigma(3,4), Sigma(4,4));
    fprintf('  double x[] = { %.15f, %.15f, %.15f, %.15f };\n\n', x(1), x(2), x(3), x(4));
    fprintf('  double res;\n  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);\n\n');
    fprintf('  CU_ASSERT_DOUBLE_EQUAL(res, %.15f, 1.0e-07);\n}\n\n', log(mvnpdf(x', zeros(4,1), Sigma)));
    
    % Test optimised PDF where sigma is a vector
    Sigma = diag(diag(Sigma));
    fprintf('static void test_mvn_logpdfv%d() {\n', i*2);
    fprintf('  double mu[] = { %.15f, %.15f, %.15f, %.15f };\n', Mu(1), Mu(2), Mu(3), Mu(4));
    fprintf('  double sigma[] = { %.15f, %.15f, %.15f, %.15f };\n',...
             Sigma(1,1), Sigma(2,2), Sigma(3,3), Sigma(4,4));
    fprintf('  double x[] = { %.15f, %.15f, %.15f, %.15f };\n\n', x(1), x(2), x(3), x(4));
    fprintf('  double res;\n  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);\n\n');
    fprintf('  CU_ASSERT_DOUBLE_EQUAL(res, %.15f, 1.0e-07);\n}\n\n', log(mvnpdf(x', Mu, Sigma)));
    
    % Test with NULL (zero) mean
    fprintf('static void test_mvn_logpdfv%d() {\n', i*2+1);
    fprintf('  double sigma[] = { %.15f, %.15f, %.15f, %.15f };\n',...
             Sigma(1,1), Sigma(2,2), Sigma(3,3), Sigma(4,4));
    fprintf('  double x[] = { %.15f, %.15f, %.15f, %.15f };\n\n', x(1), x(2), x(3), x(4));
    fprintf('  double res;\n  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);\n\n');
    fprintf('  CU_ASSERT_DOUBLE_EQUAL(res, %.15f, 1.0e-07);\n}\n\n', log(mvnpdf(x', zeros(4,1), Sigma)));
    
    % Test optimised PDF where sigma is a scalar
    Sigma = diag(ones(4,1) * Sigma(1,1));
    fprintf('static void test_mvn_logpdfs%d() {\n', i*2);
    fprintf('  double mu[] = { %.15f, %.15f, %.15f, %.15f };\n', Mu(1), Mu(2), Mu(3), Mu(4));
    fprintf('  double sigma = %.15f;\n', Sigma(1,1));
    fprintf('  double x[] = { %.15f, %.15f, %.15f, %.15f };\n\n', x(1), x(2), x(3), x(4));
    fprintf('  double res;\n  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);\n\n');
    fprintf('  CU_ASSERT_DOUBLE_EQUAL(res, %.15f, 1.0e-07);\n}\n\n', log(mvnpdf(x', Mu, Sigma)));
    
    % Test with NULL (zero) mean
    fprintf('static void test_mvn_logpdfs%d() {\n', i*2+1);
    fprintf('  double sigma = %.15f;\n', Sigma(1,1));
    fprintf('  double x[] = { %.15f, %.15f, %.15f, %.15f };\n\n', x(1), x(2), x(3), x(4));
    fprintf('  double res;\n  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);\n\n');
    fprintf('  CU_ASSERT_DOUBLE_EQUAL(res, %.15f, 1.0e-07);\n}\n\n', log(mvnpdf(x', zeros(4,1), Sigma)));
    
end
