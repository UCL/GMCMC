#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>

#define MT_MM  69
#define MT_NN 139
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0xfe000000)
#define MT_LMASK UINT32_C(0x01ffffff)
#define MT_SHIFT0 12
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

typedef struct {
  uint32_t aaa, maskB, maskC;
} mt_params;

static mt_params params[] = {
  { UINT32_C(0x91240000), UINT32_C(0xe4eced00), UINT32_C(0xdfd08000) },
  { UINT32_C(0x85fc0001), UINT32_C(0xf7b5b780), UINT32_C(0xbef58000) },
  { UINT32_C(0x89200002), UINT32_C(0xfab16e80), UINT32_C(0xdef50000) },
  { UINT32_C(0xdc0b0003), UINT32_C(0x96fab780), UINT32_C(0xff570000) },
  { UINT32_C(0xbf860004), UINT32_C(0xf2f2ed00), UINT32_C(0xdfdb0000) },
  { UINT32_C(0xe7090005), UINT32_C(0xa5eaed80), UINT32_C(0xdfad8000) },
  { UINT32_C(0xa5c90006), UINT32_C(0xbbbeed80), UINT32_C(0xdfe98000) },
  { UINT32_C(0xa07c0007), UINT32_C(0x6dad7780), UINT32_C(0xff558000) },
  { UINT32_C(0x8ac20008), UINT32_C(0xf7377780), UINT32_C(0xdee78000) },
  { UINT32_C(0xb7330009), UINT32_C(0xbaf4ef00), UINT32_C(0xdfd58000) },
  { UINT32_C(0xd2c9000a), UINT32_C(0xb6ea5b80), UINT32_C(0xff638000) },
  { UINT32_C(0x887d000b), UINT32_C(0xedb56f80), UINT32_C(0xdecf8000) },
  { UINT32_C(0xed61000c), UINT32_C(0xf3eeef00), UINT32_C(0xded48000) },
  { UINT32_C(0x90b1000d), UINT32_C(0xa6faeb80), UINT32_C(0xdfb18000) },
  { UINT32_C(0xf404000e), UINT32_C(0xeafdb780), UINT32_C(0x77558000) },
  { UINT32_C(0xc7be000f), UINT32_C(0xe6dcea80), UINT32_C(0xdfd58000) },
  { UINT32_C(0xf3270010), UINT32_C(0xbd9d6e80), UINT32_C(0xdecf8000) },
  { UINT32_C(0xed540011), UINT32_C(0xed64ad80), UINT32_C(0xdfc90000) },
  { UINT32_C(0xb09e0012), UINT32_C(0xe99bba80), UINT32_C(0xb7d58000) },
  { UINT32_C(0x85230013), UINT32_C(0xbb7aed80), UINT32_C(0xdfaf0000) },
  { UINT32_C(0xa55e0014), UINT32_C(0xed76ed80), UINT32_C(0xdfd58000) },
  { UINT32_C(0xa1660015), UINT32_C(0xe5feed00), UINT32_C(0xdfd50000) },
  { UINT32_C(0x91360016), UINT32_C(0xbcf3ba80), UINT32_C(0xf7d48000) },
  { UINT32_C(0xfe0b0017), UINT32_C(0xcf77af00), UINT32_C(0xbddf8000) },
  { UINT32_C(0x953b0018), UINT32_C(0xe4f8ed00), UINT32_C(0xdfd50000) },
  { UINT32_C(0x89c70019), UINT32_C(0xad6d7700), UINT32_C(0xdef50000) },
  { UINT32_C(0xaf53001a), UINT32_C(0xe4a4ed80), UINT32_C(0xdfed8000) },
  { UINT32_C(0xf51c001b), UINT32_C(0x96757700), UINT32_C(0xeee50000) },
  { UINT32_C(0xf195001c), UINT32_C(0xbbfced80), UINT32_C(0xdfac8000) },
  { UINT32_C(0xb1d6001d), UINT32_C(0xe5f4ed80), UINT32_C(0xdfac8000) },
  { UINT32_C(0xd25e001e), UINT32_C(0xeeeb6f80), UINT32_C(0xdd5b8000) },
  { UINT32_C(0x9474001f), UINT32_C(0xe4baed80), UINT32_C(0xdfe78000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 4423",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  32
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt4423 = &type;
