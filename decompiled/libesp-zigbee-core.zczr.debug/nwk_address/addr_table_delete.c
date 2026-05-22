/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void addr_table_delete(nwk_addr_table_t *tbl,nwk_addr_ref_t ref)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined2 in_register_0000202e;
  uint n;
  nwk_addr_table_ent_t *pnVar2;
  
  n = CONCAT22(in_register_0000202e,ref);
  _Var1 = check_table_ref(ref,tbl->ent_in_use,tbl->ent_nr);
  if (CONCAT31(extraout_var,_Var1) != 0) {
    pnVar2 = tbl->ents;
    if (pnVar2[n].ref_cnt == '\0') {
      test_and_clr_bitmap(n,tbl->ent_in_use);
      addr_table_lru_remove(tbl,ref);
      memset(tbl->ents + n,0,0x12);
    }
    else {
      pnVar2[n].field_0x11 = pnVar2[n].field_0x11 | 8;
    }
  }
  return;
}

