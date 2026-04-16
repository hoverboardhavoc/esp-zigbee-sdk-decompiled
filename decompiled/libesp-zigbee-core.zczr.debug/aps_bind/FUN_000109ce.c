/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> FUN_000109ce
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void FUN_000109ce(aps_bind_src_t *param_1,aps_bind_dst_t *param_2)

{
  uint uVar1;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  
  iVar3 = core_globals_get();
  uVar1 = ((int)param_2 - *(int *)(iVar3 + 0x974) >> 1) * -0x55555555;
  iVar3 = core_globals_get();
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar3 + 0x97c)) {
    _Var2 = test_and_set_bitmap(uVar1 & 0xffff,(bitmap_t *)(param_1 + 1));
    if (CONCAT31(extraout_var,_Var2) != 0) {
      return;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_bind.c",0x76,"bind_table_bind",0x1097c);
  }
  param_2->ref_cnt = param_2->ref_cnt + '\x01';
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0x980) & 1) == 0) {
    aps_bind_table_store_bind(param_1,param_2);
  }
  return;
}

