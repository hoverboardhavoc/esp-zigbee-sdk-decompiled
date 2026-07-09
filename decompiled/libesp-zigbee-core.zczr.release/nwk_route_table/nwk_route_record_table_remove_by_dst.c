/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_record_table_remove_by_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_record_table_remove_by_dst(void)

{
  undefined4 unaff_retaddr;
  undefined4 unaff_s0;
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_10 [4];
  
  uVar2 = nwk_route_record_table_find();
  if (uVar2 == 0) {
    return;
  }
  iVar3 = core_globals_get();
  uVar1 = *(uint *)(iVar3 + 0xc70);
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0xc74);
  iVar3 = core_globals_get();
  uVar5 = (uint)*(ushort *)(iVar3 + 0xc78);
  iVar3 = 0x1c;
  if (uVar2 < uVar1) {
    register0x00002008 = (BADSPACEBASE *)auStack_10;
    unaff_retaddr = 0x10180;
    iVar4 = mempool_free_ent_part_0();
  }
  uVar2 = (int)(uVar2 - uVar1) / iVar3 & 0xffff;
  *(undefined4 *)((int)register0x00002008 + -4) = unaff_retaddr;
  *(undefined4 *)((int)register0x00002008 + -8) = unaff_s0;
  if (uVar2 < uVar5) goto _L0;
  do {
    iVar4 = mempool_free_ent_part_0();
_L0:
    uVar1 = 1 << (uVar2 & 7) & 0xff;
    uVar5 = uVar2 >> 3;
    uVar2 = 5;
    uVar5 = __atomic_fetch_and_1(iVar4 + uVar5,~uVar1 & 0xff);
  } while ((uVar1 & uVar5) == 0);
  return;
}

