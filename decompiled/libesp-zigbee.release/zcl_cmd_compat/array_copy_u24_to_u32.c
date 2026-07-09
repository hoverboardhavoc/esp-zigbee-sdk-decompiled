/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> array_copy_u24_to_u32
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void array_copy_u24_to_u32(int param_1,uint3 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    *(uint *)(iVar1 * 4 + param_1) = (uint)*param_2;
    iVar1 = iVar1 + 1;
    param_2 = (uint3 *)((int)param_2 + 3);
  } while (param_3 != iVar1);
  return;
}

