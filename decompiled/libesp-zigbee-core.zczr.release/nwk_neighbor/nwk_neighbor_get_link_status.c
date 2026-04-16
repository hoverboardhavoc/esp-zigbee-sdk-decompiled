/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_get_link_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_neighbor_get_link_status(nwk_neighbor_t *nbr)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = *(uint *)&nbr->field_0xc;
  bVar2 = nwk_neighbor_get_incoming_cost(nbr);
  return bVar2 & 7 | (byte)((uVar1 >> 0x1a & 7) << 4);
}

