/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_neighbor_table_handle_tick(void)

{
  bool bVar1;
  nwk_neighbor_t *nbr;
  int iVar2;
  uint uVar3;
  
  nbr = (nwk_neighbor_t *)0x0;
_L0:
  nbr = nwk_neighbor_table_next(nbr);
  if (nbr == (nwk_neighbor_t *)0x0) {
    return;
  }
  uVar3 = *(uint *)&nbr->field_0xc & 0x3c0;
  if (uVar3 != 0x140) goto _L0;
  goto _L0;
_L0:
  if (uVar3 == 0x40) {
    iVar2 = nwk_get_keepalive_mode();
    bVar1 = iVar2 != 0;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
_L0:
    if (((undefined1  [12])nbr->dev & (undefined1  [12])0xfffff00000000) == (undefined1  [12])0x0) {
      nwk_neighbor_table_delete(nbr);
    }
    else {
      uVar3 = *(uint *)((int)&nbr->dev + 4);
      *(uint *)((int)&nbr->dev + 4) = uVar3 & 0xfff00000 | (uVar3 & 0xfffff) + 0xfffff & 0xfffff;
    }
  }
  goto _L0;
}

