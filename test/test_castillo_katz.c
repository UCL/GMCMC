// Sample number 4074
static void test_ode_likelihood_castillo_katz1() {
  // Input argument
  double params[] = { 2.17886626201396361, -1.58784585606265449, 0.60532070973143792, 0.73641022071666828 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 566.98965222844685741, 1.0e-06);

  }

// Sample number 4529
static void test_ode_likelihood_castillo_katz2() {
  // Input argument
  double params[] = { 3.68329280836228357, -0.42854413884841391, 0.46594213841265175, 1.78574264412980788 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 942.07464990064681842, 1.0e-06);

  }

// Sample number 635
static void test_ode_likelihood_castillo_katz3() {
  // Input argument
  double params[] = { 0.16083470309156334, 3.28617621688703165, -0.11235718023704777, 1.59999428521550890 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 248.36587238772943920, 1.0e-06);

  }

// Sample number 4565
static void test_ode_likelihood_castillo_katz4() {
  // Input argument
  double params[] = { 0.48792086422527126, 3.57749406050398200, 0.29018868018745181, 2.87050579870546585 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 609.73742647286599095, 1.0e-06);

  }

// Sample number 3160
static void test_ode_likelihood_castillo_katz5() {
  // Input argument
  double params[] = { 1.88250984170422031, -1.98821231358161432, -1.62104445006752984, 0.22124846668569287 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -597.14410301460588926, 1.0e-06);

  }

// Sample number 488
static void test_ode_likelihood_castillo_katz6() {
  // Input argument
  double params[] = { -1.97826695560743748, 0.52008427804280899, 0.30862496697884634, -1.04314594752313239 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -317.96250119943186974, 1.0e-06);

  }

// Sample number 1391
static void test_ode_likelihood_castillo_katz7() {
  // Input argument
  double params[] = { 2.58265577840343052, 2.23549196266726113, 3.26695600203066761, 0.44805479462528597 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1205.41704506350606607, 1.0e-06);

  }

// Sample number 2731
static void test_ode_likelihood_castillo_katz8() {
  // Input argument
  double params[] = { 3.26970776780522332, 1.72140427735894042, 0.86325604195452432, 1.22630751199885313 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 878.08109195961912974, 1.0e-06);

  }

// Sample number 4780
static void test_ode_likelihood_castillo_katz9() {
  // Input argument
  double params[] = { 1.90987846983216536, 3.10835402734556032, 3.59612548597468606, 2.69677917653879140 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1960.87474151075116424, 1.0e-06);

  }

// Sample number 4816
static void test_ode_likelihood_castillo_katz10() {
  // Input argument
  double params[] = { 0.72872641602031463, 1.16150522421731273, 2.37666385227167654, 2.47518999735205814 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1925.31025094468463976, 1.0e-06);

  }

// Sample number 789
static void test_ode_likelihood_castillo_katz11() {
  // Input argument
  double params[] = { 0.95359429344950430, 3.63898918438312924, 2.97744359776669576, 0.40517296679995418 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 769.19115845402018294, 1.0e-06);

  }

// Sample number 789
static void test_ode_proposal_castillo_katz11() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 0.95359429344950430, 3.63898918438312924, 2.97744359776669576, 0.40517296679995418 };
  double likelihood = 769.19115845402018294;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.95359429344950430, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.63898918438312924, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97744359776669576, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 0.40517296679995418, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 4852
static void test_ode_likelihood_castillo_katz12() {
  // Input argument
  double params[] = { 1.30141161502123781, -0.83830411980743635, 1.89779557329563686, 3.19381079866990314 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1829.46306470014405932, 1.0e-06);

  }

// Sample number 4852
static void test_ode_proposal_castillo_katz12() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.30141161502123781, -0.83830411980743635, 1.89779557329563686, 3.19381079866990314 };
  double likelihood = 1829.46306470014405932;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.30141161502123781, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.83830411980743635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.89779557329563686, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.19381079866990314, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 4784
static void test_ode_likelihood_castillo_katz13() {
  // Input argument
  double params[] = { -0.90102790389407006, -1.62204881079200769, 3.35999647520976685, 1.00188688508528356 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1294.25054245320643531, 1.0e-06);

  }

// Sample number 4784
static void test_ode_proposal_castillo_katz13() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -0.90102790389407006, -1.62204881079200769, 3.35999647520976685, 1.00188688508528356 };
  double likelihood = 1294.25054245320643531;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -0.90102790389407006, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -1.62204881079200769, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.35999647520976685, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.00188688508528356, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 2426
static void test_ode_likelihood_castillo_katz14() {
  // Input argument
  double params[] = { 2.83033573092430135, -0.88868048892670881, 3.48482513044685760, -0.34725799134012214 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 642.61060048994932004, 1.0e-06);

  }

// Sample number 2426
static void test_ode_proposal_castillo_katz14() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.83033573092430135, -0.88868048892670881, 3.48482513044685760, -0.34725799134012214 };
  double likelihood = 642.61060048994932004;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.83033573092430135, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.88868048892670881, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.48482513044685760, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.34725799134012214, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 3999
static void test_ode_likelihood_castillo_katz15() {
  // Input argument
  double params[] = { -0.62588703597899764, 2.60805688680769521, 2.74493755007950124, 1.37724040069972942 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1506.90180328241717689, 1.0e-06);

  }

// Sample number 3999
static void test_ode_proposal_castillo_katz15() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -0.62588703597899764, 2.60805688680769521, 2.74493755007950124, 1.37724040069972942 };
  double likelihood = 1506.90180328241717689;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -0.62588703597899764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.60805688680769521, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.74493755007950124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.37724040069972942, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 709
static void test_ode_likelihood_castillo_katz16() {
  // Input argument
  double params[] = { 1.36588605930629381, 2.78209764842010898, 2.72316194357737906, 1.28324861834967785 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1479.24678800558990588, 1.0e-06);

  }

// Sample number 709
static void test_ode_proposal_castillo_katz16() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.36588605930629381, 2.78209764842010898, 2.72316194357737906, 1.28324861834967785 };
  double likelihood = 1479.24678800558990588;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.36588605930629381, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.78209764842010898, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.72316194357737906, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.28324861834967785, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 2107
static void test_ode_likelihood_castillo_katz17() {
  // Input argument
  double params[] = { 0.60560008679169997, 0.75086064517789719, 0.80643231519982406, 2.46603456356606721 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1326.17564339415957875, 1.0e-06);

  }

// Sample number 2107
static void test_ode_proposal_castillo_katz17() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 0.60560008679169997, 0.75086064517789719, 0.80643231519982406, 2.46603456356606721 };
  double likelihood = 1326.17564339415957875;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.60560008679169997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.75086064517789719, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 0.80643231519982406, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.46603456356606721, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 4573
static void test_ode_likelihood_castillo_katz18() {
  // Input argument
  double params[] = { -1.40331044643558367, -1.62952134008675031, 3.08328698898310716, 3.87180564923129911 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1137.75859523920689753, 1.0e-06);

  }

