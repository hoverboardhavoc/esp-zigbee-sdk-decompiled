/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_table_clear(void)

{
  ushort uVar1;
  void *pvVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar4 = core_globals_get();
  iVar7 = *(int *)(iVar4 + 0xc58);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xc5c);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0xc60) != 0) && (iVar7 != 0)) && (iVar4 != 0)) {
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0xc58);
    iVar4 = core_globals_get();
    memset(pvVar2,0,(uint)*(ushort *)(iVar4 + 0xc60) << 4);
    iVar4 = core_globals_get();
    pvVar2 = *(void **)(iVar4 + 0xc5c);
    iVar4 = core_globals_get();
    memset(pvVar2,0,*(ushort *)(iVar4 + 0xc60) + 7 >> 3);
    return;
  }
  __assert_func(0,0,0,0);
  iVar4 = core_globals_get();
  iVar7 = *(int *)(iVar4 + 0xc58);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xc5c);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0xc60) != 0) && (iVar7 != 0)) && (iVar4 != 0)) {
    iVar4 = core_globals_get();
    mm_free(*(undefined4 *)(iVar4 + 0xc58));
    iVar4 = core_globals_get();
    *(undefined4 *)(iVar4 + 0xc58) = 0;
    iVar4 = core_globals_get();
    mm_free(*(undefined4 *)(iVar4 + 0xc5c));
    iVar4 = core_globals_get();
    *(undefined4 *)(iVar4 + 0xc5c) = 0;
    return;
  }
  uVar3 = __assert_func(0,0,0,0);
  iVar4 = core_globals_get();
  iVar7 = *(int *)(iVar4 + 0xc64);
  iVar4 = core_globals_get();
  iVar5 = *(int *)(iVar4 + 0xc68);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0xc6c) != 0) && (iVar7 != 0)) && (iVar5 != 0)) {
    __assert_func(0,0,0,0);
  }
  iVar4 = core_globals_get();
  memset((void *)(iVar4 + 0xc64),0,0xc);
  iVar4 = core_globals_get();
  *(undefined2 *)(iVar4 + 0xc6c) = uVar3;
  iVar4 = core_globals_get();
  uVar3 = *(undefined2 *)(iVar4 + 0xc6c);
  iVar4 = core_globals_get();
  uVar6 = mm_calloc(uVar3,0x10);
  *(undefined4 *)(iVar4 + 0xc64) = uVar6;
  iVar4 = core_globals_get();
  uVar1 = *(ushort *)(iVar4 + 0xc6c);
  iVar4 = core_globals_get();
  uVar6 = mm_calloc(uVar1 + 7 >> 3,1);
  *(undefined4 *)(iVar4 + 0xc68) = uVar6;
  return;
}

