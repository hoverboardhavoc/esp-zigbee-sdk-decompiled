/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_get_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_neighbor_get_shortaddr(undefined2 *param_1)

{
  int iVar1;
  uint uVar2;
  uint extraout_a1;
  ushort auStack_12 [7];
  
  iVar1 = nwk_address_short_by_ref(*param_1,auStack_12);
  if (iVar1 == 0) {
    return (uint)auStack_12[0];
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xa0,
                        "nwk_neighbor_get_shortaddr",
                        "(nwk_address_short_by_ref(nbr->addr_ref, &shortaddr)) == 0");
  *(uint *)(uVar2 + 0xc) = *(uint *)(uVar2 + 0xc) & 0xe3ffffff | (extraout_a1 & 7) << 0x1a;
  if (extraout_a1 == 0) {
    nwk_neighbor_get_shortaddr();
    nwk_route_table_remove_by_dst();
    nwk_neighbor_get_shortaddr(uVar2);
    uVar2 = nwk_route_table_remove_by_next_hop();
  }
  return uVar2;
}

