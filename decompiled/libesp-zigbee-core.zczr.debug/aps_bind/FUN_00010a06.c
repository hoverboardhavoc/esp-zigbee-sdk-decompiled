/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> FUN_00010a06
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void FUN_00010a06(int param_1)

{
  uint uVar1;
  aps_bind_dst_t *unaff_s1;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  aps_bind_src_t *unaff_s2;
  int unaff_s3;
  
  uVar1 = ((int)unaff_s1 - *(int *)(param_1 + unaff_s3 + -0x68c) >> 1) * -0x55555555;
  iVar3 = core_globals_get();
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar3 + unaff_s3 + -0x684)) {
    _Var2 = test_and_set_bitmap(uVar1 & 0xffff,(bitmap_t *)(unaff_s2 + 1));
    if (CONCAT31(extraout_var,_Var2) != 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x76,"bind_table_bind"
                  ,&_LC10);
  }
  unaff_s1->ref_cnt = unaff_s1->ref_cnt + '\x01';
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0x980) & 1) == 0) {
    aps_bind_table_store_bind(unaff_s2,unaff_s1);
  }
  return;
}

