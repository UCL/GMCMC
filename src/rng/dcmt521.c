#include <gmcmc/gmcmc_rng.h>
#include <stdint.h>

#define MT_MM  8
#define MT_NN 17
#define MT_WMASK UINT32_C(0xffffffff)
#define MT_UMASK UINT32_C(0xff800000)
#define MT_LMASK UINT32_C(0x7fffff00)
#define MT_SHIFT0 12
#define MT_SHIFT1 18
#define MT_SHIFTB  7
#define MT_SHIFTC 15

typedef struct {
  uint32_t aaa, maskB, maskC;
} mt_params;

static mt_params params[] = {
  { UINT32_C(0xe84e0000), UINT32_C(0xf4f2db80), UINT32_C(0xff770000) },
  { UINT32_C(0x83c30001), UINT32_C(0x76b15f80), UINT32_C(0xfdd50000) },
  { UINT32_C(0xa6360002), UINT32_C(0x26f55e80), UINT32_C(0xfdd58000) },
  { UINT32_C(0xdbc80003), UINT32_C(0x9b74db80), UINT32_C(0xffd58000) },
  { UINT32_C(0xbd1b0004), UINT32_C(0xe7f4da80), UINT32_C(0xffd58000) },
  { UINT32_C(0x975f0005), UINT32_C(0x9d757580), UINT32_C(0xeff58000) },
  { UINT32_C(0xac150006), UINT32_C(0x36ed5a80), UINT32_C(0xfff58000) },
  { UINT32_C(0xd68d0007), UINT32_C(0xa5bedd80), UINT32_C(0xffd58000) },
  { UINT32_C(0xaacd0008), UINT32_C(0xa664db80), UINT32_C(0xffd58000) },
  { UINT32_C(0xe9280009), UINT32_C(0x36f75b80), UINT32_C(0xff950000) },
  { UINT32_C(0xf3fa000a), UINT32_C(0x76a33a80), UINT32_C(0xffb38000) },
  { UINT32_C(0xd4f6000b), UINT32_C(0x9bfcdb80), UINT32_C(0xff750000) },
  { UINT32_C(0xa512000c), UINT32_C(0x4bf53a80), UINT32_C(0xffd58000) },
  { UINT32_C(0xdaef000d), UINT32_C(0xdbecda80), UINT32_C(0xfff58000) },
  { UINT32_C(0xcd53000e), UINT32_C(0x16f55b00), UINT32_C(0xffd70000) },
  { UINT32_C(0xf667000f), UINT32_C(0xdab55f80), UINT32_C(0xfdd58000) },
  { UINT32_C(0xab370010), UINT32_C(0xf6e55e80), UINT32_C(0xfdd58000) },
  { UINT32_C(0xecfd0011), UINT32_C(0xa6e4da80), UINT32_C(0xffd58000) },
  { UINT32_C(0xe1410012), UINT32_C(0xf4ecda80), UINT32_C(0xffd50000) },
  { UINT32_C(0xcb260013), UINT32_C(0xb6953f80), UINT32_C(0xfdf58000) },
  { UINT32_C(0x82dc0014), UINT32_C(0x76755e80), UINT32_C(0xfdd58000) },
  { UINT32_C(0x87430015), UINT32_C(0x9ab4db80), UINT32_C(0xffc58000) },
  { UINT32_C(0xc6410016), UINT32_C(0xbaf75e80), UINT32_C(0xfdd58000) },
  { UINT32_C(0x9df90017), UINT32_C(0xb56cdd80), UINT32_C(0xffd50000) },
  { UINT32_C(0xf1170018), UINT32_C(0xa676db80), UINT32_C(0xfffd8000) },
  { UINT32_C(0xd4a90019), UINT32_C(0xcb7edd80), UINT32_C(0xffd58000) },
  { UINT32_C(0xb59c001a), UINT32_C(0x74bd5d80), UINT32_C(0xffd58000) },
  { UINT32_C(0x90c0001b), UINT32_C(0xa77cdb80), UINT32_C(0xff550000) },
  { UINT32_C(0x9fa0001c), UINT32_C(0xbbe55e80), UINT32_C(0xfdd50000) },
  { UINT32_C(0xad17001d), UINT32_C(0xe4bcdc80), UINT32_C(0xffd70000) },
  { UINT32_C(0xcf15001e), UINT32_C(0x26f55e80), UINT32_C(0xfdd58000) },
  { UINT32_C(0xbf86001f), UINT32_C(0x3bb55a80), UINT32_C(0xfff58000) }
};

#include "dcmt.c"

static const gmcmc_prng64_type type = {
  "Dynamic Creator Mersenne Twister 521",
  set,
  get,
  get_double,
  0,
  UINT32_MAX,
  sizeof(mt_state),
  32
};

const gmcmc_prng64_type * gmcmc_prng64_dcmt521 = &type;
