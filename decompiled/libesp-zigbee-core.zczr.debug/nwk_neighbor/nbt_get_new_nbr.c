/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_get_new_nbr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nbt_get_new_nbr(nwk_neighbor_table_t *tbl,_Bool is_router)

{
  _Bool _Var1;
  nwk_neighbor_t *n;
  undefined3 in_register_0000202d;
  uint uVar2;
  nwk_neighbor_t *pnVar3;
  
  if (CONCAT31(in_register_0000202d,is_router) == 0) {
    pnVar3 = (nwk_neighbor_t *)(uint)tbl->ent_nr;
    uVar2 = (int)pnVar3 - (uint)tbl->ed_capacity & 0xffff;
  }
  else {
    pnVar3 = (nwk_neighbor_t *)((uint)tbl->ent_nr - (uint)tbl->ed_capacity & 0xffff);
    uVar2 = 0;
  }
  n = (nwk_neighbor_t *)bitmap_find_next_zero_bit(tbl->ent_in_use,tbl->ent_nr,uVar2);
  if (n < pnVar3) {
    _Var1 = test_and_set_bitmap((uint)n,tbl->ent_in_use);
    if (_Var1) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x11b,
                    "nbt_get_new_nbr","!test_and_set_bitmap(idx, tbl->ent_in_use)");
    }
    else {
      n = tbl->ents + (int)n;
      if (CONCAT31(in_register_0000202d,is_router) != 0) {
        nbt_inc_router_cnt(tbl);
        return n;
      }
    }
    nbt_inc_ed_cnt(tbl);
  }
  else {
    n = (nwk_neighbor_t *)0x0;
  }
  return n;
}

