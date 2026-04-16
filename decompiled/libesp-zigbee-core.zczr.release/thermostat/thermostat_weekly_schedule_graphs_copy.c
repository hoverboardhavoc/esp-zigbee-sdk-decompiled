/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_graphs_copy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ezb_zcl_status_t
thermostat_weekly_schedule_graphs_copy
          (weekly_schedule_graph_t **dst,weekly_schedule_graph_t **src,uint8_t count)

{
  byte bVar1;
  weekly_schedule_graph_t *pwVar2;
  ezb_zcl_thermostat_weekly_schedule_transition_t *__dest;
  weekly_schedule_graph_t **ppwVar3;
  weekly_schedule_graph_t *pwVar4;
  weekly_schedule_graph_t **ppwVar5;
  
  ppwVar5 = src + 7;
  ppwVar3 = dst;
  do {
    if (*src == (weekly_schedule_graph_t *)0x0) {
      *ppwVar3 = (weekly_schedule_graph_t *)0x0;
    }
    else {
      pwVar2 = (weekly_schedule_graph_t *)calloc(1,8);
      *ppwVar3 = pwVar2;
      if (pwVar2 == (weekly_schedule_graph_t *)0x0) {
_L0:
        thermostat_weekly_schedule_graphs_free(dst,'\a');
        return 0x89;
      }
      pwVar4 = *src;
      bVar1 = pwVar4->num_of_transition;
      __dest = (ezb_zcl_thermostat_weekly_schedule_transition_t *)calloc((uint)bVar1,6);
      pwVar2->transitions = __dest;
      if (__dest == (ezb_zcl_thermostat_weekly_schedule_transition_t *)0x0) goto _L0;
      pwVar2->num_of_transition = bVar1;
      pwVar2->mode_of_transition = pwVar4->mode_of_transition;
      memcpy(__dest,pwVar4->transitions,(uint)pwVar4->num_of_transition * 6);
    }
    src = src + 1;
    ppwVar3 = ppwVar3 + 1;
    if (src == ppwVar5) {
      return '\0';
    }
  } while( true );
}

