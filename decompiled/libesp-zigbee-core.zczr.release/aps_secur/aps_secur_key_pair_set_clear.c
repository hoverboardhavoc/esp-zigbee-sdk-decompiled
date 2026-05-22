/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_key_pair_set_clear(void)

{
  code *pcVar1;
  void *pvVar2;
  _Bool _Var3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  int iVar6;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 aaStack_28 [2];
  code *pcStack_14;
  
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0x9a0);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0x9a4);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0x9a8) != 0) && (iVar6 != 0)) && (iVar4 != 0)) {
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0x9a0);
    iVar4 = core_globals_get();
    memset(pvVar2,0,(uint)*(ushort *)(iVar4 + 0x9a8) * 0x38);
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0x9a4);
    iVar4 = core_globals_get();
    memset(pvVar2,0,*(ushort *)(iVar4 + 0x9a8) + 7 >> 3);
    ds_internal_remove_entry(9,0xffffffff,0);
    return;
  }
  pcVar1 = aps_secur_ctx_clear;
  __assert_func(0,0,0,0);
  pcStack_14 = pcVar1;
  aps_secur_key_pair_set_clear();
  _Var3 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var,_Var3) == 0) {
    return;
  }
  aaStack_28[0].u64._4_4_ = 0;
  aaStack_28[0].u64._0_4_ = 0;
  aps_secur_set_tc_address((ezb_extaddr_t *)aaStack_28);
  return;
}

