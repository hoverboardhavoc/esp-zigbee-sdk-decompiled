/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_hold_off
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_hold_off(weekly_schedule_context_t *sched_ctx)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  
  if (sched_ctx != (weekly_schedule_context_t *)0x0) {
    pzVar1 = thermostat_srv_get_attr_desc(sched_ctx->ep_id,0x23);
    pzVar2 = thermostat_srv_get_attr_desc(sched_ctx->ep_id,0x24);
    if ((pzVar1 != (zcl_attr_desc_t *)0x0) && (pzVar2 != (zcl_attr_desc_t *)0x0)) {
      *(undefined1 *)pzVar1->data_p = 0;
      *(undefined1 *)pzVar2->data_p = 0;
      thermostat_weekly_schedule_loop_start(sched_ctx->ep_id);
    }
  }
  return;
}

