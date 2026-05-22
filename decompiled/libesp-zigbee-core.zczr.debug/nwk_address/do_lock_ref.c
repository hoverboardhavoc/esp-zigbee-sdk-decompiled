/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> do_lock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void do_lock_ref(nwk_addr_table_t *tbl,nwk_addr_ref_t ref)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined2 in_register_0000202e;
  int iVar2;
  nwk_addr_table_ent_t *pnVar3;
  
  iVar2 = CONCAT22(in_register_0000202e,ref);
  _Var1 = check_table_ref(ref,tbl->ent_in_use,tbl->ent_nr);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    return;
  }
  pnVar3 = tbl->ents;
  if (pnVar3[iVar2].ref_cnt == 0xff) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x193,"do_lock_ref"
                  ,"ent->ref_cnt < (0xff)");
  }
  else if (pnVar3[iVar2].ref_cnt != '\0') goto _L0;
  addr_table_lru_remove(tbl,ref);
_L0:
  pnVar3[iVar2].ref_cnt = pnVar3[iVar2].ref_cnt + '\x01';
  return;
}

