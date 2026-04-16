/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_get_scene_membership_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
scenes_cluster_get_scene_membership_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t uVar1;
  ezb_zcl_status_t eVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *offset_00;
  undefined4 local_40;
  ezb_zcl_scenes_get_scene_membership_rsp_message_t message;
  uint16_t offset;
  
  message._26_2_ = 0;
  local_40 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.status = '\0';
  message.in.capacity = '\0';
  message.in.group_id = 0;
  message.in.scene_count = '\0';
  message.in._9_3_ = 0;
  message.in.scene_list = (uint8_t *)0x0;
  uVar3 = zcl_packet_to_message(&local_40,packet);
  if (uVar3 == 0) {
    uVar4 = zmsg_get_length(packet->payload);
    offset_00 = &message.field_0x1a;
    message._4_4_ = packet;
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)&message.in);
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)((int)&message.in.header + 1));
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)((int)&message.in.header + 2));
    if (((char)message.in.header == '\0') && ((ushort)message._26_2_ < uVar4)) {
      af_read_le8(packet->payload,(uint16_t *)offset_00,&message.in.status);
      uVar1 = message.in.status;
      if ((message.in._4_4_ & 0xff) != 0) {
        message.in._8_4_ = calloc(message.in._4_4_ & 0xff,1);
        if ((uint8_t *)message.in._8_4_ == (uint8_t *)0x0) {
          uVar3 = 0x89;
          goto _L0;
        }
        af_read_bytes(packet->payload,(uint16_t *)&message.field_0x1a,(ushort)uVar1,
                      (uint8_t *)message.in._8_4_);
      }
    }
    if (uVar4 < (ushort)message._26_2_) {
      uVar3 = 0x80;
    }
    else {
      message.in.scene_list = (uint8_t *)CONCAT31(message.in.scene_list._1_3_,0xfe);
      zcl_core_action_schedule(0x13,&local_40);
      if (((uint)message.in.scene_list & 0xff) != 0xfe) {
        uVar3 = (uint)message.in.scene_list & 0xff;
      }
    }
  }
_L0:
  if (message.in._8_4_ != 0) {
    mm_free();
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar2;
}

