/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_update_lqa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_update_lqa(nwk_neighbor_t *nbr,uint8_t lqi,int8_t rssi)

{
  uint8_t lqa_raw;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  
  lqa_raw = nwk_calculate_lqa_raw
                      (CONCAT31(in_register_0000202d,lqi),CONCAT31(in_register_00002031,rssi));
  nbr_update_lqa(nbr,lqa_raw);
  nbr->rssi = rssi;
  return;
}

