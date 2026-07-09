/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_graphs_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_weekly_schedule_graphs_free(int param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    piVar2 = (int *)(uVar1 * 4 + param_1);
    if (*piVar2 != 0) {
      mm_free(*(undefined4 *)(*piVar2 + 4));
      mm_free(*piVar2);
      *piVar2 = 0;
    }
  }
  return;
}

