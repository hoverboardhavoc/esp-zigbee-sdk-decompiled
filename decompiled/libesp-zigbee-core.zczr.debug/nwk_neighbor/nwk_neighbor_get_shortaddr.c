/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_get_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_shortaddr_t nwk_neighbor_get_shortaddr(nwk_neighbor_t *nbr)

{
  int iVar1;
  nwk_neighbor_t *nbr_00;
  uint extraout_a1;
  ezb_shortaddr_t aeStack_12 [2];
  ezb_shortaddr_t shortaddr;
  
  iVar1 = nwk_address_short_by_ref(nbr->addr_ref,aeStack_12);
  if (iVar1 == 0) {
    return aeStack_12[0];
  }
  nbr_00 = (nwk_neighbor_t *)
           __assert_func("//build/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xa0,
                         "nwk_neighbor_get_shortaddr",
                         "(nwk_address_short_by_ref(nbr->addr_ref, &shortaddr)) == 0");
  *(uint *)&nbr_00->field_0xc = *(uint *)&nbr_00->field_0xc & 0xe3ffffff | (extraout_a1 & 7) << 0x1a
  ;
  if (extraout_a1 == 0) {
    nwk_neighbor_get_shortaddr(nbr_00);
    nwk_route_table_remove_by_dst();
    nwk_neighbor_get_shortaddr(nbr_00);
    nbr_00 = (nwk_neighbor_t *)nwk_route_table_remove_by_next_hop();
  }
  return (ezb_shortaddr_t)nbr_00;
}

