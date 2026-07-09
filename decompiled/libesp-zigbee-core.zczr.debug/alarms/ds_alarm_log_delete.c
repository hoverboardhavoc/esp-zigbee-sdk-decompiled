/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> ds_alarm_log_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ds_alarm_log_delete(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 10) == '\0') {
    uVar1 = ds_internal_remove_entry(0xc,*(undefined2 *)(param_1 + 8),param_1);
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}

