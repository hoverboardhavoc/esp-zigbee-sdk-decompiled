/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> array_copy_u48_to_u64
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void array_copy_u48_to_u64(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar3 = 0;
  do {
    iVar4 = iVar3 * 6;
    puVar2 = (undefined4 *)(iVar3 * 8 + param_1);
    iVar3 = iVar3 + 1;
    puVar5 = (undefined4 *)(iVar4 + param_2);
    uVar1 = *puVar5;
    puVar2[1] = (uint)*(ushort *)(puVar5 + 1);
    *puVar2 = uVar1;
  } while (param_3 != iVar3);
  return;
}

