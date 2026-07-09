/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_id_map_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_ace_cluster_get_zone_id_map_rsp_handler(int param_1,int param_2)

{
  int unaff_s0;
  uint uVar1;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined2 uStack_12;
  
  uStack_12 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  iStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < 0x20) {
      uVar1 = 0x80;
    }
    else {
      for (unaff_s0 = 0; unaff_s0 < 0x10; unaff_s0 = unaff_s0 + 1) {
_L0:
        af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_38 + unaff_s0 * 2);
      }
      uVar1 = zcl_packet_to_message(&uStack_44,param_1);
      if (uVar1 == 0) {
        uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
        iStack_3c = param_1;
        zcl_core_action_schedule(0x25,&uStack_44);
        if ((uStack_18 & 0xff) != 0xfe) {
          uVar1 = uStack_18 & 0xff;
        }
      }
    }
    zcl_packet_setup_default_response(param_2,param_1,uVar1);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x210,
                "ias_ace_cluster_get_zone_id_map_rsp_handler","packet && rsp");
  goto _L0;
}

