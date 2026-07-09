/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> array_copy_u64_to_u48
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void array_copy_u64_to_u48(int param_1,int param_2,uint param_3)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    puVar4 = (undefined4 *)(uVar2 * 8 + param_2);
    uVar3 = *puVar4;
    uVar1 = *(undefined2 *)(puVar4 + 1);
    puVar5 = (undefined1 *)(uVar2 * 6 + param_1);
    *puVar5 = (char)uVar3;
    puVar5[1] = (char)((uint)uVar3 >> 8);
    puVar5[2] = (char)((uint)uVar3 >> 0x10);
    puVar5[3] = (char)((uint)uVar3 >> 0x18);
    puVar5[4] = (char)uVar1;
    puVar5[5] = (char)((ushort)uVar1 >> 8);
  }
  return;
}

