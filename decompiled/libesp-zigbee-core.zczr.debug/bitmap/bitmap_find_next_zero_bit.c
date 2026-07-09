/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bitmap.o -> bitmap_find_next_zero_bit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint bitmap_find_next_zero_bit(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 < param_2) {
    uVar2 = param_3 >> 3;
    uVar3 = ~(uint)*(byte *)(param_1 + uVar2) & -1 << (param_3 & 7);
    while ((uVar3 & 0xff) == 0) {
      if (param_2 <= (uVar2 + 1) * 8) {
        return param_2;
      }
      uVar2 = uVar2 + 1 & 0xffff;
      uVar3 = ~(uint)*(byte *)(param_1 + uVar2);
    }
    iVar1 = __ctzsi2();
    uVar3 = uVar2 * 8 + iVar1;
    if (uVar3 < param_2) {
      param_2 = uVar3;
    }
    param_2 = param_2 & 0xffff;
  }
  return param_2;
}