// Sample number 4573
static void test_ode_proposal_castillo_katz18() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -1.40331044643558367, -1.62952134008675031, 3.08328698898310716, 3.87180564923129911 };
  double likelihood = 1137.75859523920689753;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -1.40331044643558367, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -1.62952134008675031, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.08328698898310716, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.87180564923129911, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 3955
static void test_ode_likelihood_castillo_katz19() {
  // Input argument
  double params[] = { -0.08881743164086764, 1.29266739936685937, 0.00175312029713282, 3.03870949815833313 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1063.27133173781385267, 1.0e-06);

  }

// Sample number 3955
static void test_ode_proposal_castillo_katz19() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -0.08881743164086764, 1.29266739936685937, 0.00175312029713282, 3.03870949815833313 };
  double likelihood = 1063.27133173781385267;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -0.08881743164086764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.29266739936685937, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 0.00175312029713282, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.03870949815833313, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 4789
static void test_ode_likelihood_castillo_katz20() {
  // Input argument
  double params[] = { 3.76688348567288100, 2.66343553512386277, 3.18813987724951975, 2.65713933849409090 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1946.84330995289428756, 1.0e-06);

  }

// Sample number 4789
static void test_ode_proposal_castillo_katz20() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.76688348567288100, 2.66343553512386277, 3.18813987724951975, 2.65713933849409090 };
  double likelihood = 1946.84330995289428756;
  double temperature = 0.00001693508780843;
  double stepsize = 1.65888000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.76688348567288100, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.66343553512386277, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.18813987724951975, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.65713933849409090, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.75188285440000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.75188285440000024, 1.0e-06);

}

// Sample number 3279
static void test_ode_likelihood_castillo_katz21() {
  // Input argument
  double params[] = { 2.42793371197200747, 3.21425017254826395, 1.14842261986751559, 0.51925302908999638 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 519.23694118516812068, 1.0e-06);

  }

// Sample number 3279
static void test_ode_proposal_castillo_katz21() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.42793371197200747, 3.21425017254826395, 1.14842261986751559, 0.51925302908999638 };
  double likelihood = 519.23694118516812068;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.42793371197200747, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.21425017254826395, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.14842261986751559, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 0.51925302908999638, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 179
static void test_ode_likelihood_castillo_katz22() {
  // Input argument
  double params[] = { 2.15525467894276002, -1.18968486649032457, 3.23667308247356189, 2.43434512354953370 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1945.35654463692594618, 1.0e-06);

  }

// Sample number 179
static void test_ode_proposal_castillo_katz22() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.15525467894276002, -1.18968486649032457, 3.23667308247356189, 2.43434512354953370 };
  double likelihood = 1945.35654463692594618;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.15525467894276002, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -1.18968486649032457, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.23667308247356189, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.43434512354953370, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 4244
static void test_ode_likelihood_castillo_katz23() {
  // Input argument
  double params[] = { 1.10237839117006287, 3.22718521520390578, 3.63379712932756682, 1.08222727952827391 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1243.53044675194860247, 1.0e-06);

  }

// Sample number 4244
static void test_ode_proposal_castillo_katz23() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.10237839117006287, 3.22718521520390578, 3.63379712932756682, 1.08222727952827391 };
  double likelihood = 1243.53044675194860247;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.10237839117006287, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.22718521520390578, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.63379712932756682, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.08222727952827391, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 4668
static void test_ode_likelihood_castillo_katz24() {
  // Input argument
  double params[] = { 3.12531206069601808, 1.64647698587925229, 2.17134006641438226, 2.02702563969039229 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1714.11457473680002295, 1.0e-06);

  }

// Sample number 4668
static void test_ode_proposal_castillo_katz24() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.12531206069601808, 1.64647698587925229, 2.17134006641438226, 2.02702563969039229 };
  double likelihood = 1714.11457473680002295;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.12531206069601808, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.64647698587925229, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.17134006641438226, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.02702563969039229, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 3391
static void test_ode_likelihood_castillo_katz25() {
  // Input argument
  double params[] = { 0.25188040951522428, 2.93845526963726078, 2.07539997781542684, 2.73320068244714376 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1713.97538205803789424, 1.0e-06);

  }

// Sample number 3391
static void test_ode_proposal_castillo_katz25() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 0.25188040951522428, 2.93845526963726078, 2.07539997781542684, 2.73320068244714376 };
  double likelihood = 1713.97538205803789424;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.25188040951522428, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.93845526963726078, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.07539997781542684, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.73320068244714376, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 3785
static void test_ode_likelihood_castillo_katz26() {
  // Input argument
  double params[] = { -1.33079363780482729, -1.11047032725935013, 1.68669637101696956, 0.21067482230476253 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 789.08725325501950465, 1.0e-06);

  }

// Sample number 3785
static void test_ode_proposal_castillo_katz26() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -1.33079363780482729, -1.11047032725935013, 1.68669637101696956, 0.21067482230476253 };
  double likelihood = 789.08725325501950465;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -1.33079363780482729, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -1.11047032725935013, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.68669637101696956, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 0.21067482230476253, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 3712
static void test_ode_likelihood_castillo_katz27() {
  // Input argument
  double params[] = { 2.77947755726233137, -0.59090413932127006, 3.15642278583369107, 2.62390477150223678 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1982.61727764732381729, 1.0e-06);

  }

// Sample number 3712
static void test_ode_proposal_castillo_katz27() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.77947755726233137, -0.59090413932127006, 3.15642278583369107, 2.62390477150223678 };
  double likelihood = 1982.61727764732381729;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.77947755726233137, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.59090413932127006, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.15642278583369107, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.62390477150223678, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 1959
static void test_ode_likelihood_castillo_katz28() {
  // Input argument
  double params[] = { 3.34544107207106478, 2.20421042180817839, 2.06017282832949711, 0.44986731491422027 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1021.69350725656454415, 1.0e-06);

  }

// Sample number 1959
static void test_ode_proposal_castillo_katz28() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.34544107207106478, 2.20421042180817839, 2.06017282832949711, 0.44986731491422027 };
  double likelihood = 1021.69350725656454415;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.34544107207106478, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.20421042180817839, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.06017282832949711, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 0.44986731491422027, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 3273
static void test_ode_likelihood_castillo_katz29() {
  // Input argument
  double params[] = { -1.72568186943392510, -0.74658733302203761, 1.90085863257200405, 0.17770594882677493 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 856.21572027262925531, 1.0e-06);

  }

// Sample number 3273
static void test_ode_proposal_castillo_katz29() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -1.72568186943392510, -0.74658733302203761, 1.90085863257200405, 0.17770594882677493 };
  double likelihood = 856.21572027262925531;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -1.72568186943392510, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.74658733302203761, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.90085863257200405, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 0.17770594882677493, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 855
static void test_ode_likelihood_castillo_katz30() {
  // Input argument
  double params[] = { 2.00275690871936263, 0.35534173475996667, 1.06129497848244725, 2.49666318782307251 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1443.97970247690636825, 1.0e-06);

  }

