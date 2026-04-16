/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_bind_table_clear(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  void *pvVar6;
  int unaff_s3;
  
  iVar2 = core_globals_get();
  iVar5 = *(int *)(iVar2 + 0x974);
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0x978);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0x97c) != 0) && (iVar5 != 0)) && (iVar2 != 0)) {
    iVar2 = core_globals_get();
    pvVar6 = *(void **)(iVar2 + 0x974);
    iVar3 = core_globals_get();
    iVar2 = 6;
    memset(pvVar6,0,(uint)*(ushort *)(iVar3 + 0x97c) * 6);
    iVar3 = core_globals_get();
    pvVar6 = *(void **)(iVar3 + 0x978);
    iVar3 = core_globals_get();
    memset(pvVar6,0,*(ushort *)(iVar3 + 0x97c) + 7 >> 3);
    iVar3 = core_globals_get();
    unaff_s3 = *(int *)(iVar3 + 0x968);
    iVar3 = core_globals_get();
    iVar5 = *(int *)(iVar3 + 0x96c);
    iVar3 = core_globals_get();
    if (*(short *)(iVar3 + 0x970) != 0) goto _L0;
  }
  do {
    __assert_func(0,0,0,0);
_L0:
  } while ((unaff_s3 == 0) || (iVar5 == 0));
  iVar3 = core_globals_get();
  pvVar6 = *(void **)(iVar3 + 0x968);
  iVar3 = core_globals_get();
  uVar1 = *(ushort *)(iVar3 + 0x970);
  sVar4 = bind_src_size();
  memset(pvVar6,0,uVar1 * sVar4);
  iVar3 = core_globals_get();
  pvVar6 = *(void **)(iVar3 + 0x96c);
  iVar3 = core_globals_get();
  memset(pvVar6,0,*(ushort *)(iVar3 + 0x970) + 7 >> 3);
  ds_internal_remove_entry(iVar2,0xffffffff,0);
  return;
}

