/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_table_unbind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool bind_table_unbind(aps_bind_src_t *src,aps_bind_dst_t *dst)

{
  uint8_t uVar1;
  _Bool _Var2;
  _Bool _Var3;
  int iVar4;
  int iVar5;
  uint n;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0x974);
  iVar5 = core_globals_get();
  n = ((int)dst - iVar4 >> 1) * -0x55555555 & 0xffff;
  if (*(ushort *)(iVar5 + 0x97c) <= n) {
    n = __assert_func(0,0,0,0);
  }
  _Var2 = test_and_clr_bitmap(n,(bitmap_t *)(src + 1));
  if (CONCAT31(extraout_var,_Var2) != 0) {
    iVar4 = core_globals_get();
    if ((*(uint *)(iVar4 + 0x980) & 1) == 0) {
      aps_bind_table_remove_stored_bind(src,dst);
    }
    _Var3 = bind_src_is_empty(src);
    if (CONCAT31(extraout_var_00,_Var3) != 0) {
      bind_src_table_free(src);
    }
    uVar1 = dst->ref_cnt;
    dst->ref_cnt = uVar1 + 0xff;
    if (uVar1 == '\x01') {
      bind_dst_table_free(dst);
    }
  }
  return _Var2;
}