// Sample number 855
static void test_ode_proposal_castillo_katz30() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.00275690871936263, 0.35534173475996667, 1.06129497848244725, 2.49666318782307251 };
  double likelihood = 1443.97970247690636825;
  double temperature = 0.00054192280986977;
  double stepsize = 1.43999999999999995;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.00275690871936263, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.35534173475996667, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.06129497848244725, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.49666318782307251, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.07359999999999989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 2.07359999999999989, 1.0e-06);

}

// Sample number 3531
static void test_ode_likelihood_castillo_katz31() {
  // Input argument
  double params[] = { 1.02267757399772719, -0.78441905701845105, 1.50893740175523394, 3.17599557960296464 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1682.92627256599325847, 1.0e-06);

  }

// Sample number 3531
static void test_ode_proposal_castillo_katz31() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.02267757399772719, -0.78441905701845105, 1.50893740175523394, 3.17599557960296464 };
  double likelihood = 1682.92627256599325847;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.02267757399772719, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.78441905701845105, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.50893740175523394, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.17599557960296464, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 160
static void test_ode_likelihood_castillo_katz32() {
  // Input argument
  double params[] = { 0.83489227445781711, 0.42507380521113175, 2.47747373152113548, 3.34540090071051299 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1944.50905035589380532, 1.0e-06);

  }

// Sample number 160
static void test_ode_proposal_castillo_katz32() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 0.83489227445781711, 0.42507380521113175, 2.47747373152113548, 3.34540090071051299 };
  double likelihood = 1944.50905035589380532;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.83489227445781711, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.42507380521113175, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.47747373152113548, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.34540090071051299, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 1385
static void test_ode_likelihood_castillo_katz33() {
  // Input argument
  double params[] = { -0.12242931569291970, 2.44791323712543285, 3.03580146612118273, 1.55608315289909682 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1638.49469423049458783, 1.0e-06);

  }

// Sample number 1385
static void test_ode_proposal_castillo_katz33() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -0.12242931569291970, 2.44791323712543285, 3.03580146612118273, 1.55608315289909682 };
  double likelihood = 1638.49469423049458783;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -0.12242931569291970, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.44791323712543285, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.03580146612118273, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.55608315289909682, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 231
static void test_ode_likelihood_castillo_katz34() {
  // Input argument
  double params[] = { 1.23524189759001768, -1.38766357049144662, 2.27829225769304866, 2.73454877533553598 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1963.88094605108494761, 1.0e-06);

  }

// Sample number 231
static void test_ode_proposal_castillo_katz34() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.23524189759001768, -1.38766357049144662, 2.27829225769304866, 2.73454877533553598 };
  double likelihood = 1963.88094605108494761;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.23524189759001768, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -1.38766357049144662, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.27829225769304866, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.73454877533553598, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 486
static void test_ode_likelihood_castillo_katz35() {
  // Input argument
  double params[] = { 3.98365185058539062, 1.81207166179309942, 2.88681774684024095, 2.73563838372907941 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2045.80462259813270975, 1.0e-06);

  }

// Sample number 486
static void test_ode_proposal_castillo_katz35() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.98365185058539062, 1.81207166179309942, 2.88681774684024095, 2.73563838372907941 };
  double likelihood = 2045.80462259813270975;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.98365185058539062, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.81207166179309942, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.88681774684024095, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.73563838372907941, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 4114
static void test_ode_likelihood_castillo_katz36() {
  // Input argument
  double params[] = { 3.01905438171786500, 2.28789802566952583, 2.98617573109686463, 1.86119898855495358 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1782.11631318036347693, 1.0e-06);

  }

// Sample number 4114
static void test_ode_proposal_castillo_katz36() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.01905438171786500, 2.28789802566952583, 2.98617573109686463, 1.86119898855495358 };
  double likelihood = 1782.11631318036347693;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.01905438171786500, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.28789802566952583, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98617573109686463, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.86119898855495358, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 3470
static void test_ode_likelihood_castillo_katz37() {
  // Input argument
  double params[] = { 3.74575387022758211, 2.64464256397173658, 1.48724429922745749, 2.60340677948132537 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1636.56568695567716532, 1.0e-06);

  }

// Sample number 3470
static void test_ode_proposal_castillo_katz37() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.74575387022758211, 2.64464256397173658, 1.48724429922745749, 2.60340677948132537 };
  double likelihood = 1636.56568695567716532;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.74575387022758211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.64464256397173658, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.48724429922745749, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.60340677948132537, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 1584
static void test_ode_likelihood_castillo_katz38() {
  // Input argument
  double params[] = { 2.19921593418499084, -0.06745478233921254, 3.39770890780546608, 1.98982148811724180 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1750.85760958768787532, 1.0e-06);

  }

// Sample number 1584
static void test_ode_proposal_castillo_katz38() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.19921593418499084, -0.06745478233921254, 3.39770890780546608, 1.98982148811724180 };
  double likelihood = 1750.85760958768787532;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.19921593418499084, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.06745478233921254, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.39770890780546608, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.98982148811724180, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 4744
static void test_ode_likelihood_castillo_katz39() {
  // Input argument
  double params[] = { -1.09005077314019694, 1.12180559264180801, 3.39391340946635989, 1.90176525089134763 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1690.14172261730618629, 1.0e-06);

  }

// Sample number 4744
static void test_ode_proposal_castillo_katz39() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -1.09005077314019694, 1.12180559264180801, 3.39391340946635989, 1.90176525089134763 };
  double likelihood = 1690.14172261730618629;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -1.09005077314019694, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.12180559264180801, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.39391340946635989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.90176525089134763, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 172
static void test_ode_likelihood_castillo_katz40() {
  // Input argument
  double params[] = { 0.24430725974962875, 1.50962367822653887, 2.89720621509348986, 2.35027037413052220 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1971.78900274522538894, 1.0e-06);

  }

// Sample number 172
static void test_ode_proposal_castillo_katz40() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 0.24430725974962875, 1.50962367822653887, 2.89720621509348986, 2.35027037413052220 };
  double likelihood = 1971.78900274522538894;
  double temperature = 0.00411522633744856;
  double stepsize = 0.76800000000000013;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.24430725974962875, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.50962367822653887, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.89720621509348986, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.35027037413052220, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.58982400000000024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.58982400000000024, 1.0e-06);

}

// Sample number 2194
static void test_ode_likelihood_castillo_katz41() {
  // Input argument
  double params[] = { 0.13795743185957182, 1.72208212388224702, 3.01278501217685957, 2.73229096779624614 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2072.12926726186060478, 1.0e-06);

  }

// Sample number 2194
static void test_ode_proposal_castillo_katz41() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 0.13795743185957182, 1.72208212388224702, 3.01278501217685957, 2.73229096779624614 };
  double likelihood = 2072.12926726186060478;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.13795743185957182, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.72208212388224702, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.01278501217685957, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.73229096779624614, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 1908
