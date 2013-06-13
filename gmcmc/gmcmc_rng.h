/*
 * gmcmc_rng.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_RNG_H
#define GMCMC_RNG_H

#include <stdio.h>
#include <stdint.h>

/**
 * 64-bit parallel RNG type.
 */
typedef struct {
  const char * name;                    /**< Name of PRNG algorithm */
  void (*seed)(void *, int, uint64_t);  /**< Seed function */
  uint64_t (*get)(void *, int);         /**< Integer generation function on [min,max] */
  double (*get_double)(void *, int);    /**< Uniform real generation function on [0,1) */
  uint64_t min, max;                    /**< Limits of integer generation function */
  size_t size;                          /**< Size of state */
  unsigned int max_id;                  /**< Number of independent substreams */
} gmcmc_prng64_type;

/**
 * 64-bit parallel RNG.
 *
 * A parallel RNG consists of multiple independent substreams of random numbers.
 */
typedef struct gmcmc_prng64 gmcmc_prng64;

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
int gmcmc_prng64_create(gmcmc_prng64 **, const gmcmc_prng64_type *, int);

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
int gmcmc_prng64_create_copy(gmcmc_prng64 **, const gmcmc_prng64 *);

/**
 * Copies the state and ID of one RNG into another.  Both RNGs must be the same
 * type.
 *
 * @param [out] dest  the destination of the copy
 * @param [in]  src   the source of the copy
 *
 * @return 0 on success, GMCMC_EINVAL if the RNGs are of different types.
 */
int gmcmc_prng64_memcpy(gmcmc_prng64 *, const gmcmc_prng64 *);

/**
 * Destroys an RNG.
 *
 * @param [in] rng  the RNG to destroy
 */
void gmcmc_prng64_destroy(gmcmc_prng64 *);

/**
 * Writes the RNG state to a file.
 *
 * @param [in]     rng   the RNG
 * @param [in,out] file  the file
 *
 * @return 0 on success, GMCMC_EIO on error.
 */
int gmcmc_prng64_fwrite(const gmcmc_prng64 *, FILE *);

/**
 * Reads the RNG state from a file.
 *
 * @param [out]    rng   the RNG
 * @param [in,out] file  the file
 *
 * @return 0 on success, GMCMC_EIO on error.
 */
int gmcmc_prng64_fread(gmcmc_prng64 *, FILE *);

/**
 * Seeds a parallel RNG.
 *
 * @param [in,out] rng     the RNG
 * @param [in]     seed    the seed value
 *
 * @return 0 on success, GMCMC_EINVAL if the stream argument is out of range.
 */
void gmcmc_prng64_seed(gmcmc_prng64 *, uint64_t);

/**
 * Generates a 64-bit unsigned integer uniformly distributed between [min,max]
 * inclusive.
 *
 * @param [in] rng  the RNG
 *
 * @return a random unsigned integer.
 */
uint64_t gmcmc_prng64_get(const gmcmc_prng64 *);

/**
 * Generates a real uniformly distributed between [0,1).
 *
 * @param [in] rng  the RNG
 *
 * @return a random real.
 */
double gmcmc_prng64_get_double(const gmcmc_prng64 *);

/*
 * Built-in RNG types.
 */

extern const gmcmc_prng64_type * gmcmc_prng64_dcmt607;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt1279;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt2281;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt4253;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt11213;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt19937;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt44497;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt86243;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt132049;
extern const gmcmc_prng64_type * gmcmc_prng64_dcmt216091;

#endif /* GMCMC_RNG_H */
