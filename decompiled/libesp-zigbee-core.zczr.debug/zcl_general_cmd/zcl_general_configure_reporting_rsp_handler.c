/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_configure_reporting_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_configure_reporting_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_cmd_hdr_t *peVar1;
  zcl_status_t zVar2;
  uint uVar3;
  uint unaff_s4;
  uint16_t uStack_36;
  undefined4 uStack_34;
  uint16_t offset;
  zcl_cmd_config_report_rsp_message_t message;
  
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.variables = (ezb_zcl_config_report_rsp_variable_t *)0x0;
  if ((((packet == (zcl_packet_t *)0x0) || (packet->payload == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x295,
                  "zcl_general_configure_reporting_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s4 = zcl_packet_to_message(&stack0xffffffcc,packet);
    if (unaff_s4 != 0) {
      uVar3 = 0x80;
      goto _L0;
    }
  }
  uStack_36 = 0;
  message._4_4_ = packet;
  uVar3 = zmsg_get_length(packet->payload);
  while (uStack_36 < uVar3) {
    peVar1 = (ezb_zcl_cmd_hdr_t *)calloc(1,8);
    *(ezb_zcl_cmd_hdr_t **)((int)&(peVar1->src_addr).u + 2) = message.in.header;
    message.in.header = peVar1;
    af_read_le8(packet->payload,&uStack_36,(uint8_t *)peVar1);
    if (uVar3 < uStack_36) {
      uVar3 = 0x80;
      goto _L0;
    }
    if ((peVar1->src_addr).addr_mode == '\0') {
      (peVar1->src_addr).field_0x1 = 0xff;
      (peVar1->src_addr).u.short_addr = 0xffff;
    }
    else {
      af_read_le8(packet->payload,&uStack_36,&(peVar1->src_addr).field_0x1);
      af_read_le16(packet->payload,&uStack_36,&(peVar1->src_addr).u.short_addr);
    }
  }
  message.in.variables =
       (ezb_zcl_config_report_rsp_variable_t *)CONCAT31(message.in.variables._1_3_,0xfe);
  zcl_core_action_schedule(3,&stack0xffffffcc);
  uVar3 = (uint)message.in.variables & 0xff;
  if (((uint)message.in.variables & 0xff) == 0xfe) {
    uVar3 = unaff_s4;
  }
_L0:
  if (message.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    while (message.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
      peVar1 = *(ezb_zcl_cmd_hdr_t **)((int)&((message.in.header)->src_addr).u + 2);
      mm_free();
      message.in.header = peVar1;
    }
  }
  zVar2 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return zVar2;
}

