/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> array_copy_u32_to_u24
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void array_copy_u32_to_u24(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    uVar2 = *(uint *)(uVar1 * 4 + param_2) & 0xffffff;
    puVar3 = (undefined1 *)(uVar1 * 3 + param_1);
    *puVar3 = (char)uVar2;
    puVar3[1] = (char)(uVar2 >> 8);
    puVar3[2] = (char)(uVar2 >> 0x10);
  }
  return;
}

