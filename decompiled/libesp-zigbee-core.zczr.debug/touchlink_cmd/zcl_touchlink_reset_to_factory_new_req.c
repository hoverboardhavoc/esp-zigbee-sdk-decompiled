/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_reset_to_factory_new_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_touchlink_reset_to_factory_new_req(undefined4 *param_1)

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
      iVar1 = zcl_touchlink_cmd_to_packet(&uStack_38,0,7,&local_50);
      if (iVar1 == 0) {
        uStack_3c = param_1[3];
        iVar1 = zmsg_append_bytes(uStack_14,4,&uStack_3c);
        if (iVar1 == 0) {
          zcl_packet_intrp_send(&uStack_38,param_1 + 4);
          iVar1 = zcl_status_to_err();
          if (iVar1 == 0) {
            return 0;
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

