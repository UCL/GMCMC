#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>
#include "dcmt.h"

#define MT_MM 151
#define MT_NN 303
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0xffffff80)
#define MT_LMASK UINT32_C(0x0000007f)
#define MT_SHIFT0 12
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

static mt_params params[] = {
  { UINT32_C(0x93370000), UINT32_C(0x2c7d7d80), UINT32_C(0xf7dc8000) },
  { UINT32_C(0xa79d0001), UINT32_C(0xd6b4f780), UINT32_C(0xfff58000) },
  { UINT32_C(0xf14c0002), UINT32_C(0x76957f80), UINT32_C(0xefee8000) },
  { UINT32_C(0xf1550003), UINT32_C(0x36bb7f80), UINT32_C(0xef750000) },
  { UINT32_C(0xbaec0004), UINT32_C(0xcb7d7f80), UINT32_C(0xeef70000) },
  { UINT32_C(0xa3d70005), UINT32_C(0xdd64df80), UINT32_C(0xffcf0000) },
  { UINT32_C(0x94760006), UINT32_C(0xc9737f80), UINT32_C(0xefd68000) },
  { UINT32_C(0xdb120007), UINT32_C(0xb584fd80), UINT32_C(0xefeb8000) },
  { UINT32_C(0xa3300008), UINT32_C(0xddb77f80), UINT32_C(0xf7fd0000) },
  { UINT32_C(0xc7210009), UINT32_C(0x66b77f80), UINT32_C(0xeffd0000) },
  { UINT32_C(0x86ef000a), UINT32_C(0x65557f80), UINT32_C(0xebed0000) },
  { UINT32_C(0xffc9000b), UINT32_C(0xd96f7f80), UINT32_C(0xeff58000) },
  { UINT32_C(0xf752000c), UINT32_C(0xd9637f80), UINT32_C(0xefd98000) },
  { UINT32_C(0xe03a000d), UINT32_C(0xe6d55b00), UINT32_C(0x7fd18000) },
  { UINT32_C(0xddab000e), UINT32_C(0xcd6cf700), UINT32_C(0xffc68000) },
  { UINT32_C(0x8268000f), UINT32_C(0xc76d7f80), UINT32_C(0xeed78000) },
  { UINT32_C(0x8e4c0010), UINT32_C(0x76d77e80), UINT32_C(0xefed0000) },
  { UINT32_C(0xbb340011), UINT32_C(0x339efe80), UINT32_C(0xeff50000) },
  { UINT32_C(0x8cc10012), UINT32_C(0x97757700), UINT32_C(0x7fd78000) },
  { UINT32_C(0xee650013), UINT32_C(0xbd54f780), UINT32_C(0xffb58000) },
  { UINT32_C(0xe8230014), UINT32_C(0x75677f80), UINT32_C(0xeef58000) },
  { UINT32_C(0xebc20015), UINT32_C(0x246d7d80), UINT32_C(0xf7f68000) },
  { UINT32_C(0xe7680016), UINT32_C(0xb7beff80), UINT32_C(0xeed58000) },
  { UINT32_C(0x84740017), UINT32_C(0x39eefe80), UINT32_C(0xefd68000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 9689",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  24
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt9689 = &type;

