/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_get_link_cost
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_neighbor_get_link_cost(nwk_neighbor_t *nbr)

{
  uint8_t uVar1;
  undefined3 extraout_var;
  uint uVar2;
  
  uVar1 = nwk_neighbor_get_incoming_cost(nbr);
  uVar2 = *(uint *)&nbr->field_0xc >> 0x1a & 7;
  if (CONCAT31(extraout_var,uVar1) < uVar2) {
    return (uint8_t)uVar2;
  }
  nwk_neighbor_get_lqa(nbr);
  uVar1 = nwk_lqa_2_cost();
  return uVar1;
}

