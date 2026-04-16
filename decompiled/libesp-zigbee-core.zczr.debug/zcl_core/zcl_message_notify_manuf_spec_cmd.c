/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_message_notify_manuf_spec_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_message_notify_manuf_spec_cmd(zcl_packet_t *packet)

{
  uint uVar1;
  uint uVar2;
  size_t __size;
  undefined4 uStack_2c;
  zcl_manuf_spec_cmd_message_t message;
  uint16_t offset;
  
  message._22_2_ = 0;
  uStack_2c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload_size = 0;
  message.in._6_2_ = 0;
  message.in.payload = (uint8_t *)0x0;
  uVar2 = zcl_packet_to_message(&uStack_2c,packet);
  if (uVar2 == 0) {
    message._4_4_ = packet;
    __size = zcl_packet_payload_get_length(packet->payload);
    message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT22(message.in.header._2_2_,(uint16_t)__size);
    message.in._4_4_ = calloc(1,__size);
    if (((void *)message.in._4_4_ == (void *)0x0) && (__size != 0)) {
      uVar2 = 0x89;
    }
    else {
      if (__size == 0) {
        message.in.payload_size = 0;
        message.in._6_2_ = 0;
      }
      af_read_bytes(packet->payload,(uint16_t *)&message.field_0x16,(uint16_t)__size,
                    (uint8_t *)message.in._4_4_);
      message.in.payload = (uint8_t *)CONCAT31(message.in.payload._1_3_,0xfe);
      zcl_core_action_schedule(9,&uStack_2c);
      uVar1 = (uint)message.in.payload & 0xff;
      if (((uint)message.in.payload & 0xff) == 0xfe) {
        uVar1 = uVar2;
      }
      uVar2 = uVar1;
      zcl_packet_send_default_response(packet,uVar2);
    }
  }
  if (message.in._4_4_ != 0) {
    mm_free();
  }
  return (zcl_status_t)uVar2;
}