static void test_ode_likelihood_castillo_katz42() {
  // Input argument
  double params[] = { -1.52132636266590282, -1.41053905161039106, 2.57105523734081709, 2.80159999116089198 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2042.62891317743469699, 1.0e-06);

  }

// Sample number 1908
static void test_ode_proposal_castillo_katz42() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -1.52132636266590282, -1.41053905161039106, 2.57105523734081709, 2.80159999116089198 };
  double likelihood = 2042.62891317743469699;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -1.52132636266590282, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -1.41053905161039106, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.57105523734081709, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.80159999116089198, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 3827
static void test_ode_likelihood_castillo_katz43() {
  // Input argument
  double params[] = { 2.12945382263463046, 2.53672689258746598, 3.04590541615281118, 3.13898327548605716 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2096.37505134920684213, 1.0e-06);

  }

// Sample number 3827
static void test_ode_proposal_castillo_katz43() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.12945382263463046, 2.53672689258746598, 3.04590541615281118, 3.13898327548605716 };
  double likelihood = 2096.37505134920684213;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.12945382263463046, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.53672689258746598, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.04590541615281118, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.13898327548605716, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 3974
static void test_ode_likelihood_castillo_katz44() {
  // Input argument
  double params[] = { -1.40172270457151860, 2.46149997636754314, 3.41056804794292789, 2.80845276780125408 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1927.85333471772605662, 1.0e-06);

  }

// Sample number 3974
static void test_ode_proposal_castillo_katz44() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -1.40172270457151860, 2.46149997636754314, 3.41056804794292789, 2.80845276780125408 };
  double likelihood = 1927.85333471772605662;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -1.40172270457151860, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.46149997636754314, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.41056804794292789, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.80845276780125408, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 934
static void test_ode_likelihood_castillo_katz45() {
  // Input argument
  double params[] = { 2.31857422755878506, 0.96082138394262939, 2.94661726926623491, 2.60733316767470713 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2057.90941501305132988, 1.0e-06);

  }

// Sample number 934
static void test_ode_proposal_castillo_katz45() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.31857422755878506, 0.96082138394262939, 2.94661726926623491, 2.60733316767470713 };
  double likelihood = 2057.90941501305132988;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.31857422755878506, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.96082138394262939, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.94661726926623491, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.60733316767470713, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 2447
static void test_ode_likelihood_castillo_katz46() {
  // Input argument
  double params[] = { 1.13279540860035155, -0.30682027022224362, 2.56159408496540308, 2.95469301038337750 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2055.05545057513336360, 1.0e-06);

  }

// Sample number 2447
static void test_ode_proposal_castillo_katz46() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.13279540860035155, -0.30682027022224362, 2.56159408496540308, 2.95469301038337750 };
  double likelihood = 2055.05545057513336360;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.13279540860035155, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.30682027022224362, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.56159408496540308, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.95469301038337750, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 2226
static void test_ode_likelihood_castillo_katz47() {
  // Input argument
  double params[] = { 3.10633414295248311, 2.27183622733674362, 3.23428181898053602, 3.01454629381381434 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2027.43484594305050450, 1.0e-06);

  }

// Sample number 2226
static void test_ode_proposal_castillo_katz47() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.10633414295248311, 2.27183622733674362, 3.23428181898053602, 3.01454629381381434 };
  double likelihood = 2027.43484594305050450;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.10633414295248311, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.27183622733674362, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.23428181898053602, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.01454629381381434, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 3228
static void test_ode_likelihood_castillo_katz48() {
  // Input argument
  double params[] = { 2.82609109476070408, -1.23300754302382232, 2.68169789796709779, 2.45198127950493738 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 1977.72570763493308732, 1.0e-06);

  }

// Sample number 3228
static void test_ode_proposal_castillo_katz48() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.82609109476070408, -1.23300754302382232, 2.68169789796709779, 2.45198127950493738 };
  double likelihood = 1977.72570763493308732;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.82609109476070408, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -1.23300754302382232, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.68169789796709779, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.45198127950493738, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 3542
static void test_ode_likelihood_castillo_katz49() {
  // Input argument
  double params[] = { 3.52684759680419635, -0.22469469275653631, 2.94909099527047314, 2.94976515864563948 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2058.28452432701078578, 1.0e-06);

  }

// Sample number 3542
static void test_ode_proposal_castillo_katz49() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.52684759680419635, -0.22469469275653631, 2.94909099527047314, 2.94976515864563948 };
  double likelihood = 2058.28452432701078578;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.52684759680419635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.22469469275653631, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.94909099527047314, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.94976515864563948, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 3767
static void test_ode_likelihood_castillo_katz50() {
  // Input argument
  double params[] = { 2.50488532012680620, 1.59548358763028819, 2.75597262116019692, 2.86711544907164084 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2087.33971790925806999, 1.0e-06);

  }

// Sample number 3767
static void test_ode_proposal_castillo_katz50() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.50488532012680620, 1.59548358763028819, 2.75597262116019692, 2.86711544907164084 };
  double likelihood = 2087.33971790925806999;
  double temperature = 0.01734152991583261;
  double stepsize = 0.49152000000000012;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.50488532012680620, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.59548358763028819, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.75597262116019692, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.86711544907164084, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24159191040000011, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.24159191040000011, 1.0e-06);

}

// Sample number 1381
static void test_ode_likelihood_castillo_katz51() {
  // Input argument
  double params[] = { 1.52507397908904840, 1.37227148908305052, 2.88247195112426446, 3.05278593798938402 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2109.82190168545776032, 1.0e-06);

  }

// Sample number 1381
static void test_ode_proposal_castillo_katz51() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.52507397908904840, 1.37227148908305052, 2.88247195112426446, 3.05278593798938402 };
  double likelihood = 2109.82190168545776032;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.52507397908904840, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.37227148908305052, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.88247195112426446, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.05278593798938402, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 3398
static void test_ode_likelihood_castillo_katz52() {
  // Input argument
  double params[] = { 2.82072879082207528, 1.07236142276940738, 2.54776322042963477, 2.88599912024983229 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2048.49409562478922453, 1.0e-06);

  }

// Sample number 3398
static void test_ode_proposal_castillo_katz52() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.82072879082207528, 1.07236142276940738, 2.54776322042963477, 2.88599912024983229 };
  double likelihood = 2048.49409562478922453;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.82072879082207528, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.07236142276940738, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.54776322042963477, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.88599912024983229, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 3275
static void test_ode_likelihood_castillo_katz53() {
  // Input argument
  double params[] = { 1.77703372477445010, 3.05315023565818722, 3.35973736005284751, 2.96307546048066062 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2028.38451788820884758, 1.0e-06);

  }

// Sample number 3275
static void test_ode_proposal_castillo_katz53() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.77703372477445010, 3.05315023565818722, 3.35973736005284751, 2.96307546048066062 };
  double likelihood = 2028.38451788820884758;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.77703372477445010, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.05315023565818722, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.35973736005284751, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.96307546048066062, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 813
