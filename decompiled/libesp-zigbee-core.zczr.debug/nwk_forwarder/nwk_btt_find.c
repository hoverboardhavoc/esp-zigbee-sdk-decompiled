/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * nwk_btt_find(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0x59 < uVar1) {
      return (undefined4 *)0x0;
    }
    if ((*(ushort *)(&DAT_00011a44 + (uVar1 + 6) * 2) == param_1) &&
       (*(byte *)((int)&DAT_00011a44 + (uVar1 + 6) * 8 + 2) == param_2)) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return &DAT_00011a44 + (uVar1 + 6) * 2;
}

