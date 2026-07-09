/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_remove_stored_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_remove_stored_child(undefined4 param_1)

{
  int local_30;
  int iStack_2c;
  undefined1 auStack_28 [4];
  int iStack_24;
  int iStack_20;
  short sStack_14;
  char cStack_12;
  
  sStack_14 = 0;
  cStack_12 = '\0';
  do {
    ds_child_info_itor_read(auStack_28);
    do {
      if (cStack_12 != '\0') {
        return;
      }
      nwk_neighbor_get_extaddr(param_1,&local_30);
      if ((local_30 == iStack_24) && (iStack_2c == iStack_20)) {
        if (cStack_12 != '\0') {
          return;
        }
        ds_internal_remove_entry(4,sStack_14,auStack_28);
        return;
      }
    } while (cStack_12 != '\0');
    sStack_14 = sStack_14 + 1;
  } while( true );
}

