/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_get_alarm_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t alarms_cluster_get_alarm_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  uint16_t uStack_2a;
  undefined4 uStack_28;
  uint16_t offset;
  ezb_zcl_alarms_get_alarm_rsp_message_t message;
  
  uStack_28 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.status = '\0';
  message.in.payload.alarm_code = '\0';
  message.in.payload.cluster_id = 0;
  message.in.payload.timestamp = 0;
  uStack_2a = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1ff,
                  "alarms_cluster_get_alarm_rsp_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,&uStack_2a,(uint8_t *)&message.in);
    if ((char)message.in.header != '\0') goto _L0;
  }
  af_read_le8(packet->payload,&uStack_2a,(uint8_t *)((int)&message.in.header + 1));
  af_read_le16(packet->payload,&uStack_2a,(uint16_t *)((int)&message.in.header + 2));
  af_read_le32(packet->payload,&uStack_2a,(uint32_t *)&message.in.payload);
_L0:
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < uStack_2a) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_packet_to_message(&stack0xffffffd8,packet);
    if (uVar2 == 0) {
      message.in.payload.timestamp = CONCAT31(message.in.payload.timestamp._1_3_,0xfe);
      message._4_4_ = packet;
      zcl_core_action_schedule(0x34,&stack0xffffffd8);
      if ((message.in.payload.timestamp & 0xff) != 0xfe) {
        uVar2 = message.in.payload.timestamp & 0xff;
      }
    }
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

