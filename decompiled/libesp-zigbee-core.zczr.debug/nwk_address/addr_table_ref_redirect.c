/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_ref_redirect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void addr_table_ref_redirect
               (nwk_addr_table_t *tbl,nwk_addr_ref_t source_ref,nwk_addr_ref_t target_ref)

{
  undefined2 in_register_0000202e;
  int iVar1;
  undefined2 in_register_00002032;
  int iVar2;
  nwk_addr_table_ent_t *pnVar3;
  nwk_addr_table_ent_t *source;
  
  iVar2 = CONCAT22(in_register_00002032,target_ref);
  iVar1 = CONCAT22(in_register_0000202e,source_ref);
  pnVar3 = tbl->ents;
  pnVar3[iVar2].ref_cnt = pnVar3[iVar2].ref_cnt + pnVar3[iVar1].ref_cnt;
  pnVar3[iVar2].redirect_ref = source_ref;
  pnVar3[iVar1].field_0xf = pnVar3[iVar1].field_0xf | 4;
  pnVar3[iVar1].redirect_ref = target_ref;
  return;
}

