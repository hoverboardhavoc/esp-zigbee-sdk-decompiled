/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_key_pair_set_deinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  aps_secur_key_pair_set_clear();
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0x9a0);
  iVar2 = core_globals_get();
  iVar3 = *(int *)(iVar2 + 0x9a4);
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0x9a8) != 0) && (iVar1 != 0)) && (iVar3 != 0)) {
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
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0xc4,
                "aps_secur_key_pair_set_deinit",&_L0);
  aps_secur_key_pair_set_deinit();
  return;
}

