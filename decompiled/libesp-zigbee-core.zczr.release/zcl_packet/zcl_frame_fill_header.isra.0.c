/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_frame_fill_header.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_frame_fill_header_isra_0(int param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined4 uStack_18;
  byte bStack_14;
  
  uStack_18 = 0;
  bStack_14 = 0;
  iVar5 = (-(uint)((*(byte *)(param_1 + 0x1a) & 4) == 0) & 0xfffffffe) + 5;
  if ((*(byte *)(param_1 + 0x1a) & 0x20) == 0) {
    iVar4 = core_globals_get();
    cVar1 = *(char *)(iVar4 + 0xd14);
    *(char *)(iVar4 + 0xd14) = cVar1 + '\x01';
    *(char *)(param_1 + 0x1e) = cVar1;
  }
  bVar2 = *(byte *)(param_1 + 0x1a);
  uVar6 = *(undefined1 *)(param_1 + 0x1e);
  *(byte *)(param_1 + 0x1a) = bVar2 & 0xdf;
  uStack_18 = CONCAT31(uStack_18._1_3_,bVar2) & 0xffffffdf;
  uVar7 = (uint)*(byte *)(param_1 + 0x20);
  if ((bVar2 & 4) == 0) goto _L0;
  uStack_18._0_2_ = CONCAT11((char)*(undefined2 *)(param_1 + 0x1c),(undefined1)uStack_18);
  uStack_18._0_3_ =
       CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0x1c) >> 8),(undefined2)uStack_18);
  uStack_18 = CONCAT13(uVar6,(undefined3)uStack_18);
  bStack_14 = *(byte *)(param_1 + 0x20);
  while (iVar5 = zmsg_prepend_bytes(*(undefined4 *)(param_1 + 0x24),iVar5,&uStack_18), iVar5 != 0) {
    uVar6 = 0;
    iVar5 = __assert_func(0,0,0);
_L0:
    uVar3 = uStack_18;
    uStack_18._0_2_ = CONCAT11(uVar6,(undefined1)uStack_18);
    uStack_18._3_1_ = SUB41(uVar3,3);
    uStack_18._0_3_ = CONCAT12((char)uVar7,(undefined2)uStack_18);
  }
  return;
}

