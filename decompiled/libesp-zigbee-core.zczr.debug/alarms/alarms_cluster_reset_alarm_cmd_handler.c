/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_reset_alarm_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t alarms_cluster_reset_alarm_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  ezb_err_t eVar3;
  uint16_t uStack_26;
  undefined4 uStack_24;
  uint16_t offset;
  ezb_zcl_alarms_reset_alarm_message_t message;
  
  uStack_24 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.alarm_code = '\0';
  message.in.payload._1_1_ = 0;
  message.in.payload.cluster_id = 0;
  uStack_26 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1d1,
                  "alarms_cluster_reset_alarm_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,&uStack_26,(uint8_t *)&message.in);
    af_read_le16(packet->payload,&uStack_26,(uint16_t *)((int)&message.in.header + 2));
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < uStack_26) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  uVar2 = zcl_packet_to_message(&stack0xffffffdc,packet);
  if (uVar2 == 0) {
    eVar3 = alarm_table_remove((packet->header).dst_ep,(uint8_t)message.in.header,
                               message.in.header._2_2_);
    if (eVar3 == 0) {
      message.in.payload.alarm_code = 0xfe;
      message._4_4_ = packet;
      zcl_core_action_schedule(0x35,&stack0xffffffdc);
      uVar2 = (uint)message.in.payload & 0xff;
      if (uVar2 == 0xfe) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0x8b;
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

