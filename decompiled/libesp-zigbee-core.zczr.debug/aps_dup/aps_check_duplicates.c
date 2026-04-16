/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_check_duplicates
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_check_duplicates(aps_header_t *aps_hdr)

{
  int iVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  int iVar3;
  aps_dup_t *paVar4;
  aps_dup_table_t *tbl;
  
  _Var2 = aps_dup_need_check(aps_hdr);
  iVar1 = CONCAT31(extraout_var,_Var2);
  if (iVar1 != 0) {
    iVar3 = core_globals_get();
    paVar4 = aps_dup_table_find((aps_dup_table_t *)(iVar3 + 0x984),aps_hdr);
    if (paVar4 == (aps_dup_t *)0x0) {
      aps_dup_table_add((aps_dup_table_t *)(iVar3 + 0x984),aps_hdr);
      iVar1 = 0;
    }
  }
  return SUB41(iVar1,0);
}

