#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>

#define MT_MM 36
#define MT_NN 72
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0xff800000)
#define MT_LMASK UINT32_C(0x007fffff)
#define MT_SHIFT0 12
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

typedef struct {
  uint32_t aaa, maskB, maskC;
} mt_params;

static mt_params params[] = {
  { UINT32_C(0xeedb0000), UINT32_C(0xef373a80), UINT32_C(0xf7e58000) },
  { UINT32_C(0xb07d0001), UINT32_C(0x369d5e80), UINT32_C(0xfbd58000) },
  { UINT32_C(0xd3c30002), UINT32_C(0xf9256a80), UINT32_C(0xdfe58000) },
  { UINT32_C(0xb52b0003), UINT32_C(0xecb56d80), UINT32_C(0xdfd78000) },
  { UINT32_C(0xa2550004), UINT32_C(0x6dd4b780), UINT32_C(0xfeb58000) },
  { UINT32_C(0xdcaa0005), UINT32_C(0xb3753700), UINT32_C(0xfed58000) },
  { UINT32_C(0xea080006), UINT32_C(0x6d7d6f80), UINT32_C(0xfef58000) },
  { UINT32_C(0xd8400007), UINT32_C(0x6df56d80), UINT32_C(0xffe58000) },
  { UINT32_C(0xce150008), UINT32_C(0xa6fcdc80), UINT32_C(0xfbc50000) },
  { UINT32_C(0x87e40009), UINT32_C(0xfb6f6f00), UINT32_C(0xdec58000) },
  { UINT32_C(0xbdf9000a), UINT32_C(0x7af53a80), UINT32_C(0xf7f58000) },
  { UINT32_C(0x88a6000b), UINT32_C(0x397ebb80), UINT32_C(0xf7b48000) },
  { UINT32_C(0xef6a000c), UINT32_C(0x75bf3680), UINT32_C(0xffed8000) },
  { UINT32_C(0xcc93000d), UINT32_C(0xbaf13b80), UINT32_C(0xf7758000) },
  { UINT32_C(0xad74000e), UINT32_C(0xefbd2b80), UINT32_C(0xf7568000) },
  { UINT32_C(0x931b000f), UINT32_C(0xdb74ab80), UINT32_C(0xf7d50000) },
  { UINT32_C(0xfb040010), UINT32_C(0x2df76f80), UINT32_C(0xfeb58000) },
  { UINT32_C(0xfbd50011), UINT32_C(0xdd557780), UINT32_C(0xeff50000) },
  { UINT32_C(0xef250012), UINT32_C(0xe97f7700), UINT32_C(0xded58000) },
  { UINT32_C(0xf7970013), UINT32_C(0x3bb53a80), UINT32_C(0xf7f58000) },
  { UINT32_C(0xe2c50014), UINT32_C(0x37b6b780), UINT32_C(0xfef58000) },
  { UINT32_C(0xe1fb0015), UINT32_C(0xacf53b80), UINT32_C(0xf7658000) },
  { UINT32_C(0xf16a0016), UINT32_C(0x2eb52b80), UINT32_C(0xf7f50000) },
  { UINT32_C(0xf5520017), UINT32_C(0x77b55d80), UINT32_C(0xfbd58000) },
  { UINT32_C(0xbdd10018), UINT32_C(0xdbb5af80), UINT32_C(0xbd550000) },
  { UINT32_C(0xb7da0019), UINT32_C(0x2ed52a80), UINT32_C(0xf7f50000) },
  { UINT32_C(0x8329001a), UINT32_C(0xa75cdd00), UINT32_C(0xfbd58000) },
  { UINT32_C(0x956f001b), UINT32_C(0x7bf76f00), UINT32_C(0xdee58000) },
  { UINT32_C(0xe1a6001c), UINT32_C(0xadb52f80), UINT32_C(0xf7e58000) },
  { UINT32_C(0x951c001d), UINT32_C(0xbaa53b80), UINT32_C(0xf7750000) },
  { UINT32_C(0xec9f001e), UINT32_C(0xa53d6f80), UINT32_C(0xfed58000) },
  { UINT32_C(0xe2be001f), UINT32_C(0x3b453b00), UINT32_C(0xf7d58000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 2281",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  32
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt2281 = &type;
