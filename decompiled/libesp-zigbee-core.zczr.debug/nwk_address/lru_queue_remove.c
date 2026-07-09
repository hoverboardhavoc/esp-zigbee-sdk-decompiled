/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> lru_queue_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void lru_queue_remove(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  param_2 = param_2 * 0x12;
  iVar1 = *(int *)(param_1 + 4) + param_2;
  uVar2 = (uint)*(ushort *)(iVar1 + 10);
  if (uVar2 != 0xffff) {
    *(undefined2 *)(*(int *)(param_1 + 4) + uVar2 * 0x12 + 0xc) = *(undefined2 *)(iVar1 + 0xc);
  }
  iVar1 = *(int *)(param_1 + 4) + param_2;
  uVar2 = (uint)*(ushort *)(iVar1 + 0xc);
  if (uVar2 != 0xffff) {
    *(undefined2 *)(*(int *)(param_1 + 4) + uVar2 * 0x12 + 10) = *(undefined2 *)(iVar1 + 10);
  }
  *(undefined2 *)(*(int *)(param_1 + 4) + param_2 + 10) = 0xffff;
  *(undefined2 *)(*(int *)(param_1 + 4) + param_2 + 0xc) = 0xffff;
  return;
}

