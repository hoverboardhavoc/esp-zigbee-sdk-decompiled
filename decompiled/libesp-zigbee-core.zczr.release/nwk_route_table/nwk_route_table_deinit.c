/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_table_deinit(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar6 = *(int *)(iVar3 + 0xc58);
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0xc5c);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0xc60) != 0) && (iVar6 != 0)) && (iVar3 != 0)) {
    iVar3 = core_globals_get();
    mm_free(*(undefined4 *)(iVar3 + 0xc58));
    iVar3 = core_globals_get();
    *(undefined4 *)(iVar3 + 0xc58) = 0;
    iVar3 = core_globals_get();
    mm_free(*(undefined4 *)(iVar3 + 0xc5c));
    iVar3 = core_globals_get();
    *(undefined4 *)(iVar3 + 0xc5c) = 0;
    return;
  }
  uVar2 = __assert_func(0,0,0,0);
  iVar3 = core_globals_get();
  iVar6 = *(int *)(iVar3 + 0xc64);
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0xc68);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xc6c) != 0) && (iVar6 != 0)) && (iVar4 != 0)) {
    __assert_func(0,0,0,0);
  }
  iVar3 = core_globals_get();
  memset((void *)(iVar3 + 0xc64),0,0xc);
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xc6c) = uVar2;
  iVar3 = core_globals_get();
  uVar2 = *(undefined2 *)(iVar3 + 0xc6c);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar2,0x10);
  *(undefined4 *)(iVar3 + 0xc64) = uVar5;
  iVar3 = core_globals_get();
  uVar1 = *(ushort *)(iVar3 + 0xc6c);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar1 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0xc68) = uVar5;
  return;
}

