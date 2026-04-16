/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> zcl_message_scenes_recall_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_scenes_recall_scene
          (zcl_packet_t *packet,uint16_t transition_time,zcl_scene_table_entry_t *entry)

{
  undefined3 uVar1;
  uint uVar2;
  undefined4 uStack_3c;
  ezb_zcl_scenes_recall_scene_message_t message;
  
  uStack_3c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.group_id = 0;
  message.in.scene_id = '\0';
  message.in._7_1_ = 0;
  message.in.transition_time = 0;
  message.in._10_2_ = 0;
  message.in.field_set = (ezb_zcl_scenes_extension_field_t *)0x0;
  if (entry == (zcl_scene_table_entry_t *)0x0) {
    uVar2 = 0x87;
  }
  else {
    uVar2 = zcl_packet_to_message(&uStack_3c,packet);
    if (uVar2 == 0) {
      uVar1._0_2_ = entry->group_id;
      uVar1._2_1_ = entry->scene_id;
      message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT13(message.in.header._3_1_,uVar1);
      message.in.group_id = transition_time;
      message.in._8_4_ = entry->extension_field;
      message.in.field_set =
           (ezb_zcl_scenes_extension_field_t *)CONCAT31(message.in.field_set._1_3_,0xfe);
      message._4_4_ = packet;
      zcl_core_action_schedule(0x15,&uStack_3c);
      if (((uint)message.in.field_set & 0xff) != 0xfe) {
        uVar2 = (uint)message.in.field_set & 0xff;
      }
    }
  }
  return (ezb_zcl_status_t)uVar2;
}

