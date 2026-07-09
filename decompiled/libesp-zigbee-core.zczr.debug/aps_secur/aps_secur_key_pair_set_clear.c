/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_clear(void)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0x9a0);
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0x9a4);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0x9a8) != 0) && (iVar2 != 0)) && (iVar4 != 0)) {
    iVar2 = core_globals_get();
    pvVar1 = *(void **)(iVar2 + 0x9a0);
    iVar2 = core_globals_get();
    memset(pvVar1,0,(uint)*(ushort *)(iVar2 + 0x9a8) * 0x38);
    iVar2 = core_globals_get();
    pvVar1 = *(void **)(iVar2 + 0x9a4);
    iVar2 = core_globals_get();
    memset(pvVar1,0,*(ushort *)(iVar2 + 0x9a8) + 7 >> 3);
    ds_delete_all_aps_key_pair();
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0xbd,
                "aps_secur_key_pair_set_clear",&_L0);
  aps_secur_key_pair_set_clear();
  iVar2 = aps_secur_is_centralized();
  if (iVar2 != 0) {
    aps_secur_set_distributed(0);
  }
  return;
}

