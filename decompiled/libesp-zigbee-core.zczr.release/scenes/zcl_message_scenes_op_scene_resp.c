/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> zcl_message_scenes_op_scene_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_scenes_op_scene_resp
          (zcl_packet_t *packet,uint8_t status,uint16_t group_id,uint8_t scene_id)

{
  uint uVar1;
  undefined1 auStack_38 [4];
  ezb_zcl_scenes_operate_scene_rsp_message_t message;
  
  memset(auStack_38,0,0x18);
  uVar1 = zcl_packet_to_message(auStack_38,packet);
  if (uVar1 == 0) {
    message.in.scene_id = 0xfe;
    message._4_4_ = packet;
    message.in.header._0_1_ = status;
    message.in.header._2_2_ = group_id;
    message.in.status = scene_id;
    zcl_core_action_schedule(0x11,auStack_38);
    if (message.in.scene_id != 0xfe) {
      uVar1 = (uint)message.in.scene_id;
    }
  }
  return (ezb_zcl_status_t)uVar1;
}

