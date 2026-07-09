/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> addr_table_lru_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void addr_table_lru_remove(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = (uint)*(ushort *)(param_1 + 10);
  if (uVar2 == param_2) {
    uVar1 = *(ushort *)(*(int *)(param_1 + 4) + param_2 * 0x12 + 0xc);
    uVar2 = (uint)uVar1;
    *(ushort *)(param_1 + 10) = uVar1;
  }
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = param_2 * 0x12 + iVar3;
  uVar1 = *(ushort *)(iVar4 + 10);
  if (uVar1 != 0xffff) {
    *(undefined2 *)((uint)uVar1 * 0x12 + iVar3 + 0xc) = *(undefined2 *)(iVar4 + 0xc);
  }
  if (*(ushort *)(iVar4 + 0xc) != 0xffff) {
    *(ushort *)(iVar3 + (uint)*(ushort *)(iVar4 + 0xc) * 0x12 + 10) = uVar1;
  }
  *(undefined2 *)(iVar4 + 10) = 0xffff;
  *(undefined2 *)(iVar4 + 0xc) = 0xffff;
  if (param_2 == uVar2) {
    *(undefined2 *)(param_1 + 10) = 0xffff;
  }
  return;
}

