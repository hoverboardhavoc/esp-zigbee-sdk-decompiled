/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void aps_group_table_clear(void)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0x95c);
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0x960);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0x964) != 0) && (iVar2 != 0)) && (iVar4 != 0)) {
    iVar2 = core_globals_get();
    pvVar1 = *(void **)(iVar2 + 0x95c);
    iVar2 = core_globals_get();
    memset(pvVar1,0,(uint)*(ushort *)(iVar2 + 0x964) * 0x22);
    iVar2 = core_globals_get();
    pvVar1 = *(void **)(iVar2 + 0x960);
    iVar2 = core_globals_get();
    memset(pvVar1,0,*(ushort *)(iVar2 + 0x964) + 7 >> 3);
    ds_delete_all_group_info();
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_group.c",0xdc,
                "aps_group_table_clear",&_LC3);
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0x95c);
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0x960);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0x964) != 0) && (iVar2 != 0)) && (iVar4 != 0)) {
    iVar2 = core_globals_get();
    mm_free(*(undefined4 *)(iVar2 + 0x95c));
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0x95c) = 0;
    iVar2 = core_globals_get();
    mm_free(*(undefined4 *)(iVar2 + 0x960));
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0x960) = 0;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_group.c",0xe2,
                "aps_group_table_deinit",&_LC3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

