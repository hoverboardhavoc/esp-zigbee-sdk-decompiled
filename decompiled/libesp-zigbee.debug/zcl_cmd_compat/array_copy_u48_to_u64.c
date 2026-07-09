/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> array_copy_u48_to_u64
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void array_copy_u48_to_u64(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    puVar3 = (undefined4 *)(uVar2 * 6 + param_2);
    uVar1 = *(ushort *)(puVar3 + 1);
    puVar4 = (undefined4 *)(uVar2 * 8 + param_1);
    *puVar4 = *puVar3;
    puVar4[1] = (uint)uVar1;
  }
  return;
}

