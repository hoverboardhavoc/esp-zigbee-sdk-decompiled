/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_clear(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int unaff_s3;
  
  iVar2 = core_globals_get();
  iVar4 = *(int *)(iVar2 + 0x974);
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0x978);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0x97c) != 0) && (iVar4 != 0)) && (iVar2 != 0)) {
    iVar2 = core_globals_get();
    pvVar5 = *(void **)(iVar2 + 0x974);
    iVar3 = core_globals_get();
    iVar2 = 6;
    memset(pvVar5,0,(uint)*(ushort *)(iVar3 + 0x97c) * 6);
    iVar3 = core_globals_get();
    pvVar5 = *(void **)(iVar3 + 0x978);
    iVar3 = core_globals_get();
    memset(pvVar5,0,*(ushort *)(iVar3 + 0x97c) + 7 >> 3);
    iVar3 = core_globals_get();
    unaff_s3 = *(int *)(iVar3 + 0x968);
    iVar3 = core_globals_get();
    iVar4 = *(int *)(iVar3 + 0x96c);
    iVar3 = core_globals_get();
    if (*(short *)(iVar3 + 0x970) != 0) goto _L0;
  }
  do {
    __assert_func(0,0,0,0);
_L0:
  } while ((unaff_s3 == 0) || (iVar4 == 0));
  iVar3 = core_globals_get();
  pvVar5 = *(void **)(iVar3 + 0x968);
  iVar3 = core_globals_get();
  uVar1 = *(ushort *)(iVar3 + 0x970);
  iVar3 = bind_src_size();
  memset(pvVar5,0,(uint)uVar1 * iVar3);
  iVar3 = core_globals_get();
  pvVar5 = *(void **)(iVar3 + 0x96c);
  iVar3 = core_globals_get();
  memset(pvVar5,0,*(ushort *)(iVar3 + 0x970) + 7 >> 3);
  ds_internal_remove_entry(iVar2,0xffffffff,0);
  return;
}

