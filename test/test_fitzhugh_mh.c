// Sample number 16295
static void test_ode_likelihood_fitzhugh_mh1() {
  // Input argument
  double params[] = { 4.41602874548031377, 1.93830309793024957, 0.61575232233961330, 0.25905953992688135, -0.76511508642119130 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -30054.63355183455860242, 1.0e-06);

  }

// Sample number 18115
static void test_ode_likelihood_fitzhugh_mh2() {
  // Input argument
  double params[] = { 4.97219442815800861, 9.44179738791085832, 9.95518387375208036, -3.34096245103094880, 3.11697855067677221 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -17299.76717135065700859, 1.0e-06);

  }

// Sample number 2540
static void test_ode_likelihood_fitzhugh_mh3() {
  // Input argument
  double params[] = { 8.85845428033448101, 2.27942027309918060, 6.50203790454203645, -2.10278339202229025, -1.35593885594553920 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -85193.77084328985074535, 1.0e-06);

  }

// Sample number 18265
static void test_ode_likelihood_fitzhugh_mh4() {
  // Input argument
  double params[] = { 9.93141839395874726, 0.47448035053214155, 9.55233260152715680, 0.49773339610740275, -0.27287916144503183 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -399966.33249196782708168, 1.0e-06);

  }

// Sample number 12645
static void test_ode_likelihood_fitzhugh_mh5() {
  // Input argument
  double params[] = { 1.92494866364539496, 8.81911973306220531, 0.71041763834674865, -3.05512992961798258, 0.42115348462334173 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -18764.43087783243390732, 1.0e-06);

  }

// Sample number 1951
static void test_ode_likelihood_fitzhugh_mh6() {
  // Input argument
  double params[] = { 0.53929333403148649, 0.67745511239094003, 3.29214040260157104, -0.92029969061974448, -2.94130082859265229 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -33270.79154942021705210, 1.0e-06);

  }

// Sample number 5569
static void test_ode_likelihood_fitzhugh_mh7() {
  // Input argument
  double params[] = { 0.86197101005103693, 2.92771575829410091, 0.53117816031590670, -3.57515371525295000, -2.02254391315386961 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -20541.29293155205959920, 1.0e-06);

  }

// Sample number 10934
static void test_ode_likelihood_fitzhugh_mh8() {
  // Input argument
  double params[] = { 8.17240542550153037, 2.23799107032309097, 9.31311282142946162, -1.00650505047542427, -1.19967936415101040 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -68850.89922321465564892, 1.0e-06);

  }

// Sample number 19143
static void test_ode_likelihood_fitzhugh_mh9() {
  // Input argument
  double params[] = { 5.85891417937289027, 0.57577466089230200, 1.28104457443699360, 0.66482045588372185, -2.07427799962594550 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -261563.53123698040144518, 1.0e-06);

  }

// Sample number 19290
static void test_ode_likelihood_fitzhugh_mh10() {
  // Input argument
  double params[] = { 9.38531222749874772, 9.38649021123733540, 2.57758307825449240, 3.29831222237664390, -3.74820118148784154 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -25133.38448519164376194, 1.0e-06);

  }

// Sample number 3153
static void test_ode_likelihood_fitzhugh_mh11() {
  // Input argument
  double params[] = { 2.64899745535519981, 5.26900577392737013, 8.92843621734348325, -3.36810738244697072, 3.00092517073362419 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -16989.51973114396969322, 1.0e-06);

  }

