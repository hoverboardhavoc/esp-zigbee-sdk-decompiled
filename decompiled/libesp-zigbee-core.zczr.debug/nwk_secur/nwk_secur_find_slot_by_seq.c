/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_find_slot_by_seq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_secur_find_slot_by_seq(int param_1,uint param_2)

{
  uint uVar1;
  byte abStack_11 [5];
  
  abStack_11[0] = (byte)((uint)*(undefined4 *)(param_1 + 0x24) >> 0x1d) & 3;
  uVar1 = 0;
  while( true ) {
    uVar1 = bitmap_find_next_bit(abStack_11,2,uVar1);
    uVar1 = uVar1 & 0xff;
    if ((1 < uVar1) || (*(byte *)(uVar1 * 0x11 + param_1 + 0x14) == param_2)) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return;
}

