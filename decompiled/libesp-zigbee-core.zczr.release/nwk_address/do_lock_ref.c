/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> do_lock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void do_lock_ref(nwk_addr_table_t *tbl,nwk_addr_ref_t ref)

{
  nwk_addr_table_ent_t *pnVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  undefined2 in_register_0000202e;
  int iVar3;
  uint uVar4;
  
  iVar3 = CONCAT22(in_register_0000202e,ref);
  _Var2 = check_table_ref(ref,tbl->ent_in_use,tbl->ent_nr);
  if (CONCAT31(extraout_var,_Var2) != 0) {
    pnVar1 = tbl->ents;
    uVar4 = (uint)pnVar1[iVar3].ref_cnt;
    if (uVar4 == 0xff) {
      __assert_func(0,0,0,0);
    }
    if (uVar4 == 0) {
      addr_table_lru_remove(tbl,ref);
    }
    pnVar1[iVar3].ref_cnt = pnVar1[iVar3].ref_cnt + '\x01';
  }
  return;
}

