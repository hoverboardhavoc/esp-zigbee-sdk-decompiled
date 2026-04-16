/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_addr_ref_t
addr_table_add(nwk_addr_table_t *tbl,ezb_shortaddr_t shortaddr,ezb_extaddr_t *extaddr)

{
  uint uVar1;
  nwk_addr_ref_t nVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  nwk_addr_table_ent_t *pnVar3;
  undefined1 auStack_28 [4];
  ezb_extaddr_t unknown_extaddr;
  
  auStack_28 = (undefined1  [4])0xffffffff;
  unknown_extaddr.field_0.u64._0_4_ = 0xffffffff;
  nVar2 = addr_table_new(tbl);
  uVar1 = CONCAT22(extraout_var,nVar2);
  if (tbl->ent_nr <= uVar1) {
    nVar2 = addr_table_lru_reuse(tbl);
    uVar1 = CONCAT22(extraout_var_00,nVar2);
  }
  if (uVar1 < tbl->ent_nr) {
    pnVar3 = tbl->ents;
    pnVar3[uVar1].shortaddr = shortaddr;
    if (extaddr == (ezb_extaddr_t *)0x0) {
      extaddr = (ezb_extaddr_t *)auStack_28;
    }
    nwk_extaddr_compress(extaddr,&pnVar3[uVar1].extaddr_c);
  }
  return (nwk_addr_ref_t)uVar1;
}

