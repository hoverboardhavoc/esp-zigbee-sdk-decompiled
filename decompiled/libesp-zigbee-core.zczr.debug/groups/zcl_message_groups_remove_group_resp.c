/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> zcl_message_groups_remove_group_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_groups_remove_group_resp(zcl_packet_t *packet,uint8_t status,uint16_t group_id)

{
  uint uVar1;
  undefined4 uStack_34;
  ezb_zcl_groups_remove_group_rsp_message_t message;
  
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.status = '\0';
  message.in._5_1_ = 0;
  message.in.group_id = 0;
  uVar1 = zcl_packet_to_message(&uStack_34,packet);
  if (uVar1 == 0) {
    message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,status);
    message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT22(group_id,message.in.header._0_2_);
    message.in.status = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x10,&uStack_34);
    if ((message.in._4_4_ & 0xff) != 0xfe) {
      uVar1 = message.in._4_4_ & 0xff;
    }
  }
  return (ezb_zcl_status_t)uVar1;
}

