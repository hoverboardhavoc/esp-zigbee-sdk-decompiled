/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_status_change_notification_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_zone_status_change_notification_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined1 *offset_00;
  undefined4 uStack_2c;
  ezb_zcl_ias_zone_status_change_notif_message_t message;
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
  message.in.payload.zone_status = 0;
  message.in.payload.extend_status = '\0';
  message.in.payload.zone_id = '\0';
  message.in.payload.delay = 0;
  message.in._10_2_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x127,
                  "ias_zone_status_change_notification_cmd_handler","packet && rsp");
  }
  else {
    offset_00 = &message.field_0x16;
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)&message.in);
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)((int)&message.in.header + 2));
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)((int)&message.in.header + 3));
    af_read_le16(packet->payload,(uint16_t *)offset_00,&message.in.payload.zone_status);
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < (ushort)message._22_2_) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uVar2 = zcl_packet_to_message(&uStack_2c,packet);
  if (uVar2 == 0) {
    message.in.payload.delay._0_1_ = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x32,&uStack_2c);
    uVar2 = message.in._8_4_ & 0xff;
    if (uVar2 == 0xfe) {
      uVar2 = 1;
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

