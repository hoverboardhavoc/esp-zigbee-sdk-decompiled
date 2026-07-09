/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_clear_weekly_schedule_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_clear_weekly_schedule_cmd_handler(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)thermostat_weekly_schedule_context_get(*(undefined1 *)(param_1 + 0x15));
  if (puVar1 != (undefined1 *)0x0) {
    thermostat_weekly_schedule_loop_stop(*puVar1);
    thermostat_weekly_schedule_graphs_free(puVar1 + 8,7);
  }
  zcl_packet_setup_default_response(param_2,param_1,0);
  return;
}

