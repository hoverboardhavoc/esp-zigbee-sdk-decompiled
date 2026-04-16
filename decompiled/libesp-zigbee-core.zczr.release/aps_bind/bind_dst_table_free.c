/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_dst_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bind_dst_table_free(aps_bind_dst_t *dst)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  uint extraout_a1;
  uint n;
  aps_bind_dst_t *paVar4;
  bitmap_t *p;
  
  if (dst->ref_cnt != '\0') {
    dst = (aps_bind_dst_t *)__assert_func(0,0,0,0);
  }
  if (((*(ushort *)&dst->ref_cnt >> 8 & 1) == 0) && ((dst->field_0).extaddr.addr_ref != 0xffff)) {
    nwk_address_unlock_ref();
  }
  iVar2 = core_globals_get();
  paVar4 = *(aps_bind_dst_t **)(iVar2 + 0x974);
  iVar2 = core_globals_get();
  p = *(bitmap_t **)(iVar2 + 0x978);
  iVar2 = core_globals_get();
  uVar3 = (uint)*(ushort *)(iVar2 + 0x97c);
  if (dst < paVar4) {
    bind_src_size();
    uVar3 = extraout_a1;
  }
  n = ((int)dst - (int)paVar4) / 6 & 0xffff;
  if (n < uVar3) goto _L26;
  do {
    n = 0;
    p = (bitmap_t *)__assert_func(0,0,0,0);
_L26:
    _Var1 = test_and_clr_bitmap(n,p);
  } while (CONCAT31(extraout_var,_Var1) == 0);
  return;
}

