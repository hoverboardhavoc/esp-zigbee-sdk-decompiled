/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_table_init(uint8_t src_capacity,uint8_t dst_capacity)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined3 in_register_00002029;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  undefined3 in_register_0000202d;
  int iVar6;
  int iVar7;
  
  iVar3 = core_globals_get();
  iVar6 = *(int *)(iVar3 + 0x974);
  iVar3 = core_globals_get();
  iVar7 = *(int *)(iVar3 + 0x978);
  iVar3 = core_globals_get();
  if (((*(short *)(iVar3 + 0x97c) != 0) && (iVar6 != 0)) && (iVar7 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1a6,
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
  *(short *)(iVar3 + 0x97c) = (short)CONCAT31(in_register_0000202d,dst_capacity);
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
  iVar6 = core_globals_get();
  iVar7 = *(int *)(iVar6 + 0x96c);
  iVar6 = core_globals_get();
  if (((*(short *)(iVar6 + 0x970) != 0) && (iVar3 != 0)) && (iVar7 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x1a7,
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
  *(short *)(iVar3 + 0x970) = (short)CONCAT31(in_register_00002029,src_capacity);
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0x970);
  sVar5 = bind_src_size();
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar1,sVar5);
  *(undefined4 *)(iVar3 + 0x968) = uVar4;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0x970);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0x96c) = uVar4;
  return;
}

