/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_clear(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_28;
  undefined4 uStack_24;
  code *pcStack_14;
  
  iVar3 = core_globals_get();
  iVar5 = *(int *)(iVar3 + 0x9a0);
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x9a4);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0x9a8) != 0) && (iVar5 != 0)) && (iVar3 != 0)) {
    iVar3 = core_globals_get();
    pvVar2 = *(void **)(iVar3 + 0x9a0);
    iVar3 = core_globals_get();
    memset(pvVar2,0,(uint)*(ushort *)(iVar3 + 0x9a8) * 0x38);
    iVar3 = core_globals_get();
    pvVar2 = *(void **)(iVar3 + 0x9a4);
    iVar3 = core_globals_get();
    memset(pvVar2,0,*(ushort *)(iVar3 + 0x9a8) + 7 >> 3);
    ds_internal_remove_entry(9,0xffffffff,0);
    return;
  }
  pcVar1 = aps_secur_ctx_clear;
  __assert_func(0,0,0,0);
  pcStack_14 = pcVar1;
  aps_secur_key_pair_set_clear();
  iVar3 = aps_secur_is_centralized();
  if (iVar3 == 0) {
    return;
  }
  uStack_24 = 0;
  uStack_28 = 0;
  aps_secur_set_tc_address(&uStack_28);
  return;
}

