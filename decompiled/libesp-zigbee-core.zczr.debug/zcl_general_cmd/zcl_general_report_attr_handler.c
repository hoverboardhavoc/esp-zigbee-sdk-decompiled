/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_report_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_report_attr_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  zcl_status_t zVar1;
  int iVar2;
  ezb_zcl_cmd_hdr_t *peVar3;
  size_t __size;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  uint unaff_s3;
  uint unaff_s5;
  uint16_t uVar7;
  uint16_t local_36;
  undefined4 uStack_34;
  uint16_t offset;
  zcl_cmd_report_attr_message_t message;
  
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.variables = (ezb_zcl_report_attr_variable_t *)0x0;
  local_36 = 0;
  if ((((packet == (zcl_packet_t *)0x0) || (packet->payload == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x34c,
                  "zcl_general_report_attr_handler",
                  "packet && packet->payload && rsp && rsp->payload");
_L0:
    uVar7 = 0;
  }
  else {
    unaff_s3 = zmsg_get_length();
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    iVar2 = zcl_packet_to_message(&stack0xffffffcc,packet);
    if (iVar2 != 0) {
      uVar6 = 0x80;
      goto _L0;
    }
    unaff_s5 = 0;
    message._4_4_ = packet;
    if (((packet->header).fc & 4) == 0) goto _L0;
    uVar7 = (packet->header).manuf_code;
  }
  while (peVar3 = message.in.header, local_36 < unaff_s3) {
    peVar3 = (ezb_zcl_cmd_hdr_t *)calloc(1,0xc);
    *(ezb_zcl_cmd_hdr_t **)((int)&(peVar3->src_addr).u + 6) = message.in.header;
    message.in.header = peVar3;
    af_read_le16(packet->payload,&local_36,(uint16_t *)peVar3);
    af_read_le8(packet->payload,&local_36,(uint8_t *)&(peVar3->src_addr).u.short_addr);
    if (unaff_s3 < local_36) {
      uVar6 = 0x80;
      goto _L0;
    }
    __size = zcl_packet_read_variable_attr_size
                       (packet->payload,*(undefined1 *)&(peVar3->src_addr).u);
    pvVar4 = calloc(1,__size);
    *(void **)((int)&(peVar3->src_addr).u + 2) = pvVar4;
    zcl_packet_read_variable_attr_value
              (packet->payload,&local_36,*(undefined1 *)&(peVar3->src_addr).u,pvVar4);
  }
  for (; peVar3 != (ezb_zcl_cmd_hdr_t *)0x0;
      peVar3 = *(ezb_zcl_cmd_hdr_t **)((int)&(peVar3->src_addr).u + 6)) {
    if (((packet->header).fc & 8) == 0) {
      uVar5 = 1;
    }
    else {
      uVar5 = 2;
    }
    zcl_reporting_mark_recv_attr_report
              ((packet->header).dst_ep,(packet->header).cluster_id,uVar5,
               *(undefined2 *)&peVar3->src_addr,uVar7);
  }
  message.in.variables = (ezb_zcl_report_attr_variable_t *)CONCAT31(message.in.variables._1_3_,0xfe)
  ;
  zcl_core_action_schedule(5,&stack0xffffffcc);
  uVar6 = (uint)message.in.variables & 0xff;
  if (((uint)message.in.variables & 0xff) == 0xfe) {
    uVar6 = unaff_s5;
  }
_L0:
  while (message.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    peVar3 = *(ezb_zcl_cmd_hdr_t **)((int)&((message.in.header)->src_addr).u + 6);
    if (*(int *)((int)&((message.in.header)->src_addr).u + 2) != 0) {
      mm_free();
    }
    mm_free(message.in.header);
    message.in.header = peVar3;
  }
  zVar1 = zcl_packet_setup_default_response(rsp,packet,uVar6);
  return zVar1;
}

