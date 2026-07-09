/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_refresh_stored_children
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nbt_refresh_stored_children(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ds_internal_remove_entry(4,0xffffffff,0);
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      iVar1 = nwk_child_table_next(iVar1);
      if (iVar1 == 0) {
        return;
      }
      iVar2 = nwk_neighbor_table_store_child(iVar1);
    } while (iVar2 == 0);
  }
  return;
}

