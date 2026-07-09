/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_panel_status_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_ace_cluster_get_panel_status_rsp_handler(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  iStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x267,
                  "ias_ace_cluster_get_panel_status_rsp_handler","packet && rsp");
  }
  else {
    iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_1c);
    if (iVar1 == 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_1c + 1);
  if (iVar1 == 0) {
    uVar2 = 0x80;
  }
  else {
    iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_1c + 2);
    if (iVar1 == 0) {
      uVar2 = 0x80;
    }
    else {
      iVar1 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_1c + 3);
      if (iVar1 == 0) {
        uVar2 = 0x80;
      }
      else {
        uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar2 < uStack_12) {
          uVar2 = 0x80;
        }
        else {
          uVar2 = zcl_packet_to_message(&uStack_28,param_1);
          if (uVar2 == 0) {
            uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
            iStack_20 = param_1;
            zcl_core_action_schedule(0x29,&uStack_28);
            if ((uStack_18 & 0xff) != 0xfe) {
              uVar2 = uStack_18 & 0xff;
            }
          }
        }
      }
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

