/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_enroll_request_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_zone_enroll_request_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined4 uStack_28;
  ezb_zcl_ias_zone_enroll_req_message_t message;
  uint16_t offset;
  
  message._18_2_ = 0;
  uStack_28 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.zone_type = 0;
  message.in.payload.manuf_code = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x110,
                  "ias_zone_enroll_request_cmd_handler","packet && rsp");
  }
  else {
    af_read_le16(packet->payload,(uint16_t *)&message.field_0x12,(uint16_t *)&message.in);
    af_read_le16(packet->payload,(uint16_t *)&message.field_0x12,
                 (uint16_t *)((int)&message.in.header + 2));
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < (ushort)message._18_2_) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uVar2 = zcl_packet_to_message(&uStack_28,packet);
  if (uVar2 == 0) {
    message.in.payload.zone_type._0_1_ = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x30,&uStack_28);
    uVar2 = (uint)message.in.payload & 0xff;
    if (uVar2 == 0xfe) {
      uVar2 = 1;
    }
    else if (uVar2 == 0) {
      return message.in.payload.zone_type;
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

