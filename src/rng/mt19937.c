#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>
#include "dcmt.h"

#define MT_NN 624
#define MT_MM 397
#define MATRIX_A UINT32_C(0x9908b0df)
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0x80000000)
#define MT_LMASK UINT32_C(0x7fffffff)
#define MT_SHIFT0 11
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

static mt_params params[] = {
  { UINT32_C(0x9908b0df), UINT32_C(0x9d2c5680), UINT32_C(0xefc60000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Mersenne Twister 19937",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  1
};

const gmcmc_prng64_type * gmcmc_prng64_mt19937 = &type;
