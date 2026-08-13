/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_zed_set_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_zed_set_timeout(int param_1,uint param_2)

{
  uint uVar1;
  
  if (((*(uint *)(param_1 + 0xc) & 3) == 2) || ((*(uint *)(param_1 + 0xc) & 0x3c0) == 0)) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xff0fffff | (param_2 & 0xf) << 0x14;
    if (param_2 != 0) {
      uVar1 = 0x3c << (param_2 & 0x1f);
      goto _L0;
    }
  }
  else {
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xab,
                            "nwk_neighbor_zed_set_timeout",0x10854);
  }
  uVar1 = 10;
_L0:
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfff00000 | uVar1 & 0xfffff;
  return;
}

