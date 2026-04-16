/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_clear
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
  undefined2 auStack_22 [7];
  code *pcStack_14;
  
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0x9a0);
  iVar5 = core_globals_get();
  iVar6 = *(int *)(iVar5 + 0x9a4);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0x9a8) != 0) && (iVar4 != 0)) && (iVar6 != 0)) {
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0x9a0);
    iVar4 = core_globals_get();
    memset(pvVar2,0,(uint)*(ushort *)(iVar4 + 0x9a8) * 0x38);
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0x9a4);
    iVar4 = core_globals_get();
    memset(pvVar2,0,*(ushort *)(iVar4 + 0x9a8) + 7 >> 3);
    ds_delete_all_aps_key_pair();
    return;
  }
  pcVar1 = aps_secur_ctx_clear;
  __assert_func("//build/esp-zigbee/src/core/aps/aps_secur.c",0xa7,"aps_secur_key_pair_set_clear",
                &_L0);
  pcStack_14 = pcVar1;
  aps_secur_key_pair_set_clear();
  _Var3 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var,_Var3) != 0) {
    aps_secur_get_tc_address();
    iVar4 = nwk_address_ref_by_extended(auStack_22);
    if (iVar4 == 0) {
      nwk_address_unlock_ref(auStack_22[0]);
    }
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0x9ac) = 0;
    *(undefined1 *)(iVar4 + 0x9ad) = 0;
    *(undefined1 *)(iVar4 + 0x9ae) = 0;
    *(undefined1 *)(iVar4 + 0x9af) = 0;
    *(undefined1 *)(iVar4 + 0x9b0) = 0;
    *(undefined1 *)(iVar4 + 0x9b1) = 0;
    *(undefined1 *)(iVar4 + 0x9b2) = 0;
    *(undefined1 *)(iVar4 + 0x9b3) = 0;
  }
  return;
}

