/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_get_next_chunk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_get_next_chunk(ushort *param_1,int *param_2)

{
  int *extraout_a1;
  ushort uVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    *(undefined2 *)(param_2 + 2) = 0;
    return;
  }
  iVar2 = *(int *)*param_2;
  *param_2 = iVar2;
  if (iVar2 == 0) {
    param_1 = (ushort *)zmsg_get_next_chunk_part_0();
    param_2 = extraout_a1;
  }
  param_2[1] = iVar2 + 4;
  *(undefined2 *)(param_2 + 2) = 0xac;
  uVar1 = *param_1;
  if (0xac < uVar1) {
    uVar1 = 0xac;
  }
  *(ushort *)(param_2 + 2) = uVar1;
  *param_1 = *param_1 - uVar1;
  return;
}

