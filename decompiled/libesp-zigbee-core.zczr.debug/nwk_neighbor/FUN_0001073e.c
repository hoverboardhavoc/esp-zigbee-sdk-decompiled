/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> FUN_0001073e
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint FUN_0001073e(undefined2 *param_1)

{
  int iVar1;
  uint uVar2;
  uint extraout_a1;
  ushort in_stack_0000000e;
  
  iVar1 = nwk_address_short_by_ref(*param_1,&stack0x0000000e);
  if (iVar1 == 0) {
    return (uint)in_stack_0000000e;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xa0,
                        "nwk_neighbor_get_shortaddr",&_L0);
  *(uint *)(uVar2 + 0xc) = *(uint *)(uVar2 + 0xc) & 0xe3ffffff | (extraout_a1 & 7) << 0x1a;
  if (extraout_a1 == 0) {
    nwk_neighbor_get_shortaddr();
    nwk_route_table_remove_by_dst();
    nwk_neighbor_get_shortaddr(uVar2);
    uVar2 = nwk_route_table_remove_by_next_hop();
  }
  return uVar2;
}

