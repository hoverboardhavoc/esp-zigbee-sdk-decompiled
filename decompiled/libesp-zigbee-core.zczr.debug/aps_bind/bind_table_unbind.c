/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_unbind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool bind_table_unbind(aps_bind_src_t *src,aps_bind_dst_t *dst)

{
  uint8_t uVar1;
  uint uVar2;
  _Bool _Var3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  iVar4 = core_globals_get();
  uVar2 = ((int)dst - *(int *)(iVar4 + 0x974) >> 1) * -0x55555555;
  iVar4 = core_globals_get();
  if ((uVar2 & 0xffff) < (uint)*(ushort *)(iVar4 + 0x97c)) {
    _Var3 = test_and_clr_bitmap(uVar2 & 0xffff,(bitmap_t *)(src + 1));
    uVar2 = CONCAT31(extraout_var,_Var3);
    if (uVar2 == 0) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x83,
                  "bind_table_unbind",&_LC10);
  }
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
_L0:
  return SUB41(uVar2,0);
}

