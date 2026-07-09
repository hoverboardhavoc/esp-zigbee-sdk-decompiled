/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_graphs_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_weekly_schedule_graphs_free(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = param_1 + param_2;
  do {
    if (*param_1 != 0) {
      mm_free(*(undefined4 *)(*param_1 + 4));
      mm_free(*param_1);
      *param_1 = 0;
    }
    param_1 = param_1 + 1;
  } while (param_1 != piVar1);
  return;
}

