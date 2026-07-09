/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_frame.o -> nwk_frame_write_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_frame_write_hdr(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                       int param_6,int param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  ushort uVar7;
  byte bStack_5c;
  byte bStack_5b;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0x9f7) == '\0') {
    iVar2 = 0;
  }
  else {
    iVar2 = nwk_route_record_table_find(param_3);
  }
  if (param_1 == 0) {
    iVar2 = 2;
  }
  else {
    if (param_5 == 0) {
      uVar7 = 8;
    }
    else {
      uVar7 = 9;
    }
    if (param_7 != 0) {
      uVar7 = uVar7 | 0x40;
    }
    if (param_6 != 0) {
      uVar7 = uVar7 | 0x200;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      iVar3 = zmsg_prepend_bytes(param_1,0xe,&uStack_40);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((iVar2 != 0) &&
       (bVar1 = *(byte *)(iVar2 + 2), iVar3 = zmsg_get_length(param_1),
       (int)((bVar1 + 1) * 2 + iVar3) < 0x69)) {
      bStack_5c = *(byte *)(iVar2 + 2);
      uVar7 = uVar7 | 0x400;
      bStack_5b = bStack_5c;
      iVar2 = zmsg_prepend_bytes(param_1,(uint)bStack_5c << 1,iVar2 + 4);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = zmsg_prepend_bytes(param_1,2,&bStack_5c);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    uStack_58 = CONCAT22((short)param_3,(undefined2)uStack_58);
    if (param_4 == 0) {
      param_4 = 0x1e;
    }
    uStack_54._0_3_ = CONCAT12((char)param_4,(short)param_2);
    uVar4 = zmsg_get_length(param_1);
    if (uVar4 < 0x59) {
      iVar2 = nwk_address_extended_by_short(param_3,&uStack_50);
      if (iVar2 == 0) {
        uVar7 = uVar7 | 0x800;
        puVar6 = &uStack_48;
      }
      else {
        puVar6 = &uStack_50;
      }
      iVar2 = nwk_address_extended_by_short(param_2,puVar6);
      if (iVar2 == 0) {
        uVar7 = uVar7 | 0x1000;
      }
    }
    uStack_58 = CONCAT22(uStack_58._2_2_,uVar7);
    uVar5 = nwk_fcf_get_hdr_size(uVar7);
    iVar2 = zmsg_prepend_bytes(param_1,uVar5,&uStack_58);
  }
  return iVar2;
}

