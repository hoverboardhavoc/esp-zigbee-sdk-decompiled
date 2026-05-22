/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_key_pair_set_clear(void)

{
  void *pvVar1;
  _Bool _Var2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x9a0);
  iVar4 = core_globals_get();
  iVar5 = *(int *)(iVar4 + 0x9a4);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0x9a8) != 0) && (iVar3 != 0)) && (iVar5 != 0)) {
    iVar3 = core_globals_get();
    pvVar1 = *(void **)(iVar3 + 0x9a0);
    iVar3 = core_globals_get();
    memset(pvVar1,0,(uint)*(ushort *)(iVar3 + 0x9a8) * 0x38);
    iVar3 = core_globals_get();
    pvVar1 = *(void **)(iVar3 + 0x9a4);
    iVar3 = core_globals_get();
    memset(pvVar1,0,*(ushort *)(iVar3 + 0x9a8) + 7 >> 3);
    ds_delete_all_aps_key_pair();
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0xbd,
                "aps_secur_key_pair_set_clear",&_L0);
  aps_secur_key_pair_set_clear();
  _Var2 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var,_Var2) != 0) {
    aps_secur_set_distributed(false);
  }
  return;
}

