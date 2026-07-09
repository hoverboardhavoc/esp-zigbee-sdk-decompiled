/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_network_join_router_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_touchlink_network_join_router_req(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
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
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_38,0);
    if (iVar1 == 0) {
      local_50 = *param_1;
      uStack_4c = param_1[1];
      uStack_48 = *(undefined2 *)(param_1 + 2);
      iVar1 = zcl_touchlink_cmd_to_packet(&uStack_38,0,0x12,&local_50);
      if (iVar1 == 0) {
        uStack_3c = param_1[3];
        iVar1 = zmsg_append_bytes(uStack_14,4,&uStack_3c);
        if ((iVar1 == 0) && (iVar1 = zmsg_append_bytes(uStack_14,8,param_1 + 4), iVar1 == 0)) {
          uStack_3c = CONCAT31(uStack_3c._1_3_,*(undefined1 *)(param_1 + 6));
          iVar1 = zmsg_append_bytes(uStack_14,1,&uStack_3c);
          if ((iVar1 == 0) &&
             (iVar1 = zmsg_append_bytes(uStack_14,0x10,(int)param_1 + 0x19), iVar1 == 0)) {
            uStack_3c = CONCAT31(uStack_3c._1_3_,*(undefined1 *)((int)param_1 + 0x29));
            iVar1 = zmsg_append_bytes(uStack_14,1,&uStack_3c);
            if (iVar1 == 0) {
              uStack_3c = CONCAT31(uStack_3c._1_3_,*(undefined1 *)((int)param_1 + 0x2a));
              iVar1 = zmsg_append_bytes(uStack_14,1,&uStack_3c);
              if (iVar1 == 0) {
                uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)(param_1 + 0xb));
                iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
                if (iVar1 == 0) {
                  uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)((int)param_1 + 0x2e));
                  iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
                  if (iVar1 == 0) {
                    uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)(param_1 + 0xc));
                    iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
                    if (iVar1 == 0) {
                      uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)((int)param_1 + 0x32));
                      iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
                      if (iVar1 == 0) {
                        uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)(param_1 + 0xd));
                        iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
                        if (iVar1 == 0) {
                          uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)((int)param_1 + 0x36))
                          ;
                          iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
                          if (iVar1 == 0) {
                            uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)(param_1 + 0xe));
                            iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
                            if (iVar1 == 0) {
                              uStack_3c = CONCAT22(uStack_3c._2_2_,
                                                   *(undefined2 *)((int)param_1 + 0x3a));
                              iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3c);
                              if (iVar1 == 0) {
                                zcl_packet_intrp_send(&uStack_38,param_1 + 0xf);
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
  zcl_packet_free(&uStack_38);
  return iVar1;
}

