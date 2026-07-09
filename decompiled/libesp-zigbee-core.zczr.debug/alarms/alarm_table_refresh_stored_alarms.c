/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_refresh_stored_alarms
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarm_table_refresh_stored_alarms(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  alarm_table_remove_stored_all();
  iVar2 = get_alarm_table(param_1);
  if ((iVar2 != 0) && (puVar1 = *(undefined4 **)(iVar2 + 4), puVar1 != (undefined4 *)0x0)) {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      alarm_table_store_entry(param_1,puVar1);
    }
  }
  return;
}

