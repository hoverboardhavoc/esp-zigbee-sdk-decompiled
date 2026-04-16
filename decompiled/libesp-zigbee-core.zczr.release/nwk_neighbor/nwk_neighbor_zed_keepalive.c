/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_zed_keepalive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_zed_keepalive(nwk_neighbor_t *nbr)

{
  nwk_neighbor_zed_set_timeout(nbr,(byte)(*(uint *)((int)&nbr->dev + 4) >> 0x14) & 0xf);
  *(uint *)((int)&nbr->dev + 4) = *(uint *)((int)&nbr->dev + 4) | 0x1000000;
  return;
}

