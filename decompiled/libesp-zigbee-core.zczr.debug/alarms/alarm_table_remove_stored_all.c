/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_remove_stored_all
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarm_table_remove_stored_all(uint param_1)

{
  undefined1 auStack_1c [7];
  byte bStack_15;
  undefined2 uStack_14;
  char cStack_12;
  
  uStack_14 = 0;
  cStack_12 = '\0';
  ds_alarm_log_itor_read(auStack_1c);
  while (cStack_12 == '\0') {
    if (bStack_15 == param_1) {
      ds_alarm_log_delete(auStack_1c);
      ds_alarm_log_itor_read(auStack_1c);
    }
    else {
      ds_alarm_log_next(auStack_1c);
    }
  }
  return;
}

