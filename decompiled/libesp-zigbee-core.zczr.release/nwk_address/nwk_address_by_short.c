/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_by_short
                    (ezb_shortaddr_t shortaddr,_Bool create,_Bool lock,nwk_addr_ref_t *ref_p)

{
  uint uVar1;
  nwk_addr_ref_t nVar2;
  undefined2 in_register_0000202a;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  nwk_addr_table_t *tbl;
  
  iVar3 = core_globals_get();
  if (0xfff7 < CONCAT22(in_register_0000202a,shortaddr)) {
    return 2;
  }
  tbl = (nwk_addr_table_t *)(iVar3 + 0xcb0);
  nVar2 = search_short(tbl,shortaddr);
  uVar1 = CONCAT22(extraout_var,nVar2);
  if (uVar1 < *(ushort *)(iVar3 + 0xcb8)) {
    addr_table_lru_update(tbl,nVar2);
  }
  else {
    if (CONCAT31(in_register_0000202d,create) == 0) {
      return 5;
    }
    nVar2 = addr_table_add(tbl,shortaddr,(ezb_extaddr_t *)0x0);
    uVar1 = CONCAT22(extraout_var_00,nVar2);
    if (*(ushort *)(iVar3 + 0xcb8) <= uVar1) {
      return 1;
    }
  }
  *ref_p = (nwk_addr_ref_t)uVar1;
  if (CONCAT31(in_register_00002031,lock) != 0) {
    nwk_address_lock_ref((nwk_addr_ref_t)uVar1);
  }
  return 0;
}

