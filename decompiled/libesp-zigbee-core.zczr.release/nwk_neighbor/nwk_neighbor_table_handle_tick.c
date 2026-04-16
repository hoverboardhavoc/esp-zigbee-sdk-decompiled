/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_neighbor_table_handle_tick(void)

{
  nwk_neighbor_t *nbr;
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  nbr = (nwk_neighbor_t *)0x0;
  while (nbr = nwk_neighbor_table_next(nbr), nbr != (nwk_neighbor_t *)0x0) {
    uVar2 = *(uint *)&nbr->field_0xc & 0x3c0;
    if ((uVar2 == 0x140) || ((uVar2 == 0x40 && (iVar1 = nwk_get_keepalive_mode(), iVar1 != 0)))) {
      uVar3 = *(uint *)((int)&nbr->dev + 4);
      uVar2 = uVar3 & 0xfffff;
      if (uVar2 == 0) {
        nwk_neighbor_table_delete(nbr);
      }
      else {
        *(uint *)((int)&nbr->dev + 4) = uVar3 & 0xfff00000 | uVar2 + 0xfffff & 0xfffff;
      }
    }
  }
  return;
}

