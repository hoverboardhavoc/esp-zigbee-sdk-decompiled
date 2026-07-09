/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> addr_table_lru_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void addr_table_lru_add(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar5 = param_2 * 0x12 + iVar3;
  if ((*(short *)(iVar5 + 10) == -1) || (*(short *)(iVar5 + 0xc) == -1)) {
    uVar2 = (undefined2)param_2;
    if ((uint)*(ushort *)(param_1 + 10) < (uint)*(ushort *)(param_1 + 8)) {
      uVar1 = *(ushort *)((uint)*(ushort *)(param_1 + 10) * 0x12 + iVar3 + 10);
      *(ushort *)(iVar5 + 10) = uVar1;
      iVar4 = (uint)uVar1 * 0x12 + iVar3;
      *(undefined2 *)(iVar5 + 0xc) = *(undefined2 *)(iVar4 + 0xc);
      if (uVar1 != 0xffff) {
        *(undefined2 *)(iVar4 + 0xc) = uVar2;
      }
      if (*(ushort *)(iVar5 + 0xc) != 0xffff) {
        *(undefined2 *)(iVar3 + (uint)*(ushort *)(iVar5 + 0xc) * 0x12 + 10) = uVar2;
      }
    }
    else {
      *(undefined2 *)(iVar5 + 10) = uVar2;
      *(undefined2 *)(iVar5 + 0xc) = uVar2;
    }
    *(undefined2 *)(param_1 + 10) = uVar2;
  }
  return;
}

