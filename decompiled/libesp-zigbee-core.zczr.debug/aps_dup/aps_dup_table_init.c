/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_dup_table_init(undefined2 param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x984);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0x988);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0x98c) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_dup.c",0x94,
                  "aps_dup_table_init",&_LC3);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0x984) = 0;
  *(undefined1 *)(iVar3 + 0x985) = 0;
  *(undefined1 *)(iVar3 + 0x986) = 0;
  *(undefined1 *)(iVar3 + 0x987) = 0;
  *(undefined1 *)(iVar3 + 0x988) = 0;
  *(undefined1 *)(iVar3 + 0x989) = 0;
  *(undefined1 *)(iVar3 + 0x98a) = 0;
  *(undefined1 *)(iVar3 + 0x98b) = 0;
  *(undefined1 *)(iVar3 + 0x98c) = 0;
  *(undefined1 *)(iVar3 + 0x98d) = 0;
  *(undefined1 *)(iVar3 + 0x98e) = 0;
  *(undefined1 *)(iVar3 + 0x98f) = 0;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0x98c) = param_1;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0x98c);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar1,4);
  *(undefined4 *)(iVar3 + 0x984) = uVar5;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0x98c);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0x988) = uVar5;
  return;
}

