/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bind_table_bind(aps_bind_src_t *src,aps_bind_dst_t *dst)

{
  uint uVar1;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  
  iVar3 = core_globals_get();
  uVar1 = ((int)dst - *(int *)(iVar3 + 0x974) >> 1) * -0x55555555;
  iVar3 = core_globals_get();
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar3 + 0x97c)) {
    _Var2 = test_and_set_bitmap(uVar1 & 0xffff,(bitmap_t *)(src + 1));
    if (CONCAT31(extraout_var,_Var2) != 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x76,"bind_table_bind"
                  ,&_LC10);
  }
  dst->ref_cnt = dst->ref_cnt + '\x01';
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0x980) & 1) == 0) {
    aps_bind_table_store_bind(src,dst);
  }
  return;
}

