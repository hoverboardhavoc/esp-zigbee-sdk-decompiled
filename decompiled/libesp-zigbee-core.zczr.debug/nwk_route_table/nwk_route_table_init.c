/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_table_init(undefined2 param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0xc58);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0xc5c);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0xc60) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",500,
                  "nwk_route_table_init",&_LC9);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xc58) = 0;
  *(undefined1 *)(iVar3 + 0xc59) = 0;
  *(undefined1 *)(iVar3 + 0xc5a) = 0;
  *(undefined1 *)(iVar3 + 0xc5b) = 0;
  *(undefined1 *)(iVar3 + 0xc5c) = 0;
  *(undefined1 *)(iVar3 + 0xc5d) = 0;
  *(undefined1 *)(iVar3 + 0xc5e) = 0;
  *(undefined1 *)(iVar3 + 0xc5f) = 0;
  *(undefined1 *)(iVar3 + 0xc60) = 0;
  *(undefined1 *)(iVar3 + 0xc61) = 0;
  *(undefined1 *)(iVar3 + 0xc62) = 0;
  *(undefined1 *)(iVar3 + 0xc63) = 0;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xc60) = param_1;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0xc60);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar1,0x10);
  *(undefined4 *)(iVar3 + 0xc58) = uVar5;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0xc60);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0xc5c) = uVar5;
  return;
}

