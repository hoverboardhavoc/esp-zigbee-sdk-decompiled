/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_table_init(uint8_t src_capacity,uint8_t dst_capacity)

{
  ushort uVar1;
  undefined3 in_register_00002029;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  undefined2 uVar6;
  undefined3 in_register_0000202d;
  int iVar7;
  int iVar8;
  
  iVar3 = CONCAT31(in_register_0000202d,dst_capacity);
  uVar6 = (undefined2)iVar3;
  iVar2 = core_globals_get();
  iVar8 = *(int *)(iVar2 + 0x974);
  iVar2 = core_globals_get();
  iVar7 = *(int *)(iVar2 + 0x978);
  iVar2 = core_globals_get();
  if (*(short *)(iVar2 + 0x97c) == 0) goto _L0;
  if (iVar8 == 0) goto _L0;
  if (iVar7 == 0) goto _L0;
  do {
    uVar6 = (undefined2)iVar3;
    __assert_func(0,0,0,0);
_L0:
    iVar3 = core_globals_get();
    memset((void *)(iVar3 + 0x974),0,0xc);
    iVar3 = core_globals_get();
    *(undefined2 *)(iVar3 + 0x97c) = uVar6;
    iVar3 = core_globals_get();
    uVar6 = *(undefined2 *)(iVar3 + 0x97c);
    iVar3 = core_globals_get();
    uVar4 = mm_calloc(uVar6,6);
    *(undefined4 *)(iVar3 + 0x974) = uVar4;
    iVar3 = core_globals_get();
    uVar1 = *(ushort *)(iVar3 + 0x97c);
    iVar3 = core_globals_get();
    uVar4 = mm_calloc(uVar1 + 7 >> 3,1);
    *(undefined4 *)(iVar3 + 0x978) = uVar4;
    iVar3 = core_globals_get();
    iVar7 = *(int *)(iVar3 + 0x968);
    iVar3 = core_globals_get();
    iVar3 = *(int *)(iVar3 + 0x96c);
    iVar2 = core_globals_get();
  } while (((*(short *)(iVar2 + 0x970) != 0) && (iVar7 != 0)) && (iVar3 != 0));
  iVar3 = core_globals_get();
  memset((void *)(iVar3 + 0x968),0,0xc);
  iVar3 = core_globals_get();
  *(short *)(iVar3 + 0x970) = (short)CONCAT31(in_register_00002029,src_capacity);
  iVar3 = core_globals_get();
  uVar6 = *(undefined2 *)(iVar3 + 0x970);
  sVar5 = bind_src_size();
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar6,sVar5);
  *(undefined4 *)(iVar3 + 0x968) = uVar4;
  iVar3 = core_globals_get();
  uVar1 = *(ushort *)(iVar3 + 0x970);
  iVar3 = core_globals_get();
  uVar4 = mm_calloc(uVar1 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0x96c) = uVar4;
  return;
}

