/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_init(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar5 = *(int *)(iVar3 + 0x974);
  iVar3 = core_globals_get();
  iVar6 = *(int *)(iVar3 + 0x978);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0x97c) != 0) && (iVar5 != 0)) && (iVar6 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1b3,
                  "aps_bind_table_init",&_LC3);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0x974) = 0;
  *(undefined1 *)(iVar3 + 0x975) = 0;
  *(undefined1 *)(iVar3 + 0x976) = 0;
  *(undefined1 *)(iVar3 + 0x977) = 0;
  *(undefined1 *)(iVar3 + 0x978) = 0;
  *(undefined1 *)(iVar3 + 0x979) = 0;
  *(undefined1 *)(iVar3 + 0x97a) = 0;
  *(undefined1 *)(iVar3 + 0x97b) = 0;
  *(undefined1 *)(iVar3 + 0x97c) = 0;
  *(undefined1 *)(iVar3 + 0x97d) = 0;
  *(undefined1 *)(iVar3 + 0x97e) = 0;
  *(undefined1 *)(iVar3 + 0x97f) = 0;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0x97c) = param_2;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0x97c);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar1,6);
  *(undefined4 *)(iVar3 + 0x974) = uVar4;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0x97c);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0x978) = uVar4;
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x968);
  iVar5 = core_globals_get();
  iVar6 = *(int *)(iVar5 + 0x96c);
  iVar5 = core_globals_get();
  if (((*(short *)(iVar5 + 0x970) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1b4,
                  "aps_bind_table_init",&_LC3);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0x968) = 0;
  *(undefined1 *)(iVar3 + 0x969) = 0;
  *(undefined1 *)(iVar3 + 0x96a) = 0;
  *(undefined1 *)(iVar3 + 0x96b) = 0;
  *(undefined1 *)(iVar3 + 0x96c) = 0;
  *(undefined1 *)(iVar3 + 0x96d) = 0;
  *(undefined1 *)(iVar3 + 0x96e) = 0;
  *(undefined1 *)(iVar3 + 0x96f) = 0;
  *(undefined1 *)(iVar3 + 0x970) = 0;
  *(undefined1 *)(iVar3 + 0x971) = 0;
  *(undefined1 *)(iVar3 + 0x972) = 0;
  *(undefined1 *)(iVar3 + 0x973) = 0;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0x970) = param_1;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0x970);
  uVar4 = bind_src_size();
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar1,uVar4);
  *(undefined4 *)(iVar3 + 0x968) = uVar4;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0x970);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0x96c) = uVar4;
  return;
}

