/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_zone_status_changed_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_ace_cluster_zone_status_changed_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined1 *offset_00;
  undefined4 uStack_3c;
  ezb_zcl_ias_ace_zone_status_changed_message_t message;
  uint16_t offset;
  
  message._38_2_ = 0;
  uStack_3c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.zone_id = '\0';
  message.in.payload._1_1_ = 0;
  message.in.payload.zone_status = 0;
  message.in.payload.aud_notif = '\0';
  message.in.payload.zone_label[0] = '\0';
  message.in.payload.zone_label[1] = '\0';
  message.in.payload.zone_label[2] = '\0';
  message.in.payload.zone_label[3] = '\0';
  message.in.payload.zone_label[4] = '\0';
  message.in.payload.zone_label[5] = '\0';
  message.in.payload.zone_label[6] = '\0';
  message.in.payload.zone_label[7] = '\0';
  message.in.payload.zone_label[8] = '\0';
  message.in.payload.zone_label[9] = '\0';
  message.in.payload.zone_label[10] = '\0';
  message.in.payload.zone_label[0xb] = '\0';
  message.in.payload.zone_label[0xc] = '\0';
  message.in.payload.zone_label[0xd] = '\0';
  message.in.payload.zone_label[0xe] = '\0';
  message.in.payload.zone_label[0xf] = '\0';
  message.in.payload.zone_label[0x10] = '\0';
  message.in._26_2_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x23c,
                  "ias_ace_cluster_zone_status_changed_cmd_handler","packet && rsp");
  }
  else {
    offset_00 = &message.field_0x26;
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)&message.in);
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)((int)&message.in.header + 2));
    af_read_le8(packet->payload,(uint16_t *)offset_00,&message.in.payload.zone_id);
    eVar1 = read_zcl_string(packet->payload,(uint16_t *)offset_00,&message.in.payload.field_0x1,
                            '\x11');
    if (CONCAT31(extraout_var,eVar1) != 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < (ushort)message._38_2_) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_packet_to_message(&uStack_3c,packet);
    if (uVar2 == 0) {
      message.in.payload.zone_label[0xf] = 0xfe;
      message._4_4_ = packet;
      zcl_core_action_schedule(0x26,&uStack_3c);
      if ((message.in._24_4_ & 0xff) != 0xfe) {
        uVar2 = message.in._24_4_ & 0xff;
      }
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

