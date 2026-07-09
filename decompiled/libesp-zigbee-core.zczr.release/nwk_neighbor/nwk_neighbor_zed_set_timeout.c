/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_zed_set_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_zed_set_timeout(int param_1,uint param_2)

{
  uint extraout_a1;
  uint uVar1;
  
  if (((*(uint *)(param_1 + 0xc) & 3) != 2) && ((*(uint *)(param_1 + 0xc) & 0x3c0) != 0)) {
    param_1 = nwk_neighbor_get_extaddr_part_0();
    param_2 = extraout_a1;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xff0fffff | (param_2 & 0xf) << 0x14;
  uVar1 = 10;
  if (param_2 != 0) {
    uVar1 = 0x3c << (param_2 & 0x1f);
  }
  *(uint *)(param_1 + 0x14) = uVar1 & 0xfffff | *(uint *)(param_1 + 0x14) & 0xfff00000;
  return;
}

