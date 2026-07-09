/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> ezb_zcl_touchlink_ep_info_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_touchlink_ep_info_cmd_req(int param_1)

{
  int iVar1;
  uint uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    iVar1 = 2;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_38,0);
    if (iVar1 == 0) {
      iVar1 = zcl_cmd_to_packet(&uStack_38,0,1,*(undefined1 *)(param_1 + 0xc),0,0x40,0x1000);
      if (iVar1 == 0) {
        uStack_40 = *(uint *)(param_1 + 0x18);
        uStack_3c = *(undefined4 *)(param_1 + 0x1c);
        iVar1 = zmsg_append_bytes(uStack_14,8,&uStack_40);
        if (iVar1 == 0) {
          uStack_40 = CONCAT22(uStack_40._2_2_,*(undefined2 *)(param_1 + 0x20));
          iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_40);
          if (iVar1 == 0) {
            uStack_40 = CONCAT31(uStack_40._1_3_,*(undefined1 *)(param_1 + 0x22));
            iVar1 = zmsg_append_bytes(uStack_14,1,&uStack_40);
            if (iVar1 == 0) {
              uStack_40 = CONCAT22(uStack_40._2_2_,*(undefined2 *)(param_1 + 0x24));
              iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_40);
              if (iVar1 == 0) {
                uStack_40 = CONCAT22(uStack_40._2_2_,*(undefined2 *)(param_1 + 0x26));
                iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_40);
                if (iVar1 == 0) {
                  uStack_40 = CONCAT31(uStack_40._1_3_,*(undefined1 *)(param_1 + 0x28)) & 0xffffff0f
                  ;
                  iVar1 = zmsg_append_bytes(uStack_14,1,&uStack_40);
                  if (iVar1 == 0) {
                    zcl_packet_send(&uStack_38,param_1 + 0x10);
                    iVar1 = zcl_status_to_err();
                    if (iVar1 == 0) {
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar1 = 2;
    }
  }
  zcl_packet_free(&uStack_38);
  return iVar1;
}

