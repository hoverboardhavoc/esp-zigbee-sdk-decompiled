/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_get_scheduled_prices_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
price_cluster_get_scheduled_prices_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint uVar1;
  ezb_zcl_cmd_hdr_t *peVar2;
  uint16_t uStack_2a;
  undefined4 uStack_28;
  uint16_t offset;
  ezb_zcl_price_get_scheduled_prices_message_t message;
  
  uStack_28 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.start_time = 0;
  message.in.payload.num_of_events = '\0';
  message.in.payload._5_3_ = 0;
  uStack_2a = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0x6e,
                  "price_cluster_get_scheduled_prices_cmd_handler","packet && rsp");
_L0:
    peVar2 = (ezb_zcl_cmd_hdr_t *)zcl_time_get_utc_time((packet->header).dst_ep);
    if (peVar2 != (ezb_zcl_cmd_hdr_t *)0xffffffff) {
      message.in.header = peVar2;
    }
_L0:
    uVar1 = zcl_packet_to_message(&stack0xffffffd8,packet);
    if (uVar1 == 0) {
      message.in.payload.num_of_events = 0xfe;
      message._4_4_ = packet;
      zcl_core_action_schedule(0x4b,&stack0xffffffd8);
      uVar1 = message.in.payload._4_4_ & 0xff;
      if (uVar1 == 0xfe) {
        uVar1 = 0x8b;
      }
      else if (uVar1 == 0) goto _L0;
    }
  }
  else {
    af_read_le32(packet->payload,&uStack_2a,(uint32_t *)&message.in);
    af_read_le8(packet->payload,&uStack_2a,(uint8_t *)&message.in.payload);
    uVar1 = zmsg_get_length(packet->payload);
    if (uStack_2a <= uVar1) {
      if (message.in.header == (ezb_zcl_cmd_hdr_t *)0x0) goto _L0;
      goto _L0;
    }
    uVar1 = 0x80;
  }
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