static void test_ode_likelihood_castillo_katz54() {
  // Input argument
  double params[] = { 2.32546293289630901, 0.84829227750844693, 2.77967437366291525, 2.88661534746216786 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2089.15653258089332667, 1.0e-06);

  }

// Sample number 813
static void test_ode_proposal_castillo_katz54() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.32546293289630901, 0.84829227750844693, 2.77967437366291525, 2.88661534746216786 };
  double likelihood = 2089.15653258089332667;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.32546293289630901, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.84829227750844693, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.77967437366291525, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.88661534746216786, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 595
static void test_ode_likelihood_castillo_katz55() {
  // Input argument
  double params[] = { 3.03054256205518868, 3.25119242556124499, 3.24345905017430969, 2.65278694216293687 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2052.53643718991588685, 1.0e-06);

  }

// Sample number 595
static void test_ode_proposal_castillo_katz55() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.03054256205518868, 3.25119242556124499, 3.24345905017430969, 2.65278694216293687 };
  double likelihood = 2052.53643718991588685;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.03054256205518868, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.25119242556124499, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.24345905017430969, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.65278694216293687, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 2490
static void test_ode_likelihood_castillo_katz56() {
  // Input argument
  double params[] = { 1.95122544714705692, 1.45389425641829795, 3.06960519742416871, 3.09008109395090047 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2113.79758474042364469, 1.0e-06);

  }

// Sample number 2490
static void test_ode_proposal_castillo_katz56() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.95122544714705692, 1.45389425641829795, 3.06960519742416871, 3.09008109395090047 };
  double likelihood = 2113.79758474042364469;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.95122544714705692, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.45389425641829795, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.06960519742416871, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.09008109395090047, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 4793
static void test_ode_likelihood_castillo_katz57() {
  // Input argument
  double params[] = { 3.81325649124902455, 3.92132799859706971, 3.13430130960630082, 3.07394002106609143 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2070.34536434505071156, 1.0e-06);

  }

// Sample number 4793
static void test_ode_proposal_castillo_katz57() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 3.81325649124902455, 3.92132799859706971, 3.13430130960630082, 3.07394002106609143 };
  double likelihood = 2070.34536434505071156;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.81325649124902455, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.92132799859706971, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.13430130960630082, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.07394002106609143, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 1700
static void test_ode_likelihood_castillo_katz58() {
  // Input argument
  double params[] = { 2.00920641201294004, -0.28320989349602099, 3.33776737882178365, 2.87460847828901844 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2025.01028523586501251, 1.0e-06);

  }

// Sample number 1700
static void test_ode_proposal_castillo_katz58() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.00920641201294004, -0.28320989349602099, 3.33776737882178365, 2.87460847828901844 };
  double likelihood = 2025.01028523586501251;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.00920641201294004, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.28320989349602099, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.33776737882178365, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.87460847828901844, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 2922
static void test_ode_likelihood_castillo_katz59() {
  // Input argument
  double params[] = { -0.11890354137325920, 0.85729344691610476, 2.95210990970721676, 2.91195139834494654 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2085.54673314389174266, 1.0e-06);

  }

// Sample number 2922
static void test_ode_proposal_castillo_katz59() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -0.11890354137325920, 0.85729344691610476, 2.95210990970721676, 2.91195139834494654 };
  double likelihood = 2085.54673314389174266;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -0.11890354137325920, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.85729344691610476, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.95210990970721676, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.91195139834494654, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 1118
static void test_ode_likelihood_castillo_katz60() {
  // Input argument
  double params[] = { -0.73144489725539508, -1.78089074455790186, 2.61339588558399960, 2.81487626445962169 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2051.29987115338826698, 1.0e-06);

  }

// Sample number 1118
static void test_ode_proposal_castillo_katz60() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -0.73144489725539508, -1.78089074455790186, 2.61339588558399960, 2.81487626445962169 };
  double likelihood = 2051.29987115338826698;
  double temperature = 0.05292214940134465;
  double stepsize = 0.25165824000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -0.73144489725539508, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -1.78089074455790186, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.61339588558399960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.81487626445962169, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.06333186975989764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.06333186975989764, 1.0e-06);

}

// Sample number 3757
static void test_ode_likelihood_castillo_katz61() {
  // Input argument
  double params[] = { 1.85256797981108923, 1.41154469320905651, 3.03717305468266119, 2.96321398526293800 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2121.82552216456087990, 1.0e-06);

  }

// Sample number 3757
static void test_ode_proposal_castillo_katz61() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.85256797981108923, 1.41154469320905651, 3.03717305468266119, 2.96321398526293800 };
  double likelihood = 2121.82552216456087990;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.85256797981108923, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.41154469320905651, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.03717305468266119, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.96321398526293800, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 1276
static void test_ode_likelihood_castillo_katz62() {
  // Input argument
  double params[] = { 1.63175533228996761, 1.17350195831211690, 2.98801228083502268, 2.79263633746071038 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2104.03418550082233196, 1.0e-06);

  }

// Sample number 1276
static void test_ode_proposal_castillo_katz62() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.63175533228996761, 1.17350195831211690, 2.98801228083502268, 2.79263633746071038 };
  double likelihood = 2104.03418550082233196;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.63175533228996761, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.17350195831211690, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98801228083502268, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.79263633746071038, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 2529
static void test_ode_likelihood_castillo_katz63() {
  // Input argument
  double params[] = { 2.04226933614559236, 1.13007456379947535, 3.06193539901226153, 2.95760283461169893 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2116.13721566345611791, 1.0e-06);

  }

// Sample number 2529
static void test_ode_proposal_castillo_katz63() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.04226933614559236, 1.13007456379947535, 3.06193539901226153, 2.95760283461169893 };
  double likelihood = 2116.13721566345611791;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.04226933614559236, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.13007456379947535, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.06193539901226153, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.95760283461169893, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 3494
static void test_ode_likelihood_castillo_katz64() {
  // Input argument
  double params[] = { 1.69975807486922914, 1.75945487719899241, 3.06489617920055846, 3.05574643131708212 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2119.05564642407853171, 1.0e-06);

  }

// Sample number 3494
static void test_ode_proposal_castillo_katz64() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.69975807486922914, 1.75945487719899241, 3.06489617920055846, 3.05574643131708212 };
  double likelihood = 2119.05564642407853171;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.69975807486922914, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.75945487719899241, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.06489617920055846, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.05574643131708212, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 4451
static void test_ode_likelihood_castillo_katz65() {
  // Input argument
  double params[] = { 1.73307661901957766, 1.79045311418456743, 3.12091672427122058, 2.99892662257603337 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2119.47568509262146108, 1.0e-06);

  }

// Sample number 4451
static void test_ode_proposal_castillo_katz65() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.73307661901957766, 1.79045311418456743, 3.12091672427122058, 2.99892662257603337 };
  double likelihood = 2119.47568509262146108;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.73307661901957766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.79045311418456743, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.12091672427122058, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.99892662257603337, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 4792
