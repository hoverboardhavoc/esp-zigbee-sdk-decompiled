/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> zcl_message_groups_get_group_membership_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_groups_get_group_membership_resp
          (zcl_packet_t *packet,uint8_t capacity,uint8_t group_count,uint16_t *group_list)

{
  uint uVar1;
  undefined4 uStack_38;
  ezb_zcl_groups_get_group_membership_rsp_message_t message;
  
  uStack_38 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.capacity = '\0';
  message.in.group_count = '\0';
  message.in._6_2_ = 0;
  message.in.group_list = (uint16_t *)0x0;
  uVar1 = zcl_packet_to_message(&uStack_38,packet);
  if (uVar1 == 0) {
    message.in.header._0_2_ = CONCAT11(group_count,capacity);
    message.in.group_list = (uint16_t *)CONCAT31(message.in.group_list._1_3_,0xfe);
    message._4_4_ = packet;
    message.in._4_4_ = group_list;
    zcl_core_action_schedule(0xf,&uStack_38);
    if (((uint)message.in.group_list & 0xff) != 0xfe) {
      uVar1 = (uint)message.in.group_list & 0xff;
    }
  }
  return (ezb_zcl_status_t)uVar1;
}

