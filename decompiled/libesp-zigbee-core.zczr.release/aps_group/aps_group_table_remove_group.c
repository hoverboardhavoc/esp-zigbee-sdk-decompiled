/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_remove_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_remove_group(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar1 = group_table_find();
  if (uVar1 == 0) {
    return;
  }
  aps_group_table_remove_stored_group();
  iVar2 = core_globals_get();
  uVar4 = *(uint *)(iVar2 + 0x95c);
  iVar2 = core_globals_get();
  uVar5 = *(undefined4 *)(iVar2 + 0x960);
  iVar2 = core_globals_get();
  uVar3 = (uint)*(ushort *)(iVar2 + 0x964);
  if (uVar1 < uVar4) {
    uVar3 = mempool_free_ent_part_0();
  }
  uVar1 = (int)(uVar1 - uVar4) / 0x22 & 0xffff;
  if (uVar1 < uVar3) goto _L18;
  do {
    uVar1 = 0;
    uVar5 = __assert_func(0,0,0,0);
_L18:
    iVar2 = test_and_clr_bitmap(uVar1,uVar5);
  } while (iVar2 == 0);
  return;
}

