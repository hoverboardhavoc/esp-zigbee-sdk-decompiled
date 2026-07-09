/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_graph_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * thermostat_weekly_schedule_graph_create(size_t param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  void *pvVar2;
  
  puVar1 = (undefined1 *)calloc(1,8);
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[1] = (char)param_1;
    *puVar1 = param_2;
    pvVar2 = calloc(param_1,6);
    *(void **)(puVar1 + 4) = pvVar2;
  }
  return puVar1;
}

