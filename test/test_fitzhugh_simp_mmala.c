// Sample number 16295
static void test_ode_likelihood_fitzhugh_simp_mmala1() {
  // Input argument
  double params[] = { 5.30772176281457675, 3.49070791216272047, 0.13701552198553010 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -30393.30529750428831903, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -6094.30756303122507234, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 7930.09412095661355124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 35489.62089548473886680, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 1406.50008107961275527, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -1881.00819482846281971, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 6604.47865289073524764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -1881.00819482846281971, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2702.64880638519389322, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -15216.00652228701437707, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 6604.47865289073524764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -15216.00652228701437707, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 758072.54189477069303393, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 18115
static void test_ode_likelihood_fitzhugh_simp_mmala2() {
  // Input argument
  double params[] = { 3.50280275038109101, 0.31608456402342666, 0.77259025411692495 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -120590.63488599375705235, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -122299.14327909013081808, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 395318.72560820187209174, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 26976.44539445302507374, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 74814.75378084374824539, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -237140.31489934676210396, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], -7689.15519635166583612, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -237140.31489934676210396, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 758912.04294846730772406, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 30402.46009287963170209, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], -7689.15519635166583612, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 30402.46009287963170209, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 24872.64722484523008461, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 2540
static void test_ode_likelihood_fitzhugh_simp_mmala3() {
  // Input argument
  double params[] = { 6.64738683872214953, 9.13328301186392366, 8.09845418861485200 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -17573.39949900427018292, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1277.29790791469849864, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 671.01478971623146208, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -63.64396175261231292, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 222.86663429700439565, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -119.32193271704224458, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 5.70461329317951726, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -119.32193271704224458, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 64.72713707161020125, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -4.46484804589183959, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 5.70461329317951726, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -4.46484804589183959, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 10.63385645161818083, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 18265
static void test_ode_likelihood_fitzhugh_simp_mmala4() {
  // Input argument
  double params[] = { 8.96555547704924294, 6.66022781691076382, 0.97285191912022950 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -26600.35172227480506990, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -3057.16655392707025385, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 3137.37724446679249013, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 1408.79303584419631079, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 449.81443171469385334, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -483.25114288592931189, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 186.89685753429444048, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -483.25114288592931189, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 525.14025280658074735, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -265.38584116581569106, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 186.89685753429444048, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -265.38584116581569106, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 2202.15783290340141320, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 12645
static void test_ode_likelihood_fitzhugh_simp_mmala5() {
  // Input argument
  double params[] = { 7.24044216570513299, 9.91574039712331512, 2.52006494231474276 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -17801.84839814954830217, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -966.36583180576599261, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 431.71104667275426436, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 519.11458422074645114, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 322.05285825536486755, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -218.16799262286124872, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 301.17338454599718034, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -218.16799262286124872, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 156.68211575463311647, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -263.46160110196984760, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 301.17338454599718034, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -263.46160110196984760, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 722.37438640816128554, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 1951
static void test_ode_likelihood_fitzhugh_simp_mmala6() {
  // Input argument
  double params[] = { 4.58861540626059128, 2.02886505371407200, 7.38042841808833483 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -29996.68309443609177833, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -9562.24397989726639935, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 11301.82602701916403021, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 102.00601958271286662, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 3039.75054997003280732, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -3603.45800181713912025, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], -33.21214546897290631, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -3603.45800181713912025, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 4272.27129259952471330, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 38.68644156904293396, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], -33.21214546897290631, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 38.68644156904293396, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 8.08688531749990069, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 5569
static void test_ode_likelihood_fitzhugh_simp_mmala7() {
  // Input argument
  double params[] = { 2.08627042526256723, 1.46762527052647584, 7.07751076658575151 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -15931.81252933866926469, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -3570.24369209542555836, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 1872.07505823340511597, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -296.42204244581694184, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 4438.39913142678415170, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -1626.66881949133585294, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 174.43644866701919227, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -1626.66881949133585294, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 719.21177698162932757, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -85.46704485471104817, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 174.43644866701919227, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -85.46704485471104817, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 24.49495497459780680, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 10934
static void test_ode_likelihood_fitzhugh_simp_mmala8() {
  // Input argument
  double params[] = { 2.70363660707864994, 6.65161240285246258, 2.05318579881762187 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -17899.89892131178203272, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 411.73156620612485312, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -272.49321256663449731, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 99.82785148969101385, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 507.00582849600499458, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -303.77688533032778651, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 11.57769257036024335, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -303.77688533032778651, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 182.43169819000468124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -8.71035388268767719, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 11.57769257036024335, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -8.71035388268767719, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 8.99247606459851312, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 19143
static void test_ode_likelihood_fitzhugh_simp_mmala9() {
  // Input argument
  double params[] = { 9.42310304112296215, 0.67100713519613775, 9.31066553459566393 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -338165.65302355901803821, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -82308.87696763518033549, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 391109.96643096115440130, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 30907.76464423954894301, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 10658.95543681849630957, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -51674.89065165810461622, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], -3906.16711242538985971, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -51674.89065165810461622, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 260473.43306378132547252, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 18001.92474651273732889, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], -3906.16711242538985971, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 18001.92474651273732889, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 1522.68968675293353954, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 19290
static void test_ode_likelihood_fitzhugh_simp_mmala10() {
  // Input argument
  double params[] = { 8.61176413779069350, 4.91690951271707899, 9.14464616384153928 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -32852.94311919403844513, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -4999.97605538145671744, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 6431.25499777820368763, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 68.06778574786926583, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 684.01894018218445126, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -881.85771689469106605, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], -9.43571135866513622, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -881.85771689469106605, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 1137.61541475323974737, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 11.55420084452324225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], -9.43571135866513622, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 11.55420084452324225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 2.86118233151505263, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 3153
static void test_ode_likelihood_fitzhugh_simp_mmala11() {
  // Input argument
  double params[] = { 6.74573396881734233, 3.03855292231693497, 1.74972370170045743 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -38442.44488384217402199, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -9472.57288142500874528, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 14224.81812159389846784, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 295.38586063013366356, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 1862.05473430588040173, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -2802.24997122995910104, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], -41.65161654291264881, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -2802.24997122995910104, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 4225.80617819890267128, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 80.47854661395686549, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], -41.65161654291264881, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 80.47854661395686549, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 244.22440134599810335, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 3153
static void test_ode_proposal_fitzhugh_simp_mmala11() {
  // Input arguments
  double params[] = { 6.74573396881734233, 3.03855292231693497, 1.74972370170045743 };
  double likelihood = -38442.44488384217402199;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -9472.57288142500874528;
  geometry->gradient_log_likelihood[1] = 14224.81812159389846784;
  geometry->gradient_log_likelihood[2] = 295.38586063013366356;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 1862.05473430588040173;
  geometry->FI[0 * geometry->ldfi + 1] = -2802.24997122995910104;
  geometry->FI[0 * geometry->ldfi + 2] = -41.65161654291264881;
  geometry->FI[1 * geometry->ldfi + 0] = -2802.24997122995910104;
  geometry->FI[1 * geometry->ldfi + 1] = 4225.80617819890267128;
  geometry->FI[1 * geometry->ldfi + 2] = 80.47854661395686549;
  geometry->FI[2 * geometry->ldfi + 0] = -41.65161654291264881;
  geometry->FI[2 * geometry->ldfi + 1] = 80.47854661395686549;
  geometry->FI[2 * geometry->ldfi + 2] = 244.22440134599810335;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 6.74519083650897411, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.03833702941576433, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.74975426219871744, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 1.56901583720741411, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 1.04190069078219638, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.07574430403824065, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 1.04190069078219660, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.69308153418985996, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.05069659886595278, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.07574430403824066, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.05069659886595278, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02459695127096492, 1.0e-06);

}

// Sample number 19411
static void test_ode_likelihood_fitzhugh_simp_mmala12() {
  // Input argument
  double params[] = { 5.18775700372736637, 4.52359344875752356, 9.91933103781988912 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -20512.15321324777323753, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -3111.79105914265892352, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 2325.64732847600498644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -64.27286563438627809, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 768.33086783361216021, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -564.90754979399287095, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 9.54863730308700198, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -564.90754979399287095, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 417.59808985208951526, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -7.74726863971552238, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 9.54863730308700198, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -7.74726863971552238, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 2.64470477673443893, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 19411
static void test_ode_proposal_fitzhugh_simp_mmala12() {
  // Input arguments
  double params[] = { 5.18775700372736637, 4.52359344875752356, 9.91933103781988912 };
  double likelihood = -20512.15321324777323753;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -3111.79105914265892352;
  geometry->gradient_log_likelihood[1] = 2325.64732847600498644;
  geometry->gradient_log_likelihood[2] = -64.27286563438627809;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 768.33086783361216021;
  geometry->FI[0 * geometry->ldfi + 1] = -564.90754979399287095;
  geometry->FI[0 * geometry->ldfi + 2] = 9.54863730308700198;
  geometry->FI[1 * geometry->ldfi + 0] = -564.90754979399287095;
  geometry->FI[1 * geometry->ldfi + 1] = 417.59808985208951526;
  geometry->FI[1 * geometry->ldfi + 2] = -7.74726863971552238;
  geometry->FI[2 * geometry->ldfi + 0] = 9.54863730308700198;
  geometry->FI[2 * geometry->ldfi + 1] = -7.74726863971552238;
  geometry->FI[2 * geometry->ldfi + 2] = 2.64470477673443893;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 5.18805538791644150, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 4.52423205971007114, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 9.91907864744364964, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 1.33636993664855486, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 1.81701410378667094, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.49774347895506499, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 1.81701410378667072, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.48339779259012161, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.71446204636599242, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.49774347895506499, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.71446204636599242, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 2.21741848781955264, 1.0e-06);

}

// Sample number 19142
static void test_ode_likelihood_fitzhugh_simp_mmala13() {
  // Input argument
  double params[] = { 0.91344669904726339, 0.64954687060182592, 2.40364595026354788 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -14181.40006756805814803, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 616.38832484635395303, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 1476.88940224127009060, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -279.91938842083561667, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 7688.67180302449469309, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 2131.26572635764478036, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 628.92701716153078451, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 2131.26572635764478036, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2090.40219159164871598, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -36.31157676325436512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 628.92701716153078451, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -36.31157676325436512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 300.79149807055779320, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 19142
static void test_ode_proposal_fitzhugh_simp_mmala13() {
  // Input arguments
  double params[] = { 0.91344669904726339, 0.64954687060182592, 2.40364595026354788 };
  double likelihood = -14181.40006756805814803;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 616.38832484635395303;
  geometry->gradient_log_likelihood[1] = 1476.88940224127009060;
  geometry->gradient_log_likelihood[2] = -279.91938842083561667;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 7688.67180302449469309;
  geometry->FI[0 * geometry->ldfi + 1] = 2131.26572635764478036;
  geometry->FI[0 * geometry->ldfi + 2] = 628.92701716153078451;
  geometry->FI[1 * geometry->ldfi + 0] = 2131.26572635764478036;
  geometry->FI[1 * geometry->ldfi + 1] = 2090.40219159164871598;
  geometry->FI[1 * geometry->ldfi + 2] = -36.31157676325436512;
  geometry->FI[2 * geometry->ldfi + 0] = 628.92701716153078451;
  geometry->FI[2 * geometry->ldfi + 1] = -36.31157676325436512;
  geometry->FI[2 * geometry->ldfi + 2] = 300.79149807055779320;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.91344323310602649, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.64958030758806196, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.40361718723188877, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00125848247345107, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00133158432628631, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00279211866041949, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00133158432628631, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00384518096502424, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00324840944135056, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00279211866041949, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00324840944135056, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02312583163175405, 1.0e-06);

}

// Sample number 9707
static void test_ode_likelihood_fitzhugh_simp_mmala14() {
  // Input argument
  double params[] = { 8.21097531144133441, 8.92757186181218820, 1.52967363487828245 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -20262.71049348211818142, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1443.00208412685947224, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 935.87541462087699529, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 896.73900877167830004, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 311.60030877119629622, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -243.38129876324052248, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 291.30317714598476186, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -243.38129876324052248, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 195.80903048846946035, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -292.72409209135952324, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 291.30317714598476186, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -292.72409209135952324, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 1269.03231563794179237, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 9707
static void test_ode_proposal_fitzhugh_simp_mmala14() {
  // Input arguments
  double params[] = { 8.21097531144133441, 8.92757186181218820, 1.52967363487828245 };
  double likelihood = -20262.71049348211818142;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -1443.00208412685947224;
  geometry->gradient_log_likelihood[1] = 935.87541462087699529;
  geometry->gradient_log_likelihood[2] = 896.73900877167830004;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 311.60030877119629622;
  geometry->FI[0 * geometry->ldfi + 1] = -243.38129876324052248;
  geometry->FI[0 * geometry->ldfi + 2] = 291.30317714598476186;
  geometry->FI[1 * geometry->ldfi + 0] = -243.38129876324052248;
  geometry->FI[1 * geometry->ldfi + 1] = 195.80903048846946035;
  geometry->FI[1 * geometry->ldfi + 2] = -292.72409209135952324;
  geometry->FI[2 * geometry->ldfi + 0] = 291.30317714598476186;
  geometry->FI[2 * geometry->ldfi + 1] = -292.72409209135952324;
  geometry->FI[2 * geometry->ldfi + 2] = 1269.03231563794179237;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 8.20973663068441972, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 8.92625399535266340, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.52968439059839367, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 1.84120524879279635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 2.52867668445844540, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.16063865780833533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 2.52867668445844496, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.51245174264401339, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.22975592633028552, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.16063865780833533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.22975592633028549, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.02012762247426548, 1.0e-06);

}

// Sample number 16003
static void test_ode_likelihood_fitzhugh_simp_mmala15() {
  // Input argument
  double params[] = { 8.88000477450161263, 9.79870349460009038, 0.30299690512992306 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -20544.14363720060282503, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1986.25750462548103314, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 1694.36092745956807448, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -6825.26013742346549407, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 683.54614633630933440, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -633.18677025621786925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 8910.84538529034580279, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -633.18677025621786925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 592.83455132207757288, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -8665.03393432454868162, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 8910.84538529034580279, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -8665.03393432454868162, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 168048.39534688627463765, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 16003
static void test_ode_proposal_fitzhugh_simp_mmala15() {
  // Input arguments
  double params[] = { 8.88000477450161263, 9.79870349460009038, 0.30299690512992306 };
  double likelihood = -20544.14363720060282503;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -1986.25750462548103314;
  geometry->gradient_log_likelihood[1] = 1694.36092745956807448;
  geometry->gradient_log_likelihood[2] = -6825.26013742346549407;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 683.54614633630933440;
  geometry->FI[0 * geometry->ldfi + 1] = -633.18677025621786925;
  geometry->FI[0 * geometry->ldfi + 2] = 8910.84538529034580279;
  geometry->FI[1 * geometry->ldfi + 0] = -633.18677025621786925;
  geometry->FI[1 * geometry->ldfi + 1] = 592.83455132207757288;
  geometry->FI[1 * geometry->ldfi + 2] = -8665.03393432454868162;
  geometry->FI[2 * geometry->ldfi + 0] = 8910.84538529034580279;
  geometry->FI[2 * geometry->ldfi + 1] = -8665.03393432454868162;
  geometry->FI[2 * geometry->ldfi + 2] = 168048.39534688627463765;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 8.87973597347834342, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 9.79877931108134348, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 0.30301331997451175, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 1.15443164952965249, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 1.37321698158552974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00959253317746595, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 1.37321698158552996, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 1.66826470323678588, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.01320480363432393, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00959253317746595, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.01320480363432393, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00020246876699301, 1.0e-06);

}

// Sample number 2838
static void test_ode_likelihood_fitzhugh_simp_mmala16() {
  // Input argument
  double params[] = { 0.52123404770558746, 1.85972722203385032, 4.32791603819953608 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -13799.59049381232398446, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1065.08633598500045991, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 629.14299911562102352, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -133.61973470761478211, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 2871.91144674234192280, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 932.91387266274352896, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 194.04141688699985480, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 932.91387266274352896, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 520.45039466327534683, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -27.93584874392650974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 194.04141688699985480, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -27.93584874392650974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 100.64782965292749850, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 2838
static void test_ode_proposal_fitzhugh_simp_mmala16() {
  // Input arguments
  double params[] = { 0.52123404770558746, 1.85972722203385032, 4.32791603819953608 };
  double likelihood = -13799.59049381232398446;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1065.08633598500045991;
  geometry->gradient_log_likelihood[1] = 629.14299911562102352;
  geometry->gradient_log_likelihood[2] = -133.61973470761478211;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 2871.91144674234192280;
  geometry->FI[0 * geometry->ldfi + 1] = 932.91387266274352896;
  geometry->FI[0 * geometry->ldfi + 2] = 194.04141688699985480;
  geometry->FI[1 * geometry->ldfi + 0] = 932.91387266274352896;
  geometry->FI[1 * geometry->ldfi + 1] = 520.45039466327534683;
  geometry->FI[1 * geometry->ldfi + 2] = -27.93584874392650974;
  geometry->FI[2 * geometry->ldfi + 0] = 194.04141688699985480;
  geometry->FI[2 * geometry->ldfi + 1] = -27.93584874392650974;
  geometry->FI[2 * geometry->ldfi + 2] = 100.64782965292749850;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.52124721644215344, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.85975157001132496, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 4.32784027800903282, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00848987136635004, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.01634020879874458, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.02090322541296490, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.01634020879874458, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.04136193871699802, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.04298312389059648, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.02090322541296490, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.04298312389059649, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.10272373851515551, 1.0e-06);

}

// Sample number 8433
static void test_ode_likelihood_fitzhugh_simp_mmala17() {
  // Input argument
  double params[] = { 1.54490892664056467, 3.25166788715831601, 8.60425058493798822 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -14024.37841851914345170, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -749.13463057755802765, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 251.80190158240517917, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -143.66157884085339447, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 1298.24685144563090944, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -93.53851071332110223, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 60.62678446631932871, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -93.53851071332110223, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 48.50650604482579809, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -19.28110245170573478, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 60.62678446631932871, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -19.28110245170573478, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 11.66467929177718332, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 8433
static void test_ode_proposal_fitzhugh_simp_mmala17() {
  // Input arguments
  double params[] = { 1.54490892664056467, 3.25166788715831601, 8.60425058493798822 };
  double likelihood = -14024.37841851914345170;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -749.13463057755802765;
  geometry->gradient_log_likelihood[1] = 251.80190158240517917;
  geometry->gradient_log_likelihood[2] = -143.66157884085339447;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 1298.24685144563090944;
  geometry->FI[0 * geometry->ldfi + 1] = -93.53851071332110223;
  geometry->FI[0 * geometry->ldfi + 2] = 60.62678446631932871;
  geometry->FI[1 * geometry->ldfi + 0] = -93.53851071332110223;
  geometry->FI[1 * geometry->ldfi + 1] = 48.50650604482579809;
  geometry->FI[1 * geometry->ldfi + 2] = -19.28110245170573478;
  geometry->FI[2 * geometry->ldfi + 0] = 60.62678446631932871;
  geometry->FI[2 * geometry->ldfi + 1] = -19.28110245170573478;
  geometry->FI[2 * geometry->ldfi + 2] = 11.66467929177718332;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.54490856628844453, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 3.25170511738768697, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 8.60378401066061826, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00518332458759127, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00207957336954845, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.03037758355129073, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00207957336954845, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.30632266114568785, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.51714379010308820, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.03037758355129073, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.51714379010308820, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 1.44837736198358513, 1.0e-06);

}

// Sample number 18309
static void test_ode_likelihood_fitzhugh_simp_mmala18() {
  // Input argument
  double params[] = { 7.89861977282778582, 4.12200452549465446, 6.08073271914716074 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -34959.43213655917497817, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -6368.90648752817196510, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 8709.72952468333096476, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 52.78237752851459419, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 987.06796688943268236, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -1350.85422222240867995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], -14.54101505755993351, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -1350.85422222240867995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 1849.49748155344695988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 19.42872846786347196, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], -14.54101505755993351, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 19.42872846786347196, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 18.20202886704844047, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 18309
static void test_ode_proposal_fitzhugh_simp_mmala18() {
  // Input arguments
  double params[] = { 7.89861977282778582, 4.12200452549465446, 6.08073271914716074 };
  double likelihood = -34959.43213655917497817;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -6368.90648752817196510;
  geometry->gradient_log_likelihood[1] = 8709.72952468333096476;
  geometry->gradient_log_likelihood[2] = 52.78237752851459419;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 987.06796688943268236;
  geometry->FI[0 * geometry->ldfi + 1] = -1350.85422222240867995;
  geometry->FI[0 * geometry->ldfi + 2] = -14.54101505755993351;
  geometry->FI[1 * geometry->ldfi + 0] = -1350.85422222240867995;
  geometry->FI[1 * geometry->ldfi + 1] = 1849.49748155344695988;
  geometry->FI[1 * geometry->ldfi + 2] = 19.42872846786347196;
  geometry->FI[2 * geometry->ldfi + 0] = -14.54101505755993351;
  geometry->FI[2 * geometry->ldfi + 1] = 19.42872846786347196;
  geometry->FI[2 * geometry->ldfi + 2] = 18.20202886704844047;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 7.89776498370624225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 4.12158399408430043, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 6.08062351429705750, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 12.36797774650613668, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 9.03091566625032449, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.24083811644184455, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 9.03091566625032272, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 6.59702092214454971, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.17289020451099860, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.24083811644184450, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.17289020451099860, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.28705885968968686, 1.0e-06);

}

// Sample number 15838
static void test_ode_likelihood_fitzhugh_simp_mmala19() {
  // Input argument
  double params[] = { 5.97631014221676082, 4.69827147431422709, 4.05516776884386498 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -22240.52564390111365356, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -3649.78143296186317457, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 3093.88600873644645617, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -78.46283899257815619, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 796.63111023503108754, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -679.61540129305581104, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 11.67096908216680262, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -679.61540129305581104, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 581.88820413761106920, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -11.67274049504557532, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 11.67096908216680262, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -11.67274049504557532, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44.00812860784166958, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15838
static void test_ode_proposal_fitzhugh_simp_mmala19() {
  // Input arguments
  double params[] = { 5.97631014221676082, 4.69827147431422709, 4.05516776884386498 };
  double likelihood = -22240.52564390111365356;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -3649.78143296186317457;
  geometry->gradient_log_likelihood[1] = 3093.88600873644645617;
  geometry->gradient_log_likelihood[2] = -78.46283899257815619;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 796.63111023503108754;
  geometry->FI[0 * geometry->ldfi + 1] = -679.61540129305581104;
  geometry->FI[0 * geometry->ldfi + 2] = 11.67096908216680262;
  geometry->FI[1 * geometry->ldfi + 0] = -679.61540129305581104;
  geometry->FI[1 * geometry->ldfi + 1] = 581.88820413761106920;
  geometry->FI[1 * geometry->ldfi + 2] = -11.67274049504557532;
  geometry->FI[2 * geometry->ldfi + 0] = 11.67096908216680262;
  geometry->FI[2 * geometry->ldfi + 1] = -11.67274049504557532;
  geometry->FI[2 * geometry->ldfi + 2] = 44.00812860784166958;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 5.97573866597693826, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 4.69783198542146163, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 4.05512603074880484, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 1.82320719385251206, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 2.13105137379057208, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.08172614905033893, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 2.13105137379057252, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 2.49965476606956161, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.09785434763403335, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.08172614905033894, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.09785434763403338, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.11976116743418826, 1.0e-06);

}

// Sample number 19182
static void test_ode_likelihood_fitzhugh_simp_mmala20() {
  // Input argument
  double params[] = { 9.87382973359608940, 4.39938589558734172, 5.27976116023749942 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -45798.82867847270972561, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -7482.11359785458262195, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 12721.86742958898321376, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 161.87917451884217712, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 897.56425925607447880, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -1525.80075748931767521, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], -25.08987109565775953, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -1525.80075748931767521, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2597.12475480307284670, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 39.52206838876112727, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], -25.08987109565775953, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 39.52206838876112727, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 24.49431225803590451, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 19182
static void test_ode_proposal_fitzhugh_simp_mmala20() {
  // Input arguments
  double params[] = { 9.87382973359608940, 4.39938589558734172, 5.27976116023749942 };
  double likelihood = -45798.82867847270972561;
  double temperature = 0.00001693508780843;
  double stepsize = 0.00927712935936001;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -7482.11359785458262195;
  geometry->gradient_log_likelihood[1] = 12721.86742958898321376;
  geometry->gradient_log_likelihood[2] = 161.87917451884217712;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 897.56425925607447880;
  geometry->FI[0 * geometry->ldfi + 1] = -1525.80075748931767521;
  geometry->FI[0 * geometry->ldfi + 2] = -25.08987109565775953;
  geometry->FI[1 * geometry->ldfi + 0] = -1525.80075748931767521;
  geometry->FI[1 * geometry->ldfi + 1] = 2597.12475480307284670;
  geometry->FI[1 * geometry->ldfi + 2] = 39.52206838876112727;
  geometry->FI[2 * geometry->ldfi + 0] = -25.08987109565775953;
  geometry->FI[2 * geometry->ldfi + 1] = 39.52206838876112727;
  geometry->FI[2 * geometry->ldfi + 2] = 24.49431225803590451;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 9.87338280673666624, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 4.39933552218445634, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 5.27966904088490452, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 5.00337520684639347, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 2.93350189052612453, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.39176346516543897, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 2.93350189052612453, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 1.72193170638668946, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.22645590425826845, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.39176346516543903, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.22645590425826845, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.24337686456558191, 1.0e-06);

}

// Sample number 13115
static void test_ode_likelihood_fitzhugh_simp_mmala21() {
  // Input argument
  double params[] = { 0.07972296897846337, 0.04208076361524250, 3.07174458895110858 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -139.01509657858503033, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 4980.23974974320299225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -263.37727473816119073, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 2323.75056163350836869, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 58606.98936170012166258, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -7112.82477878138342930, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 36870.15647605643607676, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -7112.82477878138342930, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3537.41849211910721351, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -7778.39317398660296021, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 36870.15647605643607676, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -7778.39317398660296021, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44208.69926499565190170, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 13115
static void test_ode_proposal_fitzhugh_simp_mmala21() {
  // Input arguments
  double params[] = { 0.07972296897846337, 0.04208076361524250, 3.07174458895110858 };
  double likelihood = -139.01509657858503033;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 4980.23974974320299225;
  geometry->gradient_log_likelihood[1] = -263.37727473816119073;
  geometry->gradient_log_likelihood[2] = 2323.75056163350836869;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 58606.98936170012166258;
  geometry->FI[0 * geometry->ldfi + 1] = -7112.82477878138342930;
  geometry->FI[0 * geometry->ldfi + 2] = 36870.15647605643607676;
  geometry->FI[1 * geometry->ldfi + 0] = -7112.82477878138342930;
  geometry->FI[1 * geometry->ldfi + 1] = 3537.41849211910721351;
  geometry->FI[1 * geometry->ldfi + 2] = -7778.39317398660296021;
  geometry->FI[2 * geometry->ldfi + 0] = 36870.15647605643607676;
  geometry->FI[2 * geometry->ldfi + 1] = -7778.39317398660296021;
  geometry->FI[2 * geometry->ldfi + 2] = 44208.69926499565190170;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.08008994821392368, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.04240752141995326, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.07166911931458930, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00043912954051760, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00012667243845688, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00034394739257929, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00012667243845688, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00564032316131200, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00088675349425988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00034394739257929, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00088675349425988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00071779037394941, 1.0e-06);

}

// Sample number 715
static void test_ode_likelihood_fitzhugh_simp_mmala22() {
  // Input argument
  double params[] = { 0.07472328271251523, 0.39573822269845566, 3.22740988399130924 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -519.48455429988416654, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -2114.58604987473518122, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -2985.75224677005098783, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -4970.56343404604649550, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 69802.58688153589901049, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 23264.36900953800068237, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 39398.88704155413870467, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 23264.36900953800068237, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 15683.67621503390182625, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 23788.33101490327317151, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 39398.88704155413870467, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 23788.33101490327317151, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 41148.27110382473620120, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 715
static void test_ode_proposal_fitzhugh_simp_mmala22() {
  // Input arguments
  double params[] = { 0.07472328271251523, 0.39573822269845566, 3.22740988399130924 };
  double likelihood = -519.48455429988416654;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -2114.58604987473518122;
  geometry->gradient_log_likelihood[1] = -2985.75224677005098783;
  geometry->gradient_log_likelihood[2] = -4970.56343404604649550;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 69802.58688153589901049;
  geometry->FI[0 * geometry->ldfi + 1] = 23264.36900953800068237;
  geometry->FI[0 * geometry->ldfi + 2] = 39398.88704155413870467;
  geometry->FI[1 * geometry->ldfi + 0] = 23264.36900953800068237;
  geometry->FI[1 * geometry->ldfi + 1] = 15683.67621503390182625;
  geometry->FI[1 * geometry->ldfi + 2] = 23788.33101490327317151;
  geometry->FI[2 * geometry->ldfi + 0] = 39398.88704155413870467;
  geometry->FI[2 * geometry->ldfi + 1] = 23788.33101490327317151;
  geometry->FI[2 * geometry->ldfi + 2] = 41148.27110382473620120;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.07499874419811620, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.39547738248008368, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.22689912482774321, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00038032839085140, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00009597669003198, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00030867372302489, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00009597669003198, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00631707453190978, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00356008360283396, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00030867372302489, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00356008360283396, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00264904241839491, 1.0e-06);

}

// Sample number 16981
static void test_ode_likelihood_fitzhugh_simp_mmala23() {
  // Input argument
  double params[] = { 0.12113331806844098, 0.45566041780808447, 2.79283983600335084 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -738.21989922023453801, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 10911.20615510669085779, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 5237.74978675758757163, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 7392.96470301559747895, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 84807.78627908085763920, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 37920.36707660974934697, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 46993.39709637973282952, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 37920.36707660974934697, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 25569.14793599439144600, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 29623.03773096148506738, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 46993.39709637973282952, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 29623.03773096148506738, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 38482.83143116482824553, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 16981
static void test_ode_proposal_fitzhugh_simp_mmala23() {
  // Input arguments
  double params[] = { 0.12113331806844098, 0.45566041780808447, 2.79283983600335084 };
  double likelihood = -738.21989922023453801;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 10911.20615510669085779;
  geometry->gradient_log_likelihood[1] = 5237.74978675758757163;
  geometry->gradient_log_likelihood[2] = 7392.96470301559747895;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 84807.78627908085763920;
  geometry->FI[0 * geometry->ldfi + 1] = 37920.36707660974934697;
  geometry->FI[0 * geometry->ldfi + 2] = 46993.39709637973282952;
  geometry->FI[1 * geometry->ldfi + 0] = 37920.36707660974934697;
  geometry->FI[1 * geometry->ldfi + 1] = 25569.14793599439144600;
  geometry->FI[1 * geometry->ldfi + 2] = 29623.03773096148506738;
  geometry->FI[2 * geometry->ldfi + 0] = 46993.39709637973282952;
  geometry->FI[2 * geometry->ldfi + 1] = 29623.03773096148506738;
  geometry->FI[2 * geometry->ldfi + 2] = 38482.83143116482824553;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.12140475092627170, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.45494958213129655, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.79368821133154244, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00046177515161946, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00029149593334169, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00033951212921695, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00029149593334169, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00457773744447104, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00316785694707925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00033951212921695, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00316785694707925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00316894669410253, 1.0e-06);

}

// Sample number 18678
static void test_ode_likelihood_fitzhugh_simp_mmala24() {
  // Input argument
  double params[] = { 0.07949921970809190, 0.78259132152244826, 2.98785575281233262 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -1887.53386424751988670, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -10760.54514912144804839, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -13405.90485608788912941, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -6910.00157476080221386, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 117951.24691969683044590, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 90523.18481037011952139, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 45169.20373158595612040, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 90523.18481037011952139, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 100230.82247847921098582, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 50385.01875733572524041, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 45169.20373158595612040, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 50385.01875733572524041, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 26608.02409561578315333, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 18678
static void test_ode_proposal_fitzhugh_simp_mmala24() {
  // Input arguments
  double params[] = { 0.07949921970809190, 0.78259132152244826, 2.98785575281233262 };
  double likelihood = -1887.53386424751988670;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -10760.54514912144804839;
  geometry->gradient_log_likelihood[1] = -13405.90485608788912941;
  geometry->gradient_log_likelihood[2] = -6910.00157476080221386;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 117951.24691969683044590;
  geometry->FI[0 * geometry->ldfi + 1] = 90523.18481037011952139;
  geometry->FI[0 * geometry->ldfi + 2] = 45169.20373158595612040;
  geometry->FI[1 * geometry->ldfi + 0] = 90523.18481037011952139;
  geometry->FI[1 * geometry->ldfi + 1] = 100230.82247847921098582;
  geometry->FI[1 * geometry->ldfi + 2] = 50385.01875733572524041;
  geometry->FI[2 * geometry->ldfi + 0] = 45169.20373158595612040;
  geometry->FI[2 * geometry->ldfi + 1] = 50385.01875733572524041;
  geometry->FI[2 * geometry->ldfi + 2] = 26608.02409561578315333;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.07961797701261583, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.78224908298806950, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98744699188251772, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00033659817348019, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00034839902320441, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00008832748486469, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00034839902320441, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00288126935899815, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00486454401025518, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00008832748486469, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00486454401025518, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00951833647624812, 1.0e-06);

}

// Sample number 13572
static void test_ode_likelihood_fitzhugh_simp_mmala25() {
  // Input argument
  double params[] = { 0.43200369796210730, 0.28131677859128496, 2.74447935659651820 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -1863.89946897182153407, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -31471.11518838893607608, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -7831.46399131458565535, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -9680.11042011242170702, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 450612.63997984508750960, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 125409.15968187295948155, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 144675.44519366812892258, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 125409.15968187295948155, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 38789.61051777518878225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 41628.85262460988451494, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 144675.44519366812892258, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 41628.85262460988451494, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 49787.50565179833211005, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 13572
static void test_ode_proposal_fitzhugh_simp_mmala25() {
  // Input arguments
  double params[] = { 0.43200369796210730, 0.28131677859128496, 2.74447935659651820 };
  double likelihood = -1863.89946897182153407;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -31471.11518838893607608;
  geometry->gradient_log_likelihood[1] = -7831.46399131458565535;
  geometry->gradient_log_likelihood[2] = -9680.11042011242170702;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 450612.63997984508750960;
  geometry->FI[0 * geometry->ldfi + 1] = 125409.15968187295948155;
  geometry->FI[0 * geometry->ldfi + 2] = 144675.44519366812892258;
  geometry->FI[1 * geometry->ldfi + 0] = 125409.15968187295948155;
  geometry->FI[1 * geometry->ldfi + 1] = 38789.61051777518878225;
  geometry->FI[1 * geometry->ldfi + 2] = 41628.85262460988451494;
  geometry->FI[2 * geometry->ldfi + 0] = 144675.44519366812892258;
  geometry->FI[2 * geometry->ldfi + 1] = 41628.85262460988451494;
  geometry->FI[2 * geometry->ldfi + 2] = 49787.50565179833211005;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.43152969806214064, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.28206238782136966, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.74459301954134283, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00048128416921806, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00053677280684062, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00094973155932172, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00053677280684062, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00365046042572000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00149247553786747, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00094973155932172, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00149247553786747, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00425180062480132, 1.0e-06);

}

// Sample number 15152
static void test_ode_likelihood_fitzhugh_simp_mmala26() {
  // Input argument
  double params[] = { 1.67952550552606916, 1.19035449428852180, 2.97893580470204400 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -13828.53772597956412937, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -2115.08304545909049921, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 890.38332190303185598, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -285.78958602181177184, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 6722.92236820781272399, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -733.84859788804646996, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 269.45888547565630233, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -733.84859788804646996, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 471.30092893508867746, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -96.63369689274752261, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 269.45888547565630233, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -96.63369689274752261, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 126.61128842020666241, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15152
static void test_ode_proposal_fitzhugh_simp_mmala26() {
  // Input arguments
  double params[] = { 1.67952550552606916, 1.19035449428852180, 2.97893580470204400 };
  double likelihood = -13828.53772597956412937;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -2115.08304545909049921;
  geometry->gradient_log_likelihood[1] = 890.38332190303185598;
  geometry->gradient_log_likelihood[2] = -285.78958602181177184;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 6722.92236820781272399;
  geometry->FI[0 * geometry->ldfi + 1] = -733.84859788804646996;
  geometry->FI[0 * geometry->ldfi + 2] = 269.45888547565630233;
  geometry->FI[1 * geometry->ldfi + 0] = -733.84859788804646996;
  geometry->FI[1 * geometry->ldfi + 1] = 471.30092893508867746;
  geometry->FI[1 * geometry->ldfi + 2] = -96.63369689274752261;
  geometry->FI[2 * geometry->ldfi + 0] = 269.45888547565630233;
  geometry->FI[2 * geometry->ldfi + 1] = -96.63369689274752261;
  geometry->FI[2 * geometry->ldfi + 2] = 126.61128842020666241;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 1.67915453243514090, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 1.19543043397180138, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97616601819532312, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00223097752520922, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00296412225752103, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00248573906485540, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00296412225752103, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.03450983689010528, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.02003063130922720, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00248573906485540, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.02003063130922720, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.11657021963215558, 1.0e-06);

}

// Sample number 14859
static void test_ode_likelihood_fitzhugh_simp_mmala27() {
  // Input argument
  double params[] = { 2.37368330546891126, 6.64322972109641796, 3.56885615978620940 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -14448.89076364125685359, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1829.72185314163425573, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -1849.22270407900009559, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 3145.64610607183612956, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 12911.72975641332595842, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -9696.96245084127622249, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 16218.51158657092310023, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -9696.96245084127622249, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 7451.81629297051676986, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -12507.16321115751270554, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 16218.51158657092310023, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -12507.16321115751270554, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 21017.99958801550383214, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 14859
static void test_ode_proposal_fitzhugh_simp_mmala27() {
  // Input arguments
  double params[] = { 2.37368330546891126, 6.64322972109641796, 3.56885615978620940 };
  double likelihood = -14448.89076364125685359;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1829.72185314163425573;
  geometry->gradient_log_likelihood[1] = -1849.22270407900009559;
  geometry->gradient_log_likelihood[2] = 3145.64610607183612956;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 12911.72975641332595842;
  geometry->FI[0 * geometry->ldfi + 1] = -9696.96245084127622249;
  geometry->FI[0 * geometry->ldfi + 2] = 16218.51158657092310023;
  geometry->FI[1 * geometry->ldfi + 0] = -9696.96245084127622249;
  geometry->FI[1 * geometry->ldfi + 1] = 7451.81629297051676986;
  geometry->FI[1 * geometry->ldfi + 2] = -12507.16321115751270554;
  geometry->FI[2 * geometry->ldfi + 0] = 16218.51158657092310023;
  geometry->FI[2 * geometry->ldfi + 1] = -12507.16321115751270554;
  geometry->FI[2 * geometry->ldfi + 2] = 21017.99958801550383214;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.36419477060105487, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 6.60402947009136199, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.55334398600267098, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.07225634935797917, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.36033913643424631, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.15867018826028309, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.36033913643424637, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 3.11958749622452913, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 1.57831507077999644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.15867018826028326, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 1.57831507077999644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.81734722172105712, 1.0e-06);

}

// Sample number 7842
static void test_ode_likelihood_fitzhugh_simp_mmala28() {
  // Input argument
  double params[] = { 2.95428174002215371, 4.29805945283107960, 0.39499808820572735 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -16793.02062743651913479, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -2753.69591323946860939, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 1795.22142074559224056, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -2482.80546497384329996, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 6790.53628197296893632, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -5517.95308566065887135, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 26628.97615561443672050, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -5517.95308566065887135, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 4639.91055941908689420, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -22884.77964108402738930, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 26628.97615561443672050, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -22884.77964108402738930, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 122089.85855382664885838, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 7842
static void test_ode_proposal_fitzhugh_simp_mmala28() {
  // Input arguments
  double params[] = { 2.95428174002215371, 4.29805945283107960, 0.39499808820572735 };
  double likelihood = -16793.02062743651913479;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -2753.69591323946860939;
  geometry->gradient_log_likelihood[1] = 1795.22142074559224056;
  geometry->gradient_log_likelihood[2] = -2482.80546497384329996;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 6790.53628197296893632;
  geometry->FI[0 * geometry->ldfi + 1] = -5517.95308566065887135;
  geometry->FI[0 * geometry->ldfi + 2] = 26628.97615561443672050;
  geometry->FI[1 * geometry->ldfi + 0] = -5517.95308566065887135;
  geometry->FI[1 * geometry->ldfi + 1] = 4639.91055941908689420;
  geometry->FI[1 * geometry->ldfi + 2] = -22884.77964108402738930;
  geometry->FI[2 * geometry->ldfi + 0] = 26628.97615561443672050;
  geometry->FI[2 * geometry->ldfi + 1] = -22884.77964108402738930;
  geometry->FI[2 * geometry->ldfi + 2] = 122089.85855382664885838;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 2.95060348982605669, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 4.30503145399377019, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 0.39704022698530872, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.06360693490551636, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.09560154239657512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], 0.00404646777393760, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.09560154239657515, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.17838072369587046, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.01258443886558646, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], 0.00404646777393760, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.01258443886558646, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00157582690343375, 1.0e-06);

}

// Sample number 13105
static void test_ode_likelihood_fitzhugh_simp_mmala29() {
  // Input argument
  double params[] = { 0.02922655215442187, 0.23086409477263986, 3.09743064193888262 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -354.19339981478003665, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 5888.45899639265735459, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 282.78773453915687242, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 2542.95963529820346594, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 45347.94651342930592364, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 4928.31425014203523460, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 26609.81627833686070517, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 4928.31425014203523460, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3569.96091268608779501, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 8328.81457878227956826, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 26609.81627833686070517, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 8328.81457878227956826, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 42004.37335836527927313, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 13105
static void test_ode_proposal_fitzhugh_simp_mmala29() {
  // Input arguments
  double params[] = { 0.02922655215442187, 0.23086409477263986, 3.09743064193888262 };
  double likelihood = -354.19339981478003665;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 5888.45899639265735459;
  geometry->gradient_log_likelihood[1] = 282.78773453915687242;
  geometry->gradient_log_likelihood[2] = 2542.95963529820346594;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 45347.94651342930592364;
  geometry->FI[0 * geometry->ldfi + 1] = 4928.31425014203523460;
  geometry->FI[0 * geometry->ldfi + 2] = 26609.81627833686070517;
  geometry->FI[1 * geometry->ldfi + 0] = 4928.31425014203523460;
  geometry->FI[1 * geometry->ldfi + 1] = 3569.96091268608779501;
  geometry->FI[1 * geometry->ldfi + 2] = 8328.81457878227956826;
  geometry->FI[2 * geometry->ldfi + 0] = 26609.81627833686070517;
  geometry->FI[2 * geometry->ldfi + 1] = 8328.81457878227956826;
  geometry->FI[2 * geometry->ldfi + 2] = 42004.37335836527927313;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.02971742399183603, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.23057301988588183, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.09737675968835013, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042753242953679, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00007755113500124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00028621944491906, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00007755113500124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00634909635692071, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00130805588469116, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00028621944491906, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00130805588469116, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00073003038925952, 1.0e-06);

}

// Sample number 3423
static void test_ode_likelihood_fitzhugh_simp_mmala30() {
  // Input argument
  double params[] = { 0.37515850886622848, 0.65431063830975655, 1.98212433514485542 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -1377.97078017276976425, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -27434.76767147647115053, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -19987.40213944881907082, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -1099.59954007477654159, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 1316874.81976339383982122, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 964227.35702548525296152, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 90727.22064665300422348, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 964227.35702548525296152, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 714826.91067950823344290, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 66622.84206718722998630, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 90727.22064665300422348, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 66622.84206718722998630, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 7976.61916189730891347, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 3423
static void test_ode_proposal_fitzhugh_simp_mmala30() {
  // Input arguments
  double params[] = { 0.37515850886622848, 0.65431063830975655, 1.98212433514485542 };
  double likelihood = -1377.97078017276976425;
  double temperature = 0.00054192280986977;
  double stepsize = 0.08115632763568126;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -27434.76767147647115053;
  geometry->gradient_log_likelihood[1] = -19987.40213944881907082;
  geometry->gradient_log_likelihood[2] = -1099.59954007477654159;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 1316874.81976339383982122;
  geometry->FI[0 * geometry->ldfi + 1] = 964227.35702548525296152;
  geometry->FI[0 * geometry->ldfi + 2] = 90727.22064665300422348;
  geometry->FI[1 * geometry->ldfi + 0] = 964227.35702548525296152;
  geometry->FI[1 * geometry->ldfi + 1] = 714826.91067950823344290;
  geometry->FI[1 * geometry->ldfi + 2] = 66622.84206718722998630;
  geometry->FI[2 * geometry->ldfi + 0] = 90727.22064665300422348;
  geometry->FI[2 * geometry->ldfi + 1] = 66622.84206718722998630;
  geometry->FI[2 * geometry->ldfi + 2] = 7976.61916189730891347;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.37498249412559059, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.65431544430956246, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 1.98363223782290032, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00076855236404883, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00100184386464646, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00037395972914092, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00100184386464646, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00138268991468132, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00015347635728670, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00037395972914092, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00015347635728670, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00705900884760861, 1.0e-06);

}

// Sample number 14121
static void test_ode_likelihood_fitzhugh_simp_mmala31() {
  // Input argument
  double params[] = { 0.28245270301918429, 0.36092828009455741, 2.75118833985311539 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -15.03796518953741668, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 321.64754439838679900, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 238.68853745326441640, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 1356.28245521357757752, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 213274.79174033179879189, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 69266.61288890082505532, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 89951.34309505876444746, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 69266.61288890082505532, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 26760.20459372940240428, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 32021.29461601899311063, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 89951.34309505876444746, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 32021.29461601899311063, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 43532.05039121350273490, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 14121
static void test_ode_proposal_fitzhugh_simp_mmala31() {
  // Input arguments
  double params[] = { 0.28245270301918429, 0.36092828009455741, 2.75118833985311539 };
  double likelihood = -15.03796518953741668;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 321.64754439838679900;
  geometry->gradient_log_likelihood[1] = 238.68853745326441640;
  geometry->gradient_log_likelihood[2] = 1356.28245521357757752;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 213274.79174033179879189;
  geometry->FI[0 * geometry->ldfi + 1] = 69266.61288890082505532;
  geometry->FI[0 * geometry->ldfi + 2] = 89951.34309505876444746;
  geometry->FI[1 * geometry->ldfi + 0] = 69266.61288890082505532;
  geometry->FI[1 * geometry->ldfi + 1] = 26760.20459372940240428;
  geometry->FI[1 * geometry->ldfi + 2] = 32021.29461601899311063;
  geometry->FI[2 * geometry->ldfi + 0] = 89951.34309505876444746;
  geometry->FI[2 * geometry->ldfi + 1] = 32021.29461601899311063;
  geometry->FI[2 * geometry->ldfi + 2] = 43532.05039121350273490;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.27641198409717044, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.34678929321320889, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.77670035473852872, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00168052840369068, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00162508958425439, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00227713406043805, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00162508958425439, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01436585590421697, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00720927019854041, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00227713406043805, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00720927019854041, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01095055378458977, 1.0e-06);

}

// Sample number 637
static void test_ode_likelihood_fitzhugh_simp_mmala32() {
  // Input argument
  double params[] = { 0.24489316831907842, 0.46750941962857151, 2.76947764626931381 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -9.14487859420505345, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -2144.58513987153492053, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -1175.34512250794114152, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -124.17497053136276008, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 203686.45557689823908731, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 89961.29257739063177723, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 83738.77908797410782427, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 89961.29257739063177723, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 45858.77355538686970249, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 41273.79277311131590977, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 83738.77908797410782427, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 41273.79277311131590977, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 40291.10467237271950580, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 637
static void test_ode_proposal_fitzhugh_simp_mmala32() {
  // Input arguments
  double params[] = { 0.24489316831907842, 0.46750941962857151, 2.76947764626931381 };
  double likelihood = -9.14487859420505345;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -2144.58513987153492053;
  geometry->gradient_log_likelihood[1] = -1175.34512250794114152;
  geometry->gradient_log_likelihood[2] = -124.17497053136276008;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 203686.45557689823908731;
  geometry->FI[0 * geometry->ldfi + 1] = 89961.29257739063177723;
  geometry->FI[0 * geometry->ldfi + 2] = 83738.77908797410782427;
  geometry->FI[1 * geometry->ldfi + 0] = 89961.29257739063177723;
  geometry->FI[1 * geometry->ldfi + 1] = 45858.77355538686970249;
  geometry->FI[1 * geometry->ldfi + 2] = 41273.79277311131590977;
  geometry->FI[2 * geometry->ldfi + 0] = 83738.77908797410782427;
  geometry->FI[2 * geometry->ldfi + 1] = 41273.79277311131590977;
  geometry->FI[2 * geometry->ldfi + 2] = 40291.10467237271950580;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.24263677946811557, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.44542322286080938, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.79653195365083862, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00165629656956522, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00193486249852922, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00146030095756039, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00193486249852922, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01372335900845795, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.01003675763731165, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00146030095756039, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.01003675763731165, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01433461568861071, 1.0e-06);

}

// Sample number 5538
static void test_ode_likelihood_fitzhugh_simp_mmala33() {
  // Input argument
  double params[] = { 0.18753095622084062, 0.02900604298165450, 2.92598839658119481 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -39.71537958407562030, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 5495.14340106115650997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -440.74210683053763660, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 3881.24921553230251448, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 102456.47869145865843166, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -12295.07404110969036992, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 59183.55944609967991710, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -12295.07404110969036992, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 4346.07187670762505149, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -9074.54555798296860303, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 59183.55944609967991710, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -9074.54555798296860303, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45972.23506971835740842, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 5538
static void test_ode_proposal_fitzhugh_simp_mmala33() {
  // Input arguments
  double params[] = { 0.18753095622084062, 0.02900604298165450, 2.92598839658119481 };
  double likelihood = -39.71537958407562030;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 5495.14340106115650997;
  geometry->gradient_log_likelihood[1] = -440.74210683053763660;
  geometry->gradient_log_likelihood[2] = 3881.24921553230251448;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 102456.47869145865843166;
  geometry->FI[0 * geometry->ldfi + 1] = -12295.07404110969036992;
  geometry->FI[0 * geometry->ldfi + 2] = 59183.55944609967991710;
  geometry->FI[1 * geometry->ldfi + 0] = -12295.07404110969036992;
  geometry->FI[1 * geometry->ldfi + 1] = 4346.07187670762505149;
  geometry->FI[1 * geometry->ldfi + 2] = -9074.54555798296860303;
  geometry->FI[2 * geometry->ldfi + 0] = 59183.55944609967991710;
  geometry->FI[2 * geometry->ldfi + 1] = -9074.54555798296860303;
  geometry->FI[2 * geometry->ldfi + 2] = 45972.23506971835740842;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.18939408595234411, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.04020217542413115, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.93292546220467010, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00157051013700407, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00037665266015652, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00194748913543535, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00037665266015652, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01614565522808655, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00270212746105262, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00194748913543535, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00270212746105262, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00393277691451990, 1.0e-06);

}

// Sample number 924
static void test_ode_likelihood_fitzhugh_simp_mmala34() {
  // Input argument
  double params[] = { 0.21901735622133420, 0.36970602298383393, 2.90890350578275036 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 96.40450694676432875, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1768.41579133042660033, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -960.03339262896099626, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -622.63301579668802788, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 153489.38466444928781129, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 49834.80310561186342966, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 73306.78237348643597215, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 49834.80310561186342966, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 20709.46879440609700396, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 27854.45942717015714152, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 73306.78237348643597215, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 27854.45942717015714152, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 42895.97821107433264842, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 924
static void test_ode_proposal_fitzhugh_simp_mmala34() {
  // Input arguments
  double params[] = { 0.21901735622133420, 0.36970602298383393, 2.90890350578275036 };
  double likelihood = 96.40450694676432875;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -1768.41579133042660033;
  geometry->gradient_log_likelihood[1] = -960.03339262896099626;
  geometry->gradient_log_likelihood[2] = -622.63301579668802788;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 153489.38466444928781129;
  geometry->FI[0 * geometry->ldfi + 1] = 49834.80310561186342966;
  geometry->FI[0 * geometry->ldfi + 2] = 73306.78237348643597215;
  geometry->FI[1 * geometry->ldfi + 0] = 49834.80310561186342966;
  geometry->FI[1 * geometry->ldfi + 1] = 20709.46879440609700396;
  geometry->FI[1 * geometry->ldfi + 2] = 27854.45942717015714152;
  geometry->FI[2 * geometry->ldfi + 0] = 73306.78237348643597215;
  geometry->FI[2 * geometry->ldfi + 1] = 27854.45942717015714152;
  geometry->FI[2 * geometry->ldfi + 2] = 42895.97821107433264842;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21827600818425216, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.35245026366968601, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.92015036830122110, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00155902095996840, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00132769206599476, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00180214250071871, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00132769206599476, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01677349249723953, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00862290005499691, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00180214250071871, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00862290005499691, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00963526493844004, 1.0e-06);

}

// Sample number 1943
static void test_ode_likelihood_fitzhugh_simp_mmala35() {
  // Input argument
  double params[] = { 0.16055065489838621, 0.15885605931934271, 3.04302405626373451 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 126.93787080428363367, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1959.30737689481293273, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 58.89116349130750194, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 537.71119780390893084, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 94879.93687012424925342, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 5313.62637497727246227, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 55059.89850583376392024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 5313.62637497727246227, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2506.67550431707650205, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 4219.59729916211108502, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 55059.89850583376392024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 4219.59729916211108502, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44891.80448590346350102, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 1943
static void test_ode_proposal_fitzhugh_simp_mmala35() {
  // Input arguments
  double params[] = { 0.16055065489838621, 0.15885605931934271, 3.04302405626373451 };
  double likelihood = 126.93787080428363367;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1959.30737689481293273;
  geometry->gradient_log_likelihood[1] = 58.89116349130750194;
  geometry->gradient_log_likelihood[2] = 537.71119780390893084;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 94879.93687012424925342;
  geometry->FI[0 * geometry->ldfi + 1] = 5313.62637497727246227;
  geometry->FI[0 * geometry->ldfi + 2] = 55059.89850583376392024;
  geometry->FI[1 * geometry->ldfi + 0] = 5313.62637497727246227;
  geometry->FI[1 * geometry->ldfi + 1] = 2506.67550431707650205;
  geometry->FI[1 * geometry->ldfi + 2] = 4219.59729916211108502;
  geometry->FI[2 * geometry->ldfi + 0] = 55059.89850583376392024;
  geometry->FI[2 * geometry->ldfi + 1] = 4219.59729916211108502;
  geometry->FI[2 * geometry->ldfi + 2] = 44891.80448590346350102;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.16456157995706425, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15892716325979250, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.03910890777776643, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00150032727856738, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00009832280505633, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00183091292457628, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00009832280505633, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01944604258590008, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00170723422649921, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00183091292457628, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00170723422649921, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00331981192252498, 1.0e-06);

}

// Sample number 16466
static void test_ode_likelihood_fitzhugh_simp_mmala36() {
  // Input argument
  double params[] = { 0.32987381827005913, 0.21770680445884621, 2.86753911603078038 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -302.19205994190508591, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -12664.92826438462361693, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -1945.97013598801731860, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -4622.29823190992192394, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 241587.92078782466705889, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 41070.28809569220175035, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 101665.28187621814140584, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 41070.28809569220175035, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 10001.11754235115222400, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 18663.38177782424463658, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 101665.28187621814140584, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 18663.38177782424463658, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 48206.66689757841231767, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 16466
static void test_ode_proposal_fitzhugh_simp_mmala36() {
  // Input arguments
  double params[] = { 0.32987381827005913, 0.21770680445884621, 2.86753911603078038 };
  double likelihood = -302.19205994190508591;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -12664.92826438462361693;
  geometry->gradient_log_likelihood[1] = -1945.97013598801731860;
  geometry->gradient_log_likelihood[2] = -4622.29823190992192394;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 241587.92078782466705889;
  geometry->FI[0 * geometry->ldfi + 1] = 41070.28809569220175035;
  geometry->FI[0 * geometry->ldfi + 2] = 101665.28187621814140584;
  geometry->FI[1 * geometry->ldfi + 0] = 41070.28809569220175035;
  geometry->FI[1 * geometry->ldfi + 1] = 10001.11754235115222400;
  geometry->FI[1 * geometry->ldfi + 2] = 18663.38177782424463658;
  geometry->FI[2 * geometry->ldfi + 0] = 101665.28187621814140584;
  geometry->FI[2 * geometry->ldfi + 1] = 18663.38177782424463658;
  geometry->FI[2 * geometry->ldfi + 2] = 48206.66689757841231767;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.32076311934505480, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.21856372283711495, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.87832859149020326, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00156994169281549, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00096736234879144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00293640529425271, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00096736234879144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01537476747624320, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00391228021818603, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00293640529425271, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00391228021818603, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00855826600038555, 1.0e-06);

}

// Sample number 13893
static void test_ode_likelihood_fitzhugh_simp_mmala37() {
  // Input argument
  double params[] = { 0.18173075532058772, 0.18263993520273986, 3.12158914879382632 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -52.32588718785501669, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -5111.78671626870618638, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -670.99740983506399061, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -4098.94384090293351619, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 111905.02677726635010913, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 10800.47497289277453092, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 61583.80583765629853588, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 10800.47497289277453092, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3319.06512439181369700, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 7663.51489077416044893, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 61583.80583765629853588, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 7663.51489077416044893, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45371.64107049294398166, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 13893
static void test_ode_proposal_fitzhugh_simp_mmala37() {
  // Input arguments
  double params[] = { 0.18173075532058772, 0.18263993520273986, 3.12158914879382632 };
  double likelihood = -52.32588718785501669;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -5111.78671626870618638;
  geometry->gradient_log_likelihood[1] = -670.99740983506399061;
  geometry->gradient_log_likelihood[2] = -4098.94384090293351619;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 111905.02677726635010913;
  geometry->FI[0 * geometry->ldfi + 1] = 10800.47497289277453092;
  geometry->FI[0 * geometry->ldfi + 2] = 61583.80583765629853588;
  geometry->FI[1 * geometry->ldfi + 0] = 10800.47497289277453092;
  geometry->FI[1 * geometry->ldfi + 1] = 3319.06512439181369700;
  geometry->FI[1 * geometry->ldfi + 2] = 7663.51489077416044893;
  geometry->FI[2 * geometry->ldfi + 0] = 61583.80583765629853588;
  geometry->FI[2 * geometry->ldfi + 1] = 7663.51489077416044893;
  geometry->FI[2 * geometry->ldfi + 2] = 45371.64107049294398166;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.18306856658966017, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.18326596365290773, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.11204270408785044, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00145262195750184, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00028600922488012, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00192336337354337, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00028600922488012, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.02031586532083923, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00304325337533836, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00192336337354337, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00304325337533836, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00402869891460316, 1.0e-06);

}

// Sample number 6340
static void test_ode_likelihood_fitzhugh_simp_mmala38() {
  // Input argument
  double params[] = { 0.25914820837195685, 0.26832200943197421, 2.91456339416344301 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 72.06469003423586628, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -4555.35155388155635592, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -1055.18448246019670478, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -1662.38620978449080212, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 173994.68433999264379963, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 36682.75385371786251199, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 81814.05967168961069547, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 36682.75385371786251199, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 10895.73773726262152195, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 19541.03056000817741733, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 81814.05967168961069547, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 19541.03056000817741733, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45604.46448742966458667, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 6340
static void test_ode_proposal_fitzhugh_simp_mmala38() {
  // Input arguments
  double params[] = { 0.25914820837195685, 0.26832200943197421, 2.91456339416344301 };
  double likelihood = 72.06469003423586628;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -4555.35155388155635592;
  geometry->gradient_log_likelihood[1] = -1055.18448246019670478;
  geometry->gradient_log_likelihood[2] = -1662.38620978449080212;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 173994.68433999264379963;
  geometry->FI[0 * geometry->ldfi + 1] = 36682.75385371786251199;
  geometry->FI[0 * geometry->ldfi + 2] = 81814.05967168961069547;
  geometry->FI[1 * geometry->ldfi + 0] = 36682.75385371786251199;
  geometry->FI[1 * geometry->ldfi + 1] = 10895.73773726262152195;
  geometry->FI[1 * geometry->ldfi + 2] = 19541.03056000817741733;
  geometry->FI[2 * geometry->ldfi + 0] = 81814.05967168961069547;
  geometry->FI[2 * geometry->ldfi + 1] = 19541.03056000817741733;
  geometry->FI[2 * geometry->ldfi + 2] = 45604.46448742966458667;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.25478829999295333, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.25966120525982583, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.92301951079511824, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00156724517308373, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00101038203551995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00237868781262330, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00101038203551995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01691175308922491, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00543388965488084, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00237868781262330, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00543388965488084, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00749515516330291, 1.0e-06);

}

// Sample number 18997
static void test_ode_likelihood_fitzhugh_simp_mmala39() {
  // Input argument
  double params[] = { 0.15995808664012778, 0.21121571691060487, 3.03882996952186257 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 125.44120747092051715, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1817.08216544244851320, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -3.38204458928091611, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 415.98942817622457824, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 96832.05272732165758498, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 11919.00446919142086699, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 55450.04818002563115442, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 11919.00446919142086699, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3999.65810871356643474, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 9191.99689666331141780, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 55450.04818002563115442, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 9191.99689666331141780, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44349.86729545574053191, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 18997
static void test_ode_proposal_fitzhugh_simp_mmala39() {
  // Input arguments
  double params[] = { 0.15995808664012778, 0.21121571691060487, 3.03882996952186257 };
  double likelihood = 125.44120747092051715;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1817.08216544244851320;
  geometry->gradient_log_likelihood[1] = -3.38204458928091611;
  geometry->gradient_log_likelihood[2] = 415.98942817622457824;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 96832.05272732165758498;
  geometry->FI[0 * geometry->ldfi + 1] = 11919.00446919142086699;
  geometry->FI[0 * geometry->ldfi + 2] = 55450.04818002563115442;
  geometry->FI[1 * geometry->ldfi + 0] = 11919.00446919142086699;
  geometry->FI[1 * geometry->ldfi + 1] = 3999.65810871356643474;
  geometry->FI[1 * geometry->ldfi + 2] = 9191.99689666331141780;
  geometry->FI[2 * geometry->ldfi + 0] = 55450.04818002563115442;
  geometry->FI[2 * geometry->ldfi + 1] = 9191.99689666331141780;
  geometry->FI[2 * geometry->ldfi + 2] = 44349.86729545574053191;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.16400687501896763, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.20678098687649926, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.03547862276545688, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00149611280493652, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00030455841991412, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00180744683026354, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00030455841991412, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01964582070000208, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00369102668917626, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00180744683026354, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00369102668917626, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00394971974890005, 1.0e-06);

}

// Sample number 689
static void test_ode_likelihood_fitzhugh_simp_mmala40() {
  // Input argument
  double params[] = { 0.05244195298972831, 0.50482514307274884, 3.12006291672564284 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -408.55716957690611935, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 872.79439526509690950, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -2956.07562017048621783, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -3087.90876856601335021, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 63214.30835848159767920, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 29076.48396458339993842, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 34187.60727851412957534, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 29076.48396458339993842, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 28921.36699262648835429, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 32073.87956669385312125, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 34187.60727851412957534, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 32073.87956669385312125, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 38586.98990406160010025, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 689
static void test_ode_proposal_fitzhugh_simp_mmala40() {
  // Input arguments
  double params[] = { 0.05244195298972831, 0.50482514307274884, 3.12006291672564284 };
  double likelihood = -408.55716957690611935;
  double temperature = 0.00411522633744856;
  double stepsize = 0.41085390865563637;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 872.79439526509690950;
  geometry->gradient_log_likelihood[1] = -2956.07562017048621783;
  geometry->gradient_log_likelihood[2] = -3087.90876856601335021;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 63214.30835848159767920;
  geometry->FI[0 * geometry->ldfi + 1] = 29076.48396458339993842;
  geometry->FI[0 * geometry->ldfi + 2] = 34187.60727851412957534;
  geometry->FI[1 * geometry->ldfi + 0] = 29076.48396458339993842;
  geometry->FI[1 * geometry->ldfi + 1] = 28921.36699262648835429;
  geometry->FI[1 * geometry->ldfi + 2] = 32073.87956669385312125;
  geometry->FI[2 * geometry->ldfi + 0] = 34187.60727851412957534;
  geometry->FI[2 * geometry->ldfi + 1] = 32073.87956669385312125;
  geometry->FI[2 * geometry->ldfi + 2] = 38586.98990406160010025;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.06203967939442937, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.48749294870844001, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.11921202037371392, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00125315803706003, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00036543970964344, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00080652586973764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00036543970964344, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01824638731711233, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.01484279860862538, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00080652586973764, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.01484279860862538, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.01411506710108954, 1.0e-06);

}

// Sample number 8775
static void test_ode_likelihood_fitzhugh_simp_mmala41() {
  // Input argument
  double params[] = { 0.13167909948504586, 0.05081313042973305, 3.06184143852986912 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 58.60121836998956724, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 3050.14865912334016684, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 56.89038070508631506, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 988.19683586974838363, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 78693.49384115490829572, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -7468.81656036854383274, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 48007.60288894304540008, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -7468.81656036854383274, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3149.18239935409383179, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -6539.85064102215437742, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 48007.60288894304540008, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -6539.85064102215437742, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45044.08688490224449197, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 8775
static void test_ode_proposal_fitzhugh_simp_mmala41() {
  // Input arguments
  double params[] = { 0.13167909948504586, 0.05081313042973305, 3.06184143852986912 };
  double likelihood = 58.60121836998956724;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 3050.14865912334016684;
  geometry->gradient_log_likelihood[1] = 56.89038070508631506;
  geometry->gradient_log_likelihood[2] = 988.19683586974838363;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 78693.49384115490829572;
  geometry->FI[0 * geometry->ldfi + 1] = -7468.81656036854383274;
  geometry->FI[0 * geometry->ldfi + 2] = 48007.60288894304540008;
  geometry->FI[1 * geometry->ldfi + 0] = -7468.81656036854383274;
  geometry->FI[1 * geometry->ldfi + 1] = 3149.18239935409383179;
  geometry->FI[1 * geometry->ldfi + 2] = -6539.85064102215437742;
  geometry->FI[2 * geometry->ldfi + 0] = 48007.60288894304540008;
  geometry->FI[2 * geometry->ldfi + 1] = -6539.85064102215437742;
  geometry->FI[2 * geometry->ldfi + 2] = 45044.08688490224449197;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.15205162796562324, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.08034063489011395, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.05041483463625385, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00115041538293906, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00026081646312911, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00118823552322526, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00026081646312911, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01439664056009781, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00181224021735205, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00118823552322526, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00181224021735205, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00222968213645482, 1.0e-06);

}

// Sample number 7631
static void test_ode_likelihood_fitzhugh_simp_mmala42() {
  // Input argument
  double params[] = { 0.17797495359448942, 0.07795516363060223, 3.04087047929198429 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 140.34169359065356275, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 413.54421804426988274, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 196.58472050797973907, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -306.16061601036471984, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 101998.19741159834666178, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -4470.83268714893983997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 58459.99500683934456902, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -4470.83268714893983997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2465.46527075947415142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -3303.00532343345912523, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 58459.99500683934456902, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -3303.00532343345912523, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45746.73589297896978678, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 7631
static void test_ode_proposal_fitzhugh_simp_mmala42() {
  // Input arguments
  double params[] = { 0.17797495359448942, 0.07795516363060223, 3.04087047929198429 };
  double likelihood = 140.34169359065356275;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 413.54421804426988274;
  geometry->gradient_log_likelihood[1] = 196.58472050797973907;
  geometry->gradient_log_likelihood[2] = -306.16061601036471984;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 101998.19741159834666178;
  geometry->FI[0 * geometry->ldfi + 1] = -4470.83268714893983997;
  geometry->FI[0 * geometry->ldfi + 2] = 58459.99500683934456902;
  geometry->FI[1 * geometry->ldfi + 0] = -4470.83268714893983997;
  geometry->FI[1 * geometry->ldfi + 1] = 2465.46527075947415142;
  geometry->FI[1 * geometry->ldfi + 2] = -3303.00532343345912523;
  geometry->FI[2 * geometry->ldfi + 0] = 58459.99500683934456902;
  geometry->FI[2 * geometry->ldfi + 1] = -3303.00532343345912523;
  geometry->FI[2 * geometry->ldfi + 2] = 45746.73589297896978678;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.18624340747273707, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.10030784184815457, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.03008796839918482, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00115676668448469, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00012980865913529, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00146886580201265, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00012980865913529, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01417627992318325, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00085767243765003, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00146886580201265, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00085767243765003, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00262839868522000, 1.0e-06);

}

// Sample number 15309
static void test_ode_likelihood_fitzhugh_simp_mmala43() {
  // Input argument
  double params[] = { 0.18393626510508004, 0.23505783362905960, 3.00473772068422118 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 146.49454651960348883, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 952.38839857185428173, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -85.41403924870240871, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 250.84542782984078713, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 112127.19350794459751341, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 17644.97548877483495744, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 61495.91805536676110933, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 17644.97548877483495744, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 5553.81769922906096326, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 12265.67910089982069621, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 61495.91805536676110933, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 12265.67910089982069621, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44583.15491841047332855, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15309
static void test_ode_proposal_fitzhugh_simp_mmala43() {
  // Input arguments
  double params[] = { 0.18393626510508004, 0.23505783362905960, 3.00473772068422118 };
  double likelihood = 146.49454651960348883;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 952.38839857185428173;
  geometry->gradient_log_likelihood[1] = -85.41403924870240871;
  geometry->gradient_log_likelihood[2] = 250.84542782984078713;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 112127.19350794459751341;
  geometry->FI[0 * geometry->ldfi + 1] = 17644.97548877483495744;
  geometry->FI[0 * geometry->ldfi + 2] = 61495.91805536676110933;
  geometry->FI[1 * geometry->ldfi + 0] = 17644.97548877483495744;
  geometry->FI[1 * geometry->ldfi + 1] = 5553.81769922906096326;
  geometry->FI[1 * geometry->ldfi + 2] = 12265.67910089982069621;
  geometry->FI[2 * geometry->ldfi + 0] = 61495.91805536676110933;
  geometry->FI[2 * geometry->ldfi + 1] = 12265.67910089982069621;
  geometry->FI[2 * geometry->ldfi + 2] = 44583.15491841047332855;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19058407563930377, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.21346498482893206, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00304724609185536, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00116545524926635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00038839953916707, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00150071829860769, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00038839953916707, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01460103613013831, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00348128430488144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00150071829860769, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00348128430488144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00373518299362866, 1.0e-06);

}

// Sample number 15902
static void test_ode_likelihood_fitzhugh_simp_mmala44() {
  // Input argument
  double params[] = { 0.26858615386277629, 0.06124711127584816, 2.96085258637504989 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 5.92480051966533949, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -6611.47725240098588984, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 468.13153127256668995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -2931.94914927377976710, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 161841.04712068187654950, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -5871.18050630663219636, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 80462.14359549032815266, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -5871.18050630663219636, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2764.40910202466011469, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -3390.19171622897465568, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 80462.14359549032815266, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -3390.19171622897465568, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 47954.07510353959514759, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15902
static void test_ode_proposal_fitzhugh_simp_mmala44() {
  // Input arguments
  double params[] = { 0.26858615386277629, 0.06124711127584816, 2.96085258637504989 };
  double likelihood = 5.92480051966533949;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -6611.47725240098588984;
  geometry->gradient_log_likelihood[1] = 468.13153127256668995;
  geometry->gradient_log_likelihood[2] = -2931.94914927377976710;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 161841.04712068187654950;
  geometry->FI[0 * geometry->ldfi + 1] = -5871.18050630663219636;
  geometry->FI[0 * geometry->ldfi + 2] = 80462.14359549032815266;
  geometry->FI[1 * geometry->ldfi + 0] = -5871.18050630663219636;
  geometry->FI[1 * geometry->ldfi + 1] = 2764.40910202466011469;
  geometry->FI[1 * geometry->ldfi + 2] = -3390.19171622897465568;
  geometry->FI[2 * geometry->ldfi + 0] = 80462.14359549032815266;
  geometry->FI[2 * geometry->ldfi + 1] = -3390.19171622897465568;
  geometry->FI[2 * geometry->ldfi + 2] = 47954.07510353959514759;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.25152767164191042, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.08826547908030120, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97466571836022275, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00117589211542387, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00008512854274840, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00196701110301755, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00008512854274840, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01249772709861028, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00074071006007331, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00196701110301755, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00074071006007331, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00401048200627334, 1.0e-06);

}

// Sample number 3737
static void test_ode_likelihood_fitzhugh_simp_mmala45() {
  // Input argument
  double params[] = { 0.21938510156203328, 0.31608652856213948, 2.87260025267006780 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 63.78802611324685756, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 3395.50533190665328220, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 813.43534022124242711, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 2398.88686312344407270, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 142301.15872462326660752, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 37252.77872517645300832, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 70934.32255613205779810, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 37252.77872517645300832, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 13499.89438430193513341, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 21856.41014850782084977, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 70934.32255613205779810, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 21856.41014850782084977, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 43607.80682716658338904, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 3737
static void test_ode_proposal_fitzhugh_simp_mmala45() {
  // Input arguments
  double params[] = { 0.21938510156203328, 0.31608652856213948, 2.87260025267006780 };
  double likelihood = 63.78802611324685756;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 3395.50533190665328220;
  geometry->gradient_log_likelihood[1] = 813.43534022124242711;
  geometry->gradient_log_likelihood[2] = 2398.88686312344407270;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 142301.15872462326660752;
  geometry->FI[0 * geometry->ldfi + 1] = 37252.77872517645300832;
  geometry->FI[0 * geometry->ldfi + 2] = 70934.32255613205779810;
  geometry->FI[1 * geometry->ldfi + 0] = 37252.77872517645300832;
  geometry->FI[1 * geometry->ldfi + 1] = 13499.89438430193513341;
  geometry->FI[1 * geometry->ldfi + 2] = 21856.41014850782084977;
  geometry->FI[2 * geometry->ldfi + 0] = 70934.32255613205779810;
  geometry->FI[2 * geometry->ldfi + 1] = 21856.41014850782084977;
  geometry->FI[2 * geometry->ldfi + 2] = 43607.80682716658338904;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21676664933960182, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.27605515722255014, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.91196645718716285, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00122331406565635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00081712514447502, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00158034850258701, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00081712514447502, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01293608540160330, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00515444793125024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00158034850258701, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00515444793125024, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00587730898550921, 1.0e-06);

}

// Sample number 9793
static void test_ode_likelihood_fitzhugh_simp_mmala46() {
  // Input argument
  double params[] = { 0.22440709131700762, 0.13019537145058899, 2.97717327813071497 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.50829384299026970, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1054.16223714084981111, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 28.93367473246951249, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -394.81461189326864769, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 132009.37819344032322988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 4588.32689573486095469, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 69996.16971292778907809, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 4588.32689573486095469, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2502.83021016177144702, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 2904.14283893699303007, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 69996.16971292778907809, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 2904.14283893699303007, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46558.70984210939786863, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 9793
static void test_ode_proposal_fitzhugh_simp_mmala46() {
  // Input arguments
  double params[] = { 0.22440709131700762, 0.13019537145058899, 2.97717327813071497 };
  double likelihood = 154.50829384299026970;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -1054.16223714084981111;
  geometry->gradient_log_likelihood[1] = 28.93367473246951249;
  geometry->gradient_log_likelihood[2] = -394.81461189326864769;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 132009.37819344032322988;
  geometry->FI[0 * geometry->ldfi + 1] = 4588.32689573486095469;
  geometry->FI[0 * geometry->ldfi + 2] = 69996.16971292778907809;
  geometry->FI[1 * geometry->ldfi + 0] = 4588.32689573486095469;
  geometry->FI[1 * geometry->ldfi + 1] = 2502.83021016177144702;
  geometry->FI[1 * geometry->ldfi + 2] = 2904.14283893699303007;
  geometry->FI[2 * geometry->ldfi + 0] = 69996.16971292778907809;
  geometry->FI[2 * geometry->ldfi + 1] = 2904.14283893699303007;
  geometry->FI[2 * geometry->ldfi + 2] = 46558.70984210939786863;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21964719522276252, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.13695962355768823, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98158845885946500, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00117871487985165, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00011283640280567, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00176503674652397, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00011283640280567, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01359486777988205, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00067835474856936, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00176503674652397, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00067835474856936, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00337324053163589, 1.0e-06);

}

// Sample number 8910
static void test_ode_likelihood_fitzhugh_simp_mmala47() {
  // Input argument
  double params[] = { 0.19440519678266885, 0.13543867866273965, 3.01066647614394167 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.60270395307034619, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 468.68769087443251919, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 54.33705085300425708, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 70.78342637932209414, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 112905.97820609931659419, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 3815.55300677357354289, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 62754.28456014666880947, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 3815.55300677357354289, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2375.87564784081860125, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 2686.83428417286359036, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 62754.28456014666880947, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 2686.83428417286359036, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45824.78994296853488777, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 8910
static void test_ode_proposal_fitzhugh_simp_mmala47() {
  // Input arguments
  double params[] = { 0.19440519678266885, 0.13543867866273965, 3.01066647614394167 };
  double likelihood = 157.60270395307034619;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 468.68769087443251919;
  geometry->gradient_log_likelihood[1] = 54.33705085300425708;
  geometry->gradient_log_likelihood[2] = 70.78342637932209414;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 112905.97820609931659419;
  geometry->FI[0 * geometry->ldfi + 1] = 3815.55300677357354289;
  geometry->FI[0 * geometry->ldfi + 2] = 62754.28456014666880947;
  geometry->FI[1 * geometry->ldfi + 0] = 3815.55300677357354289;
  geometry->FI[1 * geometry->ldfi + 1] = 2375.87564784081860125;
  geometry->FI[1 * geometry->ldfi + 2] = 2686.83428417286359036;
  geometry->FI[2 * geometry->ldfi + 0] = 62754.28456014666880947;
  geometry->FI[2 * geometry->ldfi + 1] = 2686.83428417286359036;
  geometry->FI[2 * geometry->ldfi + 2] = 45824.78994296853488777;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19814477878831391, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14139584860583307, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00561845601615962, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00116982757918830, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00007176917777867, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00159780025166317, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00007176917777867, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01422128998837832, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00073555004055486, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00159780025166317, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00073555004055486, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00291944576924081, 1.0e-06);

}

// Sample number 12922
static void test_ode_likelihood_fitzhugh_simp_mmala48() {
  // Input argument
  double params[] = { 0.30756830105767752, 0.05192014437110582, 2.80103167954327237 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, -3.68288493003970530, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -348.15169183663994090, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 195.38026515087807411, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 1250.58371502025374866, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 187126.10696200429811142, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -8829.62571572517663299, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 88747.74872181378304958, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -8829.62571572517663299, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3414.32154589801120892, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -4636.19397908991959412, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 88747.74872181378304958, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -4636.19397908991959412, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 48782.09351137957128230, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 12922
static void test_ode_proposal_fitzhugh_simp_mmala48() {
  // Input arguments
  double params[] = { 0.30756830105767752, 0.05192014437110582, 2.80103167954327237 };
  double likelihood = -3.68288493003970530;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -348.15169183663994090;
  geometry->gradient_log_likelihood[1] = 195.38026515087807411;
  geometry->gradient_log_likelihood[2] = 1250.58371502025374866;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 187126.10696200429811142;
  geometry->FI[0 * geometry->ldfi + 1] = -8829.62571572517663299;
  geometry->FI[0 * geometry->ldfi + 2] = 88747.74872181378304958;
  geometry->FI[1 * geometry->ldfi + 0] = -8829.62571572517663299;
  geometry->FI[1 * geometry->ldfi + 1] = 3414.32154589801120892;
  geometry->FI[1 * geometry->ldfi + 2] = -4636.19397908991959412;
  geometry->FI[2 * geometry->ldfi + 0] = 88747.74872181378304958;
  geometry->FI[2 * geometry->ldfi + 1] = -4636.19397908991959412;
  geometry->FI[2 * geometry->ldfi + 2] = 48782.09351137957128230;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.28001132957513419, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.07715494969953723, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.86057389959264885, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00123110306098165, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00016358741924020, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00222416043036795, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00016358741924021, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01062732778985183, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00071239947765340, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00222416043036794, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00071239947765340, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00476055685272388, 1.0e-06);

}

// Sample number 14182
static void test_ode_likelihood_fitzhugh_simp_mmala49() {
  // Input argument
  double params[] = { 0.24044589905240638, 0.11139551159578634, 2.91492799092215815 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 123.18649185230924559, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1327.59392197325746565, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 138.52318794445352523, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 1398.49906046948490257, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 139506.53444975119782612, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 1579.47699577651928848, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 72730.58143693022429943, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 1579.47699577651928848, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2493.54208977978987605, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 940.96160253836114862, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 72730.58143693022429943, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 940.96160253836114862, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46655.40335122286342084, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 14182
static void test_ode_proposal_fitzhugh_simp_mmala49() {
  // Input arguments
  double params[] = { 0.24044589905240638, 0.11139551159578634, 2.91492799092215815 };
  double likelihood = 123.18649185230924559;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1327.59392197325746565;
  geometry->gradient_log_likelihood[1] = 138.52318794445352523;
  geometry->gradient_log_likelihood[2] = 1398.49906046948490257;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 139506.53444975119782612;
  geometry->FI[0 * geometry->ldfi + 1] = 1579.47699577651928848;
  geometry->FI[0 * geometry->ldfi + 2] = 72730.58143693022429943;
  geometry->FI[1 * geometry->ldfi + 0] = 1579.47699577651928848;
  geometry->FI[1 * geometry->ldfi + 1] = 2493.54208977978987605;
  geometry->FI[1 * geometry->ldfi + 2] = 940.96160253836114862;
  geometry->FI[2 * geometry->ldfi + 0] = 72730.58143693022429943;
  geometry->FI[2 * geometry->ldfi + 1] = 940.96160253836114862;
  geometry->FI[2 * geometry->ldfi + 2] = 46655.40335122286342084;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.23146903513005776, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.12399499256269084, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.93686472079566308, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00120730574078057, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00005494699707491, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00188094709682522, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00005494699707491, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01274731982692223, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00017143590822109, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00188094709682522, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00017143590822109, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00361161955322021, 1.0e-06);

}

// Sample number 15087
static void test_ode_likelihood_fitzhugh_simp_mmala50() {
  // Input argument
  double params[] = { 0.21996278119012569, 0.39933365894025014, 2.83550923631122487 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 51.11564318046879407, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 2124.41880550837731789, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 569.66151046027619032, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 1663.97533386749546480, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 157073.85246596101205796, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 56947.59787384989613201, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 73584.57550557702779770, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 56947.59787384989613201, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 25733.35119585309075774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 30973.10223695719469106, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 73584.57550557702779770, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 30973.10223695719469106, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 41949.12318727351521375, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15087
static void test_ode_proposal_fitzhugh_simp_mmala50() {
  // Input arguments
  double params[] = { 0.21996278119012569, 0.39933365894025014, 2.83550923631122487 };
  double likelihood = 51.11564318046879407;
  double temperature = 0.01734152991583261;
  double stepsize = 0.73953703558014539;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 2124.41880550837731789;
  geometry->gradient_log_likelihood[1] = 569.66151046027619032;
  geometry->gradient_log_likelihood[2] = 1663.97533386749546480;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 157073.85246596101205796;
  geometry->FI[0 * geometry->ldfi + 1] = 56947.59787384989613201;
  geometry->FI[0 * geometry->ldfi + 2] = 73584.57550557702779770;
  geometry->FI[1 * geometry->ldfi + 0] = 56947.59787384989613201;
  geometry->FI[1 * geometry->ldfi + 1] = 25733.35119585309075774;
  geometry->FI[1 * geometry->ldfi + 2] = 30973.10223695719469106;
  geometry->FI[2 * geometry->ldfi + 0] = 73584.57550557702779770;
  geometry->FI[2 * geometry->ldfi + 1] = 30973.10223695719469106;
  geometry->FI[2 * geometry->ldfi + 2] = 41949.12318727351521375;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21790680713053179, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.33830456119648145, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.89502359155644751, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00123164656223643, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00112505242668619, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00132979717769898, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00112505242668619, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01203803020652376, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00691477230129610, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00132979717769898, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00691477230129609, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00818997777675989, 1.0e-06);

}

// Sample number 5521
static void test_ode_likelihood_fitzhugh_simp_mmala51() {
  // Input argument
  double params[] = { 0.18280891932505533, 0.00002506571740844, 3.01014684480835415 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 123.68804475937305654, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 926.63409970242855707, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 305.58619424774508389, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 228.27081746646763349, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 102656.79750341355975252, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -15302.68686442026410077, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 58976.53494915932242293, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -15302.68686442026410077, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 5281.70599918291463837, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -11405.49784734656714136, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 58976.53494915932242293, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -11405.49784734656714136, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46167.13325222922867397, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 5521
static void test_ode_proposal_fitzhugh_simp_mmala51() {
  // Input arguments
  double params[] = { 0.18280891932505533, 0.00002506571740844, 3.01014684480835415 };
  double likelihood = 123.68804475937305654;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 926.63409970242855707;
  geometry->gradient_log_likelihood[1] = 305.58619424774508389;
  geometry->gradient_log_likelihood[2] = 228.27081746646763349;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 102656.79750341355975252;
  geometry->FI[0 * geometry->ldfi + 1] = -15302.68686442026410077;
  geometry->FI[0 * geometry->ldfi + 2] = 58976.53494915932242293;
  geometry->FI[1 * geometry->ldfi + 0] = -15302.68686442026410077;
  geometry->FI[1 * geometry->ldfi + 1] = 5281.70599918291463837;
  geometry->FI[1 * geometry->ldfi + 2] = -11405.49784734656714136;
  geometry->FI[2 * geometry->ldfi + 0] = 58976.53494915932242293;
  geometry->FI[2 * geometry->ldfi + 1] = -11405.49784734656714136;
  geometry->FI[2 * geometry->ldfi + 2] = 46167.13325222922867397;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20343217874943911, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.11670847730329859, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.01634872587457137, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00104944534791248, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00031204465058410, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00126353146792070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00031204465058410, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01163453023395826, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00247566372971423, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00126353146792070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00247566372971423, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00284171325126884, 1.0e-06);

}

// Sample number 13594
static void test_ode_likelihood_fitzhugh_simp_mmala52() {
  // Input argument
  double params[] = { 0.16040465196022738, 0.22319399987962757, 3.05021359706380668 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 126.28171439251461550, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 987.02536867545450150, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -160.38501463938268898, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -214.15085048226745812, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 98302.29560344161291141, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 13664.83794951709387533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 55917.67816757474793121, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 13664.83794951709387533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 4537.57232539924189041, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 10431.14544980110622419, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 55917.67816757474793121, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 10431.14544980110622419, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44304.04305348606430925, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 13594
static void test_ode_proposal_fitzhugh_simp_mmala52() {
  // Input arguments
  double params[] = { 0.16040465196022738, 0.22319399987962757, 3.05021359706380668 };
  double likelihood = 126.28171439251461550;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 987.02536867545450150;
  geometry->gradient_log_likelihood[1] = -160.38501463938268898;
  geometry->gradient_log_likelihood[2] = -214.15085048226745812;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 98302.29560344161291141;
  geometry->FI[0 * geometry->ldfi + 1] = 13664.83794951709387533;
  geometry->FI[0 * geometry->ldfi + 2] = 55917.67816757474793121;
  geometry->FI[1 * geometry->ldfi + 0] = 13664.83794951709387533;
  geometry->FI[1 * geometry->ldfi + 1] = 4537.57232539924189041;
  geometry->FI[1 * geometry->ldfi + 2] = 10431.14544980110622419;
  geometry->FI[2 * geometry->ldfi + 0] = 55917.67816757474793121;
  geometry->FI[2 * geometry->ldfi + 1] = 10431.14544980110622419;
  geometry->FI[2 * geometry->ldfi + 2] = 44304.04305348606430925;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19539617848074722, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17504733062575295, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.01374799828473572, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00103013746121648, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00024710312471486, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00124199333959737, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00024710312471486, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01372119270794908, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00291870256001805, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00124199333959737, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00291870256001805, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00289665807343944, 1.0e-06);

}

// Sample number 13101
static void test_ode_likelihood_fitzhugh_simp_mmala53() {
  // Input argument
  double params[] = { 0.18273687801951749, 0.32256978570147415, 2.94074926560503958 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 91.83673662101813306, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 3029.17432417658710619, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 484.89403279199831331, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 1720.51673501902405405, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 116970.15151441928173881, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 31130.05321727393675246, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 62178.41620536250411533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 31130.05321727393675246, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 12256.71877173788016080, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 20687.29468470969368354, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 62178.41620536250411533, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 20687.29468470969368354, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 43183.52596583085687598, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 13101
static void test_ode_proposal_fitzhugh_simp_mmala53() {
  // Input arguments
  double params[] = { 0.18273687801951749, 0.32256978570147415, 2.94074926560503958 };
  double likelihood = 91.83673662101813306;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 3029.17432417658710619;
  geometry->gradient_log_likelihood[1] = 484.89403279199831331;
  geometry->gradient_log_likelihood[2] = 1720.51673501902405405;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 116970.15151441928173881;
  geometry->FI[0 * geometry->ldfi + 1] = 31130.05321727393675246;
  geometry->FI[0 * geometry->ldfi + 2] = 62178.41620536250411533;
  geometry->FI[1 * geometry->ldfi + 0] = 31130.05321727393675246;
  geometry->FI[1 * geometry->ldfi + 1] = 12256.71877173788016080;
  geometry->FI[1 * geometry->ldfi + 2] = 20687.29468470969368354;
  geometry->FI[2 * geometry->ldfi + 0] = 62178.41620536250411533;
  geometry->FI[2 * geometry->ldfi + 1] = 20687.29468470969368354;
  geometry->FI[2 * geometry->ldfi + 2] = 43183.52596583085687598;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20378697237601290, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.20169067474579411, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99832975942803470, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00106621269569254, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00061034525110261, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00124281247274030, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00061034525110261, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01246979882531566, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00509490823144956, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00124281247274030, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00509490823144956, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00488878209149977, 1.0e-06);

}

// Sample number 3252
static void test_ode_likelihood_fitzhugh_simp_mmala54() {
  // Input argument
  double params[] = { 0.19556183777119560, 0.31173060713465567, 2.96374550183349461 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 132.79740907537626526, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 240.35386260627581123, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -316.14506585557546714, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 57.12406272570831334, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 126636.93333203256770503, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 32092.14730996848084033, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 65733.84024068614235148, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 32092.14730996848084033, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 11851.81863729111501016, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 20392.02505121974172653, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 65733.84024068614235148, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 20392.02505121974172653, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 43677.44619257950398605, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 3252
static void test_ode_proposal_fitzhugh_simp_mmala54() {
  // Input arguments
  double params[] = { 0.19556183777119560, 0.31173060713465567, 2.96374550183349461 };
  double likelihood = 132.79740907537626526;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 240.35386260627581123;
  geometry->gradient_log_likelihood[1] = -316.14506585557546714;
  geometry->gradient_log_likelihood[2] = 57.12406272570831334;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 126636.93333203256770503;
  geometry->FI[0 * geometry->ldfi + 1] = 32092.14730996848084033;
  geometry->FI[0 * geometry->ldfi + 2] = 65733.84024068614235148;
  geometry->FI[1 * geometry->ldfi + 0] = 32092.14730996848084033;
  geometry->FI[1 * geometry->ldfi + 1] = 11851.81863729111501016;
  geometry->FI[1 * geometry->ldfi + 2] = 20392.02505121974172653;
  geometry->FI[2 * geometry->ldfi + 0] = 65733.84024068614235148;
  geometry->FI[2 * geometry->ldfi + 1] = 20392.02505121974172653;
  geometry->FI[2 * geometry->ldfi + 2] = 43677.44619257950398605;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20566339087609878, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.19499282005847296, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00402929421097431, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00105859066729373, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00063685348279997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00129582891315129, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00063685348279997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01258218026826411, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00491588517303891, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00129582891315129, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00491588517303891, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00489642944392130, 1.0e-06);

}

// Sample number 2380
static void test_ode_likelihood_fitzhugh_simp_mmala55() {
  // Input argument
  double params[] = { 0.20378251599506719, 0.26817275553715797, 2.96186133232363025 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 144.72917392705369366, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 594.99018153223391892, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -108.60365980821794096, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 393.33523612319567064, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 127795.36738232706557028, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 25736.45330054283840582, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 66925.40923683295841329, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 25736.45330054283840582, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 8326.16168706409553124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 16384.94433251978261978, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 66925.40923683295841329, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 16384.94433251978261978, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44554.33396714682749007, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 2380
static void test_ode_proposal_fitzhugh_simp_mmala55() {
  // Input arguments
  double params[] = { 0.20378251599506719, 0.26817275553715797, 2.96186133232363025 };
  double likelihood = 144.72917392705369366;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 594.99018153223391892;
  geometry->gradient_log_likelihood[1] = -108.60365980821794096;
  geometry->gradient_log_likelihood[2] = 393.33523612319567064;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 127795.36738232706557028;
  geometry->FI[0 * geometry->ldfi + 1] = 25736.45330054283840582;
  geometry->FI[0 * geometry->ldfi + 2] = 66925.40923683295841329;
  geometry->FI[1 * geometry->ldfi + 0] = 25736.45330054283840582;
  geometry->FI[1 * geometry->ldfi + 1] = 8326.16168706409553124;
  geometry->FI[1 * geometry->ldfi + 2] = 16384.94433251978261978;
  geometry->FI[2 * geometry->ldfi + 0] = 66925.40923683295841329;
  geometry->FI[2 * geometry->ldfi + 1] = 16384.94433251978261978;
  geometry->FI[2 * geometry->ldfi + 2] = 44554.33396714682749007;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20738638881118876, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.18357112708247714, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99420377827747464, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00106446662069868, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00052030441931124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00140760055596552, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00052030441931124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01261600492420174, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00385800744588510, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00140760055596552, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00385800744588510, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00417145388911127, 1.0e-06);

}

// Sample number 9965
static void test_ode_likelihood_fitzhugh_simp_mmala56() {
  // Input argument
  double params[] = { 0.17586465723155023, 0.13561769001074150, 3.02685720300166805 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 143.67466998423506652, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1484.71209111012990434, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 76.04083055018767823, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 465.95068125931419445, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 102087.97084728223853745, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 2988.08148605513997609, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 58337.07771006958500948, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 2988.08148605513997609, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2284.00062219779920270, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 2273.65795274039601281, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 58337.07771006958500948, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 2273.65795274039601281, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45407.89311588040436618, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 9965
static void test_ode_proposal_fitzhugh_simp_mmala56() {
  // Input arguments
  double params[] = { 0.17586465723155023, 0.13561769001074150, 3.02685720300166805 };
  double likelihood = 143.67466998423506652;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1484.71209111012990434;
  geometry->gradient_log_likelihood[1] = 76.04083055018767823;
  geometry->gradient_log_likelihood[2] = 465.95068125931419445;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 102087.97084728223853745;
  geometry->FI[0 * geometry->ldfi + 1] = 2988.08148605513997609;
  geometry->FI[0 * geometry->ldfi + 2] = 58337.07771006958500948;
  geometry->FI[1 * geometry->ldfi + 0] = 2988.08148605513997609;
  geometry->FI[1 * geometry->ldfi + 1] = 2284.00062219779920270;
  geometry->FI[1 * geometry->ldfi + 2] = 2273.65795274039601281;
  geometry->FI[2 * geometry->ldfi + 0] = 58337.07771006958500948;
  geometry->FI[2 * geometry->ldfi + 1] = 2273.65795274039601281;
  geometry->FI[2 * geometry->ldfi + 2] = 45407.89311588040436618;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20039008579331352, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15313777192519709, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00219325574158091, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00104792547058190, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00003236996577774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00134468496976406, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00003236996577774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01310553761706910, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00061463192198140, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00134468496976406, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00061463192198140, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00238463659338991, 1.0e-06);

}

// Sample number 19190
static void test_ode_likelihood_fitzhugh_simp_mmala57() {
  // Input argument
  double params[] = { 0.20381090361946677, 0.18145674784509394, 2.97830626536475762 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.38498058043859373, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1116.59613290775996575, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 62.63555290845437895, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 704.05739878877398041, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 120535.34431843784113880, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 11254.37003426856608712, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 65379.25773507179837907, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 11254.37003426856608712, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3489.95190908796394069, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 7515.89501861712778918, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 65379.25773507179837907, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 7515.89501861712778918, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45591.80654720521124545, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 19190
static void test_ode_proposal_fitzhugh_simp_mmala57() {
  // Input arguments
  double params[] = { 0.20381090361946677, 0.18145674784509394, 2.97830626536475762 };
  double likelihood = 154.38498058043859373;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1116.59613290775996575;
  geometry->gradient_log_likelihood[1] = 62.63555290845437895;
  geometry->gradient_log_likelihood[2] = 704.05739878877398041;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 120535.34431843784113880;
  geometry->FI[0 * geometry->ldfi + 1] = 11254.37003426856608712;
  geometry->FI[0 * geometry->ldfi + 2] = 65379.25773507179837907;
  geometry->FI[1 * geometry->ldfi + 0] = 11254.37003426856608712;
  geometry->FI[1 * geometry->ldfi + 1] = 3489.95190908796394069;
  geometry->FI[1 * geometry->ldfi + 2] = 7515.89501861712778918;
  geometry->FI[2 * geometry->ldfi + 0] = 65379.25773507179837907;
  geometry->FI[2 * geometry->ldfi + 1] = 7515.89501861712778918;
  geometry->FI[2 * geometry->ldfi + 2] = 45591.80654720521124545;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20714703548932070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16288825106914498, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98820419434108508, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00106593429527614, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00022563554288911, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00149136753105599, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00022563554288911, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01268196741069133, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00176708179554421, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00149136753105599, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00176708179554421, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00305371914863369, 1.0e-06);

}

// Sample number 6806
static void test_ode_likelihood_fitzhugh_simp_mmala58() {
  // Input argument
  double params[] = { 0.21439403654787090, 0.15026581176148512, 2.94623834298170317 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 129.94569354334259970, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 2286.87751350831058517, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 182.59662734536800599, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 1670.30554449295050290, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 124056.49832612332829740, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 6742.21660088016597001, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 66899.48219283274374902, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 6742.21660088016597001, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2756.61688248687642044, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 4406.83953857288906875, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 66899.48219283274374902, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 4406.83953857288906875, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45777.58429635027277982, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 6806
static void test_ode_proposal_fitzhugh_simp_mmala58() {
  // Input arguments
  double params[] = { 0.21439403654787090, 0.15026581176148512, 2.94623834298170317 };
  double likelihood = 129.94569354334259970;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 2286.87751350831058517;
  geometry->gradient_log_likelihood[1] = 182.59662734536800599;
  geometry->gradient_log_likelihood[2] = 1670.30554449295050290;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 124056.49832612332829740;
  geometry->FI[0 * geometry->ldfi + 1] = 6742.21660088016597001;
  geometry->FI[0 * geometry->ldfi + 2] = 66899.48219283274374902;
  geometry->FI[1 * geometry->ldfi + 0] = 6742.21660088016597001;
  geometry->FI[1 * geometry->ldfi + 1] = 2756.61688248687642044;
  geometry->FI[1 * geometry->ldfi + 2] = 4406.83953857288906875;
  geometry->FI[2 * geometry->ldfi + 0] = 66899.48219283274374902;
  geometry->FI[2 * geometry->ldfi + 1] = 4406.83953857288906875;
  geometry->FI[2 * geometry->ldfi + 2] = 45777.58429635027277982;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20989515086434066, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15788279117487325, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.97953738553294745, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00108337299779491, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00014029941657826, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00156973804237394, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00014029941657826, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01221120283776665, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00097049361255839, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00156973804237394, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00097049361255839, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00300868521510646, 1.0e-06);

}

// Sample number 11701
static void test_ode_likelihood_fitzhugh_simp_mmala59() {
  // Input argument
  double params[] = { 0.23685559837778242, 0.16458766857730825, 2.94156712463872561 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 148.24440311732485043, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -508.05560906368151564, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -10.56444480238324246, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 189.46163477417439935, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 142293.93894488655496389, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 11355.83964179898612201, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 73296.30687644750287291, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 11355.83964179898612201, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3387.54040039673100182, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 6854.35903933481495187, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 73296.30687644750287291, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 6854.35903933481495187, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46425.90535834201727994, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 11701
static void test_ode_proposal_fitzhugh_simp_mmala59() {
  // Input arguments
  double params[] = { 0.23685559837778242, 0.16458766857730825, 2.94156712463872561 };
  double likelihood = 148.24440311732485043;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -508.05560906368151564;
  geometry->gradient_log_likelihood[1] = -10.56444480238324246;
  geometry->gradient_log_likelihood[2] = 189.46163477417439935;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 142293.93894488655496389;
  geometry->FI[0 * geometry->ldfi + 1] = 11355.83964179898612201;
  geometry->FI[0 * geometry->ldfi + 2] = 73296.30687644750287291;
  geometry->FI[1 * geometry->ldfi + 0] = 11355.83964179898612201;
  geometry->FI[1 * geometry->ldfi + 1] = 3387.54040039673100182;
  geometry->FI[1 * geometry->ldfi + 2] = 6854.35903933481495187;
  geometry->FI[2 * geometry->ldfi + 0] = 73296.30687644750287291;
  geometry->FI[2 * geometry->ldfi + 1] = 6854.35903933481495187;
  geometry->FI[2 * geometry->ldfi + 2] = 46425.90535834201727994;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21414176385179207, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15748891868280060, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98154635170674176, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00107499064368237, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00024178779851349, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00166147634883873, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00024178779851349, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01202583537845263, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00139377445100048, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00166147634883873, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00139377445100048, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00344144888128715, 1.0e-06);

}

// Sample number 4475
static void test_ode_likelihood_fitzhugh_simp_mmala60() {
  // Input argument
  double params[] = { 0.22163704573102253, 0.22102967885179037, 2.95916383517195314 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 152.26503936943205986, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -546.06050563764949857, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -182.98700380017118050, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -63.83217311257965321, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 136497.51403225376270711, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 20025.34000040876344428, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 70633.50689701206283644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 20025.34000040876344428, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 5656.48129812399747607, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 12339.15743925952483551, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 70633.50689701206283644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 12339.15743925952483551, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45555.25661325928376755, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 4475
static void test_ode_proposal_fitzhugh_simp_mmala60() {
  // Input arguments
  double params[] = { 0.22163704573102253, 0.22102967885179037, 2.95916383517195314 };
  double likelihood = 152.26503936943205986;
  double temperature = 0.05292214940134465;
  double stepsize = 1.22680319758319123;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -546.06050563764949857;
  geometry->gradient_log_likelihood[1] = -182.98700380017118050;
  geometry->gradient_log_likelihood[2] = -63.83217311257965321;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 136497.51403225376270711;
  geometry->FI[0 * geometry->ldfi + 1] = 20025.34000040876344428;
  geometry->FI[0 * geometry->ldfi + 2] = 70633.50689701206283644;
  geometry->FI[1 * geometry->ldfi + 0] = 20025.34000040876344428;
  geometry->FI[1 * geometry->ldfi + 1] = 5656.48129812399747607;
  geometry->FI[1 * geometry->ldfi + 2] = 12339.15743925952483551;
  geometry->FI[2 * geometry->ldfi + 0] = 70633.50689701206283644;
  geometry->FI[2 * geometry->ldfi + 1] = 12339.15743925952483551;
  geometry->FI[2 * geometry->ldfi + 2] = 45555.25661325928376755;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21081279799050201, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17132953079323310, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98835426119092995, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00106771722080148, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00041220434378124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00154384724427183, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00041220434378124, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.01244756311484539, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00273243994005988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00154384724427183, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00273243994005988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00375812219130061, 1.0e-06);

}

// Sample number 15026
static void test_ode_likelihood_fitzhugh_simp_mmala61() {
  // Input argument
  double params[] = { 0.17293207875201463, 0.23042741011073820, 3.01627046179172664 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 137.09378044195887014, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1542.69337727637366697, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -15.18657864357935949, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 466.84621376569299400, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 105017.03399525990244001, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 15709.94345340503969055, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 58714.41708578860561829, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 15709.94345340503969055, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 5076.65123971628509025, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 11411.15562109876736940, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 58714.41708578860561829, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 11411.15562109876736940, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44400.78247259034833405, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15026
static void test_ode_proposal_fitzhugh_simp_mmala61() {
  // Input arguments
  double params[] = { 0.17293207875201463, 0.23042741011073820, 3.01627046179172664 };
  double likelihood = 137.09378044195887014;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1542.69337727637366697;
  geometry->gradient_log_likelihood[1] = -15.18657864357935949;
  geometry->gradient_log_likelihood[2] = 466.84621376569299400;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 105017.03399525990244001;
  geometry->FI[0 * geometry->ldfi + 1] = 15709.94345340503969055;
  geometry->FI[0 * geometry->ldfi + 2] = 58714.41708578860561829;
  geometry->FI[1 * geometry->ldfi + 0] = 15709.94345340503969055;
  geometry->FI[1 * geometry->ldfi + 1] = 5076.65123971628509025;
  geometry->FI[1 * geometry->ldfi + 2] = 11411.15562109876736940;
  geometry->FI[2 * geometry->ldfi + 0] = 58714.41708578860561829;
  geometry->FI[2 * geometry->ldfi + 1] = 11411.15562109876736940;
  geometry->FI[2 * geometry->ldfi + 2] = 44400.78247259034833405;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.19961934255231151, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17526438237900976, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00306932708806462, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042025478895779, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00012155829900625, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00052449288047001, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00012155829900625, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00536596258362401, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00121832558838414, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00052449288047001, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00121832558838414, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00126409349600622, 1.0e-06);

}

// Sample number 5102
static void test_ode_likelihood_fitzhugh_simp_mmala62() {
  // Input argument
  double params[] = { 0.19818487444370622, 0.09240087861927357, 3.01721351046107600 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 152.52727953358879631, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -346.46430229859936389, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 161.10611641799920335, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -439.70524172847069622, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 113859.59360345611639787, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -2252.25701935615052207, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 63325.65247114602243528, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -2252.25701935615052207, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2318.37847321542130885, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -1556.08969015624984422, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 63325.65247114602243528, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -1556.08969015624984422, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46183.62720340553642018, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 5102
static void test_ode_proposal_fitzhugh_simp_mmala62() {
  // Input arguments
  double params[] = { 0.19818487444370622, 0.09240087861927357, 3.01721351046107600 };
  double likelihood = 152.52727953358879631;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -346.46430229859936389;
  geometry->gradient_log_likelihood[1] = 161.10611641799920335;
  geometry->gradient_log_likelihood[2] = -439.70524172847069622;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 113859.59360345611639787;
  geometry->FI[0 * geometry->ldfi + 1] = -2252.25701935615052207;
  geometry->FI[0 * geometry->ldfi + 2] = 63325.65247114602243528;
  geometry->FI[1 * geometry->ldfi + 0] = -2252.25701935615052207;
  geometry->FI[1 * geometry->ldfi + 1] = 2318.37847321542130885;
  geometry->FI[1 * geometry->ldfi + 2] = -1556.08969015624984422;
  geometry->FI[2 * geometry->ldfi + 0] = 63325.65247114602243528;
  geometry->FI[2 * geometry->ldfi + 1] = -1556.08969015624984422;
  geometry->FI[2 * geometry->ldfi + 2] = 46183.62720340553642018;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20553946416875576, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14136910156088883, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00161439847709577, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042293259312255, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00002213482767755, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00057916712595681, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00002213482767755, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00504493799544772, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00013963116341588, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00057916712595681, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00013963116341588, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00104630929603194, 1.0e-06);

}

// Sample number 10119
static void test_ode_likelihood_fitzhugh_simp_mmala63() {
  // Input argument
  double params[] = { 0.18315871614474655, 0.15174688247045939, 3.01281624418331662 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 148.14881954029510780, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1500.94582412325871701, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 72.95179580023410892, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 614.72048253571449550, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 106627.19666144342045300, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 5478.94108032603162428, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 60150.04750921890808968, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 5478.94108032603162428, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2537.45618214507521770, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 3998.11621802939953341, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 60150.04750921890808968, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 3998.11621802939953341, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45444.88687219434359577, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 10119
static void test_ode_proposal_fitzhugh_simp_mmala63() {
  // Input arguments
  double params[] = { 0.18315871614474655, 0.15174688247045939, 3.01281624418331662 };
  double likelihood = 148.14881954029510780;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1500.94582412325871701;
  geometry->gradient_log_likelihood[1] = 72.95179580023410892;
  geometry->gradient_log_likelihood[2] = 614.72048253571449550;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 106627.19666144342045300;
  geometry->FI[0 * geometry->ldfi + 1] = 5478.94108032603162428;
  geometry->FI[0 * geometry->ldfi + 2] = 60150.04750921890808968;
  geometry->FI[1 * geometry->ldfi + 0] = 5478.94108032603162428;
  geometry->FI[1 * geometry->ldfi + 1] = 2537.45618214507521770;
  geometry->FI[1 * geometry->ldfi + 2] = 3998.11621802939953341;
  geometry->FI[2 * geometry->ldfi + 0] = 60150.04750921890808968;
  geometry->FI[2 * geometry->ldfi + 1] = 3998.11621802939953341;
  geometry->FI[2 * geometry->ldfi + 2] = 45444.88687219434359577;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20227160833820471, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15660766331555040, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99727029257380728, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042333118213393, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00003623874305359, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00055712547117501, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00003623874305359, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00523203396425111, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00041233500662250, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00055712547117501, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00041233500662250, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00102516770875811, 1.0e-06);

}

// Sample number 13980
static void test_ode_likelihood_fitzhugh_simp_mmala64() {
  // Input argument
  double params[] = { 0.21529514369249345, 0.19888564499424516, 2.98383339107542378 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.78080091625088244, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1007.95616811305990268, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -212.26381019387167726, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -498.38543417499573707, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 130597.25898221691022627, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 15485.60730785407213261, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 68770.46862183307530358, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 15485.60730785407213261, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 4376.18387202658504975, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 9827.70444160379702225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 68770.46862183307530358, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 9827.70444160379702225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45667.82832260613940889, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 13980
static void test_ode_proposal_fitzhugh_simp_mmala64() {
  // Input arguments
  double params[] = { 0.21529514369249345, 0.19888564499424516, 2.98383339107542378 };
  double likelihood = 154.78080091625088244;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -1007.95616811305990268;
  geometry->gradient_log_likelihood[1] = -212.26381019387167726;
  geometry->gradient_log_likelihood[2] = -498.38543417499573707;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 130597.25898221691022627;
  geometry->FI[0 * geometry->ldfi + 1] = 15485.60730785407213261;
  geometry->FI[0 * geometry->ldfi + 2] = 68770.46862183307530358;
  geometry->FI[1 * geometry->ldfi + 0] = 15485.60730785407213261;
  geometry->FI[1 * geometry->ldfi + 1] = 4376.18387202658504975;
  geometry->FI[1 * geometry->ldfi + 2] = 9827.70444160379702225;
  geometry->FI[2 * geometry->ldfi + 0] = 68770.46862183307530358;
  geometry->FI[2 * geometry->ldfi + 1] = 9827.70444160379702225;
  geometry->FI[2 * geometry->ldfi + 2] = 45667.82832260613940889;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20896785813174448, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16585917624310878, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99225635002637169, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042599788348033, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00012927661941070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00061368325802784, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00012927661941070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00509345810783539, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00090143518277174, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00061368325802784, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00090143518277174, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00136838710745274, 1.0e-06);

}

// Sample number 17815
static void test_ode_likelihood_fitzhugh_simp_mmala65() {
  // Input argument
  double params[] = { 0.19423488684121257, 0.02998531402937407, 2.99494525491288721 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 136.72070837790343489, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1047.81169353662926369, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 203.75404363056054535, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 520.61266667591416990, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 108899.20310908417741302, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -11544.14202286852741963, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 61594.05546862888149917, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -11544.14202286852741963, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3900.68178844604517508, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -8268.88266891848252271, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 61594.05546862888149917, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -8268.88266891848252271, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46310.20544440374214901, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 17815
static void test_ode_proposal_fitzhugh_simp_mmala65() {
  // Input arguments
  double params[] = { 0.19423488684121257, 0.02998531402937407, 2.99494525491288721 };
  double likelihood = 136.72070837790343489;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1047.81169353662926369;
  geometry->gradient_log_likelihood[1] = 203.75404363056054535;
  geometry->gradient_log_likelihood[2] = 520.61266667591416990;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 108899.20310908417741302;
  geometry->FI[0 * geometry->ldfi + 1] = -11544.14202286852741963;
  geometry->FI[0 * geometry->ldfi + 2] = 61594.05546862888149917;
  geometry->FI[1 * geometry->ldfi + 0] = -11544.14202286852741963;
  geometry->FI[1 * geometry->ldfi + 1] = 3900.68178844604517508;
  geometry->FI[1 * geometry->ldfi + 2] = -8268.88266891848252271;
  geometry->FI[2 * geometry->ldfi + 0] = 61594.05546862888149917;
  geometry->FI[2 * geometry->ldfi + 1] = -8268.88266891848252271;
  geometry->FI[2 * geometry->ldfi + 2] = 46310.20544440374214901;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20606717820092690, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.12475567065632917, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00458933169618003, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042559484868550, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00009590102406218, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00054893123788485, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00009590102406218, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00473605788209825, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00071809169546043, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00054893123788485, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00071809169546043, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00110510545810463, 1.0e-06);

}

// Sample number 19182
static void test_ode_likelihood_fitzhugh_simp_mmala66() {
  // Input argument
  double params[] = { 0.20050191669046197, 0.16270822411165856, 3.03941585338018161 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 126.78466032606378633, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -2313.27664010855505694, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -222.30565387470886662, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -1716.01257884269489296, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 119681.52362807345343754, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 8651.35434355839788623, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 65028.62437877388583729, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 8651.35434355839788623, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2912.27557067409770752, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 5846.30580729569373943, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 65028.62437877388583729, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 5846.30580729569373943, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45805.90340474909316981, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 19182
static void test_ode_proposal_fitzhugh_simp_mmala66() {
  // Input arguments
  double params[] = { 0.20050191669046197, 0.16270822411165856, 3.03941585338018161 };
  double likelihood = 126.78466032606378633;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -2313.27664010855505694;
  geometry->gradient_log_likelihood[1] = -222.30565387470886662;
  geometry->gradient_log_likelihood[2] = -1716.01257884269489296;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 119681.52362807345343754;
  geometry->FI[0 * geometry->ldfi + 1] = 8651.35434355839788623;
  geometry->FI[0 * geometry->ldfi + 2] = 65028.62437877388583729;
  geometry->FI[1 * geometry->ldfi + 0] = 8651.35434355839788623;
  geometry->FI[1 * geometry->ldfi + 1] = 2912.27557067409770752;
  geometry->FI[1 * geometry->ldfi + 2] = 5846.30580729569373943;
  geometry->FI[2 * geometry->ldfi + 0] = 65028.62437877388583729;
  geometry->FI[2 * geometry->ldfi + 1] = 5846.30580729569373943;
  geometry->FI[2 * geometry->ldfi + 2] = 45805.90340474909316981;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20390278541396886, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16101414599043942, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00661246753575684, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00041854798006713, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00006794067747722, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00058552272544444, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00006794067747722, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00528730791638043, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00057837807381926, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00058552272544444, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00057837807381926, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00115456856543492, 1.0e-06);

}

// Sample number 10942
static void test_ode_likelihood_fitzhugh_simp_mmala67() {
  // Input argument
  double params[] = { 0.21631046465326240, 0.21780588623738562, 2.95106531827180563 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 148.90152134761376601, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 850.61265523388601650, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 41.94500891849400404, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 740.99893395959361442, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 131607.04773041044245474, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 18580.81022084460710175, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 68995.46624398624408059, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 18580.81022084460710175, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 5321.88511198149717529, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 11688.56034197281587694, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 68995.46624398624408059, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 11688.56034197281587694, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45421.37983486247685505, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 10942
static void test_ode_proposal_fitzhugh_simp_mmala67() {
  // Input arguments
  double params[] = { 0.21631046465326240, 0.21780588623738562, 2.95106531827180563 };
  double likelihood = 148.90152134761376601;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 850.61265523388601650;
  geometry->gradient_log_likelihood[1] = 41.94500891849400404;
  geometry->gradient_log_likelihood[2] = 740.99893395959361442;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 131607.04773041044245474;
  geometry->FI[0 * geometry->ldfi + 1] = 18580.81022084460710175;
  geometry->FI[0 * geometry->ldfi + 2] = 68995.46624398624408059;
  geometry->FI[1 * geometry->ldfi + 0] = 18580.81022084460710175;
  geometry->FI[1 * geometry->ldfi + 1] = 5321.88511198149717529;
  geometry->FI[1 * geometry->ldfi + 2] = 11688.56034197281587694;
  geometry->FI[2 * geometry->ldfi + 0] = 68995.46624398624408059;
  geometry->FI[2 * geometry->ldfi + 1] = 11688.56034197281587694;
  geometry->FI[2 * geometry->ldfi + 2] = 45421.37983486247685505;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21001123421738194, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.17168264410826725, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98477964878659741, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00043115648512882, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00015386506964839, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00061533536995330, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00015386506964839, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00499395851276306, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00105140340025582, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00061533536995330, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00105140340025582, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00145688411023846, 1.0e-06);

}

// Sample number 2772
static void test_ode_likelihood_fitzhugh_simp_mmala68() {
  // Input argument
  double params[] = { 0.19465342779641953, 0.20083884141967029, 3.00728497344830492 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 156.02025020932154575, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 66.82818624474049329, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -128.69054969168806224, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -182.65772731957869723, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 116964.86998628913715947, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 13667.81820606156543363, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 63721.27022456309350673, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 13667.81820606156543363, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 4100.49139763012681215, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 9292.77582017676650139, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 63721.27022456309350673, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 9292.77582017676650139, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45212.54166009681648575, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 2772
static void test_ode_proposal_fitzhugh_simp_mmala68() {
  // Input arguments
  double params[] = { 0.19465342779641953, 0.20083884141967029, 3.00728497344830492 };
  double likelihood = 156.02025020932154575;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 66.82818624474049329;
  geometry->gradient_log_likelihood[1] = -128.69054969168806224;
  geometry->gradient_log_likelihood[2] = -182.65772731957869723;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 116964.86998628913715947;
  geometry->FI[0 * geometry->ldfi + 1] = 13667.81820606156543363;
  geometry->FI[0 * geometry->ldfi + 2] = 63721.27022456309350673;
  geometry->FI[1 * geometry->ldfi + 0] = 13667.81820606156543363;
  geometry->FI[1 * geometry->ldfi + 1] = 4100.49139763012681215;
  geometry->FI[1 * geometry->ldfi + 2] = 9292.77582017676650139;
  geometry->FI[2 * geometry->ldfi + 0] = 63721.27022456309350673;
  geometry->FI[2 * geometry->ldfi + 1] = 9292.77582017676650139;
  geometry->FI[2 * geometry->ldfi + 2] = 45212.54166009681648575;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20434971275570801, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16699904549938488, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99753440227172341, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042315062276701, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00011027317882849, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00057371141494774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00011027317882849, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00524624792511747, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00092287355026886, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00057371141494774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00092287355026886, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00125103829051637, 1.0e-06);

}

// Sample number 2985
static void test_ode_likelihood_fitzhugh_simp_mmala69() {
  // Input argument
  double params[] = { 0.17683374845004740, 0.18434839910623080, 3.02571520746945222 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 146.49159841048344788, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 1151.55698740735192587, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -8.49362945749413356, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 236.36339878987178054, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 104940.88253882316348609, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 9680.93263552410462580, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 59118.02609076738008298, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 9680.93263552410462580, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3258.37770786644205145, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 7089.86245203632734047, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 59118.02609076738008298, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 7089.86245203632734047, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 44979.20385468937456608, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 2985
static void test_ode_proposal_fitzhugh_simp_mmala69() {
  // Input arguments
  double params[] = { 0.17683374845004740, 0.18434839910623080, 3.02571520746945222 };
  double likelihood = 146.49159841048344788;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 1151.55698740735192587;
  geometry->gradient_log_likelihood[1] = -8.49362945749413356;
  geometry->gradient_log_likelihood[2] = 236.36339878987178054;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 104940.88253882316348609;
  geometry->FI[0 * geometry->ldfi + 1] = 9680.93263552410462580;
  geometry->FI[0 * geometry->ldfi + 2] = 59118.02609076738008298;
  geometry->FI[1 * geometry->ldfi + 0] = 9680.93263552410462580;
  geometry->FI[1 * geometry->ldfi + 1] = 3258.37770786644205145;
  geometry->FI[1 * geometry->ldfi + 2] = 7089.86245203632734047;
  geometry->FI[2 * geometry->ldfi + 0] = 59118.02609076738008298;
  geometry->FI[2 * geometry->ldfi + 1] = 7089.86245203632734047;
  geometry->FI[2 * geometry->ldfi + 2] = 44979.20385468937456608;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20033125236191063, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16428867157149285, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00194785845917345, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042051786078733, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00007119170738921, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00054148238219660, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00007119170738921, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00535059553922703, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00074981925655408, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00054148238219660, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00074981925655408, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00108397713888594, 1.0e-06);

}

// Sample number 5148
static void test_ode_likelihood_fitzhugh_simp_mmala70() {
  // Input argument
  double params[] = { 0.17411084347726496, 0.08750545587902914, 3.01995806136670852 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 131.15823875135214394, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 2020.72837987679372418, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 104.35058636363176277, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 867.25104760220688149, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 99416.10559047009155620, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -3469.73136371757300367, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 57506.30480669140524697, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -3469.73136371757300367, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2387.20269218605244532, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -2585.13766467077266498, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 57506.30480669140524697, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -2585.13766467077266498, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45726.27269059480022406, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 5148
static void test_ode_proposal_fitzhugh_simp_mmala70() {
  // Input arguments
  double params[] = { 0.17411084347726496, 0.08750545587902914, 3.01995806136670852 };
  double likelihood = 131.15823875135214394;
  double temperature = 0.13168724279835398;
  double stepsize = 1.22680319758319145;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 2020.72837987679372418;
  geometry->gradient_log_likelihood[1] = 104.35058636363176277;
  geometry->gradient_log_likelihood[2] = 867.25104760220688149;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 99416.10559047009155620;
  geometry->FI[0 * geometry->ldfi + 1] = -3469.73136371757300367;
  geometry->FI[0 * geometry->ldfi + 2] = 57506.30480669140524697;
  geometry->FI[1 * geometry->ldfi + 0] = -3469.73136371757300367;
  geometry->FI[1 * geometry->ldfi + 1] = 2387.20269218605244532;
  geometry->FI[1 * geometry->ldfi + 2] = -2585.13766467077266498;
  geometry->FI[2 * geometry->ldfi + 0] = 57506.30480669140524697;
  geometry->FI[2 * geometry->ldfi + 1] = -2585.13766467077266498;
  geometry->FI[2 * geometry->ldfi + 2] = 45726.27269059480022406;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20037797129298324, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14157146306252610, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 3.00425306405226422, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00042214247559865, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00004117891569273, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00052856704221708, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00004117891569273, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00510382933648831, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00023675785357854, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00052856704221708, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00023675785357854, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00092806455240459, 1.0e-06);

}

// Sample number 16815
static void test_ode_likelihood_fitzhugh_simp_mmala71() {
  // Input argument
  double params[] = { 0.20328253069297350, 0.09585722171871133, 3.01366820177757377 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 152.18811353822474075, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -726.89041236619641495, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 153.08442423399114318, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -601.95684906627900546, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 117173.36831584082392510, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -1607.91912144308207644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 64603.20068935677409172, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -1607.91912144308207644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2299.13135553890015217, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -1094.11497109366064251, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 64603.20068935677409172, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -1094.11497109366064251, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46284.14984832214395283, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 16815
static void test_ode_proposal_fitzhugh_simp_mmala71() {
  // Input arguments
  double params[] = { 0.20328253069297350, 0.09585722171871133, 3.01366820177757377 };
  double likelihood = 152.18811353822474075;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -726.89041236619641495;
  geometry->gradient_log_likelihood[1] = 153.08442423399114318;
  geometry->gradient_log_likelihood[2] = -601.95684906627900546;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 117173.36831584082392510;
  geometry->FI[0 * geometry->ldfi + 1] = -1607.91912144308207644;
  geometry->FI[0 * geometry->ldfi + 2] = 64603.20068935677409172;
  geometry->FI[1 * geometry->ldfi + 0] = -1607.91912144308207644;
  geometry->FI[1 * geometry->ldfi + 1] = 2299.13135553890015217;
  geometry->FI[1 * geometry->ldfi + 2] = -1094.11497109366064251;
  geometry->FI[2 * geometry->ldfi + 0] = 64603.20068935677409172;
  geometry->FI[2 * geometry->ldfi + 1] = -1094.11497109366064251;
  geometry->FI[2 * geometry->ldfi + 2] = 46284.14984832214395283;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20843266647712899, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16786092943023995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99288946491553842, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030603152258798, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00001087186620771, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00042690037224817, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00001087186620771, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00363486078217965, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00007074988426644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00042690037224817, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00007074988426644, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00077604691576243, 1.0e-06);

}

// Sample number 5086
static void test_ode_likelihood_fitzhugh_simp_mmala72() {
  // Input argument
  double params[] = { 0.21726179244175503, 0.15584387435374689, 2.97636444286104629 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.34148871594601360, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -205.18970191256872226, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -0.12543941956454319, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 39.85101299417753751, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 128430.04655647219624370, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 8327.02221353929417091, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 68515.12729076835967135, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 8327.02221353929417091, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2912.53855979383251906, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 5360.66168920017844357, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 68515.12729076835967135, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 5360.66168920017844357, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46180.60112730486434884, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 5086
static void test_ode_proposal_fitzhugh_simp_mmala72() {
  // Input arguments
  double params[] = { 0.21726179244175503, 0.15584387435374689, 2.97636444286104629 };
  double likelihood = 159.34148871594601360;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -205.18970191256872226;
  geometry->gradient_log_likelihood[1] = -0.12543941956454319;
  geometry->gradient_log_likelihood[2] = 39.85101299417753751;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 128430.04655647219624370;
  geometry->FI[0 * geometry->ldfi + 1] = 8327.02221353929417091;
  geometry->FI[0 * geometry->ldfi + 2] = 68515.12729076835967135;
  geometry->FI[1 * geometry->ldfi + 0] = 8327.02221353929417091;
  geometry->FI[1 * geometry->ldfi + 1] = 2912.53855979383251906;
  geometry->FI[1 * geometry->ldfi + 2] = 5360.66168920017844357;
  geometry->FI[2 * geometry->ldfi + 0] = 68515.12729076835967135;
  geometry->FI[2 * geometry->ldfi + 1] = 5360.66168920017844357;
  geometry->FI[2 * geometry->ldfi + 2] = 46180.60112730486434884;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20566371982086767, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15529728723349234, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99464984795869960, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030923872232152, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00005046614526047, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00045293906924105, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00005046614526047, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00361572728427525, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00034484168625512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00045293906924105, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00034484168625512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00089093449206361, 1.0e-06);

}

// Sample number 16285
static void test_ode_likelihood_fitzhugh_simp_mmala73() {
  // Input argument
  double params[] = { 0.21341473257565952, 0.12944640687383197, 2.96948551023897744 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 153.62990653592038370, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 931.16685818987775747, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 100.78466951643157756, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 735.27992404654719394, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 123470.72316777435480617, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 3608.13674147637175338, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 66893.46111063740681857, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 3608.13674147637175338, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2438.44513353701677261, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 2381.50197788173863955, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 66893.46111063740681857, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 2381.50197788173863955, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46173.48853626628988422, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 16285
static void test_ode_proposal_fitzhugh_simp_mmala73() {
  // Input arguments
  double params[] = { 0.21341473257565952, 0.12944640687383197, 2.96948551023897744 };
  double likelihood = 153.62990653592038370;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 931.16685818987775747;
  geometry->gradient_log_likelihood[1] = 100.78466951643157756;
  geometry->gradient_log_likelihood[2] = 735.27992404654719394;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 123470.72316777435480617;
  geometry->FI[0 * geometry->ldfi + 1] = 3608.13674147637175338;
  geometry->FI[0 * geometry->ldfi + 2] = 66893.46111063740681857;
  geometry->FI[1 * geometry->ldfi + 0] = 3608.13674147637175338;
  geometry->FI[1 * geometry->ldfi + 1] = 2438.44513353701677261;
  geometry->FI[1 * geometry->ldfi + 2] = 2381.50197788173863955;
  geometry->FI[2 * geometry->ldfi + 0] = 66893.46111063740681857;
  geometry->FI[2 * geometry->ldfi + 1] = 2381.50197788173863955;
  geometry->FI[2 * geometry->ldfi + 2] = 46173.48853626628988422;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20728723549657599, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16178377541919531, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99541885077407910, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00031120787820155, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00002122847781997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00044976494291897, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00002122847781997, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00356945791172656, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00015334827290974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00044976494291897, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00015334827290974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00083843926393168, 1.0e-06);

}

// Sample number 4870
static void test_ode_likelihood_fitzhugh_simp_mmala74() {
  // Input argument
  double params[] = { 0.21893664710464161, 0.12556088841112015, 2.98491794283608947 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 156.58237423581141456, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -834.46244702952219541, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 49.13867275188236050, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -356.23652718541558215, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 128119.83914141519926488, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 3530.78832710792357830, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 68618.90384152818296570, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 3530.78832710792357830, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2416.79526219398303510, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 2277.96850776433802821, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 68618.90384152818296570, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 2277.96850776433802821, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46476.73101105786918197, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 4870
static void test_ode_proposal_fitzhugh_simp_mmala74() {
  // Input arguments
  double params[] = { 0.21893664710464161, 0.12556088841112015, 2.98491794283608947 };
  double likelihood = 156.58237423581141456;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -834.46244702952219541;
  geometry->gradient_log_likelihood[1] = 49.13867275188236050;
  geometry->gradient_log_likelihood[2] = -356.23652718541558215;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 128119.83914141519926488;
  geometry->FI[0 * geometry->ldfi + 1] = 3530.78832710792357830;
  geometry->FI[0 * geometry->ldfi + 2] = 68618.90384152818296570;
  geometry->FI[1 * geometry->ldfi + 0] = 3530.78832710792357830;
  geometry->FI[1 * geometry->ldfi + 1] = 2416.79526219398303510;
  geometry->FI[1 * geometry->ldfi + 2] = 2277.96850776433802821;
  geometry->FI[2 * geometry->ldfi + 0] = 68618.90384152818296570;
  geometry->FI[2 * geometry->ldfi + 1] = 2277.96850776433802821;
  geometry->FI[2 * geometry->ldfi + 2] = 46476.73101105786918197;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20518759679947707, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16053135962133680, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99449077775158035, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030831456702175, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00002241170353112, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00045410152593429, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00002241170353112, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00358584309896832, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00014266431780948, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00045410152593429, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00014266431780948, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00085520357626398, 1.0e-06);

}

// Sample number 18582
static void test_ode_likelihood_fitzhugh_simp_mmala75() {
  // Input argument
  double params[] = { 0.19317602732109490, 0.11707919744823335, 3.00960789931670369 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 155.31314547817228799, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 721.17029359013599787, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 94.79339731683506898, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 228.85868089291585648, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 111215.56400199473137036, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 1065.46029679070488783, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 62215.15998561143351253, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 1065.46029679070488783, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2250.99624184545109529, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 777.63318327672413943, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 62215.15998561143351253, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 777.63318327672413943, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45928.57912028756254585, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 18582
static void test_ode_proposal_fitzhugh_simp_mmala75() {
  // Input arguments
  double params[] = { 0.19317602732109490, 0.11707919744823335, 3.00960789931670369 };
  double likelihood = 155.31314547817228799;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 721.17029359013599787;
  geometry->gradient_log_likelihood[1] = 94.79339731683506898;
  geometry->gradient_log_likelihood[2] = 228.85868089291585648;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 111215.56400199473137036;
  geometry->FI[0 * geometry->ldfi + 1] = 1065.46029679070488783;
  geometry->FI[0 * geometry->ldfi + 2] = 62215.15998561143351253;
  geometry->FI[1 * geometry->ldfi + 0] = 1065.46029679070488783;
  geometry->FI[1 * geometry->ldfi + 1] = 2250.99624184545109529;
  geometry->FI[1 * geometry->ldfi + 2] = 777.63318327672413943;
  geometry->FI[2 * geometry->ldfi + 0] = 62215.15998561143351253;
  geometry->FI[2 * geometry->ldfi + 1] = 777.63318327672413943;
  geometry->FI[2 * geometry->ldfi + 2] = 45928.57912028756254585;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21110092298996466, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16475357306336330, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99037853365063455, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030670434467987, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00000165468387025, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00041543573741925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00000165468387025, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00369203796313664, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00006026976809123, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00041543573741925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00006026976809123, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00074366335953110, 1.0e-06);

}

// Sample number 6998
static void test_ode_likelihood_fitzhugh_simp_mmala76() {
  // Input argument
  double params[] = { 0.21579076881610798, 0.08693950385836537, 2.98704379893896732 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 153.76672779951596226, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -543.28102939108896408, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 170.82156336334284674, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -225.76105152122971731, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 124102.89464892906835303, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -2850.14776929189974908, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 67379.88748405862133950, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -2850.14776929189974908, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2425.26041495579147522, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -1890.58582450047310886, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 67379.88748405862133950, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -1890.58582450047310886, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46655.82619555044220760, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 6998
static void test_ode_proposal_fitzhugh_simp_mmala76() {
  // Input arguments
  double params[] = { 0.21579076881610798, 0.08693950385836537, 2.98704379893896732 };
  double likelihood = 153.76672779951596226;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -543.28102939108896408;
  geometry->gradient_log_likelihood[1] = 170.82156336334284674;
  geometry->gradient_log_likelihood[2] = -225.76105152122971731;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 124102.89464892906835303;
  geometry->FI[0 * geometry->ldfi + 1] = -2850.14776929189974908;
  geometry->FI[0 * geometry->ldfi + 2] = 67379.88748405862133950;
  geometry->FI[1 * geometry->ldfi + 0] = -2850.14776929189974908;
  geometry->FI[1 * geometry->ldfi + 1] = 2425.26041495579147522;
  geometry->FI[1 * geometry->ldfi + 2] = -1890.58582450047310886;
  geometry->FI[2 * geometry->ldfi + 0] = 67379.88748405862133950;
  geometry->FI[2 * geometry->ldfi + 1] = -1890.58582450047310886;
  geometry->FI[2 * geometry->ldfi + 2] = 46655.82619555044220760;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20661711585351833, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16741100052570973, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99786354594017457, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030843341191349, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00001573024453683, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00044479909383101, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00001573024453683, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00351862408210738, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00011986410187980, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00044479909383101, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00011986410187980, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00082431846591285, 1.0e-06);

}

// Sample number 3931
static void test_ode_likelihood_fitzhugh_simp_mmala77() {
  // Input argument
  double params[] = { 0.20793232568553782, 0.15839889292362669, 3.00637956264266348 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 155.05819468759057145, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1062.92252969703440613, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -90.11242464043684208, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -712.77963084664781945, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 123198.87053787811601069, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 8254.37620098225670517, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 66445.55437066074227914, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 8254.37620098225670517, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2875.76931885224666985, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 5455.34661103033431573, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 66445.55437066074227914, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 5455.34661103033431573, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45907.94815804393147118, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 3931
static void test_ode_proposal_fitzhugh_simp_mmala77() {
  // Input arguments
  double params[] = { 0.20793232568553782, 0.15839889292362669, 3.00637956264266348 };
  double likelihood = 155.05819468759057145;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -1062.92252969703440613;
  geometry->gradient_log_likelihood[1] = -90.11242464043684208;
  geometry->gradient_log_likelihood[2] = -712.77963084664781945;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 123198.87053787811601069;
  geometry->FI[0 * geometry->ldfi + 1] = 8254.37620098225670517;
  geometry->FI[0 * geometry->ldfi + 2] = 66445.55437066074227914;
  geometry->FI[1 * geometry->ldfi + 0] = 8254.37620098225670517;
  geometry->FI[1 * geometry->ldfi + 1] = 2875.76931885224666985;
  geometry->FI[1 * geometry->ldfi + 2] = 5455.34661103033431573;
  geometry->FI[2 * geometry->ldfi + 0] = 66445.55437066074227914;
  geometry->FI[2 * geometry->ldfi + 1] = 5455.34661103033431573;
  geometry->FI[2 * geometry->ldfi + 2] = 45907.94815804393147118;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20660700644044094, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15575581812693015, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99035579863363310, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030634294612941, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00004930356063995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00043753118308646, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00004930356063995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00371708891342520, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00037034994308725, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00043753118308646, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00037034994308725, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00085724855300115, 1.0e-06);

}

// Sample number 5020
static void test_ode_likelihood_fitzhugh_simp_mmala78() {
  // Input argument
  double params[] = { 0.18741984391863822, 0.14397133219911740, 3.01584092107428159 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.09385899484593097, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 896.26216671390761803, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 51.75226555227061453, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 246.82047971322182889, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 109040.88918568380177021, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 4677.32857617620356905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 61149.81922034463786986, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 4677.32857617620356905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2442.05300450404456569, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 3367.35733211637216300, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 61149.81922034463786986, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 3367.35733211637216300, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45593.76066109108796809, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 5020
static void test_ode_proposal_fitzhugh_simp_mmala78() {
  // Input arguments
  double params[] = { 0.18741984391863822, 0.14397133219911740, 3.01584092107428159 };
  double likelihood = 154.09385899484593097;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 896.26216671390761803;
  geometry->gradient_log_likelihood[1] = 51.75226555227061453;
  geometry->gradient_log_likelihood[2] = 246.82047971322182889;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 109040.88918568380177021;
  geometry->FI[0 * geometry->ldfi + 1] = 4677.32857617620356905;
  geometry->FI[0 * geometry->ldfi + 2] = 61149.81922034463786986;
  geometry->FI[1 * geometry->ldfi + 0] = 4677.32857617620356905;
  geometry->FI[1 * geometry->ldfi + 1] = 2442.05300450404456569;
  geometry->FI[1 * geometry->ldfi + 2] = 3367.35733211637216300;
  geometry->FI[2 * geometry->ldfi + 0] = 61149.81922034463786986;
  geometry->FI[2 * geometry->ldfi + 1] = 3367.35733211637216300;
  geometry->FI[2 * geometry->ldfi + 2] = 45593.76066109108796809;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.21191350664177760, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16014380928884769, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.98816112980916548, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030582778855397, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00002245836061160, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00040851398058189, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00002245836061160, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00376854254503961, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00024820730983712, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00040851398058189, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00024820730983712, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00074743761164454, 1.0e-06);

}

// Sample number 12316
static void test_ode_likelihood_fitzhugh_simp_mmala79() {
  // Input argument
  double params[] = { 0.20283876594632871, 0.17479026355698601, 3.00194005066136071 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.16368608050964895, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -272.08391049169193820, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -81.00702575790036519, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -269.69818454308870059, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 120564.55540540200308897, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 10363.81784252907891641, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 65362.09823512702860171, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 10363.81784252907891641, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3270.57224284022322536, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 6933.79981248096919444, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 65362.09823512702860171, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 6933.79981248096919444, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45670.29490723329217872, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 12316
static void test_ode_proposal_fitzhugh_simp_mmala79() {
  // Input arguments
  double params[] = { 0.20283876594632871, 0.17479026355698601, 3.00194005066136071 };
  double likelihood = 159.16368608050964895;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -272.08391049169193820;
  geometry->gradient_log_likelihood[1] = -81.00702575790036519;
  geometry->gradient_log_likelihood[2] = -269.69818454308870059;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 120564.55540540200308897;
  geometry->FI[0 * geometry->ldfi + 1] = 10363.81784252907891641;
  geometry->FI[0 * geometry->ldfi + 2] = 65362.09823512702860171;
  geometry->FI[1 * geometry->ldfi + 0] = 10363.81784252907891641;
  geometry->FI[1 * geometry->ldfi + 1] = 3270.57224284022322536;
  geometry->FI[1 * geometry->ldfi + 2] = 6933.79981248096919444;
  geometry->FI[2 * geometry->ldfi + 0] = 65362.09823512702860171;
  geometry->FI[2 * geometry->ldfi + 1] = 6933.79981248096919444;
  geometry->FI[2 * geometry->ldfi + 2] = 45670.29490723329217872;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20815866552955459, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15249554313764846, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99076761459996066, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030677016864401, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00006090830855990, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00042979393761121, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00006090830855990, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00373736200625151, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00048024706595925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00042979393761121, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00048024706595925, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00086893030745026, 1.0e-06);

}

// Sample number 9462
static void test_ode_likelihood_fitzhugh_simp_mmala80() {
  // Input argument
  double params[] = { 0.21793261468049030, 0.11700998676367801, 2.98975493210587873 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.93505151703888600, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1008.69379585784076880, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 72.91669727149019309, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -494.11351017320254186, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 127138.72881735954433680, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 2121.90484018256756826, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 68301.20557258796179667, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 2121.90484018256756826, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2345.79951340718434949, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 1373.48037703332056481, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 68301.20557258796179667, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 1373.48037703332056481, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46511.97353609173296718, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 9462
static void test_ode_proposal_fitzhugh_simp_mmala80() {
  // Input arguments
  double params[] = { 0.21793261468049030, 0.11700998676367801, 2.98975493210587873 };
  double likelihood = 154.93505151703888600;
  double temperature = 0.28462802079628785;
  double stepsize = 1.53350399697898920;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -1008.69379585784076880;
  geometry->gradient_log_likelihood[1] = 72.91669727149019309;
  geometry->gradient_log_likelihood[2] = -494.11351017320254186;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 127138.72881735954433680;
  geometry->FI[0 * geometry->ldfi + 1] = 2121.90484018256756826;
  geometry->FI[0 * geometry->ldfi + 2] = 68301.20557258796179667;
  geometry->FI[1 * geometry->ldfi + 0] = 2121.90484018256756826;
  geometry->FI[1 * geometry->ldfi + 1] = 2345.79951340718434949;
  geometry->FI[1 * geometry->ldfi + 2] = 1373.48037703332056481;
  geometry->FI[2 * geometry->ldfi + 0] = 68301.20557258796179667;
  geometry->FI[2 * geometry->ldfi + 1] = 1373.48037703332056481;
  geometry->FI[2 * geometry->ldfi + 2] = 46511.97353609173296718;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20535374739888973, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16221730789403827, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99440047226019734, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00030787478890774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001402279278410, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00045168926665264, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001402279278410, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00358470308757792, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00008526289886524, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00045168926665264, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00008526289886524, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00084344219779882, 1.0e-06);

}

// Sample number 7034
static void test_ode_likelihood_fitzhugh_simp_mmala81() {
  // Input argument
  double params[] = { 0.19319530155989431, 0.16063399351473429, 3.01155759862279471 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.77194197181461277, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 405.93269983124048395, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -3.15002291265289003, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 7.75078620257092155, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 113504.08733292986289598, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 7463.52051503914572095, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 62784.50248436396941543, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 7463.52051503914572095, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2790.10689590714082442, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 5204.94705992913532100, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 62784.50248436396941543, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 5204.94705992913532100, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45584.29727648261177819, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 7034
static void test_ode_proposal_fitzhugh_simp_mmala81() {
  // Input arguments
  double params[] = { 0.19319530155989431, 0.16063399351473429, 3.01155759862279471 };
  double likelihood = 157.77194197181461277;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 405.93269983124048395;
  geometry->gradient_log_likelihood[1] = -3.15002291265289003;
  geometry->gradient_log_likelihood[2] = 7.75078620257092155;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 113504.08733292986289598;
  geometry->FI[0 * geometry->ldfi + 1] = 7463.52051503914572095;
  geometry->FI[0 * geometry->ldfi + 2] = 62784.50248436396941543;
  geometry->FI[1 * geometry->ldfi + 0] = 7463.52051503914572095;
  geometry->FI[1 * geometry->ldfi + 1] = 2790.10689590714082442;
  geometry->FI[1 * geometry->ldfi + 2] = 5204.94705992913532100;
  geometry->FI[2 * geometry->ldfi + 0] = 62784.50248436396941543;
  geometry->FI[2 * geometry->ldfi + 1] = 5204.94705992913532100;
  geometry->FI[2 * geometry->ldfi + 2] = 45584.29727648261177819;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20563429639938324, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15740637164937687, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99493779406465199, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011326703495168, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001519677727939, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00015427058079774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001519677727939, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00139426993867927, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00013827084092126, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00015427058079774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00013827084092126, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00029533289267099, 1.0e-06);

}

// Sample number 16616
static void test_ode_likelihood_fitzhugh_simp_mmala82() {
  // Input argument
  double params[] = { 0.19103785213343680, 0.19176986900191351, 3.00410463180113529 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 154.90036759902727681, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 824.22178091895921170, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -19.30524560875135620, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 274.07397764619508962, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 113675.80416626029182225, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 11862.88210173978768580, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 62598.28217465816123877, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 11862.88210173978768580, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3685.38441007353776513, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 8225.18928107561259822, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 62598.28217465816123877, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 8225.18928107561259822, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45241.93114065987901995, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 16616
static void test_ode_proposal_fitzhugh_simp_mmala82() {
  // Input arguments
  double params[] = { 0.19103785213343680, 0.19176986900191351, 3.00410463180113529 };
  double likelihood = 154.90036759902727681;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 824.22178091895921170;
  geometry->gradient_log_likelihood[1] = -19.30524560875135620;
  geometry->gradient_log_likelihood[2] = 274.07397764619508962;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 113675.80416626029182225;
  geometry->FI[0 * geometry->ldfi + 1] = 11862.88210173978768580;
  geometry->FI[0 * geometry->ldfi + 2] = 62598.28217465816123877;
  geometry->FI[1 * geometry->ldfi + 0] = 11862.88210173978768580;
  geometry->FI[1 * geometry->ldfi + 1] = 3685.38441007353776513;
  geometry->FI[1 * geometry->ldfi + 2] = 8225.18928107561259822;
  geometry->FI[2 * geometry->ldfi + 0] = 62598.28217465816123877;
  geometry->FI[2 * geometry->ldfi + 1] = 8225.18928107561259822;
  geometry->FI[2 * geometry->ldfi + 2] = 45241.93114065987901995;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20551949412993592, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16180479165708161, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99465362463293827, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011340673480371, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00002497161635243, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00015237348054758, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00002497161635243, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00140140631012972, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00022023047253988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00015237348054758, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00022023047253988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00031843918672066, 1.0e-06);

}

// Sample number 11705
static void test_ode_likelihood_fitzhugh_simp_mmala83() {
  // Input argument
  double params[] = { 0.21101707163448802, 0.13535122765561036, 2.99725665317405721 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.22231313912359951, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -685.30859826808443813, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 18.16128771096771288, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -407.34778433686426524, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 123605.56280750308360439, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 4724.85476186791129294, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 66850.43795624336053152, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 4724.85476186791129294, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2474.60234840115663246, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 3122.65157002297337385, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 66850.43795624336053152, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 3122.65157002297337385, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46212.21686306557967328, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 11705
static void test_ode_proposal_fitzhugh_simp_mmala83() {
  // Input arguments
  double params[] = { 0.21101707163448802, 0.13535122765561036, 2.99725665317405721 };
  double likelihood = 158.22231313912359951;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -685.30859826808443813;
  geometry->gradient_log_likelihood[1] = 18.16128771096771288;
  geometry->gradient_log_likelihood[2] = -407.34778433686426524;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 123605.56280750308360439;
  geometry->FI[0 * geometry->ldfi + 1] = 4724.85476186791129294;
  geometry->FI[0 * geometry->ldfi + 2] = 66850.43795624336053152;
  geometry->FI[1 * geometry->ldfi + 0] = 4724.85476186791129294;
  geometry->FI[1 * geometry->ldfi + 1] = 2474.60234840115663246;
  geometry->FI[1 * geometry->ldfi + 2] = 3122.65157002297337385;
  geometry->FI[2 * geometry->ldfi + 0] = 66850.43795624336053152;
  geometry->FI[2 * geometry->ldfi + 1] = 3122.65157002297337385;
  geometry->FI[2 * geometry->ldfi + 2] = 46212.21686306557967328;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20785428488476443, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15276115982863653, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99317866328919058, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011372568028810, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001043193484701, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00016381028113916, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001043193484701, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00135148273168323, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00007623157900290, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00016381028113916, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00007623157900290, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00030827090686237, 1.0e-06);

}

// Sample number 10993
static void test_ode_likelihood_fitzhugh_simp_mmala84() {
  // Input argument
  double params[] = { 0.19929911036684800, 0.20173430983716267, 3.00299721259714136 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 156.52507258945419721, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -243.42651817367442391, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -160.67867208597726858, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -302.92546088523840808, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 120084.46952768722258043, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 14282.36196190492591995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 64887.97311396179429721, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 14282.36196190492591995, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 4216.78440696019424649, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 9547.79932020670275961, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 64887.97311396179429721, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 9547.79932020670275961, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45301.70692001555289607, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 10993
static void test_ode_proposal_fitzhugh_simp_mmala84() {
  // Input arguments
  double params[] = { 0.19929911036684800, 0.20173430983716267, 3.00299721259714136 };
  double likelihood = 156.52507258945419721;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -243.42651817367442391;
  geometry->gradient_log_likelihood[1] = -160.67867208597726858;
  geometry->gradient_log_likelihood[2] = -302.92546088523840808;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 120084.46952768722258043;
  geometry->FI[0 * geometry->ldfi + 1] = 14282.36196190492591995;
  geometry->FI[0 * geometry->ldfi + 2] = 64887.97311396179429721;
  geometry->FI[1 * geometry->ldfi + 0] = 14282.36196190492591995;
  geometry->FI[1 * geometry->ldfi + 1] = 4216.78440696019424649;
  geometry->FI[1 * geometry->ldfi + 2] = 9547.79932020670275961;
  geometry->FI[2 * geometry->ldfi + 0] = 64887.97311396179429721;
  geometry->FI[2 * geometry->ldfi + 1] = 9547.79932020670275961;
  geometry->FI[2 * geometry->ldfi + 2] = 45301.70692001555289607;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20612612145016820, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.16259698878226470, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99579519347086043, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011332816900705, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00003118180167931, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00015575390152881, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00003118180167931, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00139531815134978, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00024941430590831, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00015575390152881, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00024941430590831, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00034314294265764, 1.0e-06);

}

// Sample number 18341
static void test_ode_likelihood_fitzhugh_simp_mmala85() {
  // Input argument
  double params[] = { 0.21096920459535456, 0.16661958851739755, 2.99655340727904873 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.38826344501563881, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -874.30270760724272350, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -98.55199801709079566, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -519.85010006955599238, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 125497.41235608365968801, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 9750.26484209536829439, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 67258.55297638493357226, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 9750.26484209536829439, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3124.86138792905967421, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 6364.20898675105945586, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 67258.55297638493357226, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 6364.20898675105945586, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45918.21891497247270308, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 18341
static void test_ode_proposal_fitzhugh_simp_mmala85() {
  // Input arguments
  double params[] = { 0.21096920459535456, 0.16661958851739755, 2.99655340727904873 };
  double likelihood = 157.38826344501563881;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -874.30270760724272350;
  geometry->gradient_log_likelihood[1] = -98.55199801709079566;
  geometry->gradient_log_likelihood[2] = -519.85010006955599238;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 125497.41235608365968801;
  geometry->FI[0 * geometry->ldfi + 1] = 9750.26484209536829439;
  geometry->FI[0 * geometry->ldfi + 2] = 67258.55297638493357226;
  geometry->FI[1 * geometry->ldfi + 0] = 9750.26484209536829439;
  geometry->FI[1 * geometry->ldfi + 1] = 3124.86138792905967421;
  geometry->FI[1 * geometry->ldfi + 2] = 6364.20898675105945586;
  geometry->FI[2 * geometry->ldfi + 0] = 67258.55297638493357226;
  geometry->FI[2 * geometry->ldfi + 1] = 6364.20898675105945586;
  geometry->FI[2 * geometry->ldfi + 2] = 45918.21891497247270308;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20757008782837469, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15724590318410339, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99322852467494283, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011364963870274, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00002170397975314, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00016345977173768, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00002170397975314, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00136720095875640, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00015770155131227, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00016345977173768, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00015770155131227, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00032786031356400, 1.0e-06);

}

// Sample number 5716
static void test_ode_likelihood_fitzhugh_simp_mmala86() {
  // Input argument
  double params[] = { 0.20644284163905097, 0.17024135532878706, 2.99954394593303109 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.88033843259097466, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -523.14363908768757483, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -85.55203322880481664, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -371.74141430439880196, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 122676.74343819642672315, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 9951.09186093091193470, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 66191.54660290482570417, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 9951.09186093091193470, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3176.87981276671143860, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 6587.51976231412118068, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 66191.54660290482570417, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 6587.51976231412118068, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45791.94120954146637814, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 5716
static void test_ode_proposal_fitzhugh_simp_mmala86() {
  // Input arguments
  double params[] = { 0.20644284163905097, 0.17024135532878706, 2.99954394593303109 };
  double likelihood = 158.88033843259097466;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -523.14363908768757483;
  geometry->gradient_log_likelihood[1] = -85.55203322880481664;
  geometry->gradient_log_likelihood[2] = -371.74141430439880196;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 122676.74343819642672315;
  geometry->FI[0 * geometry->ldfi + 1] = 9951.09186093091193470;
  geometry->FI[0 * geometry->ldfi + 2] = 66191.54660290482570417;
  geometry->FI[1 * geometry->ldfi + 0] = 9951.09186093091193470;
  geometry->FI[1 * geometry->ldfi + 1] = 3176.87981276671143860;
  geometry->FI[1 * geometry->ldfi + 2] = 6587.51976231412118068;
  geometry->FI[2 * geometry->ldfi + 0] = 66191.54660290482570417;
  geometry->FI[2 * geometry->ldfi + 1] = 6587.51976231412118068;
  geometry->FI[2 * geometry->ldfi + 2] = 45791.94120954146637814;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20708492956321020, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15791348910139794, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99350336137305817, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011358011429967, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00002185446662905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00016103437642604, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00002185446662905, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00137556160890102, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00016629472643914, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00016103437642604, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00016629472643914, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00032345500413782, 1.0e-06);

}

// Sample number 15140
static void test_ode_likelihood_fitzhugh_simp_mmala87() {
  // Input argument
  double params[] = { 0.21434321320628752, 0.15478009382673016, 2.98879839925976709 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 158.85734368553141849, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -675.35589170479056520, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -38.21117679515337784, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -327.69960549414429352, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 126798.89492724348383490, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 8033.28735354665332125, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 67886.53804515216324944, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 8033.28735354665332125, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2856.54694134414330620, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 5215.34670737978740362, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 67886.53804515216324944, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 5215.34670737978740362, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46126.30126071728591342, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15140
static void test_ode_proposal_fitzhugh_simp_mmala87() {
  // Input arguments
  double params[] = { 0.21434321320628752, 0.15478009382673016, 2.98879839925976709 };
  double likelihood = 158.85734368553141849;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -675.35589170479056520;
  geometry->gradient_log_likelihood[1] = -38.21117679515337784;
  geometry->gradient_log_likelihood[2] = -327.69960549414429352;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 126798.89492724348383490;
  geometry->FI[0 * geometry->ldfi + 1] = 8033.28735354665332125;
  geometry->FI[0 * geometry->ldfi + 2] = 67886.53804515216324944;
  geometry->FI[1 * geometry->ldfi + 0] = 8033.28735354665332125;
  geometry->FI[1 * geometry->ldfi + 1] = 2856.54694134414330620;
  geometry->FI[1 * geometry->ldfi + 2] = 5215.34670737978740362;
  geometry->FI[2 * geometry->ldfi + 0] = 67886.53804515216324944;
  geometry->FI[2 * geometry->ldfi + 1] = 5215.34670737978740362;
  geometry->FI[2 * geometry->ldfi + 2] = 46126.30126071728591342;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20824542607016727, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15530819858377046, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99168701784958380, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011394036201332, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001797335992987, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00016565992087626, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001797335992987, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00135141489063217, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00012634761206070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00016565992087626, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00012634761206070, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00032437184468468, 1.0e-06);

}

// Sample number 15070
static void test_ode_likelihood_fitzhugh_simp_mmala88() {
  // Input argument
  double params[] = { 0.20467371530372075, 0.14949840167389777, 3.00828550465730915 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.28701806329820556, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -699.39201531894445907, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -36.09978336904237040, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -538.01917763299252329, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 120492.91929775140306447, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 6613.84943612396182289, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 65526.43673638426116668, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 6613.84943612396182289, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2654.49209520584599886, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 4439.00925283645119634, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 65526.43673638426116668, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 4439.00925283645119634, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45928.73301583501597634, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15070
static void test_ode_proposal_fitzhugh_simp_mmala88() {
  // Input arguments
  double params[] = { 0.20467371530372075, 0.14949840167389777, 3.00828550465730915 };
  double likelihood = 157.28701806329820556;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -699.39201531894445907;
  geometry->gradient_log_likelihood[1] = -36.09978336904237040;
  geometry->gradient_log_likelihood[2] = -538.01917763299252329;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 120492.91929775140306447;
  geometry->FI[0 * geometry->ldfi + 1] = 6613.84943612396182289;
  geometry->FI[0 * geometry->ldfi + 2] = 65526.43673638426116668;
  geometry->FI[1 * geometry->ldfi + 0] = 6613.84943612396182289;
  geometry->FI[1 * geometry->ldfi + 1] = 2654.49209520584599886;
  geometry->FI[1 * geometry->ldfi + 2] = 4439.00925283645119634;
  geometry->FI[2 * geometry->ldfi + 0] = 65526.43673638426116668;
  geometry->FI[2 * geometry->ldfi + 1] = 4439.00925283645119634;
  geometry->FI[2 * geometry->ldfi + 2] = 45928.73301583501597634;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20675545160207293, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15529590325785164, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99481890637999992, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011334548087859, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001429757816450, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00016032792365167, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001429757816450, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00137547250951194, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00011254100660438, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00016032792365167, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00011254100660438, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00030617732075866, 1.0e-06);

}

// Sample number 7606
static void test_ode_likelihood_fitzhugh_simp_mmala89() {
  // Input argument
  double params[] = { 0.19998406141514530, 0.10369294845053054, 2.99409186094700486 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 153.76315825245083602, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 934.80252797800767439, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 116.60494212525543389, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 511.21480016031875948, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 114329.05108702048892155, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], -775.02041812175593805, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 63556.23354151155217551, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], -775.02041812175593805, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2294.38536950964726202, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], -519.32990819814312999, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 63556.23354151155217551, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], -519.32990819814312999, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46135.19765549658040982, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 7606
static void test_ode_proposal_fitzhugh_simp_mmala89() {
  // Input arguments
  double params[] = { 0.19998406141514530, 0.10369294845053054, 2.99409186094700486 };
  double likelihood = 153.76315825245083602;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 934.80252797800767439;
  geometry->gradient_log_likelihood[1] = 116.60494212525543389;
  geometry->gradient_log_likelihood[2] = 511.21480016031875948;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 114329.05108702048892155;
  geometry->FI[0 * geometry->ldfi + 1] = -775.02041812175593805;
  geometry->FI[0 * geometry->ldfi + 2] = 63556.23354151155217551;
  geometry->FI[1 * geometry->ldfi + 0] = -775.02041812175593805;
  geometry->FI[1 * geometry->ldfi + 1] = 2294.38536950964726202;
  geometry->FI[1 * geometry->ldfi + 2] = -519.32990819814312999;
  geometry->FI[2 * geometry->ldfi + 0] = 63556.23354151155217551;
  geometry->FI[2 * geometry->ldfi + 1] = -519.32990819814312999;
  geometry->FI[2 * geometry->ldfi + 2] = 46135.19765549658040982;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20738954761830733, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.14923699985422897, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99380165688436772, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011418868768253, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], 0.00000297315574827, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00015727382177116, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], 0.00000297315574827, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00133588498676758, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], 0.00001094180738573, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00015727382177116, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], 0.00001094180738573, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00028304771893557, 1.0e-06);

}

// Sample number 11352
static void test_ode_likelihood_fitzhugh_simp_mmala90() {
  // Input argument
  double params[] = { 0.20308192424130916, 0.16250982865008406, 3.00441269756031692 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.18383162555278432, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -345.31408110267068423, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -52.78500981643620094, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -321.34986122792827246, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 120031.24766841769451275, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 8480.33618043858223245, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 65268.20704054575617192, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 8480.33618043858223245, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2929.52108642719394993, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 5698.11766057413478848, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 65268.20704054575617192, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 5698.11766057413478848, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45790.60618204041384161, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 11352
static void test_ode_proposal_fitzhugh_simp_mmala90() {
  // Input arguments
  double params[] = { 0.20308192424130916, 0.16250982865008406, 3.00441269756031692 };
  double likelihood = 159.18383162555278432;
  double temperature = 0.55492895730664349;
  double stepsize = 1.30247634458035511;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -345.31408110267068423;
  geometry->gradient_log_likelihood[1] = -52.78500981643620094;
  geometry->gradient_log_likelihood[2] = -321.34986122792827246;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 120031.24766841769451275;
  geometry->FI[0 * geometry->ldfi + 1] = 8480.33618043858223245;
  geometry->FI[0 * geometry->ldfi + 2] = 65268.20704054575617192;
  geometry->FI[1 * geometry->ldfi + 0] = 8480.33618043858223245;
  geometry->FI[1 * geometry->ldfi + 1] = 2929.52108642719394993;
  geometry->FI[1 * geometry->ldfi + 2] = 5698.11766057413478848;
  geometry->FI[2 * geometry->ldfi + 0] = 65268.20704054575617192;
  geometry->FI[2 * geometry->ldfi + 1] = 5698.11766057413478848;
  geometry->FI[2 * geometry->ldfi + 2] = 45790.60618204041384161;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20669587143516971, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15703803583145548, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99398975064811967, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00011346550287849, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001831701980057, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00015945011452331, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001831701980057, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00137972328809519, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00014558240542590, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00015945011452331, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00014558240542590, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00031215173284012, 1.0e-06);

}

// Sample number 1518
static void test_ode_likelihood_fitzhugh_simp_mmala91() {
  // Input argument
  double params[] = { 0.21917963803533561, 0.17221785316412369, 2.96745853527136916 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.88821060565871335, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -1.08353473102005182, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -11.40229627825151226, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 214.67462155380849254, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 130627.58002442463475745, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 11176.46999915764718025, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 69160.06357130748801865, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 11176.46999915764718025, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3395.81627945667423774, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 7107.43584599300356786, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 69160.06357130748801865, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 7107.43584599300356786, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46049.41803274469566531, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 1518
static void test_ode_proposal_fitzhugh_simp_mmala91() {
  // Input arguments
  double params[] = { 0.21917963803533561, 0.17221785316412369, 2.96745853527136916 };
  double likelihood = 157.88821060565871335;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -1.08353473102005182;
  geometry->gradient_log_likelihood[1] = -11.40229627825151226;
  geometry->gradient_log_likelihood[2] = 214.67462155380849254;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 130627.58002442463475745;
  geometry->FI[0 * geometry->ldfi + 1] = 11176.46999915764718025;
  geometry->FI[0 * geometry->ldfi + 2] = 69160.06357130748801865;
  geometry->FI[1 * geometry->ldfi + 0] = 11176.46999915764718025;
  geometry->FI[1 * geometry->ldfi + 1] = 3395.81627945667423774;
  geometry->FI[1 * geometry->ldfi + 2] = 7107.43584599300356786;
  geometry->FI[2 * geometry->ldfi + 0] = 69160.06357130748801865;
  geometry->FI[2 * geometry->ldfi + 1] = 7107.43584599300356786;
  geometry->FI[2 * geometry->ldfi + 2] = 46049.41803274469566531;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20834284086932608, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15675372740067500, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99041140114334114, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006907485664147, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001508559733182, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00010141282476030, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001508559733182, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080403297271689, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00010144084552484, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00010141282476030, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00010144084552484, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00020793882633940, 1.0e-06);

}

// Sample number 1079
static void test_ode_likelihood_fitzhugh_simp_mmala92() {
  // Input argument
  double params[] = { 0.20297089528031931, 0.14663084951652330, 3.00435574094675450 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.62128302221458398, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -205.80820068672548473, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 2.01238665345615431, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -234.10601963788292323, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 118988.93575662338116672, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 6003.67464758426740445, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 65020.20006096248107497, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 6003.67464758426740445, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2590.70721094125383388, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 4065.48270167102373307, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 65020.20006096248107497, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 4065.48270167102373307, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45934.87307166151731508, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 1079
static void test_ode_proposal_fitzhugh_simp_mmala92() {
  // Input arguments
  double params[] = { 0.20297089528031931, 0.14663084951652330, 3.00435574094675450 };
  double likelihood = 159.62128302221458398;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -205.80820068672548473;
  geometry->gradient_log_likelihood[1] = 2.01238665345615431;
  geometry->gradient_log_likelihood[2] = -234.10601963788292323;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 118988.93575662338116672;
  geometry->FI[0 * geometry->ldfi + 1] = 6003.67464758426740445;
  geometry->FI[0 * geometry->ldfi + 2] = 65020.20006096248107497;
  geometry->FI[1 * geometry->ldfi + 0] = 6003.67464758426740445;
  geometry->FI[1 * geometry->ldfi + 1] = 2590.70721094125383388;
  geometry->FI[1 * geometry->ldfi + 2] = 4065.48270167102373307;
  geometry->FI[2 * geometry->ldfi + 0] = 65020.20006096248107497;
  geometry->FI[2 * geometry->ldfi + 1] = 4065.48270167102373307;
  geometry->FI[2 * geometry->ldfi + 2] = 45934.87307166151731508;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20717623685764555, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15553976575157091, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99292395316294346, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006836390198811, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00000763158023867, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009609275549498, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00000763158023867, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00082597556808309, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00006230086900818, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009609275549498, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00006230086900818, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00018160523724911, 1.0e-06);

}

// Sample number 10615
static void test_ode_likelihood_fitzhugh_simp_mmala93() {
  // Input argument
  double params[] = { 0.20353550017355071, 0.19164847936690976, 2.99208435850367005 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.03747580028621655, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 94.06644414835602674, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -77.77507814738312675, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 2.34705216453969001, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 121836.94437238620594144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 13026.03318130439947709, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 65708.61926484227296896, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 13026.03318130439947709, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3867.96355638803606780, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 8639.27164203083339089, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 65708.61926484227296896, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 8639.27164203083339089, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45527.41834475069481414, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 10615
static void test_ode_proposal_fitzhugh_simp_mmala93() {
  // Input arguments
  double params[] = { 0.20353550017355071, 0.19164847936690976, 2.99208435850367005 };
  double likelihood = 159.03747580028621655;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 94.06644414835602674;
  geometry->gradient_log_likelihood[1] = -77.77507814738312675;
  geometry->gradient_log_likelihood[2] = 2.34705216453969001;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 121836.94437238620594144;
  geometry->FI[0 * geometry->ldfi + 1] = 13026.03318130439947709;
  geometry->FI[0 * geometry->ldfi + 2] = 65708.61926484227296896;
  geometry->FI[1 * geometry->ldfi + 0] = 13026.03318130439947709;
  geometry->FI[1 * geometry->ldfi + 1] = 3867.96355638803606780;
  geometry->FI[1 * geometry->ldfi + 2] = 8639.27164203083339089;
  geometry->FI[2 * geometry->ldfi + 0] = 65708.61926484227296896;
  geometry->FI[2 * geometry->ldfi + 1] = 8639.27164203083339089;
  geometry->FI[2 * geometry->ldfi + 2] = 45527.41834475069481414;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20731252959542876, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15839989697627824, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99298975416173407, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006852659704240, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001713280138384, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009565166020296, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001713280138384, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00083026339017881, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00013282321860041, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009565166020296, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00013282321860041, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00020368812806835, 1.0e-06);

}

// Sample number 15582
static void test_ode_likelihood_fitzhugh_simp_mmala94() {
  // Input argument
  double params[] = { 0.21238280728416628, 0.13284372267970573, 2.98840592617354073 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.68226128022794796, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -246.01961353888373196, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 46.20482358020394287, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -84.31654756283060692, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 124023.72645367879886180, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 4320.72014582387510018, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 67069.55392673202732112, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 4320.72014582387510018, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2457.42495375295357007, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 2850.00679720310472476, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 67069.55392673202732112, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 2850.00679720310472476, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46273.04807945701759309, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 15582
static void test_ode_proposal_fitzhugh_simp_mmala94() {
  // Input arguments
  double params[] = { 0.21238280728416628, 0.13284372267970573, 2.98840592617354073 };
  double likelihood = 159.68226128022794796;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -246.01961353888373196;
  geometry->gradient_log_likelihood[1] = 46.20482358020394287;
  geometry->gradient_log_likelihood[2] = -84.31654756283060692;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 124023.72645367879886180;
  geometry->FI[0 * geometry->ldfi + 1] = 4320.72014582387510018;
  geometry->FI[0 * geometry->ldfi + 2] = 67069.55392673202732112;
  geometry->FI[1 * geometry->ldfi + 0] = 4320.72014582387510018;
  geometry->FI[1 * geometry->ldfi + 1] = 2457.42495375295357007;
  geometry->FI[1 * geometry->ldfi + 2] = 2850.00679720310472476;
  geometry->FI[2 * geometry->ldfi + 0] = 67069.55392673202732112;
  geometry->FI[2 * geometry->ldfi + 1] = 2850.00679720310472476;
  geometry->FI[2 * geometry->ldfi + 2] = 46273.04807945701759309;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20798328629250332, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15394064236570840, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99180626997354926, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006869714107490, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00000571502837865, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009921971706567, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00000571502837865, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080715773426686, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00004143017814062, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009921971706567, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00004143017814062, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00018614418201051, 1.0e-06);

}

// Sample number 18677
static void test_ode_likelihood_fitzhugh_simp_mmala95() {
  // Input argument
  double params[] = { 0.19560563407155393, 0.13853795751913645, 3.00669675332415576 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.92275151110467846, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 569.37277723466934276, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 54.21480150575270329, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 166.31847288615364278, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 113664.75185526689165272, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 4304.26012459820231015, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 63048.03800953555764863, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 4304.26012459820231015, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2421.23203922878019512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 3013.63426625138799864, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 63048.03800953555764863, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 3013.63426625138799864, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45831.65796215079899412, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 18677
static void test_ode_proposal_fitzhugh_simp_mmala95() {
  // Input arguments
  double params[] = { 0.19560563407155393, 0.13853795751913645, 3.00669675332415576 };
  double likelihood = 157.92275151110467846;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 569.37277723466934276;
  geometry->gradient_log_likelihood[1] = 54.21480150575270329;
  geometry->gradient_log_likelihood[2] = 166.31847288615364278;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 113664.75185526689165272;
  geometry->FI[0 * geometry->ldfi + 1] = 4304.26012459820231015;
  geometry->FI[0 * geometry->ldfi + 2] = 63048.03800953555764863;
  geometry->FI[1 * geometry->ldfi + 0] = 4304.26012459820231015;
  geometry->FI[1 * geometry->ldfi + 1] = 2421.23203922878019512;
  geometry->FI[1 * geometry->ldfi + 2] = 3013.63426625138799864;
  geometry->FI[2 * geometry->ldfi + 0] = 63048.03800953555764863;
  geometry->FI[2 * geometry->ldfi + 1] = 3013.63426625138799864;
  geometry->FI[2 * geometry->ldfi + 2] = 45831.65796215079899412;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20714348779293520, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15563285766994162, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99304067738333224, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006837434832479, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00000487717187191, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009373805554516, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00000487717187191, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00082837326278208, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00004775995523039, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009373805554516, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00004775995523039, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00017225411664903, 1.0e-06);

}

// Sample number 2598
static void test_ode_likelihood_fitzhugh_simp_mmala96() {
  // Input argument
  double params[] = { 0.20109506246132688, 0.13380992011813439, 2.99872763986831004 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.04200683278341444, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 458.59398102558469645, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 63.62374837329626587, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 190.78359886281430136, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 116716.19540705546387471, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 3852.49554305215588101, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 64289.98201258561311988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 3852.49554305215588101, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2400.26012642081059312, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 2650.63245171469907291, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 64289.98201258561311988, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 2650.63245171469907291, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45996.30199597292812541, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 2598
static void test_ode_proposal_fitzhugh_simp_mmala96() {
  // Input arguments
  double params[] = { 0.20109506246132688, 0.13380992011813439, 2.99872763986831004 };
  double likelihood = 159.04200683278341444;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 458.59398102558469645;
  geometry->gradient_log_likelihood[1] = 63.62374837329626587;
  geometry->gradient_log_likelihood[2] = 190.78359886281430136;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 116716.19540705546387471;
  geometry->FI[0 * geometry->ldfi + 1] = 3852.49554305215588101;
  geometry->FI[0 * geometry->ldfi + 2] = 64289.98201258561311988;
  geometry->FI[1 * geometry->ldfi + 0] = 3852.49554305215588101;
  geometry->FI[1 * geometry->ldfi + 1] = 2400.26012642081059312;
  geometry->FI[1 * geometry->ldfi + 2] = 2650.63245171469907291;
  geometry->FI[2 * geometry->ldfi + 0] = 64289.98201258561311988;
  geometry->FI[2 * geometry->ldfi + 1] = 2650.63245171469907291;
  geometry->FI[2 * geometry->ldfi + 2] = 45996.30199597292812541;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20755640251082103, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15493775831253423, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99229651115598161, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006856468915985, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00000450440248288, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009557470767484, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00000450440248288, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00081931726041494, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00004091896266506, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009557470767484, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00004091896266506, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00017596452859526, 1.0e-06);

}

// Sample number 11374
static void test_ode_likelihood_fitzhugh_simp_mmala97() {
  // Input argument
  double params[] = { 0.21309990731816281, 0.14012620911627793, 2.98378925940434936 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.94194297928538617, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -60.19864537441032581, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 38.74955775706543193, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 56.41464276334857431, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 124737.83717513768351637, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 5491.20427470616232313, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 67290.98189970492967404, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 5491.20427470616232313, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2564.85224786590515578, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 3606.03429165224633834, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 67290.98189970492967404, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 3606.03429165224633834, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 46224.58920365734957159, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 11374
static void test_ode_proposal_fitzhugh_simp_mmala97() {
  // Input arguments
  double params[] = { 0.21309990731816281, 0.14012620911627793, 2.98378925940434936 };
  double likelihood = 159.94194297928538617;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -60.19864537441032581;
  geometry->gradient_log_likelihood[1] = 38.74955775706543193;
  geometry->gradient_log_likelihood[2] = 56.41464276334857431;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 124737.83717513768351637;
  geometry->FI[0 * geometry->ldfi + 1] = 5491.20427470616232313;
  geometry->FI[0 * geometry->ldfi + 2] = 67290.98189970492967404;
  geometry->FI[1 * geometry->ldfi + 0] = 5491.20427470616232313;
  geometry->FI[1 * geometry->ldfi + 1] = 2564.85224786590515578;
  geometry->FI[1 * geometry->ldfi + 2] = 3606.03429165224633834;
  geometry->FI[2 * geometry->ldfi + 0] = 67290.98189970492967404;
  geometry->FI[2 * geometry->ldfi + 1] = 3606.03429165224633834;
  geometry->FI[2 * geometry->ldfi + 2] = 46224.58920365734957159;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20807865978716839, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15450198241738991, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99110069399906875, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006880299551676, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00000728409847652, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009959102928512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00000728409847652, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00080687010584389, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00005234112781800, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009959102928512, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00005234112781800, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00018888393453424, 1.0e-06);

}

// Sample number 9385
static void test_ode_likelihood_fitzhugh_simp_mmala98() {
  // Input argument
  double params[] = { 0.20773937121915301, 0.18240782470335165, 2.98984039036181581 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.71424003940961711, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], -172.26845073712905787, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], -78.36090362611501803, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], -103.20557463886859750, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 124053.79830385677632876, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 11947.60446071250589739, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 66624.05175091302953660, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 11947.60446071250589739, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 3586.95077369012869895, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 7843.25910784340612736, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 66624.05175091302953660, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 7843.25910784340612736, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45716.74118541301140795, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 9385
static void test_ode_proposal_fitzhugh_simp_mmala98() {
  // Input arguments
  double params[] = { 0.20773937121915301, 0.18240782470335165, 2.98984039036181581 };
  double likelihood = 159.71424003940961711;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = -172.26845073712905787;
  geometry->gradient_log_likelihood[1] = -78.36090362611501803;
  geometry->gradient_log_likelihood[2] = -103.20557463886859750;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 124053.79830385677632876;
  geometry->FI[0 * geometry->ldfi + 1] = 11947.60446071250589739;
  geometry->FI[0 * geometry->ldfi + 2] = 66624.05175091302953660;
  geometry->FI[1 * geometry->ldfi + 0] = 11947.60446071250589739;
  geometry->FI[1 * geometry->ldfi + 1] = 3586.95077369012869895;
  geometry->FI[1 * geometry->ldfi + 2] = 7843.25910784340612736;
  geometry->FI[2 * geometry->ldfi + 0] = 66624.05175091302953660;
  geometry->FI[2 * geometry->ldfi + 1] = 7843.25910784340612736;
  geometry->FI[2 * geometry->ldfi + 2] = 45716.74118541301140795;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20746979978638286, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15756295224576974, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99241792217075231, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006857866750887, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00001583227976901, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009722504066063, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00001583227976901, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00082492993700795, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00011845395088730, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009722504066063, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00011845395088730, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00020227494699049, 1.0e-06);

}

// Sample number 238
static void test_ode_likelihood_fitzhugh_simp_mmala99() {
  // Input argument
  double params[] = { 0.20050418516664048, 0.14527855229055522, 3.00085566193014497 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 159.68090574680837790, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 333.94176600531193344, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 34.70059302182787775, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 93.67354151082952285, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 117047.86330300607369281, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 5581.59181188911679783, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 64321.94419295326224528, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 5581.59181188911679783, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2551.80001488529660492, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 3823.16593788290037992, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 64321.94419295326224528, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 3823.16593788290037992, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45895.40815867365745362, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 238
static void test_ode_proposal_fitzhugh_simp_mmala99() {
  // Input arguments
  double params[] = { 0.20050418516664048, 0.14527855229055522, 3.00085566193014497 };
  double likelihood = 159.68090574680837790;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 333.94176600531193344;
  geometry->gradient_log_likelihood[1] = 34.70059302182787775;
  geometry->gradient_log_likelihood[2] = 93.67354151082952285;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 117047.86330300607369281;
  geometry->FI[0 * geometry->ldfi + 1] = 5581.59181188911679783;
  geometry->FI[0 * geometry->ldfi + 2] = 64321.94419295326224528;
  geometry->FI[1 * geometry->ldfi + 0] = 5581.59181188911679783;
  geometry->FI[1 * geometry->ldfi + 1] = 2551.80001488529660492;
  geometry->FI[1 * geometry->ldfi + 2] = 3823.16593788290037992;
  geometry->FI[2 * geometry->ldfi + 0] = 64321.94419295326224528;
  geometry->FI[2 * geometry->ldfi + 1] = 3823.16593788290037992;
  geometry->FI[2 * geometry->ldfi + 2] = 45895.40815867365745362;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20735141882464522, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15567818514953466, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99227154307760967, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006848331772082, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00000685236579520, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009540785417892, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00000685236579520, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00082491017258690, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00005911290676399, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009540785417892, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00005911290676399, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00017874505714331, 1.0e-06);

}

// Sample number 6740
static void test_ode_likelihood_fitzhugh_simp_mmala100() {
  // Input argument
  double params[] = { 0.19364349023846725, 0.14113925065681751, 3.01110462454210337 };
  size_t block[] = { 0, 1, 2 };
  // Output arguments
  double likelihood;
  gmcmc_geometry_simp_mmala * geometry;

  // Call test function
  int error = gmcmc_ode_likelihood_simp_mmala(data, model, params, 3, block, &likelihood, (void **)&geometry);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(likelihood, 157.54512788072742069, 1.0e-06);

  // Check geometry
  CU_ASSERT_FATAL(geometry != NULL);

  // Check gradient log likelihood
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[0], 503.99358480012119799, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[1], 43.77304169833136882, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_likelihood[2], 82.13342987589982158, 1.0e-06);

  // Check gradient log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->gradient_log_prior[2], 0.00000000000000000, 1.0e-06);

  // Check fisher information
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 0], 112712.02739177504554391, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 1], 4610.32006266670396144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[0 * geometry->ldfi + 2], 62636.01614012375648599, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 0], 4610.32006266670396144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 1], 2441.46951573326077778, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[1 * geometry->ldfi + 2], 3244.40293247949421129, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 0], 62636.01614012375648599, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 1], 3244.40293247949421129, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->FI[2 * geometry->ldfi + 2], 45762.00810670810460579, 1.0e-06);

  // Check hessian log prior
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[0], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[1], 0.00000000000000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(geometry->hessian_log_prior[2], 0.00000000000000000, 1.0e-06);

  free(geometry->gradient_log_likelihood);
  free(geometry->gradient_log_prior);
  free(geometry->hessian_log_prior);
  free(geometry->FI);
  free(geometry);
}

// Sample number 6740
static void test_ode_proposal_fitzhugh_simp_mmala100() {
  // Input arguments
  double params[] = { 0.19364349023846725, 0.14113925065681751, 3.01110462454210337 };
  double likelihood = 157.54512788072742069;
  double temperature = 1.00000000000000000;
  double stepsize = 1.35674619227120341;

  gmcmc_geometry_simp_mmala * geometry;
  CU_ASSERT_FATAL((geometry = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) != NULL);
  CU_ASSERT_FATAL((geometry->gradient_log_likelihood = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->gradient_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->hessian_log_prior = malloc(3 * sizeof(double))) != NULL &&
                  (geometry->FI = malloc((geometry->ldfi = (3 + 1u) & ~1u) * 3 * sizeof(double))) != NULL);
  size_t block[] = { 0, 1, 2 };

  geometry->gradient_log_likelihood[0] = 503.99358480012119799;
  geometry->gradient_log_likelihood[1] = 43.77304169833136882;
  geometry->gradient_log_likelihood[2] = 82.13342987589982158;

  geometry->gradient_log_prior[0] = 0.00000000000000000;
  geometry->gradient_log_prior[1] = 0.00000000000000000;
  geometry->gradient_log_prior[2] = 0.00000000000000000;

  geometry->FI[0 * geometry->ldfi + 0] = 112712.02739177504554391;
  geometry->FI[0 * geometry->ldfi + 1] = 4610.32006266670396144;
  geometry->FI[0 * geometry->ldfi + 2] = 62636.01614012375648599;
  geometry->FI[1 * geometry->ldfi + 0] = 4610.32006266670396144;
  geometry->FI[1 * geometry->ldfi + 1] = 2441.46951573326077778;
  geometry->FI[1 * geometry->ldfi + 2] = 3244.40293247949421129;
  geometry->FI[2 * geometry->ldfi + 0] = 62636.01614012375648599;
  geometry->FI[2 * geometry->ldfi + 1] = 3244.40293247949421129;
  geometry->FI[2 * geometry->ldfi + 2] = 45762.00810670810460579;

  geometry->hessian_log_prior[0] = 0.00000000000000000;
  geometry->hessian_log_prior[1] = 0.00000000000000000;
  geometry->hessian_log_prior[2] = 0.00000000000000000;

 // Output arguments
  size_t ldc = (3 + 1u) & ~1u;
  double mean[3];
  double covariance[3 * ldc];

  // Call test function
  int error = gmcmc_proposal_simp_mmala(3, block, params, likelihood, temperature, stepsize, geometry, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[0], 0.20690856564395793, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[1], 0.15591631092178782, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(mean[2], 2.99355250494678460, 1.0e-06);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 0], 0.00006825979259635, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 1], -0.00000523482404370, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[0 * ldc + 2], -0.00009305836366223, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 0], -0.00000523482404370, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 1], 0.00083277847106146, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[1 * ldc + 2], -0.00005187666556917, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 0], -0.00009305836366223, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 1], -0.00005187666556917, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL_REL(covariance[2 * ldc + 2], 0.00017127469988177, 1.0e-06);

}

