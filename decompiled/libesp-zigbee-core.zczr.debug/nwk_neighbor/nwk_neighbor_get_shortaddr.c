/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xa0,
                         "nwk_neighbor_get_shortaddr",&_L0);
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

