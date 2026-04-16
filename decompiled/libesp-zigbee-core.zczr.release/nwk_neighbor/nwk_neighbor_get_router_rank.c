/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_get_router_rank
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t nwk_neighbor_get_router_rank(nwk_neighbor_t *nbr)

{
  if (1 < (*(uint *)&nbr->field_0xc & 3)) {
    nbr = (nwk_neighbor_t *)__assert_func(0,0,0,0);
  }
  return (ushort)(nbr->dev).r.connectivity +
         (((ushort)(nbr->dev).r.outbound_activity + (ushort)(nbr->dev).r.inbound_activity) * 2 +
         (ushort)(nbr->dev).r.nbrset_diversity) * 4;
}

