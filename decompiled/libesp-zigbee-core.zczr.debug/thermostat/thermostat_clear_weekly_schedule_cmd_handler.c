/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_clear_weekly_schedule_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
thermostat_clear_weekly_schedule_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  weekly_schedule_context_t *pwVar2;
  
  pwVar2 = thermostat_weekly_schedule_context_get((packet->header).dst_ep);
  if (pwVar2 != (weekly_schedule_context_t *)0x0) {
    thermostat_weekly_schedule_loop_stop(pwVar2->ep_id);
    thermostat_weekly_schedule_graphs_free(pwVar2->graph,'\a');
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,0);
  return eVar1;
}

