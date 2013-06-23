#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>

#define MT_MM 34
#define MT_NN 69
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0xffffffe0)
#define MT_LMASK UINT32_C(0x0000001f)
#define MT_SHIFT0 12
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

typedef struct {
  uint32_t aaa, maskB, maskC;
} mt_params;

static mt_params params[] = {
  { UINT32_C(0x90e70000), UINT32_C(0xbadcef80), UINT32_C(0xdf978000) },
  { UINT32_C(0x969e0001), UINT32_C(0x23b4ef80), UINT32_C(0xef558000) },
  { UINT32_C(0xf2d90002), UINT32_C(0xbd74ef80), UINT32_C(0xefa58000) },
  { UINT32_C(0xb6050003), UINT32_C(0x35a57f80), UINT32_C(0xeff58000) },
  { UINT32_C(0xd6dd0004), UINT32_C(0x256ef780), UINT32_C(0xefeb8000) },
  { UINT32_C(0xefc80005), UINT32_C(0x73755f80), UINT32_C(0xf7d58000) },
  { UINT32_C(0xb7d70006), UINT32_C(0xed757700), UINT32_C(0x77d78000) },
  { UINT32_C(0xe8040007), UINT32_C(0x2a9b6f80), UINT32_C(0xedc78000) },
  { UINT32_C(0xa6990008), UINT32_C(0xdd72f700), UINT32_C(0xf7d68000) },
  { UINT32_C(0xc17f0009), UINT32_C(0xcd74df80), UINT32_C(0xf7e58000) },
  { UINT32_C(0xce81000a), UINT32_C(0x25f6f680), UINT32_C(0xefd78000) },
  { UINT32_C(0x9f73000b), UINT32_C(0xeadf7780), UINT32_C(0x77f58000) },
  { UINT32_C(0xf6b9000c), UINT32_C(0xbad26e80), UINT32_C(0xefa78000) },
  { UINT32_C(0xc2a4000d), UINT32_C(0x2a777780), UINT32_C(0xf7ea8000) },
  { UINT32_C(0xc7d2000e), UINT32_C(0x35737780), UINT32_C(0xefe78000) },
  { UINT32_C(0xb490000f), UINT32_C(0xb9b56f80), UINT32_C(0x6e978000) },
  { UINT32_C(0xdf450010), UINT32_C(0xc966f700), UINT32_C(0xefd28000) },
  { UINT32_C(0xe7eb0011), UINT32_C(0x3676f780), UINT32_C(0xefe58000) },
  { UINT32_C(0xbc470012), UINT32_C(0xb3b4ed80), UINT32_C(0xefd58000) },
  { UINT32_C(0xf71d0013), UINT32_C(0xdd6f7780), UINT32_C(0xefd58000) },
  { UINT32_C(0x81cf0014), UINT32_C(0xcd777780), UINT32_C(0xefe38000) },
  { UINT32_C(0xb63b0015), UINT32_C(0xebdd5d80), UINT32_C(0x77d68000) },
  { UINT32_C(0xfe740016), UINT32_C(0xe6d55f00), UINT32_C(0x7bd48000) },
  { UINT32_C(0x97400017), UINT32_C(0xd564ed80), UINT32_C(0xefe58000) },
  { UINT32_C(0xb4570018), UINT32_C(0x66ab7780), UINT32_C(0xefe58000) },
  { UINT32_C(0xb1560019), UINT32_C(0xdaff7f80), UINT32_C(0xf7ed0000) },
  { UINT32_C(0xd181001a), UINT32_C(0x95dc6f00), UINT32_C(0xefd68000) },
  { UINT32_C(0xcce2001b), UINT32_C(0xb7915f80), UINT32_C(0x7b558000) },
  { UINT32_C(0xa862001c), UINT32_C(0x23b6ef80), UINT32_C(0xeedb8000) },
  { UINT32_C(0x961f001d), UINT32_C(0x65597f80), UINT32_C(0xeff58000) },
  { UINT32_C(0xa809001e), UINT32_C(0xdcb4df80), UINT32_C(0xf7d58000) },
  { UINT32_C(0xa1ce001f), UINT32_C(0xddf57780), UINT32_C(0xeeb58000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 2203",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  32
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt2203 = &type;
