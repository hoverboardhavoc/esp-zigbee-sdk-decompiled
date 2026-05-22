/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_table_init(uint16_t capacity)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar6 = *(int *)(iVar3 + 0xc58);
  iVar3 = core_globals_get();
  iVar5 = *(int *)(iVar3 + 0xc5c);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0xc60) != 0) && (iVar6 != 0)) && (iVar5 != 0)) {
    __assert_func(0,0,0,0);
  }
  iVar3 = core_globals_get();
  memset((void *)(iVar3 + 0xc58),0,0xc);
  iVar3 = core_globals_get();
  *(uint16_t *)(iVar3 + 0xc60) = capacity;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0xc60);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar1,0x10);
  *(undefined4 *)(iVar3 + 0xc58) = uVar4;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0xc60);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0xc5c) = uVar4;
  return;
}

