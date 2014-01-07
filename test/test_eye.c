// Sample number 815
static void test_eye_likelihood_mh1() {
  // Input argument
  double params[] = { 0.94415365822702646, 5.34977452240577112, 0.01148640830982054, 51.50525416487992203, 1.02701342841024457, 100.52195798097233137, 1.38167152826097905 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17535.93191653460235102) <= 1.0e-06);

  }

// Sample number 815
static void test_eye_proposal_mh1() {
  // Input arguments
  double params[] = { 0.94415365822702646, 5.34977452240577112, 0.01148640830982054, 51.50525416487992203, 1.02701342841024457, 100.52195798097233137, 1.38167152826097905 };
  double likelihood = -17535.93191653460235102;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.94415365822702646) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.34977452240577112) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.01148640830982054) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.50525416487992203) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.02701342841024457) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.52195798097233137) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 1.38167152826097905) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 905
static void test_eye_likelihood_mh2() {
  // Input argument
  double params[] = { 0.97738817263610100, 5.29779568706349213, 0.04607537241599206, 51.46622949579705875, 1.00057014039914227, 100.47892242400448026, 1.36609939591122376 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17489.44948334545915714) <= 1.0e-06);

  }

// Sample number 905
static void test_eye_proposal_mh2() {
  // Input arguments
  double params[] = { 0.97738817263610100, 5.29779568706349213, 0.04607537241599206, 51.46622949579705875, 1.00057014039914227, 100.47892242400448026, 1.36609939591122376 };
  double likelihood = -17489.44948334545915714;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.97738817263610100) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.29779568706349213) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.04607537241599206) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.46622949579705875) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.00057014039914227) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.47892242400448026) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 1.36609939591122376) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 127
static void test_eye_likelihood_mh3() {
  // Input argument
  double params[] = { 0.94405226931644781, 5.42651121628284461, 0.00153073963371018, 51.67572039482346469, 1.00749481077117142, 100.47605644925307899, 2.00948415518685275 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -16857.82771395589588792) <= 1.0e-06);

  }

// Sample number 127
static void test_eye_proposal_mh3() {
  // Input arguments
  double params[] = { 0.94405226931644781, 5.42651121628284461, 0.00153073963371018, 51.67572039482346469, 1.00749481077117142, 100.47605644925307899, 2.00948415518685275 };
  double likelihood = -16857.82771395589588792;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.94405226931644781) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.42651121628284461) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.00153073963371018) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.67572039482346469) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.00749481077117142) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.47605644925307899) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 2.00948415518685275) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 911
static void test_eye_likelihood_mh4() {
  // Input argument
  double params[] = { 1.00100683995536865, 5.34855347867108577, 0.06762733311234506, 51.50330510950391272, 1.01266507454949806, 100.53875814613543582, 1.31632029416047969 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17947.28135784417099785) <= 1.0e-06);

  }

// Sample number 911
static void test_eye_proposal_mh4() {
  // Input arguments
  double params[] = { 1.00100683995536865, 5.34855347867108577, 0.06762733311234506, 51.50330510950391272, 1.01266507454949806, 100.53875814613543582, 1.31632029416047969 };
  double likelihood = -17947.28135784417099785;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 1.00100683995536865) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.34855347867108577) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.06762733311234506) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.50330510950391272) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.01266507454949806) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.53875814613543582) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 1.31632029416047969) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 630
static void test_eye_likelihood_mh5() {
  // Input argument
  double params[] = { 0.95414438052541006, 5.39973309885350972, 0.00346250190281080, 51.55220974455011884, 1.01518591329843821, 100.61018399492061803, 1.60170951331762002 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17144.25422655844886322) <= 1.0e-06);

  }

// Sample number 630
static void test_eye_proposal_mh5() {
  // Input arguments
  double params[] = { 0.95414438052541006, 5.39973309885350972, 0.00346250190281080, 51.55220974455011884, 1.01518591329843821, 100.61018399492061803, 1.60170951331762002 };
  double likelihood = -17144.25422655844886322;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.95414438052541006) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.39973309885350972) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.00346250190281080) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.55220974455011884) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.01518591329843821) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.61018399492061803) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 1.60170951331762002) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 98
static void test_eye_likelihood_mh6() {
  // Input argument
  double params[] = { 0.94405226931644781, 5.42651121628284461, 0.00153073963371018, 51.67572039482346469, 1.00749481077117142, 100.47605644925307899, 2.00948415518685275 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17101.16087327046989230) <= 1.0e-06);

  }

// Sample number 98
static void test_eye_proposal_mh6() {
  // Input arguments
  double params[] = { 0.94405226931644781, 5.42651121628284461, 0.00153073963371018, 51.67572039482346469, 1.00749481077117142, 100.47605644925307899, 2.00948415518685275 };
  double likelihood = -17101.16087327046989230;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.94405226931644781) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.42651121628284461) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.00153073963371018) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.67572039482346469) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.00749481077117142) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.47605644925307899) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 2.00948415518685275) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 277
