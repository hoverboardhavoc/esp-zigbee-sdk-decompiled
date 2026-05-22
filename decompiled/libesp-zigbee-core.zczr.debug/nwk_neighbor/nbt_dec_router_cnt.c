/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_dec_router_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nbt_dec_router_cnt(nwk_neighbor_table_t *tbl)

{
  uint uVar1;
  int extraout_a1;
  
  if (tbl->r_num != 0) {
    tbl->r_num = tbl->r_num - 1;
    return;
  }
  uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xda,
                        "nbt_dec_router_cnt",&_LC4);
  __atomic_fetch_or_1((uVar1 >> 3) + extraout_a1,1 << (uVar1 & 7) & 0xff,5);
  return;
}

