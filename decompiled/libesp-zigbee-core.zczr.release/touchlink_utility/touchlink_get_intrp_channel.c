/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_get_intrp_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint touchlink_get_intrp_channel(void)

{
  int iVar1;
  uint uVar2;
  uint auStack_14 [4];
  
  auStack_14[0] = 0;
  iVar1 = nwk_mm_get_pib_attr(0,0x62,auStack_14,4);
  if (iVar1 == 0) {
    uVar2 = 0xc;
    do {
      if (((auStack_14[0] & 0x7ffffff) >> (uVar2 & 0x1f) & 1) != 0) {
        return uVar2 & 0xff;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 0x1b);
  }
  return 0xb;
}

