/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_read_reporting_configuration_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t
zcl_general_read_reporting_configuration_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_cmd_hdr_t *peVar1;
  zcl_status_t zVar2;
  uint uVar3;
  int iVar4;
  uint unaff_s5;
  uint16_t uStack_36;
  undefined4 uStack_34;
  uint16_t offset;
  zcl_cmd_read_report_config_rsp_message_t message;
  
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.variables = (ezb_zcl_read_report_config_rsp_variable_t *)0x0;
  if ((((packet == (zcl_packet_t *)0x0) || (packet->payload == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x319,
                  "zcl_general_read_reporting_configuration_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s5 = zcl_packet_to_message(&stack0xffffffcc,packet);
    if (unaff_s5 != 0) {
      uVar3 = 0x80;
      goto _L0;
    }
  }
  uStack_36 = 0;
  message._4_4_ = packet;
  uVar3 = zmsg_get_length(packet->payload);
  while (uStack_36 < uVar3) {
    peVar1 = (ezb_zcl_cmd_hdr_t *)calloc(1,0x20);
    *(ezb_zcl_cmd_hdr_t **)&peVar1->profile_id = message.in.header;
    message.in.header = peVar1;
    af_read_le8(packet->payload,&uStack_36,(uint8_t *)peVar1);
    af_read_le8(packet->payload,&uStack_36,&(peVar1->src_addr).field_0x1);
    af_read_le16(packet->payload,&uStack_36,&(peVar1->src_addr).u.short_addr);
    if (uVar3 < uStack_36) {
      uVar3 = 0x80;
      goto _L0;
    }
    if ((peVar1->src_addr).addr_mode == '\0') {
      if ((peVar1->src_addr).field_0x1 == '\0') {
        af_read_le8(packet->payload,&uStack_36,(uint8_t *)((int)&(peVar1->src_addr).u + 6));
        af_read_le16(packet->payload,&uStack_36,(uint16_t *)&peVar1->dst_addr);
        af_read_le16(packet->payload,&uStack_36,&(peVar1->dst_addr).u.short_addr);
        iVar4 = zcl_attr_type_is_analog(*(undefined1 *)((int)&(peVar1->src_addr).u + 6));
        if (iVar4 == 0) {
          *(undefined4 *)((int)&(peVar1->dst_addr).u + 4) = 0;
          peVar1->src_ep = '\0';
          peVar1->dst_ep = '\0';
          peVar1->cluster_id = 0;
        }
        else {
          zcl_packet_read_variable_attr_value
                    (packet->payload,&uStack_36,*(undefined1 *)((int)&(peVar1->src_addr).u + 6),
                     (undefined1 *)((int)&(peVar1->dst_addr).u + 4));
        }
      }
      else {
        af_read_le16(packet->payload,&uStack_36,(uint16_t *)((int)&(peVar1->src_addr).u + 6));
      }
    }
    else {
      *(undefined1 *)((int)&(peVar1->src_addr).u + 6) = 0xff;
      *(undefined1 *)((int)&(peVar1->src_addr).u + 7) = 0xff;
      memset((void *)((int)&(peVar1->src_addr).u + 6),0xff,0x10);
    }
  }
  message.in.variables =
       (ezb_zcl_read_report_config_rsp_variable_t *)CONCAT31(message.in.variables._1_3_,0xfe);
  zcl_core_action_schedule(4,&stack0xffffffcc);
  uVar3 = (uint)message.in.variables & 0xff;
  if (((uint)message.in.variables & 0xff) == 0xfe) {
    uVar3 = unaff_s5;
  }
_L0:
  if (message.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    while (message.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
      peVar1 = *(ezb_zcl_cmd_hdr_t **)&(message.in.header)->profile_id;
      mm_free();
      message.in.header = peVar1;
    }
  }
  zVar2 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return zVar2;
}

