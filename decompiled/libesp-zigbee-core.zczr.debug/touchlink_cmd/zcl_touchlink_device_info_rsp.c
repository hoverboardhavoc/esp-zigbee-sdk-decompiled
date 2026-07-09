/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_device_info_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_touchlink_device_info_rsp(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined2 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_48,0);
    if (iVar1 == 0) {
      local_60 = *param_1;
      uStack_5c = param_1[1];
      uStack_58 = *(undefined2 *)(param_1 + 2);
      iVar1 = zcl_touchlink_cmd_to_packet(&uStack_48,1,3,&local_60);
      if (iVar1 == 0) {
        uStack_2c._0_3_ = CONCAT12(*(undefined1 *)((int)param_1 + 10),(undefined2)uStack_2c);
        uStack_30 = uStack_30 | 0x200000;
        uStack_50 = param_1[3];
        iVar1 = zmsg_append_bytes(uStack_24,4,&uStack_50);
        if (iVar1 == 0) {
          uStack_50 = CONCAT31(uStack_50._1_3_,*(undefined1 *)(param_1 + 4));
          iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_50);
          if (iVar1 == 0) {
            uStack_50 = CONCAT31(uStack_50._1_3_,*(undefined1 *)((int)param_1 + 0x11));
            iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_50);
            if (iVar1 == 0) {
              uStack_50 = CONCAT31(uStack_50._1_3_,*(undefined1 *)((int)param_1 + 0x12));
              iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_50);
              uVar2 = 0;
              if (iVar1 == 0) {
                for (; uVar2 < *(byte *)((int)param_1 + 0x12); uVar2 = uVar2 + 1 & 0xff) {
                  iVar3 = uVar2 * 0x12;
                  uStack_50 = *(undefined4 *)(param_1[5] + iVar3);
                  uStack_4c = ((undefined4 *)(param_1[5] + iVar3))[1];
                  iVar1 = zmsg_append_bytes(uStack_24,8,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT31(uStack_50._1_3_,*(undefined1 *)(param_1[5] + iVar3 + 8));
                  iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT22(uStack_50._2_2_,*(undefined2 *)(param_1[5] + iVar3 + 10));
                  iVar1 = zmsg_append_bytes(uStack_24,2,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT22(uStack_50._2_2_,*(undefined2 *)(param_1[5] + iVar3 + 0xc));
                  iVar1 = zmsg_append_bytes(uStack_24,2,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT31(uStack_50._1_3_,*(undefined1 *)(param_1[5] + iVar3 + 0xe));
                  iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT31(uStack_50._1_3_,*(undefined1 *)(param_1[5] + iVar3 + 0xf));
                  iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT31(uStack_50._1_3_,*(undefined1 *)(param_1[5] + iVar3 + 0x10));
                  iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                }
                zcl_packet_intrp_send(&uStack_48,param_1 + 6);
                iVar1 = zcl_status_to_err();
_L0:
                if (iVar1 == 0) {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  zcl_packet_free(&uStack_48);
  return iVar1;
}

