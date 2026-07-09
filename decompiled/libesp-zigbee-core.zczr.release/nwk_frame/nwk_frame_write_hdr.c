/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_frame.o -> nwk_frame_write_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_frame_write_hdr(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                       int param_6,int param_7)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined2 uStack_44;
  undefined1 uStack_42;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [20];
  
  memset(&uStack_48,0,0x18);
  iVar3 = core_globals_get();
  iVar6 = 0;
  if (*(char *)(iVar3 + 0x9f7) != '\0') {
    iVar6 = nwk_route_record_table_find(param_3);
  }
  iVar3 = 2;
  if (param_1 != 0) {
    uVar2 = param_5 + 8U | param_7 << 6;
    if (param_6 != 0) {
      uStack_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      iVar3 = zmsg_prepend_bytes(param_1,0xe,&uStack_58);
      uVar2 = uVar2 | 0x200;
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((iVar6 != 0) &&
       (bVar1 = *(byte *)(iVar6 + 2), iVar3 = zmsg_get_length(param_1),
       (int)(iVar3 + (bVar1 + 1) * 2) < 0x69)) {
      bVar1 = *(byte *)(iVar6 + 2);
      uStack_58._0_2_ = CONCAT11(bVar1,bVar1);
      iVar3 = zmsg_prepend_bytes(param_1,(uint)bVar1 << 1,iVar6 + 4);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = zmsg_prepend_bytes(param_1,2,&uStack_58);
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar2 = uVar2 | 0x400;
    }
    uStack_46 = (undefined2)param_3;
    uStack_44 = (undefined2)param_2;
    if (param_4 == 0) {
      param_4 = 0x1e;
    }
    uStack_42 = (undefined1)param_4;
    uVar4 = zmsg_get_length(param_1);
    if (uVar4 < 0x59) {
      iVar3 = nwk_address_extended_by_short(param_3,auStack_40);
      puVar5 = auStack_40;
      if (iVar3 == 0) {
        uVar2 = uVar2 | 0x800;
        puVar5 = auStack_38;
      }
      iVar3 = nwk_address_extended_by_short(param_2,puVar5);
      if (iVar3 == 0) {
        uVar2 = uVar2 | 0x1000;
      }
    }
    uVar4 = uVar2 >> 8 & 8;
    uStack_48 = (undefined2)uVar2;
    iVar3 = uVar4 + 8;
    if ((int)(uVar2 << 0x13) < 0) {
      iVar3 = uVar4 + 0x10;
    }
    iVar3 = zmsg_prepend_bytes(param_1,iVar3,&uStack_48);
  }
  return iVar3;
}