static void test_ode_likelihood_castillo_katz66() {
  // Input argument
  double params[] = { 1.01096042602591796, 1.49381556262217563, 2.99734398811358060, 2.98431888545948931 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2112.09519952863638537, 1.0e-06);

  }

// Sample number 4792
static void test_ode_proposal_castillo_katz66() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.01096042602591796, 1.49381556262217563, 2.99734398811358060, 2.98431888545948931 };
  double likelihood = 2112.09519952863638537;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.01096042602591796, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.49381556262217563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99734398811358060, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.98431888545948931, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 2733
static void test_ode_likelihood_castillo_katz67() {
  // Input argument
  double params[] = { 1.53399300869315591, 1.43170219637626794, 3.01007345823356287, 2.87053776827384466 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2115.24494986613444780, 1.0e-06);

  }

// Sample number 2733
static void test_ode_proposal_castillo_katz67() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.53399300869315591, 1.43170219637626794, 3.01007345823356287, 2.87053776827384466 };
  double likelihood = 2115.24494986613444780;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.53399300869315591, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.43170219637626794, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.01007345823356287, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.87053776827384466, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 693
static void test_ode_likelihood_castillo_katz68() {
  // Input argument
  double params[] = { 2.17453131473513128, 1.55879995008406635, 3.07328878990620380, 2.86497971335429158 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2115.54045271112636328, 1.0e-06);

  }

// Sample number 693
static void test_ode_proposal_castillo_katz68() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.17453131473513128, 1.55879995008406635, 3.07328878990620380, 2.86497971335429158 };
  double likelihood = 2115.54045271112636328;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.17453131473513128, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.55879995008406635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.07328878990620380, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.86497971335429158, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 746
static void test_ode_likelihood_castillo_katz69() {
  // Input argument
  double params[] = { 2.24176382296921384, 2.51045472510272738, 2.87293516291052553, 2.95960195917660362 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2100.35477510261262069, 1.0e-06);

  }

// Sample number 746
static void test_ode_proposal_castillo_katz69() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.24176382296921384, 2.51045472510272738, 2.87293516291052553, 2.95960195917660362 };
  double likelihood = 2100.35477510261262069;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.24176382296921384, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.51045472510272738, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.87293516291052553, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.95960195917660362, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 1286
static void test_ode_likelihood_castillo_katz70() {
  // Input argument
  double params[] = { -0.47490246298207534, -0.56929010419631632, 2.87965336326469989, 3.08265088731110737 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2070.58012422868296198, 1.0e-06);

  }

// Sample number 1286
static void test_ode_proposal_castillo_katz70() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { -0.47490246298207534, -0.56929010419631632, 2.87965336326469989, 3.08265088731110737 };
  double likelihood = 2070.58012422868296198;
  double temperature = 0.13168724279835398;
  double stepsize = 0.16777216000000009;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], -0.47490246298207534, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], -0.56929010419631632, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.87965336326469989, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.08265088731110737, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02814749767106563, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.02814749767106563, 1.0e-06);

}

// Sample number 4204
static void test_ode_likelihood_castillo_katz71() {
  // Input argument
  double params[] = { 2.42923883390011497, 2.08634411748182202, 3.08503384713113604, 2.97913669378615875 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2119.27786973365391532, 1.0e-06);

  }

// Sample number 4204
static void test_ode_proposal_castillo_katz71() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.42923883390011497, 2.08634411748182202, 3.08503384713113604, 2.97913669378615875 };
  double likelihood = 2119.27786973365391532;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.42923883390011497, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.08634411748182202, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.08503384713113604, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.97913669378615875, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 1272
static void test_ode_likelihood_castillo_katz72() {
  // Input argument
  double params[] = { 2.28710704473900472, 1.88967438882472671, 3.11262512624736898, 3.05050261452560578 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2116.96677654422455817, 1.0e-06);

  }

// Sample number 1272
static void test_ode_proposal_castillo_katz72() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.28710704473900472, 1.88967438882472671, 3.11262512624736898, 3.05050261452560578 };
  double likelihood = 2116.96677654422455817;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.28710704473900472, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.88967438882472671, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.11262512624736898, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.05050261452560578, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 4070
static void test_ode_likelihood_castillo_katz73() {
  // Input argument
  double params[] = { 1.89043901386965896, 1.53241000616031231, 2.99430543507110558, 2.92540628604908237 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2122.29064825081513845, 1.0e-06);

  }

// Sample number 4070
static void test_ode_proposal_castillo_katz73() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.89043901386965896, 1.53241000616031231, 2.99430543507110558, 2.92540628604908237 };
  double likelihood = 2122.29064825081513845;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.89043901386965896, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.53241000616031231, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99430543507110558, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.92540628604908237, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 1217
static void test_ode_likelihood_castillo_katz74() {
  // Input argument
  double params[] = { 2.11275608267683213, 2.12905898119326586, 3.02182839427778527, 2.86007548871576489 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2118.58141445124510938, 1.0e-06);

  }

// Sample number 1217
static void test_ode_proposal_castillo_katz74() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.11275608267683213, 2.12905898119326586, 3.02182839427778527, 2.86007548871576489 };
  double likelihood = 2118.58141445124510938;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.11275608267683213, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.12905898119326586, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.02182839427778527, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.86007548871576489, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 4643
static void test_ode_likelihood_castillo_katz75() {
  // Input argument
  double params[] = { 2.16784888229838213, 1.90514216712827977, 3.04034174696816528, 3.01737065637107760 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2123.74845397386161494, 1.0e-06);

  }

// Sample number 4643
static void test_ode_proposal_castillo_katz75() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.16784888229838213, 1.90514216712827977, 3.04034174696816528, 3.01737065637107760 };
  double likelihood = 2123.74845397386161494;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.16784888229838213, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.90514216712827977, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.04034174696816528, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.01737065637107760, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 1749
static void test_ode_likelihood_castillo_katz76() {
  // Input argument
  double params[] = { 2.33344621618213122, 2.04421927887290611, 3.14993277522704496, 2.97162030634164198 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2117.72756819124788308, 1.0e-06);

  }

// Sample number 1749
static void test_ode_proposal_castillo_katz76() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.33344621618213122, 2.04421927887290611, 3.14993277522704496, 2.97162030634164198 };
  double likelihood = 2117.72756819124788308;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.33344621618213122, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.04421927887290611, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.14993277522704496, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.97162030634164198, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 982
static void test_ode_likelihood_castillo_katz77() {
  // Input argument
  double params[] = { 1.55768795089696677, 2.02668656367948286, 3.02804061121471157, 2.95979926262123527 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2119.66039873690442619, 1.0e-06);

  }

// Sample number 982
static void test_ode_proposal_castillo_katz77() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.55768795089696677, 2.02668656367948286, 3.02804061121471157, 2.95979926262123527 };
  double likelihood = 2119.66039873690442619;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.55768795089696677, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.02668656367948286, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.02804061121471157, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.95979926262123527, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 1254
