#define CONCATx(x, y) x ## y
#define CONCAT(x, y) CONCATx(x, y)
CU_ADD_TEST(five_state, CONCAT(test_five_state_ion_likelihood_mh, I));
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");
