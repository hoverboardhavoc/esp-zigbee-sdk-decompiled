/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_information_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_ace_cluster_get_zone_information_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined4 local_50;
  ezb_zcl_ias_ace_get_zone_info_rsp_message_t message;
  uint64_t address;
  uint16_t auStack_12 [2];
  uint16_t offset;
  
  auStack_12[0] = 0;
  message.out.result = '\0';
  message._45_3_ = 0;
  local_50 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.zone_id = '\0';
  message.in.payload._1_1_ = 0;
  message.in.payload.zone_type = 0;
  message.in.payload.address.field_0.u64._0_4_ = 0;
  message.in.payload.address.field_0.u64._4_4_ = 0;
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
  message.in.payload._29_1_ = 0;
  message.in._34_2_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x225,
                  "ias_ace_cluster_get_zone_information_rsp_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,auStack_12,(uint8_t *)&message.in);
    af_read_le16(packet->payload,auStack_12,(uint16_t *)((int)&message.in.header + 2));
    af_read_le64(packet->payload,auStack_12,(uint64_t *)&message.out);
    message.in.payload.zone_id = message.out.result;
    message.in.payload._1_1_ = message._45_1_;
    message.in.payload.zone_type = message._46_2_;
    message.in.payload.address.field_0.u64._0_4_ = 0;
    eVar1 = read_zcl_string(packet->payload,auStack_12,message.in.payload.address.field_0.u8 + 4,
                            '\x11');
    if (CONCAT31(extraout_var,eVar1) != 0) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < auStack_12[0]) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_packet_to_message(&local_50,packet);
    if (uVar2 == 0) {
      message.in.payload.zone_label[0x10] = 0xfe;
      message._4_4_ = packet;
      zcl_core_action_schedule(0x25,&local_50);
      if ((message.in._32_4_ & 0xff) != 0xfe) {
        uVar2 = message.in._32_4_ & 0xff;
      }
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

