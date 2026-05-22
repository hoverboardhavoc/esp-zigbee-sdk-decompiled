/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> do_unlock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void do_unlock_ref(nwk_addr_table_t *tbl,nwk_addr_ref_t ref)

{
  uint8_t uVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  undefined2 in_register_0000202e;
  int iVar3;
  nwk_addr_table_ent_t *pnVar4;
  
  iVar3 = CONCAT22(in_register_0000202e,ref);
  _Var2 = check_table_ref(ref,tbl->ent_in_use,tbl->ent_nr);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    return;
  }
  pnVar4 = tbl->ents;
  uVar1 = pnVar4[iVar3].ref_cnt;
  if (uVar1 == '\0') {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x1a5,
                  "do_unlock_ref","ent->ref_cnt > 0");
  }
  else {
    pnVar4[iVar3].ref_cnt = uVar1 + 0xff;
    if (uVar1 != '\x01') {
      return;
    }
    if ((*(ushort *)&pnVar4[iVar3].ref_cnt & 0xc00) != 0) {
      nwk_address_delete(ref);
      return;
    }
  }
  addr_table_lru_add(tbl,ref);
  return;
}

