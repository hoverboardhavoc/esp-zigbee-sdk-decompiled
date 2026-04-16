/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_price_ack_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t price_cluster_price_ack_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  uint16_t uStack_32;
  undefined4 uStack_30;
  uint16_t offset;
  ezb_zcl_price_price_ack_message_t message;
  
  uStack_30 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.provider_id = 0;
  message.in.payload.issuer_event_id = 0;
  message.in.payload.price_ack_time = 0;
  message.in.payload.control = '\0';
  message.in.payload._13_3_ = 0;
  uStack_32 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/price.c",0xb6,
                  "price_cluster_price_ack_cmd_handler","packet && rsp");
  }
  else {
    af_read_le32(packet->payload,&uStack_32,(uint32_t *)&message.in);
    af_read_le32(packet->payload,&uStack_32,&message.in.payload.provider_id);
    af_read_le32(packet->payload,&uStack_32,&message.in.payload.issuer_event_id);
    af_read_le8(packet->payload,&uStack_32,(uint8_t *)&message.in.payload.price_ack_time);
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < uStack_32) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uVar2 = zcl_packet_to_message(&stack0xffffffd0,packet);
  if (uVar2 == 0) {
    message.in.payload.control = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x4d,&stack0xffffffd0);
    if ((message.in.payload._12_4_ & 0xff) != 0xfe) {
      uVar2 = message.in.payload._12_4_ & 0xff;
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

