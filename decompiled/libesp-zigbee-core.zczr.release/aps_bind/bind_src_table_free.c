/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_src_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bind_src_table_free(aps_bind_src_t *src)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  uint extraout_a1;
  uint n;
  aps_bind_src_t *paVar5;
  bitmap_t *p;
  
  _Var1 = bind_src_is_empty(src);
  if (CONCAT31(extraout_var_00,_Var1) == 0) {
    __assert_func(0,0,0);
  }
  if (src->addr_ref != 0xffff) {
    nwk_address_unlock_ref();
  }
  iVar2 = core_globals_get();
  paVar5 = *(aps_bind_src_t **)(iVar2 + 0x968);
  iVar2 = core_globals_get();
  p = *(bitmap_t **)(iVar2 + 0x96c);
  sVar3 = bind_src_size();
  iVar2 = core_globals_get();
  uVar4 = (uint)*(ushort *)(iVar2 + 0x970);
  if (src < paVar5) {
    bind_src_size();
    uVar4 = extraout_a1;
  }
  n = ((int)src - (int)paVar5) / (int)sVar3 & 0xffff;
  if (n < uVar4) goto _L26;
  do {
    n = 0;
    p = (bitmap_t *)__assert_func(0,0,0,0);
_L26:
    _Var1 = test_and_clr_bitmap(n,p);
  } while (CONCAT31(extraout_var,_Var1) == 0);
  return;
}

