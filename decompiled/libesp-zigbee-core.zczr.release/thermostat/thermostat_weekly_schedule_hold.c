/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_hold
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_weekly_schedule_hold(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = thermostat_weekly_schedule_context_get();
  if (iVar1 != 0) {
    milli_timer_stop();
    if (param_1 == 0) {
      pcVar2 = thermostat_weekly_schedule_hold_off;
    }
    else {
      pcVar2 = thermostat_weekly_schedule_hold_on;
    }
    milli_timer_init(pcVar2,iVar1);
    milli_timer_start(iVar1 + 0x24,param_2);
    return;
  }
  return;
}

