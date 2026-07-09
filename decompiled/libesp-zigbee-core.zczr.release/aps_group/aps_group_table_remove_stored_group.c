/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_remove_stored_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_remove_stored_group(short *param_1)

{
  short asStack_38 [17];
  short sStack_16;
  char cStack_14;
  
  sStack_16 = 0;
  cStack_14 = '\0';
  while( true ) {
    ds_group_info_itor_read(asStack_38);
    if (cStack_14 != '\0') {
      return;
    }
    if (asStack_38[0] == *param_1) break;
    sStack_16 = sStack_16 + 1;
  }
  ds_internal_remove_entry(5,asStack_38);
  return;
}

