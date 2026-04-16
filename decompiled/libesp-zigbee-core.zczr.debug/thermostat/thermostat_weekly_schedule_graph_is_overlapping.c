/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_graph_is_overlapping
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool thermostat_weekly_schedule_graph_is_overlapping(weekly_schedule_graph_t *graph)

{
  ezb_zcl_thermostat_weekly_schedule_transition_t *peVar1;
  uint uVar2;
  uint uVar3;
  ezb_zcl_thermostat_weekly_schedule_transition_t *peVar4;
  
  if (graph == (weekly_schedule_graph_t *)0x0) {
    return false;
  }
  uVar2 = 1;
  uVar3 = 0;
  while( true ) {
    if (graph->num_of_transition <= uVar3) {
      return false;
    }
    if (graph->num_of_transition <= uVar2) break;
    peVar4 = graph->transitions + uVar3;
    peVar1 = graph->transitions + uVar2;
    if (((peVar4->start_time == peVar1->start_time) &&
        (peVar4->heat_setpoint == peVar1->heat_setpoint)) &&
       (peVar4->cool_setpoint == peVar1->cool_setpoint)) {
      return true;
    }
    uVar3 = uVar3 + 1 & 0xff;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return false;
}

