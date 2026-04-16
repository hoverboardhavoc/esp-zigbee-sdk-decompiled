/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_get_meas_prof_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
electrical_measurement_cluster_get_meas_prof_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ushort length;
  undefined1 *offset_00;
  ezb_zcl_status_t eVar1;
  short sVar2;
  uint uVar3;
  undefined4 uStack_34;
  ezb_zcl_electrical_measurement_get_meas_prof_rsp_message_t message;
  uint16_t offset;
  
  message._30_2_ = 0;
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.start_time = 0;
  message.in.payload.status = '\0';
  message.in.payload.prof_interval_period = '\0';
  message.in.payload.num_of_intervals_delivered = '\0';
  message.in.payload._7_1_ = 0;
  message.in.payload.attr_id = 0;
  message.in.payload._10_2_ = 0;
  message.in.payload.intervals = (uint8_t *)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement.c",0xc6,
                  "electrical_measurement_cluster_get_meas_prof_rsp_handler","packet && rsp");
  }
  else {
    offset_00 = &message.field_0x1e;
    af_read_le32(packet->payload,(uint16_t *)offset_00,(uint32_t *)&message.in);
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)&message.in.payload);
    af_read_le8(packet->payload,(uint16_t *)offset_00,
                (uint8_t *)((int)&message.in.payload.start_time + 1));
    af_read_le8(packet->payload,(uint16_t *)offset_00,
                (uint8_t *)((int)&message.in.payload.start_time + 2));
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)&message.in.payload.status);
    uVar3 = zmsg_get_length(packet->payload);
    if ((ushort)message._30_2_ <= uVar3) {
      if ((message.in.payload.start_time >> 0x10 & 0xff) != 0) {
        sVar2 = zmsg_get_length(packet->payload);
        length = sVar2 - message._30_2_;
        message.in.payload._8_4_ = calloc((uint)length,1);
        if ((uint8_t *)message.in.payload._8_4_ == (uint8_t *)0x0) {
          uVar3 = 0x89;
          goto _L0;
        }
        af_read_bytes(packet->payload,(uint16_t *)&message.field_0x1e,length,
                      (uint8_t *)message.in.payload._8_4_);
      }
      uVar3 = zcl_packet_to_message(&uStack_34,packet);
      if (uVar3 == 0) {
        message.in.payload.intervals = (uint8_t *)CONCAT31(message.in.payload.intervals._1_3_,0xfe);
        message._4_4_ = packet;
        zcl_core_action_schedule(0x41,&uStack_34);
        if (((uint)message.in.payload.intervals & 0xff) != 0xfe) {
          uVar3 = (uint)message.in.payload.intervals & 0xff;
        }
      }
      goto _L0;
    }
  }
  uVar3 = 0x80;
_L0:
  if (message.in.payload._8_4_ != 0) {
    mm_free();
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar1;
}

