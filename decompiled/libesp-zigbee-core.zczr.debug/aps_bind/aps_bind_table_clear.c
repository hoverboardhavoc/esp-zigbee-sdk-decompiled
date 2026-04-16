/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_bind_table_clear(void)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x974);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0x978);
  iVar4 = core_globals_get();
  if (*(short *)(iVar4 + 0x97c) == 0) goto _L0;
  if (iVar3 == 0) goto _L0;
  if (iVar6 == 0) goto _L0;
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
  iVar6 = *(int *)(iVar4 + 0x96c);
  iVar4 = core_globals_get();
  if (*(short *)(iVar4 + 0x970) != 0) goto _L0;
  do {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_bind.c",0x1ad,"aps_bind_table_clear",&_LC3);
_L0:
    __assert_func("//build/esp-zigbee/src/core/aps/aps_bind.c",0x1ac,"aps_bind_table_clear",&_LC3);
_L0:
  } while ((iVar3 == 0) || (iVar6 == 0));
  iVar3 = core_globals_get();
  pvVar2 = *(void **)(iVar3 + 0x968);
  iVar3 = core_globals_get();
  uVar1 = *(ushort *)(iVar3 + 0x970);
  sVar5 = bind_src_size();
  memset(pvVar2,0,uVar1 * sVar5);
  iVar3 = core_globals_get();
  pvVar2 = *(void **)(iVar3 + 0x96c);
  iVar3 = core_globals_get();
  memset(pvVar2,0,*(ushort *)(iVar3 + 0x970) + 7 >> 3);
  ds_delete_all_bind_info();
  return;
}

