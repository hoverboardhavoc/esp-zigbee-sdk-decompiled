/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_loop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000107c2) */
/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_loop(weekly_schedule_context_t *sched_ctx)

{
  int16_t heat;
  int16_t cool;
  ezb_zcl_status_t eVar1;
  weekly_schedule_context_t *pwVar2;
  zcl_attr_desc_t *pzVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  uint8_t mode;
  int iVar6;
  weekly_schedule_graph_t *pwVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ezb_zcl_thermostat_weekly_schedule_transition_t *peVar12;
  uint uVar13;
  
  if (sched_ctx == (weekly_schedule_context_t *)0x0) {
    return;
  }
  pzVar3 = thermostat_srv_get_attr_desc(sched_ctx->ep_id,0x23);
                    /* WARNING: Load size is inaccurate */
  if ((pzVar3 != (zcl_attr_desc_t *)0x0) && (*pzVar3->data_p != '\0')) {
    pwVar2 = thermostat_weekly_schedule_context_get(sched_ctx->ep_id);
    if (pwVar2 != (weekly_schedule_context_t *)0x0) {
      milli_timer_stop();
      milli_timer_init(thermostat_weekly_schedule_hold_on,pwVar2);
      milli_timer_start(&pwVar2->hold_timer,0);
      return;
    }
    return;
  }
  if ((((sched_ctx->exec_daily != 0xff) && (uVar9 = (uint)sched_ctx->exec_point, uVar9 != 0xff)) &&
      (pwVar7 = sched_ctx->graph[sched_ctx->exec_daily], pwVar7 != (weekly_schedule_graph_t *)0x0))
     && (peVar12 = pwVar7->transitions,
        peVar12 != (ezb_zcl_thermostat_weekly_schedule_transition_t *)0x0)) {
    mode = pwVar7->mode_of_transition + 0xff;
    heat = peVar12[uVar9].heat_setpoint;
    cool = peVar12[uVar9].cool_setpoint;
    eVar1 = zcl_message_thermostat_setpoint(sched_ctx->ep_id,mode,heat,cool);
    if (CONCAT31(extraout_var,eVar1) == 0) {
      thermostat_set_heat_cool_value(sched_ctx->ep_id,mode,heat,cool);
    }
  }
  iVar4 = milli_timer_get_now();
  uVar9 = zcl_time_get_utc_time(sched_ctx->ep_id);
  if (uVar9 == 0xffffffff) {
    uVar9 = milli_timer_get_now();
    uVar9 = uVar9 / 1000;
  }
  uVar8 = (uVar9 / 0x15180 + 4) % 7;
  uVar9 = uVar9 % 0x93a80 + 0x54600;
  pwVar7 = sched_ctx->graph[uVar8];
  uVar13 = (uVar8 + 1) * 0x15180;
  if ((pwVar7 != (weekly_schedule_graph_t *)0x0) && (pwVar7->num_of_transition != '\0')) {
    uVar10 = (uint)sched_ctx->exec_point;
    do {
      uVar11 = uVar10 + 1;
      uVar10 = uVar11 & 0xff;
      uVar5 = (uint)pwVar7->transitions[uVar10].start_time * 0x3c + uVar8 * 0x15180;
    } while (uVar5 < uVar9);
    sched_ctx->exec_daily = (uint8_t)uVar8;
    sched_ctx->exec_point = (uint8_t)uVar11;
    iVar6 = uVar5 - uVar9;
    if (uVar13 != uVar5) goto _L0;
  }
  iVar6 = uVar13 - uVar9;
  sched_ctx->exec_daily = 0xff;
  sched_ctx->exec_point = 0xff;
_L0:
  milli_timer_fire_at(&sched_ctx->loop_timer,iVar6 * 1000 + iVar4);
  return;
}

