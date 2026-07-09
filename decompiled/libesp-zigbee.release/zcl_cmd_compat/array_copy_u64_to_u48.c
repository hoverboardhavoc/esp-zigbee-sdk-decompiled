/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> array_copy_u64_to_u48
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void array_copy_u64_to_u48(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar2 = 0;
  do {
    puVar4 = (undefined4 *)(iVar2 * 8 + param_2);
    uVar3 = *puVar4;
    uVar1 = *(undefined2 *)(puVar4 + 1);
    iVar5 = iVar2 * 6;
    iVar2 = iVar2 + 1;
    puVar6 = (undefined1 *)(iVar5 + param_1);
    *puVar6 = (char)uVar3;
    puVar6[1] = (char)((uint)uVar3 >> 8);
    puVar6[4] = (char)uVar1;
    puVar6[2] = (char)((uint)uVar3 >> 0x10);
    puVar6[3] = (char)((uint)uVar3 >> 0x18);
    puVar6[5] = (char)((ushort)uVar1 >> 8);
  } while (param_3 != iVar2);
  return;
}

