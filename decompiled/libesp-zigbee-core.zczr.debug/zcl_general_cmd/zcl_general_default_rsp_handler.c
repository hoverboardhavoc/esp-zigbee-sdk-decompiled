/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_default_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_default_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  zcl_status_t zVar1;
  uint uVar2;
  uint unaff_s2;
  uint16_t uStack_36;
  undefined4 uStack_34;
  uint16_t offset;
  zcl_cmd_default_rsp_message_t message;
  
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.rsp_to_cmd = '\0';
  message.in.status_code = '\0';
  message.in._6_2_ = 0;
  uStack_36 = 0;
  if ((((packet == (zcl_packet_t *)0x0) || (packet->payload == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x468,
                  "zcl_general_default_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s2 = zcl_packet_to_message(&stack0xffffffcc,packet);
    if (unaff_s2 != 0) {
      uVar2 = 0xfe;
      goto _L0;
    }
  }
  message._4_4_ = packet;
  af_read_le8(packet->payload,&uStack_36,(uint8_t *)&message.in);
  af_read_le8(packet->payload,&uStack_36,(uint8_t *)((int)&message.in.header + 1));
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < uStack_36) {
    uVar2 = 0x80;
  }
  else {
    message.in.rsp_to_cmd = 0xfe;
    zcl_core_action_schedule(8,&stack0xffffffcc);
    uVar2 = message.in._4_4_ & 0xff;
    if ((message.in._4_4_ & 0xff) == 0xfe) {
      uVar2 = unaff_s2;
    }
  }
_L0:
  zVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return zVar1;
}

