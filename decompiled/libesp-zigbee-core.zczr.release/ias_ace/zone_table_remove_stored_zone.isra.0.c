/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> zone_table_remove_stored_zone.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zone_table_remove_stored_zone_isra_0(uint param_1,uint param_2)

{
  byte bStack_34;
  byte bStack_33;
  short sStack_16;
  char cStack_14;
  
  sStack_16 = 0;
  cStack_14 = '\0';
  while( true ) {
    ds_ias_zone_info_itor_read(&bStack_34);
    if (cStack_14 != '\0') {
      return;
    }
    if ((bStack_34 == param_1) && (bStack_33 == param_2)) break;
    sStack_16 = sStack_16 + 1;
  }
  ds_internal_remove_entry(0xd,&bStack_34);
  return;
}

