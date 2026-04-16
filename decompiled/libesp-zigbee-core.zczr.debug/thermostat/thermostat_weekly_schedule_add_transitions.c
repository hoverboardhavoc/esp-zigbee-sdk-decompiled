/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_add_transitions
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
thermostat_weekly_schedule_add_transitions
          (uint8_t ep_id,ezb_zcl_thermostat_set_weekly_schedule_payload_t *payload)

{
  short sVar1;
  uint uVar2;
  ezb_zcl_status_t eVar3;
  _Bool _Var4;
  weekly_schedule_context_t *pwVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint uVar6;
  weekly_schedule_graph_t *pwVar7;
  int iVar8;
  weekly_schedule_graph_t **src;
  uint uVar9;
  uint uVar10;
  int16_t local_50;
  int16_t iStack_4e;
  int16_t min_value;
  int16_t max_value;
  weekly_schedule_graph_t *dump_graph [7];
  
  _min_value = (weekly_schedule_graph_t *)0x0;
  dump_graph[0] = (weekly_schedule_graph_t *)0x0;
  dump_graph[1] = (weekly_schedule_graph_t *)0x0;
  dump_graph[2] = (weekly_schedule_graph_t *)0x0;
  dump_graph[3] = (weekly_schedule_graph_t *)0x0;
  dump_graph[4] = (weekly_schedule_graph_t *)0x0;
  dump_graph[5] = (weekly_schedule_graph_t *)0x0;
  pwVar5 = thermostat_weekly_schedule_context_get(ep_id);
  src = pwVar5->graph;
  eVar3 = thermostat_weekly_schedule_graphs_copy((weekly_schedule_graph_t **)&min_value,src,'\a');
  iVar8 = CONCAT31(extraout_var,eVar3);
  if (iVar8 == 0) {
    for (uVar2 = 0; uVar6 = (uint)payload->num_of_trans, uVar2 < uVar6; uVar2 = uVar2 + 1 & 0xff) {
      if ((payload->mode_for_req & 1) != 0) {
        local_50 = 0;
        iStack_4e = 0;
        sVar1 = payload->transitions[uVar2].heat_setpoint;
        thermostat_get_heat_setpoint_limit(ep_id,&local_50,&iStack_4e);
        if ((sVar1 < local_50) || (iStack_4e < sVar1)) {
          iVar8 = 0x87;
          goto _L0;
        }
      }
      if ((payload->mode_for_req & 2) != 0) {
        local_50 = 0;
        iStack_4e = 0;
        sVar1 = payload->transitions[uVar2].cool_setpoint;
        thermostat_get_cool_setpoint_limit(ep_id,&local_50,&iStack_4e);
        if (((sVar1 < local_50) || (iStack_4e < sVar1)) ||
           (payload->transitions[uVar2].cool_setpoint != sVar1)) {
          iVar8 = 0x87;
          goto _L0;
        }
      }
    }
    uVar9 = 0;
    uVar10 = 0;
    for (uVar2 = 0;
        (uVar2 < 7 && (pwVar7 = pwVar5->graph[uVar2], pwVar7 != (weekly_schedule_graph_t *)0x0));
        uVar2 = uVar2 + 1 & 0xff) {
      _Var4 = thermostat_weekly_schedule_day_is_set(payload->day_of_week,(uint8_t)uVar2);
      if (CONCAT31(extraout_var_00,_Var4) != 0) {
        uVar10 = pwVar7->num_of_transition + uVar10 & 0xff;
        uVar9 = uVar9 + 1 & 0xff;
      }
    }
    if (pwVar5->daily_limit < uVar6) {
      iVar8 = 0x89;
    }
    else {
      if (uVar10 + uVar9 * uVar6 <= (uint)pwVar5->weekly_limit) {
        for (uVar2 = 0; uVar2 < 7; uVar2 = uVar2 + 1 & 0xff) {
          _Var4 = thermostat_weekly_schedule_day_is_set(payload->day_of_week,(uint8_t)uVar2);
          if (CONCAT31(extraout_var_01,_Var4) != 0) {
            thermostat_weekly_schedule_graphs_free(pwVar5->graph + uVar2,'\x01');
            pwVar7 = thermostat_weekly_schedule_graph_create
                               (payload->num_of_trans,payload->mode_for_req);
            pwVar5->graph[uVar2] = pwVar7;
            if (pwVar7 == (weekly_schedule_graph_t *)0x0) {
              iVar8 = 0x89;
              goto _L0;
            }
            memcpy(pwVar7->transitions,payload->transitions,(uint)payload->num_of_trans * 6);
            weekly_schedule_transitions_sort
                      (pwVar5->graph[uVar2]->transitions,pwVar5->graph[uVar2]->num_of_transition);
            _Var4 = thermostat_weekly_schedule_graph_is_overlapping(pwVar5->graph[uVar2]);
            if (CONCAT31(extraout_var_02,_Var4) != 0) {
              iVar8 = 1;
              goto _L0;
            }
          }
        }
        goto _L0;
      }
      iVar8 = 0x89;
    }
  }
_L0:
  thermostat_weekly_schedule_graphs_free(src,'\a');
  thermostat_weekly_schedule_graphs_copy(src,(weekly_schedule_graph_t **)&min_value,'\a');
_L0:
  thermostat_weekly_schedule_graphs_free((weekly_schedule_graph_t **)&min_value,'\a');
  return (ezb_zcl_status_t)iVar8;
}

