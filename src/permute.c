/**
 * Generates a random permutation on [0,n).
 *
 * @param [in]  n
 * @param [out] indices  the permutation
 * @param [in]  rng      an RNG
 */
void gmcmc_permute(size_t n, size_t * indices, const gmcmc_prng64 * rng) {
  // Knuth shuffle
  for (size_t i = 0; i < n; i++) {
    // Generate j = [0,i]
    const size_t scale = (rng->type->max - rng->type->min) / (i + 1);
    size_t j;
    do {
      j = gmcmc_prng64_get(rng) / scale;
    } while (j > i);

    // Swap indices[i] with indices[j] and initialise indices[j]
    indices[i] = indices[j];
    indices[j] = i;
  }
}
