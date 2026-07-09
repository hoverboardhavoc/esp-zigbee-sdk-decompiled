/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_set_outgoing_cost
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_set_outgoing_cost(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xe3ffffff | (param_2 & 7) << 0x1a;
  if (param_2 == 0) {
    nwk_neighbor_get_shortaddr();
    nwk_route_table_remove_by_dst();
    nwk_neighbor_get_shortaddr(param_1);
    nwk_route_table_remove_by_next_hop();
  }
  return;
}

