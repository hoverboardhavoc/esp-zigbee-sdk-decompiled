/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_find_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nwk_mesh_find_child(ezb_shortaddr_t dst_addr)

{
  undefined2 in_register_0000202a;
  nwk_neighbor_t *pnVar1;
  
  pnVar1 = (nwk_neighbor_t *)
           nwk_neighbor_table_get_by_short(CONCAT22(in_register_0000202a,dst_addr));
  if (pnVar1 == (nwk_neighbor_t *)0x0) {
    pnVar1 = (nwk_neighbor_t *)0x0;
  }
  else if ((*(uint *)&pnVar1->field_0xc & 0x3c0) != 0x40) {
    pnVar1 = (nwk_neighbor_t *)0x0;
  }
  return pnVar1;
}

