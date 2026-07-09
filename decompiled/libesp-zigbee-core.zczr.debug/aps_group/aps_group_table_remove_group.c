/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_remove_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_remove_group(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = group_table_find();
  if (iVar1 != 0) {
    aps_group_table_remove_stored_group();
    iVar2 = core_globals_get();
    uVar3 = *(undefined4 *)(iVar2 + 0x95c);
    iVar2 = core_globals_get();
    uVar4 = *(undefined4 *)(iVar2 + 0x960);
    iVar2 = core_globals_get();
    mempool_free_ent(uVar3,uVar4,0x22,*(undefined2 *)(iVar2 + 0x964),iVar1);
  }
  return;
}

