/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_graphs_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_weekly_schedule_graphs_free(weekly_schedule_graph_t **graphs,uint8_t count)

{
  uint uVar1;
  weekly_schedule_graph_t **ppwVar2;
  undefined3 in_register_0000202d;
  
  for (uVar1 = 0; uVar1 < CONCAT31(in_register_0000202d,count); uVar1 = uVar1 + 1 & 0xff) {
    ppwVar2 = graphs + uVar1;
    if (*ppwVar2 != (weekly_schedule_graph_t *)0x0) {
      mm_free((*ppwVar2)->transitions);
      mm_free(*ppwVar2);
      *ppwVar2 = (weekly_schedule_graph_t *)0x0;
    }
  }
  return;
}

