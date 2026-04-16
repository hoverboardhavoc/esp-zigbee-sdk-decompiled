/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> zcl_message_thermostat_get_weekly_schedule_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_thermostat_get_weekly_schedule_response
          (zcl_packet_t *packet,ezb_zcl_thermostat_get_weekly_schedule_rsp_payload_t *payload)

{
  uint uVar1;
  undefined4 uStack_24;
  ezb_zcl_thermostat_get_weekly_schedule_rsp_message_t message;
  
  uStack_24 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload = (ezb_zcl_thermostat_get_weekly_schedule_rsp_payload_t *)0x0;
  uVar1 = zcl_packet_to_message(&uStack_24,packet);
  if (uVar1 == 0) {
    message.in.payload =
         (ezb_zcl_thermostat_get_weekly_schedule_rsp_payload_t *)
         CONCAT31(message.in.payload._1_3_,0xfe);
    message._4_4_ = packet;
    message.in.header = (ezb_zcl_cmd_hdr_t *)payload;
    zcl_core_action_schedule(0x39,&uStack_24);
    if (((uint)message.in.payload & 0xff) != 0xfe) {
      uVar1 = (uint)message.in.payload & 0xff;
    }
  }
  return (ezb_zcl_status_t)uVar1;
}

