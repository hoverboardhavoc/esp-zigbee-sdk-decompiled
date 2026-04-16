/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_refresh_stored_children
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nbt_refresh_stored_children(void)

{
  nwk_neighbor_t *nbr;
  int iVar1;
  ezb_err_t eVar2;
  
  iVar1 = ds_internal_remove_entry(4,0xffffffff,0);
  if (iVar1 == 0) {
    nbr = (nwk_neighbor_t *)0x0;
    do {
      nbr = nwk_child_table_next(nbr);
      if (nbr == (nwk_neighbor_t *)0x0) {
        return;
      }
      eVar2 = nwk_neighbor_table_store_child(nbr);
    } while (eVar2 == 0);
  }
  return;
}

