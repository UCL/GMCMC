#define CONCATx(x, y) x ## y
#define CONCAT(x, y) CONCATx(x, y)
CU_ADD_TEST(fitzhugh_ode_simp_mmala, CONCAT(test_fitzhugh_ode_likelihood_simp_mmala, I));
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");
