#define CONCATx(x, y) x ## y
#define CONCAT(x, y) CONCATx(x, y)
static void CONCAT(test_fitzhugh_ode_likelihood_simp_mmala,I)() {
  // Input argument
  double params[] = { PARAMS };
  // Output argument
  double likelihood;

  // Call test function
  int error = gmcmc_likelihood(data, model, params, &likelihood, NULL, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(likelihood, LL, 1.0e-3);
}
