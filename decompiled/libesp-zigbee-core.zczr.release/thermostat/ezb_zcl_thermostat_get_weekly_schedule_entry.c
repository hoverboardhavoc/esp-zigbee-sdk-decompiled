/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> ezb_zcl_thermostat_get_weekly_schedule_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_thermostat_get_weekly_schedule_entry(uint param_1)

{
  int iVar1;
  
  iVar1 = thermostat_weekly_schedule_context_get();
  if (iVar1 != 0) {
    if (param_1 < 7) {
      iVar1 = *(int *)(iVar1 + param_1 * 4 + 8);
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

