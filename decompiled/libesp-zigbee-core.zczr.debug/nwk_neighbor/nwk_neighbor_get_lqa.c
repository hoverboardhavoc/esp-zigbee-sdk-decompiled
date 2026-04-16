/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_get_lqa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_neighbor_get_lqa(nwk_neighbor_t *nbr)

{
  byte bVar1;
  uint uVar2;
  _Bool agc;
  uint uVar3;
  uint uVar4;
  
  bVar1 = nbr->lqa[0];
  uVar2 = (uint)bVar1;
  if (uVar2 != 0) {
    uVar3 = (uint)nbr->lqa[1];
    if (uVar3 != 0) {
      uVar4 = (uint)nbr->lqa[2];
      if (uVar4 == 0) {
        return (uint8_t)(uVar2 + uVar3 >> 1);
      }
      if ((uVar3 < uVar2 == uVar4 < uVar2) && (bVar1 = nbr->lqa[2], uVar3 < uVar2 == uVar4 < uVar3))
      {
        return nbr->lqa[1];
      }
    }
  }
  return bVar1;
}

