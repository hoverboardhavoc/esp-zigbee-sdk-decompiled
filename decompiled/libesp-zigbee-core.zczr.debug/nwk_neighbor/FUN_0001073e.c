/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> FUN_0001073e
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

nwk_neighbor_t * FUN_0001073e(undefined2 *param_1)

{
  int iVar1;
  nwk_neighbor_t *nbr;
  uint extraout_a1;
  ushort in_stack_0000000e;
  
  iVar1 = nwk_address_short_by_ref(*param_1,&stack0x0000000e);
  if (iVar1 == 0) {
    return (nwk_neighbor_t *)(uint)in_stack_0000000e;
  }
  nbr = (nwk_neighbor_t *)
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xa0,
                      "nwk_neighbor_get_shortaddr",&_L0);
  *(uint *)&nbr->field_0xc = *(uint *)&nbr->field_0xc & 0xe3ffffff | (extraout_a1 & 7) << 0x1a;
  if (extraout_a1 == 0) {
    nwk_neighbor_get_shortaddr(nbr);
    nwk_route_table_remove_by_dst();
    nwk_neighbor_get_shortaddr(nbr);
    nbr = (nwk_neighbor_t *)nwk_route_table_remove_by_next_hop();
  }
  return nbr;
}