static void test_ode_likelihood_castillo_katz78() {
  // Input argument
  double params[] = { 1.97502824651687692, 1.76535887314507534, 2.99392627103950204, 2.98411932372469124 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2124.78433314770290963, 1.0e-06);

  }

// Sample number 1254
static void test_ode_proposal_castillo_katz78() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.97502824651687692, 1.76535887314507534, 2.99392627103950204, 2.98411932372469124 };
  double likelihood = 2124.78433314770290963;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.97502824651687692, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.76535887314507534, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99392627103950204, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.98411932372469124, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 3076
static void test_ode_likelihood_castillo_katz79() {
  // Input argument
  double params[] = { 2.35647970292696796, 2.07876273077885987, 3.10405344347412671, 3.03141271811471791 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2118.73281629972188966, 1.0e-06);

  }

// Sample number 3076
static void test_ode_proposal_castillo_katz79() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.35647970292696796, 2.07876273077885987, 3.10405344347412671, 3.03141271811471791 };
  double likelihood = 2118.73281629972188966;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.35647970292696796, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.07876273077885987, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.10405344347412671, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.03141271811471791, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 2363
static void test_ode_likelihood_castillo_katz80() {
  // Input argument
  double params[] = { 1.66951897525802195, 1.89926470779609557, 3.02642053940309319, 3.02491300613235570 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2121.36549057158981668, 1.0e-06);

  }

// Sample number 2363
static void test_ode_proposal_castillo_katz80() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.66951897525802195, 1.89926470779609557, 3.02642053940309319, 3.02491300613235570 };
  double likelihood = 2121.36549057158981668;
  double temperature = 0.28462802079628785;
  double stepsize = 0.10307921510400006;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.66951897525802195, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.89926470779609557, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.02642053940309319, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.02491300613235570, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01062532458645672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.01062532458645672, 1.0e-06);

}

// Sample number 1759
static void test_ode_likelihood_castillo_katz81() {
  // Input argument
  double params[] = { 2.35229307781132491, 2.00031327977380924, 2.93371561566289785, 3.01530851362161645 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2117.35872024678201342, 1.0e-06);

  }

// Sample number 1759
static void test_ode_proposal_castillo_katz81() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.35229307781132491, 2.00031327977380924, 2.93371561566289785, 3.01530851362161645 };
  double likelihood = 2117.35872024678201342;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.35229307781132491, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.00031327977380924, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.93371561566289785, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.01530851362161645, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 4154
static void test_ode_likelihood_castillo_katz82() {
  // Input argument
  double params[] = { 2.16927570429708894, 1.94188729019292450, 3.02973165442418502, 2.99009523146500955 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2124.72870147306457511, 1.0e-06);

  }

// Sample number 4154
static void test_ode_proposal_castillo_katz82() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.16927570429708894, 1.94188729019292450, 3.02973165442418502, 2.99009523146500955 };
  double likelihood = 2124.72870147306457511;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.16927570429708894, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.94188729019292450, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.02973165442418502, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.99009523146500955, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 2926
static void test_ode_likelihood_castillo_katz83() {
  // Input argument
  double params[] = { 1.94517185008831661, 1.92069529649457671, 3.07225102814630135, 2.94262989309345224 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2124.27796701577244676, 1.0e-06);

  }

// Sample number 2926
static void test_ode_proposal_castillo_katz83() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.94517185008831661, 1.92069529649457671, 3.07225102814630135, 2.94262989309345224 };
  double likelihood = 2124.27796701577244676;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.94517185008831661, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.92069529649457671, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.07225102814630135, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.94262989309345224, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 2747
static void test_ode_likelihood_castillo_katz84() {
  // Input argument
  double params[] = { 2.14658108109831547, 1.50778134479204806, 2.96116936341911741, 3.00751506402231339 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2119.96468149022439320, 1.0e-06);

  }

// Sample number 2747
static void test_ode_proposal_castillo_katz84() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.14658108109831547, 1.50778134479204806, 2.96116936341911741, 3.00751506402231339 };
  double likelihood = 2119.96468149022439320;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.14658108109831547, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.50778134479204806, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.96116936341911741, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.00751506402231339, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 4583
static void test_ode_likelihood_castillo_katz85() {
  // Input argument
  double params[] = { 2.34418304734456928, 1.93581621513299673, 3.01885700976442983, 3.01637210316668680 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2120.75052075654230066, 1.0e-06);

  }

// Sample number 4583
static void test_ode_proposal_castillo_katz85() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.34418304734456928, 1.93581621513299673, 3.01885700976442983, 3.01637210316668680 };
  double likelihood = 2120.75052075654230066;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.34418304734456928, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.93581621513299673, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.01885700976442983, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.01637210316668680, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 1428
static void test_ode_likelihood_castillo_katz86() {
  // Input argument
  double params[] = { 1.82811448332191451, 1.78785660441178851, 2.97917470693538533, 3.04729844007214457 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2120.91604204942041179, 1.0e-06);

  }

// Sample number 1428
static void test_ode_proposal_castillo_katz86() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.82811448332191451, 1.78785660441178851, 2.97917470693538533, 3.04729844007214457 };
  double likelihood = 2120.91604204942041179;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.82811448332191451, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.78785660441178851, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97917470693538533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.04729844007214457, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 3782
static void test_ode_likelihood_castillo_katz87() {
  // Input argument
  double params[] = { 2.17075982108396337, 1.95702501812284591, 2.98208867913115316, 2.95562089808841577 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2123.74610208219246488, 1.0e-06);

  }

// Sample number 3782
static void test_ode_proposal_castillo_katz87() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.17075982108396337, 1.95702501812284591, 2.98208867913115316, 2.95562089808841577 };
  double likelihood = 2123.74610208219246488;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.17075982108396337, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.95702501812284591, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98208867913115316, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.95562089808841577, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 3764
static void test_ode_likelihood_castillo_katz88() {
  // Input argument
  double params[] = { 2.00308886527824281, 2.07089584030814233, 2.99367927780125642, 2.87138207877097296 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2119.28449147906121652, 1.0e-06);

  }

// Sample number 3764
static void test_ode_proposal_castillo_katz88() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.00308886527824281, 2.07089584030814233, 2.99367927780125642, 2.87138207877097296 };
  double likelihood = 2119.28449147906121652;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.00308886527824281, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.07089584030814233, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99367927780125642, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.87138207877097296, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 1900
static void test_ode_likelihood_castillo_katz89() {
  // Input argument
  double params[] = { 1.36180171301039543, 1.75341740550093173, 3.03510007439995633, 2.96639436953322733 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2118.60865921165441250, 1.0e-06);

  }

// Sample number 1900
static void test_ode_proposal_castillo_katz89() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.36180171301039543, 1.75341740550093173, 3.03510007439995633, 2.96639436953322733 };
  double likelihood = 2118.60865921165441250;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.36180171301039543, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.75341740550093173, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.03510007439995633, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.96639436953322733, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 2834
