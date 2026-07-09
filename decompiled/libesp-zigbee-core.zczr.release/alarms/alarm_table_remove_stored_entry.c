/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_remove_stored_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarm_table_remove_stored_entry(uint param_1,uint param_2,uint param_3,int param_4)

{
  int iStack_2c;
  ushort uStack_28;
  byte bStack_26;
  byte bStack_25;
  short sStack_24;
  char cStack_22;
  
  sStack_24 = 0;
  cStack_22 = '\0';
  while( true ) {
    ds_alarm_log_itor_read(&iStack_2c);
    if (cStack_22 != '\0') {
      return;
    }
    if ((((bStack_25 == param_1) && (bStack_26 == param_2)) && (uStack_28 == param_3)) &&
       (iStack_2c == param_4)) break;
    sStack_24 = sStack_24 + 1;
  }
  ds_internal_remove_entry(0xc,&iStack_2c);
  return;
}

