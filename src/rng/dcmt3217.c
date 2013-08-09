#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>
#include "dcmt.h"

#define MT_MM  50
#define MT_NN 101
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0xffff8000)
#define MT_LMASK UINT32_C(0x00007fff)
#define MT_SHIFT0 12
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

static mt_params params[] = {
  { UINT32_C(0xd11b0000), UINT32_C(0x24af5f80), UINT32_C(0xfedf0000) },
  { UINT32_C(0x8c360001), UINT32_C(0x8cbb5f80), UINT32_C(0xfaff8000) },
  { UINT32_C(0xcecf0002), UINT32_C(0xcafd5e80), UINT32_C(0xffdd0000) },
  { UINT32_C(0xe1660003), UINT32_C(0x54f2db80), UINT32_C(0xff7f8000) },
  { UINT32_C(0xc9c60004), UINT32_C(0xc77d5780), UINT32_C(0xff758000) },
  { UINT32_C(0x81940005), UINT32_C(0x65b55780), UINT32_C(0xff770000) },
  { UINT32_C(0x89280006), UINT32_C(0x9d775f80), UINT32_C(0xfbd50000) },
  { UINT32_C(0xd1560007), UINT32_C(0x8e775680), UINT32_C(0xfff58000) },
  { UINT32_C(0xd5f00008), UINT32_C(0x9cb55b80), UINT32_C(0xfff38000) },
  { UINT32_C(0xf5bb0009), UINT32_C(0xa9bfda80), UINT32_C(0xffd58000) },
  { UINT32_C(0xc83c000a), UINT32_C(0xa66ad580), UINT32_C(0xffc18000) },
  { UINT32_C(0xdb5f000b), UINT32_C(0x57b2da80), UINT32_C(0xff6f8000) },
  { UINT32_C(0xa9a2000c), UINT32_C(0x32f4d680), UINT32_C(0xfff70000) },
  { UINT32_C(0x9853000d), UINT32_C(0x8cbf7780), UINT32_C(0xeee70000) },
  { UINT32_C(0x827a000e), UINT32_C(0x89b55f80), UINT32_C(0xfd7c8000) },
  { UINT32_C(0x9d49000f), UINT32_C(0x76b75b80), UINT32_C(0xffd58000) },
  { UINT32_C(0x99930010), UINT32_C(0xe7f7da80), UINT32_C(0xbf7c8000) },
  { UINT32_C(0xe7480011), UINT32_C(0xd6b75b80), UINT32_C(0xffd40000) },
  { UINT32_C(0xd9f20012), UINT32_C(0xc934d780), UINT32_C(0xffd78000) },
  { UINT32_C(0xfdd70013), UINT32_C(0x36e75f80), UINT32_C(0xff5b0000) },
  { UINT32_C(0xb8df0014), UINT32_C(0xb96dd700), UINT32_C(0xffe58000) },
  { UINT32_C(0x937d0015), UINT32_C(0x56ffde80), UINT32_C(0xffd50000) },
  { UINT32_C(0xbefa0016), UINT32_C(0x9d355b80), UINT32_C(0xfff58000) },
  { UINT32_C(0xa85b0017), UINT32_C(0xcff55700), UINT32_C(0xfeff8000) },
  { UINT32_C(0xdb230018), UINT32_C(0x657b6e80), UINT32_C(0xbfd58000) },
  { UINT32_C(0x80860019), UINT32_C(0x76dd7680), UINT32_C(0xffe70000) },
  { UINT32_C(0xf31b001a), UINT32_C(0x99375780), UINT32_C(0xfef78000) },
  { UINT32_C(0xed5a001b), UINT32_C(0x56bcdb80), UINT32_C(0xff738000) },
  { UINT32_C(0xf561001c), UINT32_C(0x38755d80), UINT32_C(0xfffd0000) },
  { UINT32_C(0xda7d001d), UINT32_C(0xb9bfdf80), UINT32_C(0xfbf50000) },
  { UINT32_C(0xa50f001e), UINT32_C(0xa6ccd700), UINT32_C(0xffe48000) },
  { UINT32_C(0xc3ab001f), UINT32_C(0x737b5780), UINT32_C(0xefe18000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 3217",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  32
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt3217 = &type;
