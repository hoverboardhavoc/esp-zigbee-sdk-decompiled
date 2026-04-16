/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_graphs_copy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
thermostat_weekly_schedule_graphs_copy
          (weekly_schedule_graph_t **dst,weekly_schedule_graph_t **src,uint8_t count)

{
  weekly_schedule_graph_t **ppwVar1;
  uint uVar2;
  weekly_schedule_graph_t *pwVar3;
  ezb_zcl_thermostat_weekly_schedule_transition_t *peVar4;
  undefined3 in_register_00002031;
  weekly_schedule_graph_t **ppwVar5;
  
  if (((dst != (weekly_schedule_graph_t **)0x0) && (src != (weekly_schedule_graph_t **)0x0)) &&
     (CONCAT31(in_register_00002031,count) != 0)) {
    for (uVar2 = 0; uVar2 < CONCAT31(in_register_00002031,count); uVar2 = uVar2 + 1 & 0xff) {
      ppwVar5 = src + uVar2;
      if (*ppwVar5 == (weekly_schedule_graph_t *)0x0) {
        dst[uVar2] = (weekly_schedule_graph_t *)0x0;
      }
      else {
        ppwVar1 = dst + uVar2;
        pwVar3 = (weekly_schedule_graph_t *)calloc(1,8);
        *ppwVar1 = pwVar3;
        if (pwVar3 == (weekly_schedule_graph_t *)0x0) {
_L0:
          thermostat_weekly_schedule_graphs_free(dst,count);
          return 0x89;
        }
        peVar4 = (ezb_zcl_thermostat_weekly_schedule_transition_t *)
                 calloc((uint)(*ppwVar5)->num_of_transition,6);
        pwVar3->transitions = peVar4;
        if ((*ppwVar1)->transitions == (ezb_zcl_thermostat_weekly_schedule_transition_t *)0x0)
        goto _L0;
        (*ppwVar1)->num_of_transition = (*ppwVar5)->num_of_transition;
        (*ppwVar1)->mode_of_transition = (*ppwVar5)->mode_of_transition;
        if ((*ppwVar1)->transitions == (ezb_zcl_thermostat_weekly_schedule_transition_t *)0x0)
        goto _L0;
        memcpy((*ppwVar1)->transitions,(*ppwVar5)->transitions,
               (uint)(*ppwVar5)->num_of_transition * 6);
      }
    }
  }
  return '\0';
}

