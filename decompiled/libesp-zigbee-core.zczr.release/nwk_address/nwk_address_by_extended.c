/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_by_extended
                    (ezb_extaddr_t *extaddr,_Bool create,_Bool lock,nwk_addr_ref_t *ref_p)

{
  uint uVar1;
  nwk_addr_ref_t nVar2;
  int iVar3;
  ezb_err_t eVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  nwk_addr_table_t *tbl;
  
  iVar3 = core_globals_get();
  if (extaddr == (ezb_extaddr_t *)0x0) {
    eVar4 = 2;
  }
  else if ((*(int *)((int)&extaddr->field_0 + 4) + 1U != (uint)(*(int *)&extaddr->field_0 == 0)) ||
          (eVar4 = 2, *(int *)&extaddr->field_0 - 1U < 0xfffffffe)) {
    tbl = (nwk_addr_table_t *)(iVar3 + 0xc4c);
    nVar2 = search_extended(tbl,extaddr);
    uVar1 = CONCAT22(extraout_var,nVar2);
    if (uVar1 < *(ushort *)(iVar3 + 0xc54)) {
      addr_table_lru_update(tbl,nVar2);
    }
    else {
      if (CONCAT31(in_register_0000202d,create) == 0) {
        return 5;
      }
      nVar2 = addr_table_add(tbl,0xffff,extaddr);
      uVar1 = CONCAT22(extraout_var_00,nVar2);
      if (*(ushort *)(iVar3 + 0xc54) <= uVar1) {
        return 1;
      }
    }
    *ref_p = (nwk_addr_ref_t)uVar1;
    if (CONCAT31(in_register_00002031,lock) != 0) {
      nwk_address_lock_ref((nwk_addr_ref_t)uVar1);
    }
    eVar4 = 0;
  }
  return eVar4;
}

