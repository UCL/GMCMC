/*
 * dcmt.c
 *
 * The code for this is taken from the original 32-bit Mersenne Twister
 * implementation:
 * http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/MT2002/emt19937ar.html
 *
 * The parameters for the parallel RNGs are found using the Dynamic Creator
 * Mersenne Twister (which currently only supports 32-bit output):
 * http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/DC/dc.html
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

typedef struct {
  uint32_t state[MT_NN];
  int i;
} mt_state;

static void set(void * state, int id, uint64_t seed) {
  mt_state * mt = (mt_state *)state;

  mt->state[0] = (uint32_t)(seed & MT_WMASK);
  for (int i = 1; i < MT_NN; i++) {
    mt->state[i] = (UINT32_C(1812433253) * (mt->state[i - 1] ^
                                            (mt->state[i - 1] >> 30))) + i + 1;
    mt->state[i] &= MT_WMASK;
  }
  mt->i = MT_NN;
}

static uint64_t get(void * state, int id) {
  mt_state * mt = (mt_state *)state;
  const uint32_t mag01[] = { UINT32_C(0), params[id].aaa };

  if (mt->i >= MT_NN) {
    for (int k = 0; k < (MT_NN - MT_MM); k++) {
      uint32_t x = (mt->state[k] & MT_UMASK) | (mt->state[k + 1] & MT_LMASK);
      mt->state[k] = mt->state[k + MT_MM] ^ (x >> 1) ^ mag01[x & UINT32_C(0x1)];
    }
    for (int k = (MT_NN - MT_MM); k < (MT_NN - 1); k++) {
      uint32_t x = (mt->state[k] & MT_UMASK) | (mt->state[k + 1] & MT_LMASK);
      mt->state[k] = mt->state[k + MT_MM - MT_NN] ^ (x >> 1) ^ mag01[x & UINT32_C(0x1)];
    }
    uint32_t x = (mt->state[MT_NN - 1] & MT_UMASK) | (mt->state[0] & MT_LMASK);
    mt->state[MT_NN - 1] = mt->state[MT_MM - 1] ^ (x >> 1) ^ mag01[x & UINT32_C(0x1)];
    mt->i = 0;
  }

  uint32_t x = mt->state[mt->i++];

  x ^= x >> MT_SHIFT0;
  x ^= (x << MT_SHIFTB) & params[id].maskB;
  x ^= (x << MT_SHIFTC) & params[id].maskC;
  x ^= x >> MT_SHIFT1;

  return x;
}

static double get_double(void * state, int id) {
  uint64_t a = get(state, id) >> 5;
  uint64_t b = get(state, id) >> 6;
  return (a * 67108864.0 + b) * (1.0 / 9007199254740992.0);
}
