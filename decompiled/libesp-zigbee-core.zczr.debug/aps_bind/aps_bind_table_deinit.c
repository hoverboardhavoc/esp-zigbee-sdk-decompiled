/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_bind_table_deinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0x974);
  iVar2 = core_globals_get();
  iVar3 = *(int *)(iVar2 + 0x978);
  iVar2 = core_globals_get();
  if (*(short *)(iVar2 + 0x97c) == 0) goto _L0;
  if (iVar1 == 0) goto _L0;
  if (iVar3 == 0) goto _L0;
  iVar1 = core_globals_get();
  mm_free(*(undefined4 *)(iVar1 + 0x974));
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x974) = 0;
  iVar1 = core_globals_get();
  mm_free(*(undefined4 *)(iVar1 + 0x978));
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x978) = 0;
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0x968);
  iVar2 = core_globals_get();
  iVar3 = *(int *)(iVar2 + 0x96c);
  iVar2 = core_globals_get();
  if (*(short *)(iVar2 + 0x970) != 0) goto _L0;
  do {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1b4,
                  "aps_bind_table_deinit",&_LC3);
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1b3,
                  "aps_bind_table_deinit",&_LC3);
_L0:
  } while ((iVar1 == 0) || (iVar3 == 0));
  iVar1 = core_globals_get();
  mm_free(*(undefined4 *)(iVar1 + 0x968));
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x968) = 0;
  iVar1 = core_globals_get();
  mm_free(*(undefined4 *)(iVar1 + 0x96c));
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x96c) = 0;
  return;
}

