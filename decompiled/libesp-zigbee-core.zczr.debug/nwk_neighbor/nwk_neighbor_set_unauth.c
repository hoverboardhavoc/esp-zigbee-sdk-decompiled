/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_set_unauth
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_set_unauth(nwk_neighbor_t *nbr,uint8_t timeout)

{
  undefined3 in_register_0000202d;
  
  *(uint *)&nbr->field_0xc = *(uint *)&nbr->field_0xc & 0xfffffc3f | 0x140;
  (nbr->dev).field2[0] = 0;
  (nbr->dev).field2[1] = 0;
  (nbr->dev).field2[2] = 0;
  (nbr->dev).field2[3] = 0;
  (nbr->dev).r.connectivity = '\0';
  (nbr->dev).r.tmp_connectivity = '\0';
  (nbr->dev).r.nbrset_diversity = '\0';
  (nbr->dev).r.tmp_diversity = '\0';
  (nbr->dev).r.outbound_activity = '\0';
  (nbr->dev).r.inbound_activity = '\0';
  (nbr->dev).field2[10] = 0;
  (nbr->dev).field2[0xb] = 0;
  *(uint *)((int)&nbr->dev + 4) =
       *(uint *)((int)&nbr->dev + 4) & 0xfff00000 | CONCAT31(in_register_0000202d,timeout);
  return;
}

