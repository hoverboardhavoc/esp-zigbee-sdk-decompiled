/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_req_fast_poll_mode_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
metering_cluster_req_fast_poll_mode_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar3;
  uint16_t uStack_2a;
  undefined4 uStack_28;
  uint16_t offset;
  ezb_zcl_metering_request_fast_poll_mode_rsp_message_t message;
  
  uStack_28 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.period = '\0';
  message.in.payload._1_3_ = 0;
  message.in.payload.end_time = 0;
  uStack_2a = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x1f6,
                  "metering_cluster_req_fast_poll_mode_rsp_cmd_handler","packet && rsp");
  }
  else {
    uVar2 = af_read_le8(packet->payload,&uStack_2a,(uint8_t *)&message.in);
    if (CONCAT22(extraout_var,uVar2) == 0) {
      uVar3 = 0x80;
      goto _L0;
    }
  }
  uVar2 = af_read_le32(packet->payload,&uStack_2a,(uint32_t *)&message.in.payload);
  if (CONCAT22(extraout_var_00,uVar2) == 0) {
    uVar3 = 0x80;
  }
  else {
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < uStack_2a) {
      uVar3 = 0x80;
    }
    else {
      uVar3 = zcl_packet_to_message(&stack0xffffffd8,packet);
      if (uVar3 == 0) {
        message.in.payload.end_time = CONCAT31(message.in.payload.end_time._1_3_,0xfe);
        message._4_4_ = packet;
        zcl_core_action_schedule(0x45,&stack0xffffffd8);
        if ((message.in.payload.end_time & 0xff) != 0xfe) {
          uVar3 = message.in.payload.end_time & 0xff;
        }
      }
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar1;
}

