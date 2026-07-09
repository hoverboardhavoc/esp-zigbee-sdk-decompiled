/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> route_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int route_table_new(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = *param_1;
  uVar1 = *(ushort *)(param_1 + 2);
  uVar4 = mempool_alloc_idx(param_1[1],(uint)uVar1);
  if (uVar4 < uVar1) {
    iVar2 = iVar2 + uVar4 * 0x10;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    uVar4 = 0;
    while (uVar4 = bitmap_find_next_bit(param_1[1],(short)param_1[2],uVar4),
          uVar4 < *(ushort *)(param_1 + 2)) {
      iVar5 = *param_1 + uVar4 * 0x10;
      iVar3 = iVar2;
      if (*(char *)(iVar5 + 0xc) == '\0') {
        if ((*(uint *)(iVar5 + 0xc) & 0x500000) == 0x500000) {
          return iVar5;
        }
        iVar3 = iVar5;
        if (iVar2 != 0) {
          if (((*(byte *)(iVar2 + 10) <= *(byte *)(iVar5 + 10)) &&
              (iVar3 = iVar2, *(byte *)(iVar5 + 10) == *(byte *)(iVar2 + 10))) &&
             (*(uint *)(iVar5 + 4) < *(uint *)(iVar2 + 4))) {
            iVar3 = iVar5;
          }
        }
      }
      uVar4 = uVar4 + 1 & 0xffff;
      iVar2 = iVar3;
    }
  }
  return iVar2;
}

