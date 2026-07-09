/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_record_table_init(undefined2 param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0xc70);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0xc74);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0xc78) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x212,
                  "nwk_route_record_table_init",&_LC9);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xc70) = 0;
  *(undefined1 *)(iVar3 + 0xc71) = 0;
  *(undefined1 *)(iVar3 + 0xc72) = 0;
  *(undefined1 *)(iVar3 + 0xc73) = 0;
  *(undefined1 *)(iVar3 + 0xc74) = 0;
  *(undefined1 *)(iVar3 + 0xc75) = 0;
  *(undefined1 *)(iVar3 + 0xc76) = 0;
  *(undefined1 *)(iVar3 + 0xc77) = 0;
  *(undefined1 *)(iVar3 + 0xc78) = 0;
  *(undefined1 *)(iVar3 + 0xc79) = 0;
  *(undefined1 *)(iVar3 + 0xc7a) = 0;
  *(undefined1 *)(iVar3 + 0xc7b) = 0;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0xc78) = param_1;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0xc78);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar1,0x1c);
  *(undefined4 *)(iVar3 + 0xc70) = uVar5;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0xc78);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0xc74) = uVar5;
  return;
}

