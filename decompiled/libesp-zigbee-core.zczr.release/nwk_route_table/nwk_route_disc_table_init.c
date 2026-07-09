/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_disc_table_init(undefined2 param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar6 = *(int *)(iVar3 + 0xc64);
  iVar3 = core_globals_get();
  iVar5 = *(int *)(iVar3 + 0xc68);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xc6c) != 0) && (iVar6 != 0)) && (iVar5 != 0)) {
    __assert_func(0,0,0,0);
  }
  iVar3 = core_globals_get();
  memset((void *)(iVar3 + 0xc64),0,0xc);
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xc6c) = param_1;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0xc6c);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar1,0x10);
  *(undefined4 *)(iVar3 + 0xc64) = uVar4;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0xc6c);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0xc68) = uVar4;
  return;
}

