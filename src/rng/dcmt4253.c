#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>
#include "dcmt.h"

#define MT_MM  66
#define MT_NN 133
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0xfffffff8)
#define MT_LMASK UINT32_C(0x00000007)
#define MT_SHIFT0 12
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

static mt_params params[] = {
  { UINT32_C(0xd3a40000), UINT32_C(0xef54ef80), UINT32_C(0xddd58000) },
  { UINT32_C(0xaadc0001), UINT32_C(0x74bd7780), UINT32_C(0xedd50000) },
  { UINT32_C(0x9ac20002), UINT32_C(0xa7707700), UINT32_C(0xf5d78000) },
  { UINT32_C(0xd91c0003), UINT32_C(0x2add7700), UINT32_C(0xf7f78000) },
  { UINT32_C(0xe6340004), UINT32_C(0xaa74ef80), UINT32_C(0xede78000) },
  { UINT32_C(0xdf7b0005), UINT32_C(0x76b57780), UINT32_C(0xe7ff8000) },
  { UINT32_C(0xe2070006), UINT32_C(0x75527680), UINT32_C(0xedd50000) },
  { UINT32_C(0xaf970007), UINT32_C(0xa76d6d80), UINT32_C(0x7bd58000) },
  { UINT32_C(0xefa60008), UINT32_C(0xce56b780), UINT32_C(0x77cd8000) },
  { UINT32_C(0xe99f0009), UINT32_C(0xc6aaeb80), UINT32_C(0xefc28000) },
  { UINT32_C(0xed68000a), UINT32_C(0x375af780), UINT32_C(0xeef58000) },
  { UINT32_C(0xbf91000b), UINT32_C(0x39c56f80), UINT32_C(0xed550000) },
  { UINT32_C(0xeced000c), UINT32_C(0x315cf700), UINT32_C(0xedeb8000) },
  { UINT32_C(0xd969000d), UINT32_C(0x67687780), UINT32_C(0xedc78000) },
  { UINT32_C(0xc50c000e), UINT32_C(0xab757380), UINT32_C(0x77ed0000) },
  { UINT32_C(0xcd8b000f), UINT32_C(0xb57ef780), UINT32_C(0xedeb8000) },
  { UINT32_C(0xd4980010), UINT32_C(0xe756ee80), UINT32_C(0xddd58000) },
  { UINT32_C(0x9ce70011), UINT32_C(0xa6a4f780), UINT32_C(0xefd78000) },
  { UINT32_C(0x89a50012), UINT32_C(0x67357700), UINT32_C(0xeded8000) },
  { UINT32_C(0xb5910013), UINT32_C(0xea3ce780), UINT32_C(0xdd968000) },
  { UINT32_C(0xea280014), UINT32_C(0xd6b4ef80), UINT32_C(0xedd78000) },
  { UINT32_C(0xaa880015), UINT32_C(0xdab4d780), UINT32_C(0xf7eb8000) },
  { UINT32_C(0x8cde0016), UINT32_C(0xb6aaf780), UINT32_C(0xefc48000) },
  { UINT32_C(0xfc630017), UINT32_C(0xb946e780), UINT32_C(0xefeb8000) },
  { UINT32_C(0xd05d0018), UINT32_C(0xcabb7780), UINT32_C(0xedee0000) },
  { UINT32_C(0xeb860019), UINT32_C(0x67ae7b80), UINT32_C(0xebc58000) },
  { UINT32_C(0xcd5f001a), UINT32_C(0x66a57700), UINT32_C(0xefd78000) },
  { UINT32_C(0xb573001b), UINT32_C(0x67b57780), UINT32_C(0xeded8000) },
  { UINT32_C(0xde27001c), UINT32_C(0xd9a4f580), UINT32_C(0xf7d58000) },
  { UINT32_C(0xb082001d), UINT32_C(0xa5a36d80), UINT32_C(0x7bc98000) },
  { UINT32_C(0xb07c001e), UINT32_C(0x33755f80), UINT32_C(0xf5d58000) },
  { UINT32_C(0xcda4001f), UINT32_C(0xd6f56b80), UINT32_C(0x6f558000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 4253",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  32
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt4253 = &type;
