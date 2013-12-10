

static inline size_t min(size_t a, size_t b) { return (a < b) ? a : b; }

static int stochastic_eye_sim(const gmcmc_eye_model * eye_model,
                              const double * params, double * macro_c, size_t num_timepoints) {
  // Number of timepoints to use when approximating a bump
  static const size_t num_bump_approx_timepoints = 1000;

  // 3 shape parameters (A, p, tao)
  double a   = params[0];
  double p   = params[1];
  double tao = params[2];

  // 2 latency parameters (mean and variance in log space)
  double mean_lat = params[3];
  double var_lat  = params[4];

  // 2 refract parameters (mean and variance in log space)
  double mean_ref = params[5];
  double var_ref  = params[6];

  // Constant for "gamma" function used to create bump approximation
  const double i_fac = a * exp(p) / pow(p, p);

  // Create bump approximation and find it's peak
  double * bump_approx;
  if ((bump_approx = malloc(num_bump_approx_timepoints * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate bump approximation", GMCMC_ENOMEM);

  unsigned int bump_max = 0;  // Index of the maximum point in the bump approximation
  for (size_t i = 0; i < num_bump_approx_timepoints; i++) {
    double x = (double)i;
    bump_approx[i] = i_fac * pow(x / tao, p) * exp(-x / tao);
    if (bump_approx[i] > bump_approx[bump_max])
      bump_max = i;
  }

  // If the bump approximation never goes above 0.025 then the parameters are
  // invalid
  if (bump_approx[bump_max] < 0.025) {
    free(bump_approx);
    GMCMC_ERROR("Bump approximation never goes above 0.025", GMCMC_EINVAL);
  }

  // Find the first point after the maximum that the bump approximation is below 0.025
  unsigned int bump_duration = bump_max;
  while (bump_approx[bump_duration] >= 0.025)
    bump_duration++;

  double * bump_series;
  if ((bump_series = malloc(num_timepoints * sizeof(double))) == NULL) {
    free(bump_approx);
    GMCMC_ERROR("Failed to allocate bump series", GMCMC_ENOMEM);
  }

  for (size_t k = 0; k < num_timepoints; k++)
    macro_c[k] = 0.0;

  const size_t num_photoreceptors = gmcmc_eye_model_num_photoreceptors(eye_model);
  const gmcmc_prng64 * rng = gmcmc_eye_model_rng(eye_model);
  for (size_t i = 0; i < num_photoreceptors; i++) {
    const size_t num_stimuli = gmcmc_eye_model_num_stimuli(eye_model, i);
    const unsigned int * stimuli = gmcmc_eye_model_stimuli(eye_model, i);

    for (size_t k = 0; k < num_timepoints; k++)
      bump_series[k] = 0.0;

    unsigned int lrefrac = 0;
    for (size_t j = 0; j < num_stimuli; j++) {
      if (j == 0 || stimuli[j] > lrefrac) {
        double latency = floor(mean_lat * pow(var_lat, gmcmc_randn(rng)));
        double refract = floor(mean_ref * pow(var_ref, gmcmc_randn(rng)));

        if (latency > SIZE_MAX || refract > SIZE_MAX)
          continue;

        size_t lat = (size_t)latency;
        size_t ref = (size_t)refract;

        if (stimuli[j] + lat < num_timepoints)
          memcpy(&bump_series[stimuli[j] + lat], bump_approx, min(num_bump_approx_timepoints, num_timepoints - stimuli[j] - lat));

        lrefrac = min(stimuli[j] + lat + bump_duration + ref, num_timepoints);
      }
    }

    for (size_t k = 0; k < num_timepoints; k++)
      macro_c[k] += bump_series[k];
  }

  free(bump_series);
  free(bump_approx);

  return 0;
}
