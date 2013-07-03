#include <gmcmc/gmcmc_rng.h>

#define MT_NN 312
#define MT_MM 156
#define MT_WMASK UINT32_C(0xffffffffffffffff)
#define MT_UMASK UINT64_C(0xffffffff80000000)
#define MT_LMASK UINT64_C(0x000000007fffffff)
#define MT_SHIFT0 29
#define MT_SHIFT1 43
#define MT_SHIFTB 17
#define MT_SHIFTC 37

typedef struct {
  uint64_t aaa, mask0, maskB, maskC;
} mt_params;

static mt_params params[] = {
  { UINT64_C(0xB5026F5AA96619E9), UINT64_C(0x5555555555555555),
    UINT64_C(0x71D67FFFEDA60000), UINT64_C(0xFFF7EEE000000000) }
};

typedef struct {
  uint64_t state[MT_NN];
  int i;
} mt_state;

static void set(void * state, int id, uint64_t seed) {
  mt_state * mt = (mt_state *)state;

  mt->state[0] = seed & MT_WMASK;
  for (int i = 1; i < MT_NN; i++) {
    mt->state[i] = (UINT64_C(6364136223846793005) * (mt->state[i - 1] ^
                                            (mt->state[i - 1] >> 62))) + i + 1;
    mt->state[i] &= MT_WMASK;
  }
  mt->i = MT_NN;
}

uint64_t get(void * state, int id) {
  mt_state * mt = (mt_state *)state;
  const uint32_t mag01[] = { UINT64_C(0), params[id].aaa };

  if (mt->i >= MT_NN) {
    for (int k = 0; k < MT_NN - MT_MM; k++) {
      uint64_t x = (mt->state[k] & MT_UMASK) | (mt->state[k + 1] & MT_LMASK);
      mt->state[k] = mt->state[k + MT_MM] ^ (x >> 1) ^ mag01[x & UINT64_C(1)];
    }
    for (int k = MT_NN - MT_MM; k < MT_NN - 1; k++) {
      uint64_t x = (mt->state[k] & MT_UMASK) | (mt->state[k + 1] & MT_LMASK);
      mt->state[k] = mt->state[k + (MT_MM - MT_NN)] ^ (x >> 1) ^ mag01[x & UINT64_C(1)];
    }
    uint64_t x = (mt->state[MT_NN - 1] & MT_UMASK) | (mt->state[0] & MT_LMASK);
    mt->state[MT_NN - 1] = mt->state[MT_MM - 1] ^ (x >> 1) ^ mag01[x & UINT64_C(1)];
    mt->i = 0;
  }

  uint64_t x = mt->state[mt->i++];

  x ^= (x >> MT_SHIFT0) & params[id].mask0;
  x ^= (x << MT_SHIFTB) & params[id].maskB;
  x ^= (x << MT_SHIFTC) & params[id].maskC;
  x ^= x >> MT_SHIFT1;

  return x;
}

static double get_double(void * state, int id) {
  return (get(state, id) >> 11) * (1.0/9007199254740992.0);
}

static const gmcmc_prng64_type type = {
  "Mersenne Twister 19937 64 bit",
  set,
  get,
  get_double,
  0,
  UINT64_MAX,
  sizeof(mt_state),
  1
};

const gmcmc_prng64_type * gmcmc_prng64_mt19937_64 = &type;
