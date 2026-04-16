/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nwk_neighbor_table_new(_Bool is_router)

{
  undefined3 in_register_00002029;
  int iVar1;
  nwk_neighbor_t *nbr;
  uint uVar2;
  
  iVar1 = core_globals_get();
  nbr = nbt_get_new_nbr((nwk_neighbor_table_t *)(iVar1 + 0xb1c),is_router);
  if (CONCAT31(in_register_00002029,is_router) == 0) {
    if (nbr == (nwk_neighbor_t *)0x0) {
      return (nwk_neighbor_t *)0x0;
    }
  }
  else if (nbr == (nwk_neighbor_t *)0x0) {
    nbr = nbt_get_stale_router((nwk_neighbor_table_t *)(iVar1 + 0xb1c));
    if (nbr == (nwk_neighbor_t *)0x0) {
      return (nwk_neighbor_t *)0x0;
    }
    if (nbr->addr_ref != 0xffff) {
      nwk_address_unlock_ref();
    }
  }
  memset(nbr,0,0x20);
  nbr->addr_ref = 0xffff;
  uVar2 = *(uint *)&nbr->field_0xc;
  *(uint *)&nbr->field_0xc = uVar2 | 3;
  uVar2 = uVar2 & 0xfffffc3f;
  *(uint *)&nbr->field_0xc = uVar2 | 0xc3;
  *(uint *)&nbr->field_0xc = uVar2 | 0x1c0000c3;
  nwk_neighbor_clear_lqa(nbr);
  return nbr;
}

