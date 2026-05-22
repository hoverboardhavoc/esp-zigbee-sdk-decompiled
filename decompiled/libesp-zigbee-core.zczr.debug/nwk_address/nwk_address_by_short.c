/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_by_short
                    (ezb_shortaddr_t shortaddr,_Bool create,_Bool lock,nwk_addr_ref_t *ref_p)

{
  nwk_addr_table_t *tbl;
  uint uVar1;
  nwk_addr_ref_t nVar2;
  undefined2 in_register_0000202a;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  
  iVar3 = core_globals_get();
  tbl = (nwk_addr_table_t *)(iVar3 + 0xc4c);
  if (0xfff7 < CONCAT22(in_register_0000202a,shortaddr)) {
    return 2;
  }
  nVar2 = search_short(tbl,shortaddr);
  uVar1 = CONCAT22(extraout_var,nVar2);
  if (uVar1 < *(ushort *)(iVar3 + 0xc54)) {
    addr_table_lru_update(tbl,nVar2);
  }
  else {
    if (CONCAT31(in_register_0000202d,create) == 0) {
      return 5;
    }
    nVar2 = addr_table_add(tbl,shortaddr,(ezb_extaddr_t *)0x0);
    uVar1 = CONCAT22(extraout_var_00,nVar2);
    if (*(ushort *)(iVar3 + 0xc54) <= uVar1) {
      return 1;
    }
  }
  *ref_p = (nwk_addr_ref_t)uVar1;
  if (CONCAT31(in_register_00002031,lock) != 0) {
    nwk_address_lock_ref((nwk_addr_ref_t)uVar1);
  }
  return 0;
}