static void test_ode_likelihood_castillo_katz90() {
  // Input argument
  double params[] = { 1.79433727338013393, 1.41920753071445072, 2.97594358026122752, 2.95217912172607644 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2121.27272621367683314, 1.0e-06);

  }

// Sample number 2834
static void test_ode_proposal_castillo_katz90() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.79433727338013393, 1.41920753071445072, 2.97594358026122752, 2.95217912172607644 };
  double likelihood = 2121.27272621367683314;
  double temperature = 0.55492895730664349;
  double stepsize = 0.06871947673600004;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.79433727338013393, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.41920753071445072, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97594358026122752, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.95217912172607644, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00472236648286965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00472236648286965, 1.0e-06);

}

// Sample number 380
static void test_ode_likelihood_castillo_katz91() {
  // Input argument
  double params[] = { 2.20600473395458518, 1.69687309495021221, 2.98676672734864157, 2.99838160218757954 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2122.10665631640040374, 1.0e-06);

  }

// Sample number 380
static void test_ode_proposal_castillo_katz91() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.20600473395458518, 1.69687309495021221, 2.98676672734864157, 2.99838160218757954 };
  double likelihood = 2122.10665631640040374;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.20600473395458518, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.69687309495021221, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98676672734864157, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.99838160218757954, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 270
static void test_ode_likelihood_castillo_katz92() {
  // Input argument
  double params[] = { 1.76983214287762713, 1.75759669094696291, 3.01361090922781827, 3.02410554096430984 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2122.77023672095265283, 1.0e-06);

  }

// Sample number 270
static void test_ode_proposal_castillo_katz92() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.76983214287762713, 1.75759669094696291, 3.01361090922781827, 3.02410554096430984 };
  double likelihood = 2122.77023672095265283;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.76983214287762713, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.75759669094696291, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.01361090922781827, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.02410554096430984, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 2653
static void test_ode_likelihood_castillo_katz93() {
  // Input argument
  double params[] = { 1.91776017397489729, 1.66066443461261160, 3.02170134959678549, 2.93074912440485180 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2123.82587206925336432, 1.0e-06);

  }

// Sample number 2653
static void test_ode_proposal_castillo_katz93() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.91776017397489729, 1.66066443461261160, 3.02170134959678549, 2.93074912440485180 };
  double likelihood = 2123.82587206925336432;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.91776017397489729, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.66066443461261160, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.02170134959678549, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.93074912440485180, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 3894
static void test_ode_likelihood_castillo_katz94() {
  // Input argument
  double params[] = { 2.02449065947207751, 1.91697398538876151, 3.06757386663883702, 2.94645268988960529 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2124.73236087063833111, 1.0e-06);

  }

// Sample number 3894
static void test_ode_proposal_castillo_katz94() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.02449065947207751, 1.91697398538876151, 3.06757386663883702, 2.94645268988960529 };
  double likelihood = 2124.73236087063833111;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.02449065947207751, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.91697398538876151, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.06757386663883702, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.94645268988960529, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 4667
static void test_ode_likelihood_castillo_katz95() {
  // Input argument
  double params[] = { 2.03967935972508929, 1.70733973760953939, 2.97516461180486358, 2.96265106296314196 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2123.86315892671700567, 1.0e-06);

  }

// Sample number 4667
static void test_ode_proposal_castillo_katz95() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.03967935972508929, 1.70733973760953939, 2.97516461180486358, 2.96265106296314196 };
  double likelihood = 2123.86315892671700567;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.03967935972508929, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.70733973760953939, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97516461180486358, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.96265106296314196, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 649
static void test_ode_likelihood_castillo_katz96() {
  // Input argument
  double params[] = { 1.77568959595297260, 1.53982572513145533, 3.02239165142635802, 2.96036033062500481 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2123.00439735433519672, 1.0e-06);

  }

// Sample number 649
static void test_ode_proposal_castillo_katz96() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.77568959595297260, 1.53982572513145533, 3.02239165142635802, 2.96036033062500481 };
  double likelihood = 2123.00439735433519672;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.77568959595297260, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.53982572513145533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.02239165142635802, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.96036033062500481, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 2841
static void test_ode_likelihood_castillo_katz97() {
  // Input argument
  double params[] = { 2.10337833154056497, 1.80129789437786925, 2.96552226007854403, 2.99645634246797998 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2123.24129409756960740, 1.0e-06);

  }

// Sample number 2841
static void test_ode_proposal_castillo_katz97() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.10337833154056497, 1.80129789437786925, 2.96552226007854403, 2.99645634246797998 };
  double likelihood = 2123.24129409756960740;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.10337833154056497, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.80129789437786925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.96552226007854403, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.99645634246797998, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 2344
static void test_ode_likelihood_castillo_katz98() {
  // Input argument
  double params[] = { 2.01803735945867802, 1.88334464677870272, 2.99721023108543561, 2.99924358802459334 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2124.70609179428674906, 1.0e-06);

  }

// Sample number 2344
static void test_ode_proposal_castillo_katz98() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.01803735945867802, 1.88334464677870272, 2.99721023108543561, 2.99924358802459334 };
  double likelihood = 2124.70609179428674906;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.01803735945867802, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.88334464677870272, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99721023108543561, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.99924358802459334, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 60
static void test_ode_likelihood_castillo_katz99() {
  // Input argument
  double params[] = { 2.04245499393242902, 1.99586200937467884, 3.07440082331479303, 2.95904986322521157 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2124.68173579610629531, 1.0e-06);

  }

// Sample number 60
static void test_ode_proposal_castillo_katz99() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 2.04245499393242902, 1.99586200937467884, 3.07440082331479303, 2.95904986322521157 };
  double likelihood = 2124.68173579610629531;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.04245499393242902, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.99586200937467884, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.07440082331479303, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.95904986322521157, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

// Sample number 1683
static void test_ode_likelihood_castillo_katz100() {
  // Input argument
  double params[] = { 1.81029600847215710, 1.83612185984102472, 3.06910800050387511, 2.95770811923889321 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ion_likelihood_mh(data, model, params, 4, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 2123.78230933145687231, 1.0e-06);

  }

// Sample number 1683
static void test_ode_proposal_castillo_katz100() {
  // Input arguments
  size_t block[] = { 0, 1, 2, 3 };
  double params[] = { 1.81029600847215710, 1.83612185984102472, 3.06910800050387511, 2.95770811923889321 };
  double likelihood = 2123.78230933145687231;
  double temperature = 1.00000000000000000;
  double stepsize = 0.05277655813324804;
  // Output arguments
  size_t ldc = (4 + 1u) & ~1u;
  double mean[4], covariance[ldc * 4];

  // Call test function
  int error = gmcmc_proposal_mh(4, block, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.81029600847215710, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.83612185984102472, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.06910800050387511, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.95770811923889321, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00278536508839211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00278536508839211, 1.0e-06);

}

