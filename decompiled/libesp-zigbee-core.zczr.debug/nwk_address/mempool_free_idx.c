/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> mempool_free_idx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mempool_free_idx(bitmap_t *blk_busy,uint16_t blk_nr,uint16_t blk_idx)

{
  _Bool _Var1;
  undefined3 extraout_var;
  nwk_addr_table_t *tbl;
  undefined3 extraout_var_00;
  undefined2 in_register_0000202e;
  uint n;
  undefined2 in_register_00002032;
  nwk_addr_table_ent_t *pnVar2;
  
  if ((CONCAT22(in_register_00002032,blk_idx) < CONCAT22(in_register_0000202e,blk_nr)) &&
     (_Var1 = test_and_clr_bitmap(CONCAT22(in_register_00002032,blk_idx),blk_busy),
     CONCAT31(extraout_var,_Var1) != 0)) {
    return;
  }
  tbl = (nwk_addr_table_t *)
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.h",0x56,
                      "mempool_free_idx",
                      "(blk_idx < blk_nr) && test_and_clr_bitmap(blk_idx, blk_busy)");
  _Var1 = check_table_ref((uint16_t)n,tbl->ent_in_use,tbl->ent_nr);
  if (CONCAT31(extraout_var_00,_Var1) != 0) {
    pnVar2 = tbl->ents;
    if (pnVar2[n].ref_cnt == '\0') {
      test_and_clr_bitmap(n,tbl->ent_in_use);
      addr_table_lru_remove(tbl,(uint16_t)n);
      memset(tbl->ents + n,0,0x12);
    }
    else {
      pnVar2[n].field_0x11 = pnVar2[n].field_0x11 | 8;
    }
  }
  return;
}

