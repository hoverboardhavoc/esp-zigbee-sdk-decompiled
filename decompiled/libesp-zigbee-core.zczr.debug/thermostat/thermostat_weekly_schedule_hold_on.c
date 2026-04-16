/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_hold_on
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_hold_on(weekly_schedule_context_t *sched_ctx)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  uint uVar3;
  
  if (sched_ctx != (weekly_schedule_context_t *)0x0) {
    pzVar1 = thermostat_srv_get_attr_desc(sched_ctx->ep_id,0x23);
    pzVar2 = thermostat_srv_get_attr_desc(sched_ctx->ep_id,0x24);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if ((((pzVar1 != (zcl_attr_desc_t *)0x0) && (pzVar2 != (zcl_attr_desc_t *)0x0)) &&
        (uVar3 = (uint)*pzVar2->data_p, *pzVar1->data_p == '\x01')) &&
       ((uVar3 != 0 && (uVar3 < 0x5a1)))) {
      thermostat_weekly_schedule_loop_stop(sched_ctx->ep_id);
      thermostat_weekly_schedule_hold(sched_ctx->ep_id,false,uVar3 * 60000);
    }
  }
  return;
}

