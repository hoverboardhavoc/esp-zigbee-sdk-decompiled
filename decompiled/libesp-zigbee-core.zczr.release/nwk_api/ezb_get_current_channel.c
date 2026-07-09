/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_api.o -> ezb_get_current_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint ezb_get_current_channel(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = nwk_get_pan_channel();
  uVar2 = 0xc;
  do {
    if (((uVar1 & 0x7ffffff) >> (uVar2 & 0x1f) & 1) != 0) {
      return uVar2 & 0xff;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x1b);
  return 0xb;
}