static void test_eye_likelihood_mh7() {
  // Input argument
  double params[] = { 0.94174933827561336, 5.37492139995560869, 0.00049437128543596, 51.70104295186765597, 1.00956666630549141, 100.55031915083903016, 1.96538613579121968 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17116.75077698967288597) <= 1.0e-06);

  }

// Sample number 277
static void test_eye_proposal_mh7() {
  // Input arguments
  double params[] = { 0.94174933827561336, 5.37492139995560869, 0.00049437128543596, 51.70104295186765597, 1.00956666630549141, 100.55031915083903016, 1.96538613579121968 };
  double likelihood = -17116.75077698967288597;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.94174933827561336) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.37492139995560869) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.00049437128543596) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.70104295186765597) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.00956666630549141) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.55031915083903016) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 1.96538613579121968) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 544
static void test_eye_likelihood_mh8() {
  // Input argument
  double params[] = { 0.92686065744859836, 5.35506798143644858, 0.00179144672312643, 51.51945867949172708, 1.02055662481391018, 100.47956598600620737, 1.75970597295223818 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17516.67146792644052766) <= 1.0e-06);

  }

// Sample number 544
static void test_eye_proposal_mh8() {
  // Input arguments
  double params[] = { 0.92686065744859836, 5.35506798143644858, 0.00179144672312643, 51.51945867949172708, 1.02055662481391018, 100.47956598600620737, 1.75970597295223818 };
  double likelihood = -17516.67146792644052766;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.92686065744859836) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.35506798143644858) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.00179144672312643) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.51945867949172708) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.02055662481391018) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.47956598600620737) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 1.75970597295223818) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 950
static void test_eye_likelihood_mh9() {
  // Input argument
  double params[] = { 0.99138992568443074, 5.32898532618553844, 0.01348597874161318, 51.67398343837417940, 1.01874161051280221, 100.48478847553865023, 1.46539933843588743 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17767.22520857265772065) <= 1.0e-06);

  }

// Sample number 950
static void test_eye_proposal_mh9() {
  // Input arguments
  double params[] = { 0.99138992568443074, 5.32898532618553844, 0.01348597874161318, 51.67398343837417940, 1.01874161051280221, 100.48478847553865023, 1.46539933843588743 };
  double likelihood = -17767.22520857265772065;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.99138992568443074) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.32898532618553844) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.01348597874161318) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.67398343837417940) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.01874161051280221) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.48478847553865023) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 1.46539933843588743) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

// Sample number 957
static void test_eye_likelihood_mh10() {
  // Input argument
  double params[] = { 0.98015161066186762, 5.34696330104500994, 0.00660751003527961, 51.67505467450661172, 1.02759646770741120, 100.51799990877185564, 1.53284193394933888 };
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_eye_likelihood_mh(data, model, params, 7, block, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(reldif(likelihood, -17337.85570346409076592) <= 1.0e-06);

  }

// Sample number 957
static void test_eye_proposal_mh10() {
  // Input arguments
  double params[] = { 0.98015161066186762, 5.34696330104500994, 0.00660751003527961, 51.67505467450661172, 1.02759646770741120, 100.51799990877185564, 1.53284193394933888 };
  double likelihood = -17337.85570346409076592;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05368709120000003;
  size_t block[] = { 0, 1, 2, 3, 4, 5, 6 };
  // Output arguments
  size_t ldc = (7 + 1u) & ~1u;
  double mean[7], covariance[ldc * 7];

  // Call test function
  int error = gmcmc_proposal_mh(7, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT(reldif(mean[0], 0.98015161066186762) <= 1.0e-06);
  CU_ASSERT(reldif(mean[1], 5.34696330104500994) <= 1.0e-06);
  CU_ASSERT(reldif(mean[2], 0.00660751003527961) <= 1.0e-06);
  CU_ASSERT(reldif(mean[3], 51.67505467450661172) <= 1.0e-06);
  CU_ASSERT(reldif(mean[4], 1.02759646770741120) <= 1.0e-06);
  CU_ASSERT(reldif(mean[5], 100.51799990877185564) <= 1.0e-06);
  CU_ASSERT(reldif(mean[6], 1.53284193394933888) <= 1.0e-06);

  // Check covariance
  CU_ASSERT(reldif(covariance[0 * ldc + 0], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[0 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 1], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[1 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 2], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[2 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 3], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[3 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 4], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[4 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 5], 0.00288230376151712) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[5 * ldc + 6], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 0], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 1], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 2], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 3], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 4], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 5], 0.00000000000000000) <= 1.0e-06);
  CU_ASSERT(reldif(covariance[6 * ldc + 6], 0.00288230376151712) <= 1.0e-06);

}

