/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> lru_queue_insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void lru_queue_insert(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_3 * 0x12;
  *(short *)(*(int *)(param_1 + 4) + iVar2 + 10) = (short)param_2;
  *(undefined2 *)(*(int *)(param_1 + 4) + iVar2 + 0xc) =
       *(undefined2 *)(param_2 * 0x12 + *(int *)(param_1 + 4) + 0xc);
  uVar1 = (uint)*(ushort *)(*(int *)(param_1 + 4) + iVar2 + 10);
  if (uVar1 != 0xffff) {
    *(short *)(*(int *)(param_1 + 4) + uVar1 * 0x12 + 0xc) = (short)param_3;
  }
  uVar1 = (uint)*(ushort *)(iVar2 + *(int *)(param_1 + 4) + 0xc);
  if (uVar1 != 0xffff) {
    *(short *)(*(int *)(param_1 + 4) + uVar1 * 0x12 + 10) = (short)param_3;
  }
  return;
}

