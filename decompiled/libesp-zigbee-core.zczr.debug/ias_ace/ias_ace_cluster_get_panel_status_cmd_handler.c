/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_panel_status_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ias_ace_cluster_get_panel_status_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uStack_25;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  iStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",400,
                  "ias_ace_cluster_get_panel_status_cmd_handler","packet && rsp");
  }
  else {
    uVar1 = zcl_packet_to_message(&uStack_24,param_1);
    if (uVar1 != 0) goto _L0;
  }
  uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
  iStack_1c = param_1;
  zcl_core_action_schedule(0x22,&uStack_24);
  uVar1 = uStack_18 & 0xff;
  if (uVar1 == 0xfe) {
    uVar1 = 0x8b;
  }
  else if (uVar1 == 0) {
    uStack_25 = uStack_18._1_1_;
    iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_25);
    if (iVar3 == 0) {
      uStack_25 = uStack_18._2_1_;
      iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_25);
      if (iVar3 == 0) {
        uStack_25 = uStack_18._3_1_;
        iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_25);
        if (iVar3 == 0) {
          uStack_25 = (undefined1)uStack_14;
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_25);
          if (iVar3 == 0) {
            uVar1 = zcl_packet_setup_response(param_2,param_1,5);
            if (uVar1 == 0) {
              return 0;
            }
          }
          else {
            uVar1 = 0x89;
          }
        }
        else {
          uVar1 = 0x89;
        }
      }
      else {
        uVar1 = 0x89;
      }
    }
    else {
      uVar1 = 0x89;
    }
  }
_L0:
  uVar2 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar2;
}

