#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>

#define MT_MM 20
#define MT_NN 40
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0xfffffffe)
#define MT_LMASK UINT32_C(0x00000001)
#define MT_SHIFT0 12
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

typedef struct {
  uint32_t aaa, maskB, maskC;
} mt_params;

static mt_params params[] = {
  { UINT32_C(0xf0040000), UINT32_C(0xd6d56b80), UINT32_C(0x6f458000) },
  { UINT32_C(0xc81c0001), UINT32_C(0x279cf780), UINT32_C(0xedcb8000) },
  { UINT32_C(0xc30f0002), UINT32_C(0xcd76ec80), UINT32_C(0xefda8000) },
  { UINT32_C(0xaaf70003), UINT32_C(0x8d567380), UINT32_C(0xeffb8000) },
  { UINT32_C(0xc6ad0004), UINT32_C(0x6d777d80), UINT32_C(0xf7dd8000) },
  { UINT32_C(0xeb2d0005), UINT32_C(0x6ed57a80), UINT32_C(0xe7f58000) },
  { UINT32_C(0xc30f0006), UINT32_C(0x99577780), UINT32_C(0x6f558000) },
  { UINT32_C(0xe4eb0007), UINT32_C(0x33b4df80), UINT32_C(0xf5d78000) },
  { UINT32_C(0xe9d00008), UINT32_C(0xd57cec80), UINT32_C(0xefd78000) },
  { UINT32_C(0xf2010009), UINT32_C(0xb5d4f780), UINT32_C(0xed558000) },
  { UINT32_C(0x9072000a), UINT32_C(0x8d9b6f80), UINT32_C(0xeedd8000) },
  { UINT32_C(0x9ef9000b), UINT32_C(0x76357b80), UINT32_C(0xef6c8000) },
  { UINT32_C(0xa69c000c), UINT32_C(0x31d55a80), UINT32_C(0xf7f58000) },
  { UINT32_C(0xe0e9000d), UINT32_C(0x8d956f80), UINT32_C(0xeedd8000) },
  { UINT32_C(0xef44000e), UINT32_C(0x715a6e80), UINT32_C(0xedd18000) },
  { UINT32_C(0x9a43000f), UINT32_C(0x2df6f680), UINT32_C(0xe7d58000) },
  { UINT32_C(0xbf8b0010), UINT32_C(0x75547680), UINT32_C(0xedd58000) },
  { UINT32_C(0x890c0011), UINT32_C(0xc4dced80), UINT32_C(0xef578000) },
  { UINT32_C(0xc2fb0012), UINT32_C(0xd634ea80), UINT32_C(0xefd48000) },
  { UINT32_C(0xa6360013), UINT32_C(0xd6f4ea80), UINT32_C(0xefd58000) },
  { UINT32_C(0xbdd70014), UINT32_C(0xa3ec7580), UINT32_C(0xef778000) },
  { UINT32_C(0xad5e0015), UINT32_C(0x57f47680), UINT32_C(0xf5d58000) },
  { UINT32_C(0x9e370016), UINT32_C(0x26d57580), UINT32_C(0xef558000) },
  { UINT32_C(0xff200017), UINT32_C(0xdc54ef80), UINT32_C(0xedd58000) },
  { UINT32_C(0xf40a0018), UINT32_C(0x32757780), UINT32_C(0xef678000) },
  { UINT32_C(0xc3020019), UINT32_C(0x6d757d80), UINT32_C(0xf7dd8000) },
  { UINT32_C(0x93ee001a), UINT32_C(0x6df57780), UINT32_C(0xf5558000) },
  { UINT32_C(0x91ad001b), UINT32_C(0x8e757780), UINT32_C(0xed678000) },
  { UINT32_C(0xbda7001c), UINT32_C(0x8d567380), UINT32_C(0xefeb8000) },
  { UINT32_C(0xc62a001d), UINT32_C(0xbdd6ef80), UINT32_C(0xef5b8000) },
  { UINT32_C(0xc071001e), UINT32_C(0x9c956b80), UINT32_C(0x6f578000) },
  { UINT32_C(0x883c001f), UINT32_C(0x666d7b80), UINT32_C(0xef758000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 1279",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  32
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt1279 = &type;
