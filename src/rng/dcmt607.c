#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>

#define MT_MM  9
#define MT_NN 19
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
  { UINT32_C(0xe98e0000), UINT32_C(0xddee7380), UINT32_C(0x6f7a8000) },
  { UINT32_C(0xf03e0001), UINT32_C(0x32f77780), UINT32_C(0xef658000) },
  { UINT32_C(0x869d0002), UINT32_C(0x76757b80), UINT32_C(0xef6d8000) },
  { UINT32_C(0xf8770003), UINT32_C(0xdced7780), UINT32_C(0xed748000) },
  { UINT32_C(0xfec40004), UINT32_C(0xb756dd80), UINT32_C(0xf5b58000) },
  { UINT32_C(0xebe20005), UINT32_C(0xf6f76b80), UINT32_C(0x6f528000) },
  { UINT32_C(0xbfd70006), UINT32_C(0xccd5ba80), UINT32_C(0x77d58000) },
  { UINT32_C(0xc75d0007), UINT32_C(0x9cad7780), UINT32_C(0xedf58000) },
  { UINT32_C(0x9f730008), UINT32_C(0xcd755b80), UINT32_C(0x76d78000) },
  { UINT32_C(0x9e170009), UINT32_C(0xced4db80), UINT32_C(0xf7518000) },
  { UINT32_C(0xa57c000a), UINT32_C(0x332aee80), UINT32_C(0xddc18000) },
  { UINT32_C(0x8f82000b), UINT32_C(0x29f57700), UINT32_C(0xf6d58000) },
  { UINT32_C(0xfdcd000c), UINT32_C(0xf3f56b80), UINT32_C(0x6f578000) },
  { UINT32_C(0xe5d2000d), UINT32_C(0x8d7d6f80), UINT32_C(0xee578000) },
  { UINT32_C(0xa8a8000e), UINT32_C(0x9cad7780), UINT32_C(0xedf78000) },
  { UINT32_C(0xd698000f), UINT32_C(0x39d56f00), UINT32_C(0xed558000) },
  { UINT32_C(0xbd890010), UINT32_C(0x9b5d7280), UINT32_C(0x77d58000) },
  { UINT32_C(0x871f0011), UINT32_C(0xabd4db80), UINT32_C(0xf7558000) },
  { UINT32_C(0xb24c0012), UINT32_C(0x2b356f80), UINT32_C(0xed558000) },
  { UINT32_C(0xc6980013), UINT32_C(0xbb535d00), UINT32_C(0x77cd8000) },
  { UINT32_C(0xe17d0014), UINT32_C(0x236d7580), UINT32_C(0xef778000) },
  { UINT32_C(0x8a570015), UINT32_C(0xb3f47580), UINT32_C(0xef668000) },
  { UINT32_C(0xe21d0016), UINT32_C(0xcef57780), UINT32_C(0xed658000) },
  { UINT32_C(0xde170017), UINT32_C(0x9cab7780), UINT32_C(0xedf58000) },
  { UINT32_C(0xfe960018), UINT32_C(0x6e6d7b80), UINT32_C(0xe7758000) },
  { UINT32_C(0x8efc0019), UINT32_C(0xebb55b80), UINT32_C(0x77578000) },
  { UINT32_C(0xe0dc001a), UINT32_C(0x5dd47680), UINT32_C(0xeed78000) },
  { UINT32_C(0x9f40001b), UINT32_C(0xa4ac7b80), UINT32_C(0xef768000) },
  { UINT32_C(0xebe5001c), UINT32_C(0xa696f780), UINT32_C(0xef578000) },
  { UINT32_C(0x87d4001d), UINT32_C(0xcd5db380), UINT32_C(0x77558000) },
  { UINT32_C(0xe2b8001e), UINT32_C(0x8f577b80), UINT32_C(0xe6d58000) },
  { UINT32_C(0xee05001f), UINT32_C(0xea3d5d80), UINT32_C(0x77d58000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 607",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  32
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt607 = &type;
