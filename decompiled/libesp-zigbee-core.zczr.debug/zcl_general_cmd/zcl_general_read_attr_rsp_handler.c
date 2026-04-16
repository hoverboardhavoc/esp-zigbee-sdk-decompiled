/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_read_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_read_attr_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_cmd_hdr_t *peVar1;
  zcl_status_t zVar2;
  uint uVar3;
  size_t __size;
  void *pvVar4;
  int iVar5;
  zmsg_t *payload;
  uint unaff_s6;
  uint16_t local_36;
  undefined4 uStack_34;
  uint16_t offset;
  zcl_cmd_read_attr_rsp_message_t message;
  
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.variables = (ezb_zcl_read_attr_rsp_variable_t *)0x0;
  if ((((packet == (zcl_packet_t *)0x0) || (packet->payload == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0xad,
                  "zcl_general_read_attr_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s6 = zcl_packet_to_message(&stack0xffffffcc,packet);
    if (unaff_s6 != 0) {
      uVar3 = 0x80;
      goto _L0;
    }
  }
  payload = packet->payload;
  local_36 = 0;
  message._4_4_ = packet;
  uVar3 = zmsg_get_length(payload);
  while (local_36 < uVar3) {
    peVar1 = (ezb_zcl_cmd_hdr_t *)calloc(1,0xc);
    *(ezb_zcl_cmd_hdr_t **)((int)&(peVar1->src_addr).u + 6) = message.in.header;
    message.in.header = peVar1;
    af_read_le16(payload,&local_36,(uint16_t *)peVar1);
    af_read_le8(payload,&local_36,(uint8_t *)&(peVar1->src_addr).u.short_addr);
    if (uVar3 < local_36) {
      uVar3 = 0x80;
      goto _L0;
    }
    if (*(char *)&(peVar1->src_addr).u == '\0') {
      af_read_le8(payload,&local_36,(uint8_t *)((int)&(peVar1->src_addr).u.group_addr.group + 1));
      __size = zcl_packet_read_variable_attr_size
                         (payload,local_36,*(undefined1 *)((int)&(peVar1->src_addr).u + 1));
      if (__size == 0xffff) {
        uVar3 = 0x85;
        goto _L0;
      }
      pvVar4 = calloc(1,__size);
      *(void **)((int)&(peVar1->src_addr).u + 2) = pvVar4;
      if ((pvVar4 == (void *)0x0) && (__size != 0)) {
        uVar3 = 0x89;
        goto _L0;
      }
      zcl_packet_read_variable_attr_value
                (payload,&local_36,*(undefined1 *)((int)&(peVar1->src_addr).u + 1),pvVar4);
    }
  }
  if (((packet->header).cluster_id != 10) ||
     (iVar5 = zcl_time_server_read_attr_rsp_handler(&stack0xffffffcc), uVar3 = unaff_s6, iVar5 == 0)
     ) {
    message.in.variables =
         (ezb_zcl_read_attr_rsp_variable_t *)CONCAT31(message.in.variables._1_3_,0xfe);
    zcl_core_action_schedule(1,&stack0xffffffcc);
    uVar3 = (uint)message.in.variables & 0xff;
    if (((uint)message.in.variables & 0xff) == 0xfe) {
      uVar3 = unaff_s6;
    }
  }
_L0:
  while (message.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    peVar1 = *(ezb_zcl_cmd_hdr_t **)((int)&((message.in.header)->src_addr).u + 6);
    if (*(int *)((int)&((message.in.header)->src_addr).u + 2) != 0) {
      mm_free();
    }
    mm_free(message.in.header);
    message.in.header = peVar1;
  }
  zVar2 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return zVar2;
}

