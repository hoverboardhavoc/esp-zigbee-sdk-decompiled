/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_init(undefined2 param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x95c);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0x960);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0x964) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_group.c",0xd7,
                  "aps_group_table_init",&_LC3);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0x95c) = 0;
  *(undefined1 *)(iVar3 + 0x95d) = 0;
  *(undefined1 *)(iVar3 + 0x95e) = 0;
  *(undefined1 *)(iVar3 + 0x95f) = 0;
  *(undefined1 *)(iVar3 + 0x960) = 0;
  *(undefined1 *)(iVar3 + 0x961) = 0;
  *(undefined1 *)(iVar3 + 0x962) = 0;
  *(undefined1 *)(iVar3 + 0x963) = 0;
  *(undefined1 *)(iVar3 + 0x964) = 0;
  *(undefined1 *)(iVar3 + 0x965) = 0;
  *(undefined1 *)(iVar3 + 0x966) = 0;
  *(undefined1 *)(iVar3 + 0x967) = 0;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0x964) = param_1;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0x964);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar1,0x22);
  *(undefined4 *)(iVar3 + 0x95c) = uVar5;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0x964);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0x960) = uVar5;
  return;
}

