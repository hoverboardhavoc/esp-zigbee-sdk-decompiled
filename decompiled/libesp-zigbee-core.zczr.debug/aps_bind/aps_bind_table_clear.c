/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_clear(void)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x974);
  iVar4 = core_globals_get();
  iVar5 = *(int *)(iVar4 + 0x978);
  iVar4 = core_globals_get();
  if (*(short *)(iVar4 + 0x97c) == 0) goto _L0;
  if (iVar3 == 0) goto _L0;
  if (iVar5 == 0) goto _L0;
  iVar3 = core_globals_get();
  pvVar2 = *(void **)(iVar3 + 0x974);
  iVar3 = core_globals_get();
  memset(pvVar2,0,(uint)*(ushort *)(iVar3 + 0x97c) * 6);
  iVar3 = core_globals_get();
  pvVar2 = *(void **)(iVar3 + 0x978);
  iVar3 = core_globals_get();
  memset(pvVar2,0,*(ushort *)(iVar3 + 0x97c) + 7 >> 3);
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x968);
  iVar4 = core_globals_get();
  iVar5 = *(int *)(iVar4 + 0x96c);
  iVar4 = core_globals_get();
  if (*(short *)(iVar4 + 0x970) != 0) goto _L0;
  do {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1ba,
                  "aps_bind_table_clear",&_LC3);
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1b9,
                  "aps_bind_table_clear",&_LC3);
_L0:
  } while ((iVar3 == 0) || (iVar5 == 0));
  iVar3 = core_globals_get();
  pvVar2 = *(void **)(iVar3 + 0x968);
  iVar3 = core_globals_get();
  uVar1 = *(ushort *)(iVar3 + 0x970);
  iVar3 = bind_src_size();
  memset(pvVar2,0,(uint)uVar1 * iVar3);
  iVar3 = core_globals_get();
  pvVar2 = *(void **)(iVar3 + 0x96c);
  iVar3 = core_globals_get();
  memset(pvVar2,0,*(ushort *)(iVar3 + 0x970) + 7 >> 3);
  ds_delete_all_bind_info();
  return;
}

