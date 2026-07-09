/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_remove_by_next_hop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_table_remove_by_next_hop(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar1 = core_globals_get();
  uVar4 = 0;
  while (uVar4 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar1 + 0xc5c),*(undefined2 *)(iVar1 + 0xc60),uVar4),
        uVar4 < *(ushort *)(iVar1 + 0xc60)) {
    iVar5 = *(int *)(iVar1 + 0xc58) + uVar4 * 0x10;
    if (*(ushort *)(iVar5 + 2) == param_1) {
      if (*(char *)(iVar5 + 0xc) == '\0') {
        iVar2 = core_globals_get();
        uVar6 = *(undefined4 *)(iVar2 + 0xc58);
        iVar2 = core_globals_get();
        uVar3 = *(undefined4 *)(iVar2 + 0xc5c);
        iVar2 = core_globals_get();
        mempool_free_ent(uVar6,uVar3,0x10,*(undefined2 *)(iVar2 + 0xc60),iVar5);
      }
      else {
        *(ushort *)(iVar5 + 0xe) = *(ushort *)(iVar5 + 0xe) & 0xfff8 | 1;
      }
    }
    uVar4 = uVar4 + 1 & 0xffff;
  }
  return;
}

