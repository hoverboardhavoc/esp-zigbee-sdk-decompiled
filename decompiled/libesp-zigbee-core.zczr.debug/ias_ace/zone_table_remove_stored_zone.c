/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_remove_stored_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zone_table_remove_stored_zone(uint param_1,uint param_2)

{
  undefined4 uVar1;
  byte bStack_34;
  byte bStack_33;
  undefined2 uStack_16;
  char cStack_14;
  
  uStack_16 = 0;
  cStack_14 = '\0';
  ds_ias_zone_info_itor_read(&bStack_34);
  while( true ) {
    if (cStack_14 != '\0') {
      return 5;
    }
    if ((bStack_34 == param_1) && (bStack_33 == param_2)) break;
    ds_ias_zone_info_next(&bStack_34);
  }
  uVar1 = ds_ias_zone_info_delete(&bStack_34);
  return uVar1;
}

