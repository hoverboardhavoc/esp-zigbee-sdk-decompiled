/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_refresh_stored_groups
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_refresh_stored_groups(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = ds_internal_remove_entry(5,0xffffffff,0);
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    uVar3 = 0;
    while ((uVar3 = bitmap_find_next_bit
                              (*(undefined4 *)(iVar1 + 0x960),*(undefined2 *)(iVar1 + 0x964),uVar3),
           uVar3 < *(ushort *)(iVar1 + 0x964) &&
           (iVar2 = aps_group_table_store_group(*(int *)(iVar1 + 0x95c) + uVar3 * 0x22), iVar2 == 0)
           )) {
      uVar3 = uVar3 + 1 & 0xffff;
    }
  }
  return;
}

