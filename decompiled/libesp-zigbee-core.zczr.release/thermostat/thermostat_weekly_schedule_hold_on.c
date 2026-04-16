/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_hold_on
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010798) */
/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_hold_on(weekly_schedule_context_t *sched_ctx)

{
  ushort uVar1;
  weekly_schedule_context_t *pwVar2;
  zcl_attr_desc_t *pzVar3;
  zcl_attr_desc_t *pzVar4;
  
  if (sched_ctx == (weekly_schedule_context_t *)0x0) {
    return;
  }
  pzVar3 = thermostat_srv_get_attr_desc(sched_ctx->ep_id,0x23);
  pzVar4 = thermostat_srv_get_attr_desc(sched_ctx->ep_id,0x24);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  if ((((pzVar3 != (zcl_attr_desc_t *)0x0) && (pzVar4 != (zcl_attr_desc_t *)0x0)) &&
      (*pzVar3->data_p == '\x01')) && (uVar1 = *pzVar4->data_p, (uVar1 - 1 & 0xffff) < 0x5a0)) {
    thermostat_weekly_schedule_loop_stop(sched_ctx->ep_id);
    pwVar2 = thermostat_weekly_schedule_context_get(sched_ctx->ep_id);
    if (pwVar2 != (weekly_schedule_context_t *)0x0) {
      milli_timer_stop();
      milli_timer_init(thermostat_weekly_schedule_hold_off,pwVar2);
      milli_timer_start(&pwVar2->hold_timer,(uint)uVar1 * 60000);
      return;
    }
    return;
  }
  return;
}

