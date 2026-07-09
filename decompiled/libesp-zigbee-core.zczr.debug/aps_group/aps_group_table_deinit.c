/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void aps_group_table_deinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0x95c);
  iVar2 = core_globals_get();
  iVar3 = *(int *)(iVar2 + 0x960);
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0x964) != 0) && (iVar1 != 0)) && (iVar3 != 0)) {
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0x95c));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x95c) = 0;
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0x960));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x960) = 0;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_group.c",0xe2,
                "aps_group_table_deinit",&_LC3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

