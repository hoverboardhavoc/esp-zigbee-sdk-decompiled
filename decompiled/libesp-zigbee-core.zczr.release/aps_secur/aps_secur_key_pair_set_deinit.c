/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_deinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  aps_secur_key_pair_set_clear();
  iVar1 = core_globals_get();
  iVar3 = *(int *)(iVar1 + 0x9a0);
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0x9a4);
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0x9a8) != 0) && (iVar3 != 0)) && (iVar1 != 0)) {
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0x9a0));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x9a0) = 0;
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0x9a4));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x9a4) = 0;
    return;
  }
  __assert_func(0,0,0,0);
  aps_secur_key_pair_set_deinit();
  return;
}

