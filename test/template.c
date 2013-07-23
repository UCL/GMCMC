#define CONCATx(x, y) x ## y
#define CONCAT(x, y) CONCATx(x, y)
static void CONCAT(test_five_state_ion_likelihood_mh,I)() {
  // Input argument
  double params[N] = { PARAMS };
  // Output argument
  double likelihood;

  // Call test function
  int error = gmcmc_likelihood(data, model, params, N, &likelihood, NULL, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(likelihood, LL, 1.0e-04);
}