// Sample number 3153
static void test_ode_proposal_fitzhugh_mh11() {
  // Input arguments
  double params[] = { 2.64899745535519981, 5.26900577392737013, 8.92843621734348325, -3.36810738244697072, 3.00092517073362419 };
  double likelihood = -16989.51973114396969322;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.64899745535519981, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 5.26900577392737013, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 8.92843621734348325, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -3.36810738244697072, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 3.00092517073362419, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 19411
static void test_ode_likelihood_fitzhugh_mh12() {
  // Input argument
  double params[] = { 6.83574780871166610, 7.89385171784334716, 5.47089462478756339, 0.72100751682579445, -0.38800802234729292 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -19527.34553548803887679, 1.0e-06);

  }

// Sample number 19411
static void test_ode_proposal_fitzhugh_mh12() {
  // Input arguments
  double params[] = { 6.83574780871166610, 7.89385171784334716, 5.47089462478756339, 0.72100751682579445, -0.38800802234729292 };
  double likelihood = -19527.34553548803887679;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 6.83574780871166610, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 7.89385171784334716, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 5.47089462478756339, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 0.72100751682579445, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], -0.38800802234729292, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 19142
static void test_ode_likelihood_fitzhugh_mh13() {
  // Input argument
  double params[] = { 1.65081465190332177, 1.84728214091299248, 8.13280664511262863, 2.61358376054928243, 0.68668229606129938 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -14746.61435640308263828, 1.0e-06);

  }

// Sample number 19142
static void test_ode_proposal_fitzhugh_mh13() {
  // Input arguments
  double params[] = { 1.65081465190332177, 1.84728214091299248, 8.13280664511262863, 2.61358376054928243, 0.68668229606129938 };
  double likelihood = -14746.61435640308263828;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.65081465190332177, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.84728214091299248, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 8.13280664511262863, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.61358376054928243, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.68668229606129938, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 9707
static void test_ode_likelihood_fitzhugh_mh14() {
  // Input argument
  double params[] = { 8.80023048356349413, 5.13122599240989530, 7.87241644514552252, -0.55475439689863015, 3.27477203034123976 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -36823.54955065268586623, 1.0e-06);

  }

// Sample number 9707
static void test_ode_proposal_fitzhugh_mh14() {
  // Input arguments
  double params[] = { 8.80023048356349413, 5.13122599240989530, 7.87241644514552252, -0.55475439689863015, 3.27477203034123976 };
  double likelihood = -36823.54955065268586623;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 8.80023048356349413, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 5.13122599240989530, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 7.87241644514552252, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.55475439689863015, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 3.27477203034123976, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 16003
static void test_ode_likelihood_fitzhugh_mh15() {
  // Input argument
  double params[] = { 2.37203891232905395, 1.30227643195639176, 6.60186423500073438, -0.28112976403027917, 0.32590579294200417 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -16273.03404460841920809, 1.0e-06);

  }

// Sample number 16003
static void test_ode_proposal_fitzhugh_mh15() {
  // Input arguments
  double params[] = { 2.37203891232905395, 1.30227643195639176, 6.60186423500073438, -0.28112976403027917, 0.32590579294200417 };
  double likelihood = -16273.03404460841920809;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.37203891232905395, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.30227643195639176, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 6.60186423500073438, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.28112976403027917, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.32590579294200417, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 2838
static void test_ode_likelihood_fitzhugh_mh16() {
  // Input argument
  double params[] = { 2.43655881173244016, 2.85859301807329080, 1.83075048597734824, -0.57965371351888062, -0.24683440243182275 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -16401.20362006357754581, 1.0e-06);

  }

// Sample number 2838
static void test_ode_proposal_fitzhugh_mh16() {
  // Input arguments
  double params[] = { 2.43655881173244016, 2.85859301807329080, 1.83075048597734824, -0.57965371351888062, -0.24683440243182275 };
  double likelihood = -16401.20362006357754581;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.43655881173244016, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.85859301807329080, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.83075048597734824, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.57965371351888062, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], -0.24683440243182275, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 8433
static void test_ode_likelihood_fitzhugh_mh17() {
  // Input argument
  double params[] = { 3.01746103075253380, 7.89884164812763423, 6.99008006924530800, 3.39296911741019924, 0.02030302528100689 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -15555.30565609161203611, 1.0e-06);

  }

// Sample number 8433
static void test_ode_proposal_fitzhugh_mh17() {
  // Input arguments
  double params[] = { 3.01746103075253380, 7.89884164812763423, 6.99008006924530800, 3.39296911741019924, 0.02030302528100689 };
  double likelihood = -15555.30565609161203611;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.01746103075253380, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 7.89884164812763423, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 6.99008006924530800, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 3.39296911741019924, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.02030302528100689, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 18309
static void test_ode_likelihood_fitzhugh_mh18() {
  // Input argument
  double params[] = { 1.84610705287142962, 9.22483929416740445, 1.22573410641557246, 1.73731367303425510, 0.94321002082663730 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -14643.84498489689758571, 1.0e-06);

  }

// Sample number 18309
static void test_ode_proposal_fitzhugh_mh18() {
  // Input arguments
  double params[] = { 1.84610705287142962, 9.22483929416740445, 1.22573410641557246, 1.73731367303425510, 0.94321002082663730 };
  double likelihood = -14643.84498489689758571;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.84610705287142962, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 9.22483929416740445, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.22573410641557246, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.73731367303425510, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.94321002082663730, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 15838
static void test_ode_likelihood_fitzhugh_mh19() {
  // Input argument
  double params[] = { 4.81353592168002198, 6.06052763684816220, 1.98231029126733405, 2.60976652409627174, -1.21092303579664029 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -18508.67640186654170975, 1.0e-06);

  }

// Sample number 15838
static void test_ode_proposal_fitzhugh_mh19() {
  // Input arguments
  double params[] = { 4.81353592168002198, 6.06052763684816220, 1.98231029126733405, 2.60976652409627174, -1.21092303579664029 };
  double likelihood = -18508.67640186654170975;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 4.81353592168002198, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 6.06052763684816220, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.98231029126733405, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.60976652409627174, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], -1.21092303579664029, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 19182
static void test_ode_likelihood_fitzhugh_mh20() {
  // Input argument
  double params[] = { 4.80925862218467337, 8.17960846265735597, 1.90567074824301019, -1.02865311771733459, 0.70706855303704053 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -19533.00065070129494416, 1.0e-06);

  }

// Sample number 19182
static void test_ode_proposal_fitzhugh_mh20() {
  // Input arguments
  double params[] = { 4.80925862218467337, 8.17960846265735597, 1.90567074824301019, -1.02865311771733459, 0.70706855303704053 };
  double likelihood = -19533.00065070129494416;
  double temperature = 0.00001693508780843;
  double stepsize = 1.91687999622373617;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 4.80925862218467337, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 8.17960846265735597, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.90567074824301019, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02865311771733459, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.70706855303704053, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 3.67442891992271070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 3.67442891992271070, 1.0e-06);

}

// Sample number 13115
static void test_ode_likelihood_fitzhugh_mh21() {
  // Input argument
  double params[] = { 4.21165336695110248, 5.03955591705490580, 4.34995159880650117, 2.39608423421977701, 0.60600768487656276 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -17411.62400061950029340, 1.0e-06);

  }

// Sample number 13115
static void test_ode_proposal_fitzhugh_mh21() {
  // Input arguments
  double params[] = { 4.21165336695110248, 5.03955591705490580, 4.34995159880650117, 2.39608423421977701, 0.60600768487656276 };
  double likelihood = -17411.62400061950029340;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 4.21165336695110248, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 5.03955591705490580, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 4.34995159880650117, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 2.39608423421977701, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.60600768487656276, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 715
static void test_ode_likelihood_fitzhugh_mh22() {
  // Input argument
  double params[] = { 1.45681634926581194, 2.20462764444565140, 6.52591756827282143, -0.99034973191661491, 1.21281025061124681 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -14104.58172839073995419, 1.0e-06);

  }

// Sample number 715
static void test_ode_proposal_fitzhugh_mh22() {
  // Input arguments
  double params[] = { 1.45681634926581194, 2.20462764444565140, 6.52591756827282143, -0.99034973191661491, 1.21281025061124681 };
  double likelihood = -14104.58172839073995419;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.45681634926581194, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 2.20462764444565140, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 6.52591756827282143, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.99034973191661491, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.21281025061124681, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 16981
static void test_ode_likelihood_fitzhugh_mh23() {
  // Input argument
  double params[] = { 0.19263888450598926, 0.73808353488762268, 2.97508162507836404, -0.08047949915277730, 0.56559623447837337 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -1726.74296272375977424, 1.0e-06);

  }

// Sample number 16981
static void test_ode_proposal_fitzhugh_mh23() {
  // Input arguments
  double params[] = { 0.19263888450598926, 0.73808353488762268, 2.97508162507836404, -0.08047949915277730, 0.56559623447837337 };
  double likelihood = -1726.74296272375977424;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19263888450598926, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.73808353488762268, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97508162507836404, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.08047949915277730, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.56559623447837337, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 18678
static void test_ode_likelihood_fitzhugh_mh24() {
  // Input argument
  double params[] = { 0.19996187640207977, 0.45848506960082042, 2.99801476885588780, -0.18006838598644703, 1.46865355089713434 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -447.54956473895197178, 1.0e-06);

  }

// Sample number 18678
static void test_ode_proposal_fitzhugh_mh24() {
  // Input arguments
  double params[] = { 0.19996187640207977, 0.45848506960082042, 2.99801476885588780, -0.18006838598644703, 1.46865355089713434 };
  double likelihood = -447.54956473895197178;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19996187640207977, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.45848506960082042, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99801476885588780, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.18006838598644703, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.46865355089713434, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 13572
static void test_ode_likelihood_fitzhugh_mh25() {
  // Input argument
  double params[] = { 1.88140467159554925, 6.02065323356368154, 5.85466262859076814, 1.40422755356749818, 2.85561480194631789 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -14786.49079660229472211, 1.0e-06);

  }

// Sample number 13572
static void test_ode_proposal_fitzhugh_mh25() {
  // Input arguments
  double params[] = { 1.88140467159554925, 6.02065323356368154, 5.85466262859076814, 1.40422755356749818, 2.85561480194631789 };
  double likelihood = -14786.49079660229472211;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.88140467159554925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 6.02065323356368154, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 5.85466262859076814, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.40422755356749818, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 2.85561480194631789, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 15152
static void test_ode_likelihood_fitzhugh_mh26() {
  // Input argument
  double params[] = { 0.16734461185017535, 0.85829214658590758, 1.85380409810135816, -0.87963877959895709, 1.40697894722319927 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -1963.83513529304855183, 1.0e-06);

  }

// Sample number 15152
static void test_ode_proposal_fitzhugh_mh26() {
  // Input arguments
  double params[] = { 0.16734461185017535, 0.85829214658590758, 1.85380409810135816, -0.87963877959895709, 1.40697894722319927 };
  double likelihood = -1963.83513529304855183;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.16734461185017535, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.85829214658590758, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.85380409810135816, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.87963877959895709, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.40697894722319927, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 14859
static void test_ode_likelihood_fitzhugh_mh27() {
  // Input argument
  double params[] = { 0.34956324708352299, 0.71935296422346828, 0.14625947779628679, 0.06971379942496603, -0.04981326388115050 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -12264.73142988790277741, 1.0e-06);

  }

// Sample number 14859
static void test_ode_proposal_fitzhugh_mh27() {
  // Input arguments
  double params[] = { 0.34956324708352299, 0.71935296422346828, 0.14625947779628679, 0.06971379942496603, -0.04981326388115050 };
  double likelihood = -12264.73142988790277741;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.34956324708352299, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.71935296422346828, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 0.14625947779628679, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 0.06971379942496603, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], -0.04981326388115050, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 7842
static void test_ode_likelihood_fitzhugh_mh28() {
  // Input argument
  double params[] = { 3.67690757696236359, 9.39404175190827218, 4.75799296642991898, -1.93597778951819754, 1.88213883938695159 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -14619.22028809281255235, 1.0e-06);

  }

// Sample number 7842
static void test_ode_proposal_fitzhugh_mh28() {
  // Input arguments
  double params[] = { 3.67690757696236359, 9.39404175190827218, 4.75799296642991898, -1.93597778951819754, 1.88213883938695159 };
  double likelihood = -14619.22028809281255235;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 3.67690757696236359, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 9.39404175190827218, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 4.75799296642991898, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.93597778951819754, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.88213883938695159, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 13105
static void test_ode_likelihood_fitzhugh_mh29() {
  // Input argument
  double params[] = { 2.54030800237234189, 3.56542226479669244, 8.15005820140240012, 1.74344844203717431, -0.45363337400631443 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -15996.02859097142209066, 1.0e-06);

  }

// Sample number 13105
static void test_ode_proposal_fitzhugh_mh29() {
  // Input arguments
  double params[] = { 2.54030800237234189, 3.56542226479669244, 8.15005820140240012, 1.74344844203717431, -0.45363337400631443 };
  double likelihood = -15996.02859097142209066;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.54030800237234189, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.56542226479669244, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 8.15005820140240012, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 1.74344844203717431, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], -0.45363337400631443, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 3423
static void test_ode_likelihood_fitzhugh_mh30() {
  // Input argument
  double params[] = { 0.33547091477259439, 0.21997618723038653, 2.62826575817316854, -0.80766945642267429, 1.38469119306485289 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -592.99718344515440549, 1.0e-06);

  }

// Sample number 3423
static void test_ode_proposal_fitzhugh_mh30() {
  // Input arguments
  double params[] = { 0.33547091477259439, 0.21997618723038653, 2.62826575817316854, -0.80766945642267429, 1.38469119306485289 };
  double likelihood = -592.99718344515440549;
  double temperature = 0.00054192280986977;
  double stepsize = 0.40089295439070943;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.33547091477259439, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.21997618723038653, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.62826575817316854, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.80766945642267429, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.38469119306485289, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.16071516088011142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.16071516088011142, 1.0e-06);

}

// Sample number 14121
static void test_ode_likelihood_fitzhugh_mh31() {
  // Input argument
  double params[] = { 0.31777397647430627, 0.17189318112622679, 2.87630806446519971, 0.54410230586104003, 1.53984760964906742 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -482.68219065250252697, 1.0e-06);

  }

// Sample number 14121
static void test_ode_proposal_fitzhugh_mh31() {
  // Input arguments
  double params[] = { 0.31777397647430627, 0.17189318112622679, 2.87630806446519971, 0.54410230586104003, 1.53984760964906742 };
  double likelihood = -482.68219065250252697;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.31777397647430627, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17189318112622679, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.87630806446519971, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], 0.54410230586104003, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.53984760964906742, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 637
static void test_ode_likelihood_fitzhugh_mh32() {
  // Input argument
  double params[] = { 0.36619302766181305, 0.07881251457273561, 2.74284865543800827, -0.85426040201374298, 1.04583782501546363 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -143.75770907528539055, 1.0e-06);

  }

// Sample number 637
static void test_ode_proposal_fitzhugh_mh32() {
  // Input arguments
  double params[] = { 0.36619302766181305, 0.07881251457273561, 2.74284865543800827, -0.85426040201374298, 1.04583782501546363 };
  double likelihood = -143.75770907528539055;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.36619302766181305, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.07881251457273561, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.74284865543800827, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.85426040201374298, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.04583782501546363, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 5538
static void test_ode_likelihood_fitzhugh_mh33() {
  // Input argument
  double params[] = { 0.16645562275225889, 0.81527025423807387, 2.40296464482772132, -1.28960538433457605, 1.71690976818963925 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -855.20734629060143561, 1.0e-06);

  }

// Sample number 5538
static void test_ode_proposal_fitzhugh_mh33() {
  // Input arguments
  double params[] = { 0.16645562275225889, 0.81527025423807387, 2.40296464482772132, -1.28960538433457605, 1.71690976818963925 };
  double likelihood = -855.20734629060143561;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.16645562275225889, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.81527025423807387, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.40296464482772132, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.28960538433457605, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.71690976818963925, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 924
static void test_ode_likelihood_fitzhugh_mh34() {
  // Input argument
  double params[] = { 0.24213496618829872, 0.49279818531447339, 2.85726874564852373, -0.88655815359180323, 1.13036367007813965 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -133.83441721304262728, 1.0e-06);

  }

// Sample number 924
static void test_ode_proposal_fitzhugh_mh34() {
  // Input arguments
  double params[] = { 0.24213496618829872, 0.49279818531447339, 2.85726874564852373, -0.88655815359180323, 1.13036367007813965 };
  double likelihood = -133.83441721304262728;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.24213496618829872, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.49279818531447339, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.85726874564852373, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.88655815359180323, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.13036367007813965, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 1943
static void test_ode_likelihood_fitzhugh_mh35() {
  // Input argument
  double params[] = { 0.06563475342583369, 0.08774515237931643, 2.99091456266483391, -0.91100815934616997, 1.31458149461644314 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -463.50131084594198683, 1.0e-06);

  }

// Sample number 1943
static void test_ode_proposal_fitzhugh_mh35() {
  // Input arguments
  double params[] = { 0.06563475342583369, 0.08774515237931643, 2.99091456266483391, -0.91100815934616997, 1.31458149461644314 };
  double likelihood = -463.50131084594198683;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.06563475342583369, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.08774515237931643, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99091456266483391, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.91100815934616997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.31458149461644314, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 16466
static void test_ode_likelihood_fitzhugh_mh36() {
  // Input argument
  double params[] = { 0.12212518033806170, 0.07888868722900479, 3.01455453197021939, -1.38948529431762502, 1.19219504614211647 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -125.37629096418261554, 1.0e-06);

  }

// Sample number 16466
static void test_ode_proposal_fitzhugh_mh36() {
  // Input arguments
  double params[] = { 0.12212518033806170, 0.07888868722900479, 3.01455453197021939, -1.38948529431762502, 1.19219504614211647 };
  double likelihood = -125.37629096418261554;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.12212518033806170, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.07888868722900479, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.01455453197021939, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.38948529431762502, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.19219504614211647, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 13893
static void test_ode_likelihood_fitzhugh_mh37() {
  // Input argument
  double params[] = { 0.23755805969044830, 0.31429439884772525, 2.91189118478955900, -0.37086879290117658, 1.45016638145776011 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -228.94325662929730925, 1.0e-06);

  }

// Sample number 13893
static void test_ode_proposal_fitzhugh_mh37() {
  // Input arguments
  double params[] = { 0.23755805969044830, 0.31429439884772525, 2.91189118478955900, -0.37086879290117658, 1.45016638145776011 };
  double likelihood = -228.94325662929730925;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.23755805969044830, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.31429439884772525, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.91189118478955900, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.37086879290117658, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.45016638145776011, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 6340
static void test_ode_likelihood_fitzhugh_mh38() {
  // Input argument
  double params[] = { 0.22013723601918070, 0.54740206276929060, 2.51611969165118898, -0.69042661538369310, 1.76770068036543981 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -1186.28025636725419645, 1.0e-06);

  }

// Sample number 6340
static void test_ode_proposal_fitzhugh_mh38() {
  // Input arguments
  double params[] = { 0.22013723601918070, 0.54740206276929060, 2.51611969165118898, -0.69042661538369310, 1.76770068036543981 };
  double likelihood = -1186.28025636725419645;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.22013723601918070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.54740206276929060, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.51611969165118898, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.69042661538369310, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.76770068036543981, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 18997
static void test_ode_likelihood_fitzhugh_mh39() {
  // Input argument
  double params[] = { 0.08800973018089495, 0.14483183531833790, 2.86095835919439079, -1.14001065595454065, 0.82061353853339603 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -476.09540227895467979, 1.0e-06);

  }

// Sample number 18997
static void test_ode_proposal_fitzhugh_mh39() {
  // Input arguments
  double params[] = { 0.08800973018089495, 0.14483183531833790, 2.86095835919439079, -1.14001065595454065, 0.82061353853339603 };
  double likelihood = -476.09540227895467979;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.08800973018089495, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14483183531833790, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.86095835919439079, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.14001065595454065, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.82061353853339603, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 689
static void test_ode_likelihood_fitzhugh_mh40() {
  // Input argument
  double params[] = { 0.05227464388644533, 0.62164996405463679, 2.65715678835474778, -1.32313688968537635, 1.67981261096182077 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -720.95585480320210081, 1.0e-06);

  }

// Sample number 689
static void test_ode_proposal_fitzhugh_mh40() {
  // Input arguments
  double params[] = { 0.05227464388644533, 0.62164996405463679, 2.65715678835474778, -1.32313688968537635, 1.67981261096182077 };
  double likelihood = -720.95585480320210081;
  double temperature = 0.00411522633744856;
  double stepsize = 0.07644119040000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.05227464388644533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.62164996405463679, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.65715678835474778, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.32313688968537635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.67981261096182077, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00584325558976905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00584325558976905, 1.0e-06);

}

// Sample number 8775
static void test_ode_likelihood_fitzhugh_mh41() {
  // Input argument
  double params[] = { 0.27821395686900552, 0.10911381263436387, 2.94403675607005466, -0.76984829225384499, 1.03005115815856030 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 9.95527239391438457, 1.0e-06);

  }

// Sample number 8775
static void test_ode_proposal_fitzhugh_mh41() {
  // Input arguments
  double params[] = { 0.27821395686900552, 0.10911381263436387, 2.94403675607005466, -0.76984829225384499, 1.03005115815856030 };
  double likelihood = 9.95527239391438457;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.27821395686900552, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.10911381263436387, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.94403675607005466, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.76984829225384499, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.03005115815856030, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 7631
static void test_ode_likelihood_fitzhugh_mh42() {
  // Input argument
  double params[] = { 0.19293955396556001, 0.30579198380087308, 2.99971099881438974, -0.98651473315335891, 0.93481113557655282 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 108.94577081072613112, 1.0e-06);

  }

// Sample number 7631
static void test_ode_proposal_fitzhugh_mh42() {
  // Input arguments
  double params[] = { 0.19293955396556001, 0.30579198380087308, 2.99971099881438974, -0.98651473315335891, 0.93481113557655282 };
  double likelihood = 108.94577081072613112;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19293955396556001, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.30579198380087308, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99971099881438974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.98651473315335891, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.93481113557655282, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 15309
static void test_ode_likelihood_fitzhugh_mh43() {
  // Input argument
  double params[] = { 0.23451231489242944, 0.28878725218512069, 2.91459540076216017, -0.95931946793668821, 1.22198732222433626 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 71.07438808140257436, 1.0e-06);

  }

// Sample number 15309
static void test_ode_proposal_fitzhugh_mh43() {
  // Input arguments
  double params[] = { 0.23451231489242944, 0.28878725218512069, 2.91459540076216017, -0.95931946793668821, 1.22198732222433626 };
  double likelihood = 71.07438808140257436;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.23451231489242944, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.28878725218512069, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.91459540076216017, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.95931946793668821, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.22198732222433626, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 15902
static void test_ode_likelihood_fitzhugh_mh44() {
  // Input argument
  double params[] = { 0.17815765344361043, 0.01577080716188051, 2.85925172087083634, -1.23149661947140743, 1.30234427757105342 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -59.64843605623319434, 1.0e-06);

  }

// Sample number 15902
static void test_ode_proposal_fitzhugh_mh44() {
  // Input arguments
  double params[] = { 0.17815765344361043, 0.01577080716188051, 2.85925172087083634, -1.23149661947140743, 1.30234427757105342 };
  double likelihood = -59.64843605623319434;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.17815765344361043, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.01577080716188051, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.85925172087083634, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.23149661947140743, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.30234427757105342, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 3737
static void test_ode_likelihood_fitzhugh_mh45() {
  // Input argument
  double params[] = { 0.17316161709920977, 0.24030129018402019, 3.08391457465613605, -0.92346843065179762, 0.89170749013267803 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 92.36303661093447204, 1.0e-06);

  }

// Sample number 3737
static void test_ode_proposal_fitzhugh_mh45() {
  // Input arguments
  double params[] = { 0.17316161709920977, 0.24030129018402019, 3.08391457465613605, -0.92346843065179762, 0.89170749013267803 };
  double likelihood = 92.36303661093447204;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.17316161709920977, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.24030129018402019, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.08391457465613605, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.92346843065179762, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.89170749013267803, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 9793
static void test_ode_likelihood_fitzhugh_mh46() {
  // Input argument
  double params[] = { 0.20985514950780304, 0.53675648742137461, 2.71456869460652994, -1.11690505849063215, 1.41849651986517311 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -119.14087066138081639, 1.0e-06);

  }

// Sample number 9793
static void test_ode_proposal_fitzhugh_mh46() {
  // Input arguments
  double params[] = { 0.20985514950780304, 0.53675648742137461, 2.71456869460652994, -1.11690505849063215, 1.41849651986517311 };
  double likelihood = -119.14087066138081639;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20985514950780304, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.53675648742137461, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.71456869460652994, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.11690505849063215, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.41849651986517311, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 8910
static void test_ode_likelihood_fitzhugh_mh47() {
  // Input argument
  double params[] = { 0.15519006150843512, 0.34364631989106659, 2.87378349973721958, -1.31493315877691730, 1.21229977917187060 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 57.26474305222633632, 1.0e-06);

  }

// Sample number 8910
static void test_ode_proposal_fitzhugh_mh47() {
  // Input arguments
  double params[] = { 0.15519006150843512, 0.34364631989106659, 2.87378349973721958, -1.31493315877691730, 1.21229977917187060 };
  double likelihood = 57.26474305222633632;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.15519006150843512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.34364631989106659, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.87378349973721958, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.31493315877691730, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.21229977917187060, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 12922
static void test_ode_likelihood_fitzhugh_mh48() {
  // Input argument
  double params[] = { 0.20883989390649454, 0.44446777874173976, 2.88200260365340855, -0.87712033600443606, 0.85383855526096641 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 17.66335630705849269, 1.0e-06);

  }

// Sample number 12922
static void test_ode_proposal_fitzhugh_mh48() {
  // Input arguments
  double params[] = { 0.20883989390649454, 0.44446777874173976, 2.88200260365340855, -0.87712033600443606, 0.85383855526096641 };
  double likelihood = 17.66335630705849269;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20883989390649454, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.44446777874173976, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.88200260365340855, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.87712033600443606, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.85383855526096641, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 14182
static void test_ode_likelihood_fitzhugh_mh49() {
  // Input argument
  double params[] = { 0.19063202071598620, 0.04234890734364649, 3.18596532680310585, -0.61011551521476814, 1.02310238462893222 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -146.53206289000070228, 1.0e-06);

  }

// Sample number 14182
static void test_ode_proposal_fitzhugh_mh49() {
  // Input arguments
  double params[] = { 0.19063202071598620, 0.04234890734364649, 3.18596532680310585, -0.61011551521476814, 1.02310238462893222 };
  double likelihood = -146.53206289000070228;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19063202071598620, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.04234890734364649, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.18596532680310585, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.61011551521476814, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.02310238462893222, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 15087
static void test_ode_likelihood_fitzhugh_mh50() {
  // Input argument
  double params[] = { 0.19338439896157678, 0.25702293731374376, 3.09941463736436029, -0.87332623631751205, 0.92699869190417372 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 59.52009515002576734, 1.0e-06);

  }

// Sample number 15087
static void test_ode_proposal_fitzhugh_mh50() {
  // Input arguments
  double params[] = { 0.19338439896157678, 0.25702293731374376, 3.09941463736436029, -0.87332623631751205, 0.92699869190417372 };
  double likelihood = 59.52009515002576734;
  double temperature = 0.01734152991583261;
  double stepsize = 0.05308416000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19338439896157678, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.25702293731374376, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.09941463736436029, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.87332623631751205, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.92699869190417372, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00281792804290560, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00281792804290560, 1.0e-06);

}

// Sample number 5521
static void test_ode_likelihood_fitzhugh_mh51() {
  // Input argument
  double params[] = { 0.21794560335659455, 0.13241583087215247, 3.02053114287951141, -0.89111429922490626, 0.88658060802228222 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 136.44390370721745853, 1.0e-06);

  }

// Sample number 5521
static void test_ode_proposal_fitzhugh_mh51() {
  // Input arguments
  double params[] = { 0.21794560335659455, 0.13241583087215247, 3.02053114287951141, -0.89111429922490626, 0.88658060802228222 };
  double likelihood = 136.44390370721745853;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21794560335659455, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.13241583087215247, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.02053114287951141, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.89111429922490626, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.88658060802228222, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 13594
static void test_ode_likelihood_fitzhugh_mh52() {
  // Input argument
  double params[] = { 0.23160405741559792, 0.04998720940748652, 2.96609868340164962, -0.97943505278597731, 0.94496689767640840 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 142.55830528080912245, 1.0e-06);

  }

// Sample number 13594
static void test_ode_proposal_fitzhugh_mh52() {
  // Input arguments
  double params[] = { 0.23160405741559792, 0.04998720940748652, 2.96609868340164962, -0.97943505278597731, 0.94496689767640840 };
  double likelihood = 142.55830528080912245;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.23160405741559792, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.04998720940748652, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.96609868340164962, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.97943505278597731, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.94496689767640840, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 13101
static void test_ode_likelihood_fitzhugh_mh53() {
  // Input argument
  double params[] = { 0.19299632323987187, 0.17385010715212720, 2.97924823169794006, -1.01700706237292526, 1.12871332000582658 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 136.70657753254158706, 1.0e-06);

  }

// Sample number 13101
static void test_ode_proposal_fitzhugh_mh53() {
  // Input arguments
  double params[] = { 0.19299632323987187, 0.17385010715212720, 2.97924823169794006, -1.01700706237292526, 1.12871332000582658 };
  double likelihood = 136.70657753254158706;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19299632323987187, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17385010715212720, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97924823169794006, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.01700706237292526, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.12871332000582658, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 3252
static void test_ode_likelihood_fitzhugh_mh54() {
  // Input argument
  double params[] = { 0.18261923982941577, 0.12308939241876121, 3.01411533372003282, -0.97357352882033443, 0.85857304984321348 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 123.85336972104813924, 1.0e-06);

  }

// Sample number 3252
static void test_ode_proposal_fitzhugh_mh54() {
  // Input arguments
  double params[] = { 0.18261923982941577, 0.12308939241876121, 3.01411533372003282, -0.97357352882033443, 0.85857304984321348 };
  double likelihood = 123.85336972104813924;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.18261923982941577, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.12308939241876121, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.01411533372003282, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.97357352882033443, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.85857304984321348, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 2380
static void test_ode_likelihood_fitzhugh_mh55() {
  // Input argument
  double params[] = { 0.21719756051685155, 0.11274412787722767, 3.00103804158743825, -0.99688239969072834, 1.06383002375591218 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 134.80472305302492941, 1.0e-06);

  }

// Sample number 2380
static void test_ode_proposal_fitzhugh_mh55() {
  // Input arguments
  double params[] = { 0.21719756051685155, 0.11274412787722767, 3.00103804158743825, -0.99688239969072834, 1.06383002375591218 };
  double likelihood = 134.80472305302492941;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21719756051685155, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.11274412787722767, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00103804158743825, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.99688239969072834, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.06383002375591218, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 9965
static void test_ode_likelihood_fitzhugh_mh56() {
  // Input argument
  double params[] = { 0.21089144210775121, 0.24863162626669547, 2.98653598402994058, -0.92214449726935466, 1.01730882902718345 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 128.99719216799269361, 1.0e-06);

  }

// Sample number 9965
static void test_ode_proposal_fitzhugh_mh56() {
  // Input arguments
  double params[] = { 0.21089144210775121, 0.24863162626669547, 2.98653598402994058, -0.92214449726935466, 1.01730882902718345 };
  double likelihood = 128.99719216799269361;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21089144210775121, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.24863162626669547, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98653598402994058, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.92214449726935466, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.01730882902718345, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 19190
static void test_ode_likelihood_fitzhugh_mh57() {
  // Input argument
  double params[] = { 0.18473089973794871, 0.28755968092707185, 2.98603678566760644, -1.07620469980936506, 1.06519370350502562 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 123.35923670943734010, 1.0e-06);

  }

// Sample number 19190
static void test_ode_proposal_fitzhugh_mh57() {
  // Input arguments
  double params[] = { 0.18473089973794871, 0.28755968092707185, 2.98603678566760644, -1.07620469980936506, 1.06519370350502562 };
  double likelihood = 123.35923670943734010;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.18473089973794871, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.28755968092707185, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98603678566760644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.07620469980936506, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.06519370350502562, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 6806
static void test_ode_likelihood_fitzhugh_mh58() {
  // Input argument
  double params[] = { 0.21032229427203575, 0.12466032601631120, 3.04736825479453755, -0.89335078339378948, 0.92908394216873114 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 139.90091441663071237, 1.0e-06);

  }

// Sample number 6806
static void test_ode_proposal_fitzhugh_mh58() {
  // Input arguments
  double params[] = { 0.21032229427203575, 0.12466032601631120, 3.04736825479453755, -0.89335078339378948, 0.92908394216873114 };
  double likelihood = 139.90091441663071237;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21032229427203575, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.12466032601631120, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.04736825479453755, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.89335078339378948, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.92908394216873114, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 11701
static void test_ode_likelihood_fitzhugh_mh59() {
  // Input argument
  double params[] = { 0.16647351718110714, 0.17508365984679991, 2.99719350531900819, -1.07016869270316439, 0.97299292405481341 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 136.69253945662927663, 1.0e-06);

  }

// Sample number 11701
static void test_ode_proposal_fitzhugh_mh59() {
  // Input arguments
  double params[] = { 0.16647351718110714, 0.17508365984679991, 2.99719350531900819, -1.07016869270316439, 0.97299292405481341 };
  double likelihood = 136.69253945662927663;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.16647351718110714, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17508365984679991, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99719350531900819, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.07016869270316439, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.97299292405481341, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 4475
static void test_ode_likelihood_fitzhugh_mh60() {
  // Input argument
  double params[] = { 0.22204396205679730, 0.15224153225820244, 2.96519248656221901, -0.98100310044212802, 1.02001680568805098 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 152.42646429998632129, 1.0e-06);

  }

// Sample number 4475
static void test_ode_proposal_fitzhugh_mh60() {
  // Input arguments
  double params[] = { 0.22204396205679730, 0.15224153225820244, 2.96519248656221901, -0.98100310044212802, 1.02001680568805098 };
  double likelihood = 152.42646429998632129;
  double temperature = 0.05292214940134465;
  double stepsize = 0.02831155200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.22204396205679730, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15224153225820244, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.96519248656221901, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.98100310044212802, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.02001680568805098, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00080154397664870, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00080154397664870, 1.0e-06);

}

// Sample number 15026
static void test_ode_likelihood_fitzhugh_mh61() {
  // Input argument
  double params[] = { 0.24362951300858715, 0.24484599302077487, 2.97741708266246929, -0.92834926684573138, 1.06286501026968438 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 95.16689747545760270, 1.0e-06);

  }

// Sample number 15026
static void test_ode_proposal_fitzhugh_mh61() {
  // Input arguments
  double params[] = { 0.24362951300858715, 0.24484599302077487, 2.97741708266246929, -0.92834926684573138, 1.06286501026968438 };
  double likelihood = 95.16689747545760270;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.24362951300858715, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.24484599302077487, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97741708266246929, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.92834926684573138, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.06286501026968438, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 5102
static void test_ode_likelihood_fitzhugh_mh62() {
  // Input argument
  double params[] = { 0.19284254783837707, 0.28728829959948615, 2.94974087012063935, -1.09815275275753277, 1.04054782870345774 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 134.24718297465213368, 1.0e-06);

  }

// Sample number 5102
static void test_ode_proposal_fitzhugh_mh62() {
  // Input arguments
  double params[] = { 0.19284254783837707, 0.28728829959948615, 2.94974087012063935, -1.09815275275753277, 1.04054782870345774 };
  double likelihood = 134.24718297465213368;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19284254783837707, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.28728829959948615, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.94974087012063935, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.09815275275753277, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.04054782870345774, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 10119
static void test_ode_likelihood_fitzhugh_mh63() {
  // Input argument
  double params[] = { 0.20793259419817928, 0.20143265192699941, 2.98341187688870191, -1.02060422013715102, 1.03287121805350868 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.80550640271127349, 1.0e-06);

  }

// Sample number 10119
static void test_ode_proposal_fitzhugh_mh63() {
  // Input arguments
  double params[] = { 0.20793259419817928, 0.20143265192699941, 2.98341187688870191, -1.02060422013715102, 1.03287121805350868 };
  double likelihood = 154.80550640271127349;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20793259419817928, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.20143265192699941, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98341187688870191, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02060422013715102, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.03287121805350868, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 13980
static void test_ode_likelihood_fitzhugh_mh64() {
  // Input argument
  double params[] = { 0.20981133114394701, 0.14651924491678342, 2.98545348710666891, -0.98955942758296844, 0.96977806199716865 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.45741282207995937, 1.0e-06);

  }

// Sample number 13980
static void test_ode_proposal_fitzhugh_mh64() {
  // Input arguments
  double params[] = { 0.20981133114394701, 0.14651924491678342, 2.98545348710666891, -0.98955942758296844, 0.96977806199716865 };
  double likelihood = 158.45741282207995937;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20981133114394701, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14651924491678342, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98545348710666891, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.98955942758296844, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.96977806199716865, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 17815
static void test_ode_likelihood_fitzhugh_mh65() {
  // Input argument
  double params[] = { 0.17260566463881474, 0.16841212534682881, 2.98146442720424254, -1.10259410958126880, 0.97825514353056886 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 138.46138054274604201, 1.0e-06);

  }

// Sample number 17815
static void test_ode_proposal_fitzhugh_mh65() {
  // Input arguments
  double params[] = { 0.17260566463881474, 0.16841212534682881, 2.98146442720424254, -1.10259410958126880, 0.97825514353056886 };
  double likelihood = 138.46138054274604201;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.17260566463881474, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16841212534682881, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98146442720424254, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.10259410958126880, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.97825514353056886, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 19182
static void test_ode_likelihood_fitzhugh_mh66() {
  // Input argument
  double params[] = { 0.20957480864374403, 0.23167081766650593, 2.95048509018681271, -1.03035913549842251, 0.94440261689465799 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 142.91300321029979159, 1.0e-06);

  }

// Sample number 19182
static void test_ode_proposal_fitzhugh_mh66() {
  // Input arguments
  double params[] = { 0.20957480864374403, 0.23167081766650593, 2.95048509018681271, -1.03035913549842251, 0.94440261689465799 };
  double likelihood = 142.91300321029979159;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20957480864374403, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.23167081766650593, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.95048509018681271, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.03035913549842251, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.94440261689465799, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 10942
static void test_ode_likelihood_fitzhugh_mh67() {
  // Input argument
  double params[] = { 0.24541790229405680, 0.08890316814015911, 2.97998963115435789, -0.93186082286248084, 1.01185951205744828 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 137.80889014642758639, 1.0e-06);

  }

// Sample number 10942
static void test_ode_proposal_fitzhugh_mh67() {
  // Input arguments
  double params[] = { 0.24541790229405680, 0.08890316814015911, 2.97998963115435789, -0.93186082286248084, 1.01185951205744828 };
  double likelihood = 137.80889014642758639;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.24541790229405680, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.08890316814015911, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97998963115435789, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.93186082286248084, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.01185951205744828, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 2772
static void test_ode_likelihood_fitzhugh_mh68() {
  // Input argument
  double params[] = { 0.18331357013406449, 0.24132934950919377, 2.98990065056254695, -1.01830940376060242, 0.96982428228450890 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 144.25889304674151958, 1.0e-06);

  }

// Sample number 2772
static void test_ode_proposal_fitzhugh_mh68() {
  // Input arguments
  double params[] = { 0.18331357013406449, 0.24132934950919377, 2.98990065056254695, -1.01830940376060242, 0.96982428228450890 };
  double likelihood = 144.25889304674151958;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.18331357013406449, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.24132934950919377, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98990065056254695, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.01830940376060242, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.96982428228450890, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 2985
static void test_ode_likelihood_fitzhugh_mh69() {
  // Input argument
  double params[] = { 0.21407385015323790, 0.26947243739049420, 2.98136633901547743, -0.93616484233871922, 0.96570327438154235 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 137.02395919009484260, 1.0e-06);

  }

// Sample number 2985
static void test_ode_proposal_fitzhugh_mh69() {
  // Input arguments
  double params[] = { 0.21407385015323790, 0.26947243739049420, 2.98136633901547743, -0.93616484233871922, 0.96570327438154235 };
  double likelihood = 137.02395919009484260;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21407385015323790, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.26947243739049420, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98136633901547743, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.93616484233871922, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.96570327438154235, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 5148
static void test_ode_likelihood_fitzhugh_mh70() {
  // Input argument
  double params[] = { 0.17025086826647509, 0.19807588012041322, 3.00105889071126608, -1.05413001820743246, 1.05608099889214602 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 142.73293752863116879, 1.0e-06);

  }

// Sample number 5148
static void test_ode_proposal_fitzhugh_mh70() {
  // Input arguments
  double params[] = { 0.17025086826647509, 0.19807588012041322, 3.00105889071126608, -1.05413001820743246, 1.05608099889214602 };
  double likelihood = 142.73293752863116879;
  double temperature = 0.13168724279835398;
  double stepsize = 0.01572864000000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.17025086826647509, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.19807588012041322, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00105889071126608, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.05413001820743246, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.05608099889214602, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00024739011624960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00024739011624960, 1.0e-06);

}

// Sample number 16815
static void test_ode_likelihood_fitzhugh_mh71() {
  // Input argument
  double params[] = { 0.21685785874650335, 0.15088267227094648, 2.98206228942599338, -0.97683559583171431, 0.99060806649755240 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.17901045491680634, 1.0e-06);

  }

// Sample number 16815
static void test_ode_proposal_fitzhugh_mh71() {
  // Input arguments
  double params[] = { 0.21685785874650335, 0.15088267227094648, 2.98206228942599338, -0.97683559583171431, 0.99060806649755240 };
  double likelihood = 158.17901045491680634;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21685785874650335, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15088267227094648, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98206228942599338, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.97683559583171431, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.99060806649755240, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 5086
static void test_ode_likelihood_fitzhugh_mh72() {
  // Input argument
  double params[] = { 0.20044800710543240, 0.16624765258019142, 2.99963072087447369, -1.01261657074994926, 1.00291499476166734 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.57020888245494916, 1.0e-06);

  }

// Sample number 5086
static void test_ode_proposal_fitzhugh_mh72() {
  // Input arguments
  double params[] = { 0.20044800710543240, 0.16624765258019142, 2.99963072087447369, -1.01261657074994926, 1.00291499476166734 };
  double likelihood = 159.57020888245494916;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20044800710543240, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16624765258019142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99963072087447369, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.01261657074994926, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.00291499476166734, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 16285
static void test_ode_likelihood_fitzhugh_mh73() {
  // Input argument
  double params[] = { 0.23092911423341619, 0.11833817020241084, 2.97094320212278795, -0.97080628494665644, 0.96813224973458822 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.49416424247161217, 1.0e-06);

  }

// Sample number 16285
static void test_ode_proposal_fitzhugh_mh73() {
  // Input arguments
  double params[] = { 0.23092911423341619, 0.11833817020241084, 2.97094320212278795, -0.97080628494665644, 0.96813224973458822 };
  double likelihood = 154.49416424247161217;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.23092911423341619, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.11833817020241084, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97094320212278795, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.97080628494665644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.96813224973458822, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 4870
static void test_ode_likelihood_fitzhugh_mh74() {
  // Input argument
  double params[] = { 0.22951648261199586, 0.12452344452081164, 2.95830809456869215, -1.00660525653355148, 0.97467114248627817 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 151.72139428151126594, 1.0e-06);

  }

// Sample number 4870
static void test_ode_proposal_fitzhugh_mh74() {
  // Input arguments
  double params[] = { 0.22951648261199586, 0.12452344452081164, 2.95830809456869215, -1.00660525653355148, 0.97467114248627817 };
  double likelihood = 151.72139428151126594;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.22951648261199586, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.12452344452081164, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.95830809456869215, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.00660525653355148, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.97467114248627817, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 18582
static void test_ode_likelihood_fitzhugh_mh75() {
  // Input argument
  double params[] = { 0.21490985216969635, 0.20428346020593627, 2.99587909468560776, -0.95188410390450284, 0.96330347144155848 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 153.68756907773507692, 1.0e-06);

  }

// Sample number 18582
static void test_ode_proposal_fitzhugh_mh75() {
  // Input arguments
  double params[] = { 0.21490985216969635, 0.20428346020593627, 2.99587909468560776, -0.95188410390450284, 0.96330347144155848 };
  double likelihood = 153.68756907773507692;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21490985216969635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.20428346020593627, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99587909468560776, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.95188410390450284, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.96330347144155848, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 6998
static void test_ode_likelihood_fitzhugh_mh76() {
  // Input argument
  double params[] = { 0.17282395778185855, 0.14616099458992149, 2.99904237480512270, -1.08491030739356065, 1.06393865105017005 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 145.17087081908385926, 1.0e-06);

  }

// Sample number 6998
static void test_ode_proposal_fitzhugh_mh76() {
  // Input arguments
  double params[] = { 0.17282395778185855, 0.14616099458992149, 2.99904237480512270, -1.08491030739356065, 1.06393865105017005 };
  double likelihood = 145.17087081908385926;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.17282395778185855, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14616099458992149, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99904237480512270, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.08491030739356065, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.06393865105017005, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 3931
static void test_ode_likelihood_fitzhugh_mh77() {
  // Input argument
  double params[] = { 0.22435478827263489, 0.14671780513325300, 2.99820008710838604, -0.93845740515345411, 0.89475243409682126 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 149.29036917884360491, 1.0e-06);

  }

// Sample number 3931
static void test_ode_proposal_fitzhugh_mh77() {
  // Input arguments
  double params[] = { 0.22435478827263489, 0.14671780513325300, 2.99820008710838604, -0.93845740515345411, 0.89475243409682126 };
  double likelihood = 149.29036917884360491;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.22435478827263489, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14671780513325300, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99820008710838604, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.93845740515345411, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.89475243409682126, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 5020
static void test_ode_likelihood_fitzhugh_mh78() {
  // Input argument
  double params[] = { 0.18658800171104672, 0.16600293394791435, 3.00392488708660022, -1.02563399016413359, 0.99614699216741687 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 156.00832589783095727, 1.0e-06);

  }

// Sample number 5020
static void test_ode_proposal_fitzhugh_mh78() {
  // Input arguments
  double params[] = { 0.18658800171104672, 0.16600293394791435, 3.00392488708660022, -1.02563399016413359, 0.99614699216741687 };
  double likelihood = 156.00832589783095727;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.18658800171104672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16600293394791435, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00392488708660022, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02563399016413359, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.99614699216741687, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 12316
static void test_ode_likelihood_fitzhugh_mh79() {
  // Input argument
  double params[] = { 0.21761602718857276, 0.15954025260024568, 3.00994233483964413, -0.94601417955494149, 0.92649741422080922 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 153.56932317674625210, 1.0e-06);

  }

// Sample number 12316
static void test_ode_proposal_fitzhugh_mh79() {
  // Input arguments
  double params[] = { 0.21761602718857276, 0.15954025260024568, 3.00994233483964413, -0.94601417955494149, 0.92649741422080922 };
  double likelihood = 153.56932317674625210;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21761602718857276, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15954025260024568, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00994233483964413, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.94601417955494149, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.92649741422080922, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 9462
static void test_ode_likelihood_fitzhugh_mh80() {
  // Input argument
  double params[] = { 0.20215357537629880, 0.15925160316360423, 2.99184394495029649, -1.02484036166626291, 0.98664141013216211 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.92263622201551243, 1.0e-06);

  }

// Sample number 9462
static void test_ode_proposal_fitzhugh_mh80() {
  // Input arguments
  double params[] = { 0.20215357537629880, 0.15925160316360423, 2.99184394495029649, -1.02484036166626291, 0.98664141013216211 };
  double likelihood = 158.92263622201551243;
  double temperature = 0.28462802079628785;
  double stepsize = 0.01258291200000001;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20215357537629880, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15925160316360423, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99184394495029649, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02484036166626291, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.98664141013216211, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00015832967439974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00015832967439974, 1.0e-06);

}

// Sample number 7034
static void test_ode_likelihood_fitzhugh_mh81() {
  // Input argument
  double params[] = { 0.20315539852306549, 0.11900297250039407, 2.97413495597645072, -1.03078207940440225, 1.00437358459332060 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.45043326099272463, 1.0e-06);

  }

// Sample number 7034
static void test_ode_proposal_fitzhugh_mh81() {
  // Input arguments
  double params[] = { 0.20315539852306549, 0.11900297250039407, 2.97413495597645072, -1.03078207940440225, 1.00437358459332060 };
  double likelihood = 154.45043326099272463;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20315539852306549, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.11900297250039407, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97413495597645072, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.03078207940440225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.00437358459332060, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 16616
static void test_ode_likelihood_fitzhugh_mh82() {
  // Input argument
  double params[] = { 0.19095936101055452, 0.15802545540245733, 2.97313575974333189, -1.05819385683172995, 1.03804870191050758 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 151.26382727961998853, 1.0e-06);

  }

// Sample number 16616
static void test_ode_proposal_fitzhugh_mh82() {
  // Input arguments
  double params[] = { 0.19095936101055452, 0.15802545540245733, 2.97313575974333189, -1.05819385683172995, 1.03804870191050758 };
  double likelihood = 151.26382727961998853;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19095936101055452, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15802545540245733, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97313575974333189, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.05819385683172995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.03804870191050758, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 11705
static void test_ode_likelihood_fitzhugh_mh83() {
  // Input argument
  double params[] = { 0.20252826389085754, 0.17319167752239042, 2.99173367438001403, -1.02145746536915194, 1.04031894674178638 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.23364634449234245, 1.0e-06);

  }

// Sample number 11705
static void test_ode_proposal_fitzhugh_mh83() {
  // Input arguments
  double params[] = { 0.20252826389085754, 0.17319167752239042, 2.99173367438001403, -1.02145746536915194, 1.04031894674178638 };
  double likelihood = 157.23364634449234245;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20252826389085754, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17319167752239042, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99173367438001403, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02145746536915194, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.04031894674178638, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 10993
static void test_ode_likelihood_fitzhugh_mh84() {
  // Input argument
  double params[] = { 0.21625750371968389, 0.13481884954627960, 2.99367325466357714, -0.98254494583781504, 0.99660740852465779 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.03575733239154033, 1.0e-06);

  }

// Sample number 10993
static void test_ode_proposal_fitzhugh_mh84() {
  // Input arguments
  double params[] = { 0.21625750371968389, 0.13481884954627960, 2.99367325466357714, -0.98254494583781504, 0.99660740852465779 };
  double likelihood = 159.03575733239154033;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21625750371968389, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.13481884954627960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99367325466357714, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.98254494583781504, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.99660740852465779, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 18341
static void test_ode_likelihood_fitzhugh_mh85() {
  // Input argument
  double params[] = { 0.20468417937511854, 0.13159568322487489, 2.98208764628998457, -1.02733120920357046, 1.03286288108167090 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.27235385834973158, 1.0e-06);

  }

// Sample number 18341
static void test_ode_proposal_fitzhugh_mh85() {
  // Input arguments
  double params[] = { 0.20468417937511854, 0.13159568322487489, 2.98208764628998457, -1.02733120920357046, 1.03286288108167090 };
  double likelihood = 157.27235385834973158;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20468417937511854, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.13159568322487489, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98208764628998457, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02733120920357046, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.03286288108167090, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 5716
static void test_ode_likelihood_fitzhugh_mh86() {
  // Input argument
  double params[] = { 0.20090149802378815, 0.11037541719914211, 2.99854874614580735, -1.00778897207752038, 1.00711887358365915 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.33086165722681926, 1.0e-06);

  }

// Sample number 5716
static void test_ode_proposal_fitzhugh_mh86() {
  // Input arguments
  double params[] = { 0.20090149802378815, 0.11037541719914211, 2.99854874614580735, -1.00778897207752038, 1.00711887358365915 };
  double likelihood = 157.33086165722681926;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20090149802378815, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.11037541719914211, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99854874614580735, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.00778897207752038, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.00711887358365915, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 15140
static void test_ode_likelihood_fitzhugh_mh87() {
  // Input argument
  double params[] = { 0.20157418537890315, 0.17986845024043016, 2.99020376630374773, -1.02546740038253459, 1.01379681352171724 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.87062998647024870, 1.0e-06);

  }

// Sample number 15140
static void test_ode_proposal_fitzhugh_mh87() {
  // Input arguments
  double params[] = { 0.20157418537890315, 0.17986845024043016, 2.99020376630374773, -1.02546740038253459, 1.01379681352171724 };
  double likelihood = 158.87062998647024870;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20157418537890315, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17986845024043016, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99020376630374773, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02546740038253459, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.01379681352171724, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 15070
static void test_ode_likelihood_fitzhugh_mh88() {
  // Input argument
  double params[] = { 0.20046363694221517, 0.12453677605447593, 3.00339778446369499, -1.00601039279031101, 0.96930621665785333 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.22578081774338443, 1.0e-06);

  }

// Sample number 15070
static void test_ode_proposal_fitzhugh_mh88() {
  // Input arguments
  double params[] = { 0.20046363694221517, 0.12453677605447593, 3.00339778446369499, -1.00601039279031101, 0.96930621665785333 };
  double likelihood = 158.22578081774338443;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20046363694221517, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.12453677605447593, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00339778446369499, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.00601039279031101, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.96930621665785333, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 7606
static void test_ode_likelihood_fitzhugh_mh89() {
  // Input argument
  double params[] = { 0.22473300805526347, 0.15908370155980958, 2.97606579366044066, -0.96943393618567553, 0.99458156346686977 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 156.84451182052492868, 1.0e-06);

  }

// Sample number 7606
static void test_ode_proposal_fitzhugh_mh89() {
  // Input arguments
  double params[] = { 0.22473300805526347, 0.15908370155980958, 2.97606579366044066, -0.96943393618567553, 0.99458156346686977 };
  double likelihood = 156.84451182052492868;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.22473300805526347, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15908370155980958, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97606579366044066, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.96943393618567553, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.99458156346686977, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 11352
static void test_ode_likelihood_fitzhugh_mh90() {
  // Input argument
  double params[] = { 0.20532733431395808, 0.14418737173061735, 3.00390923593967107, -0.99951883008858289, 1.04546087929823517 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 153.94999418114946366, 1.0e-06);

  }

// Sample number 11352
static void test_ode_proposal_fitzhugh_mh90() {
  // Input arguments
  double params[] = { 0.20532733431395808, 0.14418737173061735, 3.00390923593967107, -0.99951883008858289, 1.04546087929823517 };
  double likelihood = 153.94999418114946366;
  double temperature = 0.55492895730664349;
  double stepsize = 0.00838860800000000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20532733431395808, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14418737173061735, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00390923593967107, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.99951883008858289, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.04546087929823517, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00007036874417766, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00007036874417766, 1.0e-06);

}

// Sample number 1518
static void test_ode_likelihood_fitzhugh_mh91() {
  // Input argument
  double params[] = { 0.20982985180113978, 0.17217216460825854, 2.98526283102899681, -1.00951537997626284, 1.03514331631582879 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.71658327971408653, 1.0e-06);

  }

// Sample number 1518
static void test_ode_proposal_fitzhugh_mh91() {
  // Input arguments
  double params[] = { 0.20982985180113978, 0.17217216460825854, 2.98526283102899681, -1.00951537997626284, 1.03514331631582879 };
  double likelihood = 157.71658327971408653;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20982985180113978, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17217216460825854, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98526283102899681, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.00951537997626284, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.03514331631582879, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 1079
static void test_ode_likelihood_fitzhugh_mh92() {
  // Input argument
  double params[] = { 0.20371742190211445, 0.17263158703317133, 2.98724958265889651, -1.01658263573955199, 1.02213674099041585 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.59925441933529555, 1.0e-06);

  }

// Sample number 1079
static void test_ode_proposal_fitzhugh_mh92() {
  // Input arguments
  double params[] = { 0.20371742190211445, 0.17263158703317133, 2.98724958265889651, -1.01658263573955199, 1.02213674099041585 };
  double likelihood = 159.59925441933529555;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20371742190211445, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17263158703317133, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98724958265889651, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.01658263573955199, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.02213674099041585, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 10615
static void test_ode_likelihood_fitzhugh_mh93() {
  // Input argument
  double params[] = { 0.20176742990128435, 0.17936645142982691, 2.98888457949194386, -1.02532642087470638, 1.04137251604826275 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.36255789090677126, 1.0e-06);

  }

// Sample number 10615
static void test_ode_proposal_fitzhugh_mh93() {
  // Input arguments
  double params[] = { 0.20176742990128435, 0.17936645142982691, 2.98888457949194386, -1.02532642087470638, 1.04137251604826275 };
  double likelihood = 157.36255789090677126;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20176742990128435, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17936645142982691, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98888457949194386, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02532642087470638, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.04137251604826275, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 15582
static void test_ode_likelihood_fitzhugh_mh94() {
  // Input argument
  double params[] = { 0.22191935609340688, 0.17079528958892914, 2.96876856831889402, -0.99606469961045352, 0.98285381850726039 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.52133014295694124, 1.0e-06);

  }

// Sample number 15582
static void test_ode_proposal_fitzhugh_mh94() {
  // Input arguments
  double params[] = { 0.22191935609340688, 0.17079528958892914, 2.96876856831889402, -0.99606469961045352, 0.98285381850726039 };
  double likelihood = 157.52133014295694124;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.22191935609340688, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17079528958892914, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.96876856831889402, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.99606469961045352, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.98285381850726039, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 18677
static void test_ode_likelihood_fitzhugh_mh95() {
  // Input argument
  double params[] = { 0.19547294452178654, 0.18569814945142471, 2.99217754437537353, -1.02264312195953400, 1.03005902251403825 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.83281646433994183, 1.0e-06);

  }

// Sample number 18677
static void test_ode_proposal_fitzhugh_mh95() {
  // Input arguments
  double params[] = { 0.19547294452178654, 0.18569814945142471, 2.99217754437537353, -1.02264312195953400, 1.03005902251403825 };
  double likelihood = 157.83281646433994183;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19547294452178654, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.18569814945142471, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99217754437537353, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.02264312195953400, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.03005902251403825, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 2598
static void test_ode_likelihood_fitzhugh_mh96() {
  // Input argument
  double params[] = { 0.20283788213755263, 0.12656736920826145, 2.97789421273976895, -1.03680586550547083, 0.99458009939375491 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 156.72917508812327014, 1.0e-06);

  }

// Sample number 2598
static void test_ode_proposal_fitzhugh_mh96() {
  // Input arguments
  double params[] = { 0.20283788213755263, 0.12656736920826145, 2.97789421273976895, -1.03680586550547083, 0.99458009939375491 };
  double likelihood = 156.72917508812327014;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20283788213755263, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.12656736920826145, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97789421273976895, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.03680586550547083, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.99458009939375491, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 11374
static void test_ode_likelihood_fitzhugh_mh97() {
  // Input argument
  double params[] = { 0.20268471475501823, 0.17104628756613346, 2.99642809640244634, -0.99627071455326310, 0.97801628896250548 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.68022569345816919, 1.0e-06);

  }

// Sample number 11374
static void test_ode_proposal_fitzhugh_mh97() {
  // Input arguments
  double params[] = { 0.20268471475501823, 0.17104628756613346, 2.99642809640244634, -0.99627071455326310, 0.97801628896250548 };
  double likelihood = 159.68022569345816919;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20268471475501823, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17104628756613346, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99642809640244634, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.99627071455326310, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.97801628896250548, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 9385
static void test_ode_likelihood_fitzhugh_mh98() {
  // Input argument
  double params[] = { 0.21124145744453568, 0.19374187871436996, 2.98682961983830086, -0.99295245984145653, 1.00596412943166125 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.20692907158445450, 1.0e-06);

  }

// Sample number 9385
static void test_ode_proposal_fitzhugh_mh98() {
  // Input arguments
  double params[] = { 0.21124145744453568, 0.19374187871436996, 2.98682961983830086, -0.99295245984145653, 1.00596412943166125 };
  double likelihood = 158.20692907158445450;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21124145744453568, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.19374187871436996, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98682961983830086, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -0.99295245984145653, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.00596412943166125, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 238
static void test_ode_likelihood_fitzhugh_mh99() {
  // Input argument
  double params[] = { 0.21129476759602570, 0.18939007777368663, 2.97281767809064856, -1.00627597539344227, 0.98581962664890055 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.16558670482271509, 1.0e-06);

  }

// Sample number 238
static void test_ode_proposal_fitzhugh_mh99() {
  // Input arguments
  double params[] = { 0.21129476759602570, 0.18939007777368663, 2.97281767809064856, -1.00627597539344227, 0.98581962664890055 };
  double likelihood = 158.16558670482271509;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21129476759602570, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.18939007777368663, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97281767809064856, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.00627597539344227, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 0.98581962664890055, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

// Sample number 6740
static void test_ode_likelihood_fitzhugh_mh100() {
  // Input argument
  double params[] = { 0.19757119176057425, 0.13918690090843786, 3.00138940148519318, -1.01809468324147789, 1.02640066743550951 };
  // Output arguments
  double likelihood;

  // Call test function
  int error = gmcmc_ode_likelihood_mh(data, model, params, 5, NULL, &likelihood, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.83075793190198510, 1.0e-06);

  }

// Sample number 6740
static void test_ode_proposal_fitzhugh_mh100() {
  // Input arguments
  double params[] = { 0.19757119176057425, 0.13918690090843786, 3.00138940148519318, -1.01809468324147789, 1.02640066743550951 };
  double likelihood = 157.83075793190198510;
  double temperature = 1.00000000000000000;
  double stepsize = 0.00515396075520000;
  // Output arguments
  size_t ldc = (5 + 1u) & ~1u;
  double mean[5], covariance[ldc * 5];

  // Call test function
  int error = gmcmc_proposal_mh(5, NULL, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19757119176057425, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.13918690090843786, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00138940148519318, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[3], -1.01809468324147789, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[4], 1.02640066743550951, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 3], 0.00002656331146614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[3 * ldc + 4], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 2], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 3], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[4 * ldc + 4], 0.00002656331146614, 1.0e-06);

}

