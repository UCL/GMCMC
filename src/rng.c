#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>

/**
 * 64-bit parallel RNG.
 *
 * A parallel RNG consists of multiple independent substreams of random numbers.
 */
struct gmcmc_prng64 {
  const gmcmc_prng64_type * type;       /**< RNG type */
  void * state;                         /**< RNG state */
  int id;                               /**< Parallel RNG stream id */
};

/**
 * Creates a new parallel RNG and allocates memory to store the state.
 *
 * @param [out] rng   the RNG to create
 * @param [in]  type  the type of RNG to create
 * @param [in]  id    the index of the parallel RNG substream to use
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory available to allocate
 *                      another RNG,
 *         GMCMC_EINVAL if the id is less than zero or greater than type->max_id
 */
int gmcmc_prng64_create(gmcmc_prng64 ** rng, const gmcmc_prng64_type * type, int id) {
  if (id < 0 || id >= type->max_id)
    GMCMC_ERROR("RNG id is out of range", GMCMC_EINVAL);

  (*rng) = malloc(sizeof(gmcmc_prng64));
  if (*rng == NULL)
    GMCMC_ERROR("Unable to allocate RNG", GMCMC_ENOMEM);

  (*rng)->state = malloc(type->size);
  if ((*rng)->state == NULL) {
    free(*rng);
    GMCMC_ERROR("Unable to allocate RNG state", GMCMC_ENOMEM);
  }

  (*rng)->type = type;
  (*rng)->id = id;

  return 0;
}

/**
 * Creates a new parallel RNG which is a copy of an existing RNG.
 *
 * @param [out] dest  the destination of the copy
 * @param [in]  src   the source of the copy
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory available to allocate
 *                      another RNG.
 */
int gmcmc_prng64_create_copy(gmcmc_prng64 ** dest, const gmcmc_prng64 * src) {
  *dest = malloc(sizeof(gmcmc_prng64));
  if (*dest == NULL)
    GMCMC_ERROR("Unable to allocate RNG", GMCMC_ENOMEM);

  (*dest)->type = src->type;
  (*dest)->id = src->id;
  (*dest)->state = malloc(src->type->size);

  if ((*dest)->state == NULL) {
    free(*dest);
    GMCMC_ERROR("Unable to allocate RNG state", GMCMC_ENOMEM);
  }

  memcpy((*dest)->state, src->state, src->type->size);

  return 0;

}

/**
 * Copies the state and ID of one RNG into another.  Both RNGs must be the same
 * type.
 *
 * @param [out] dest  the destination of the copy
 * @param [in]  src   the source of the copy
 *
 * @return 0 on success, GMCMC_EINVAL if the RNGs are of different types.
 */
int gmcmc_prng64_memcpy(gmcmc_prng64 * dest, const gmcmc_prng64 * src) {
  if (dest->type != src->type)
    GMCMC_ERROR("RNG types must match", GMCMC_EINVAL);

  memcpy(dest->state, src->state, dest->type->size);
  dest->id = src->id;

  return 0;
}

/**
 * Destroys an RNG.
 *
 * @param [in] rng  the RNG to destroy
 */
void gmcmc_prng64_destroy(gmcmc_prng64 * rng) {
  free(rng->state);
  free(rng);
}

/**
 * Writes the RNG state to a file.
 *
 * @param [in]     rng   the RNG
 * @param [in,out] file  the file
 *
 * @return 0 on success, GMCMC_EIO on error.
 */
int gmcmc_prng64_fwrite(const gmcmc_prng64 * rng, FILE * file) {
  if (fwrite(rng->state, rng->type->size, 1, file) != 1)
    GMCMC_ERROR("Unable to write RNG state", GMCMC_EIO);
  if (fwrite(&rng->id, sizeof(int), 1, file) != 1)
    GMCMC_ERROR("Unable to write RNG id", GMCMC_EIO);
  return 0;
}

/**
 * Reads the RNG state from a file.
 *
 * @param [out]    rng   the RNG
 * @param [in,out] file  the file
 *
 * @return 0 on success, GMCMC_EIO on error.
 */
int gmcmc_prng64_fread(gmcmc_prng64 * rng, FILE * file) {
  if (fread(rng->state, rng->type->size, 1, file) != 1)
    GMCMC_ERROR("Unable to read RNG state", GMCMC_EIO);
  if (fread(&rng->id, sizeof(int), 1, file) != 1)
    GMCMC_ERROR("Unable to read RNG id", GMCMC_EIO);
  return 0;
}

/**
 * Seeds a parallel RNG.
 *
 * @param [in,out] rng     the RNG
 * @param [in]     seed    the seed value
 *
 * @return 0 on success, GMCMC_EINVAL if the stream argument is out of range.
 */
void gmcmc_prng64_seed(gmcmc_prng64 * rng, uint64_t seed) {
  rng->type->seed(rng->state, rng->id, seed);
}

/**
 * Generates a 64-bit unsigned integer uniformly distributed between [min,max]
 * inclusive.
 *
 * @param [in] rng  the RNG
 *
 * @return a random unsigned integer.
 */
uint64_t gmcmc_prng64_get(const gmcmc_prng64 * rng) {
  return rng->type->get(rng->state, rng->id);
}

/**
 * Generates a real uniformly distributed between [0,1).
 *
 * @param [in] rng  the RNG
 *
 * @return a random real.
 */
double gmcmc_prng64_get_double(const gmcmc_prng64 * rng) {
  return rng->type->get_double(rng->state, rng->id);
}
