/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> window_covering.o -> window_covering_cluster_movement_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void window_covering_cluster_movement_cmd_handler(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  ushort uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  iStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_26 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/window_covering.c"
                          ,0xab,"window_covering_cluster_movement_cmd_handler","packet && rsp");
_L0:
    if (param_3 < 3) {
      sVar3 = 0;
    }
    else {
      if (param_3 != 4) {
        iVar2 = 0x81;
        goto _L0;
      }
      af_read_le16(*(undefined4 *)(iVar2 + 0x24),&uStack_26,&uStack_18);
      sVar3 = 3;
    }
  }
  else {
    param_3 = (uint)*(byte *)(param_1 + 0x20);
    iStack_1c = param_1;
    if (param_3 == 5) {
      af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_26,&uStack_18);
      sVar3 = 8;
    }
    else {
      iVar2 = param_1;
      if (param_3 < 6) goto _L0;
      if (param_3 == 7) {
        af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_26,&uStack_18);
        sVar3 = 4;
      }
      else {
        if (param_3 != 8) {
          iVar2 = 0x81;
          goto _L0;
        }
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_26,&uStack_18);
        sVar3 = 9;
      }
    }
  }
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar1 < uStack_26) {
    iVar2 = 0x80;
  }
  else if (((((1 < (ushort)(sVar3 - 3U)) && (sVar3 != 8)) && (sVar3 != 9)) ||
           (iVar2 = window_covering_srv_set_attr_value
                              (*(undefined1 *)(param_1 + 0x15),sVar3,&uStack_18), iVar2 == 0)) &&
          (iVar2 = zcl_packet_to_message(&uStack_24,param_1), iVar2 == 0)) {
    uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
    zcl_core_action_schedule(0x1b,&uStack_24);
    if ((uStack_14 & 0xff) != 0xfe) {
      if ((uStack_14 & 0xff) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,iVar2);
  return;
}

