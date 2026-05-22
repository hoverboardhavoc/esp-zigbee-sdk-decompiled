/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_by_extended
                    (ezb_extaddr_t *extaddr,_Bool create,_Bool lock,nwk_addr_ref_t *ref_p)

{
  int iVar1;
  nwk_addr_table_t *tbl;
  nwk_addr_ref_t nVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  ezb_err_t eVar4;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  uint uVar5;
  
  iVar3 = core_globals_get();
  tbl = (nwk_addr_table_t *)(iVar3 + 0xc4c);
  if (extaddr == (ezb_extaddr_t *)0x0) {
    eVar4 = 2;
  }
  else {
    iVar1 = *(int *)((int)&extaddr->field_0 + 4);
    if (*(int *)&extaddr->field_0 == 0 && iVar1 == 0) {
      eVar4 = 2;
    }
    else if ((*(int *)&extaddr->field_0 == -1) && (iVar1 == -1)) {
      eVar4 = 2;
    }
    else {
      nVar2 = search_extended(tbl,extaddr);
      uVar5 = CONCAT22(extraout_var,nVar2);
      if (uVar5 < *(ushort *)(iVar3 + 0xc54)) {
        addr_table_lru_update(tbl,nVar2);
      }
      else {
        if (CONCAT31(in_register_0000202d,create) == 0) {
          return 5;
        }
        nVar2 = addr_table_add(tbl,0xffff,extaddr);
        uVar5 = CONCAT22(extraout_var_00,nVar2);
        if (*(ushort *)(iVar3 + 0xc54) <= uVar5) {
          return 1;
        }
      }
      *ref_p = (nwk_addr_ref_t)uVar5;
      if (CONCAT31(in_register_00002031,lock) == 0) {
        eVar4 = 0;
      }
      else {
        nwk_address_lock_ref((nwk_addr_ref_t)uVar5);
        eVar4 = 0;
      }
    }
  }
  return eVar4;
}

