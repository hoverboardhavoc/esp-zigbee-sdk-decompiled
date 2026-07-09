/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_init(undefined2 param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = (undefined2)param_2;
  iVar2 = core_globals_get();
  iVar6 = *(int *)(iVar2 + 0x974);
  iVar2 = core_globals_get();
  iVar5 = *(int *)(iVar2 + 0x978);
  iVar2 = core_globals_get();
  if (*(short *)(iVar2 + 0x97c) == 0) goto _L0;
  if (iVar6 == 0) goto _L0;
  if (iVar5 == 0) goto _L0;
  do {
    uVar4 = (undefined2)param_2;
    __assert_func(0,0,0,0);
_L0:
    iVar2 = core_globals_get();
    memset((void *)(iVar2 + 0x974),0,0xc);
    iVar2 = core_globals_get();
    *(undefined2 *)(iVar2 + 0x97c) = uVar4;
    iVar2 = core_globals_get();
    uVar4 = *(undefined2 *)(iVar2 + 0x97c);
    iVar2 = core_globals_get();
    uVar3 = mm_calloc(uVar4,6);
    *(undefined4 *)(iVar2 + 0x974) = uVar3;
    iVar2 = core_globals_get();
    uVar1 = *(ushort *)(iVar2 + 0x97c);
    iVar2 = core_globals_get();
    uVar3 = mm_calloc(uVar1 + 7 >> 3,1);
    *(undefined4 *)(iVar2 + 0x978) = uVar3;
    iVar2 = core_globals_get();
    iVar5 = *(int *)(iVar2 + 0x968);
    iVar2 = core_globals_get();
    param_2 = *(int *)(iVar2 + 0x96c);
    iVar2 = core_globals_get();
  } while (((*(short *)(iVar2 + 0x970) != 0) && (iVar5 != 0)) && (param_2 != 0));
  iVar2 = core_globals_get();
  memset((void *)(iVar2 + 0x968),0,0xc);
  iVar2 = core_globals_get();
  *(undefined2 *)(iVar2 + 0x970) = param_1;
  iVar2 = core_globals_get();
  uVar4 = *(undefined2 *)(iVar2 + 0x970);
  uVar3 = bind_src_size();
  iVar2 = core_globals_get();
  uVar3 = mm_calloc(uVar4,uVar3);
  *(undefined4 *)(iVar2 + 0x968) = uVar3;
  iVar2 = core_globals_get();
  uVar1 = *(ushort *)(iVar2 + 0x970);
  iVar2 = core_globals_get();
  uVar3 = mm_calloc(uVar1 + 7 >> 3,1);
  *(undefined4 *)(iVar2 + 0x96c) = uVar3;
  return;
}

