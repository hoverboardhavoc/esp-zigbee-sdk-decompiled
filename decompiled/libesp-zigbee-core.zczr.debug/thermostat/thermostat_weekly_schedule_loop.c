/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_loop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_loop(weekly_schedule_context_t *sched_ctx)

{
  int16_t heat;
  int16_t cool;
  int iVar1;
  uint8_t mode;
  _Bool _Var2;
  ezb_zcl_status_t eVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  uint32_t uVar5;
  ezb_zcl_thermostat_weekly_schedule_transition_t *peVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  weekly_schedule_graph_t *pwVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  
  if (sched_ctx != (weekly_schedule_context_t *)0x0) {
    _Var2 = thermostat_weekly_schedule_is_holden(sched_ctx->ep_id);
    if (CONCAT31(extraout_var,_Var2) == 0) {
      if ((((sched_ctx->exec_daily != 0xff) && (uVar7 = (uint)sched_ctx->exec_point, uVar7 != 0xff))
          && (pwVar10 = sched_ctx->graph[sched_ctx->exec_daily],
             pwVar10 != (weekly_schedule_graph_t *)0x0)) &&
         (peVar6 = pwVar10->transitions,
         peVar6 != (ezb_zcl_thermostat_weekly_schedule_transition_t *)0x0)) {
        mode = pwVar10->mode_of_transition + 0xff;
        heat = peVar6[uVar7].heat_setpoint;
        cool = peVar6[uVar7].cool_setpoint;
        eVar3 = zcl_message_thermostat_setpoint(sched_ctx->ep_id,mode,heat,cool);
        if (CONCAT31(extraout_var_00,eVar3) == 0) {
          thermostat_set_heat_cool_value(sched_ctx->ep_id,mode,heat,cool);
        }
      }
      iVar4 = milli_timer_get_now();
      uVar5 = thermostat_weekly_schedule_get_utc_time(sched_ctx->ep_id);
      uVar7 = (uVar5 / 0x15180 + 4) % 7;
      uVar13 = uVar5 % 0x93a80 + 0x54600;
      iVar1 = (uVar7 + 1) * 0x15180 - uVar13;
      pwVar10 = sched_ctx->graph[uVar7];
      uVar8 = (uint)sched_ctx->exec_point;
      do {
        uVar9 = uVar8 + 1;
        uVar8 = uVar9 & 0xff;
        iVar12 = iVar1;
        if ((pwVar10 == (weekly_schedule_graph_t *)0x0) || (pwVar10->num_of_transition == '\0'))
        goto _L0;
        uVar11 = uVar7 * 0x15180 + (uint)pwVar10->transitions[uVar8].start_time * 0x3c;
      } while (uVar11 < uVar13);
      sched_ctx->exec_daily = (uint8_t)uVar7;
      sched_ctx->exec_point = (uint8_t)uVar9;
      iVar12 = uVar11 - uVar13;
_L0:
      if (iVar12 == iVar1) {
        sched_ctx->exec_daily = 0xff;
        sched_ctx->exec_point = 0xff;
      }
      milli_timer_fire_at(&sched_ctx->loop_timer,iVar12 * 1000 + iVar4);
    }
    else {
      thermostat_weekly_schedule_hold(sched_ctx->ep_id,true,0);
    }
  }
  return;
}

