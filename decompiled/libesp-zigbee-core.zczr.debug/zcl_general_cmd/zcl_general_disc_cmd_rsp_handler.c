/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_disc_cmd_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_disc_cmd_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  undefined4 uVar1;
  zcl_status_t zVar2;
  uint uVar3;
  uint8_t *value;
  uint unaff_s4;
  uint16_t uStack_3a;
  undefined4 uStack_38;
  uint16_t offset;
  zcl_cmd_discover_commands_rsp_message_t message;
  
  uStack_38 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.is_recv = '\0';
  message.in.is_completed = '\0';
  message.in._6_2_ = 0;
  message.in.variables = (ezb_zcl_disc_cmd_variable_t *)0x0;
  if ((((packet == (zcl_packet_t *)0x0) || (packet->payload == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x3c7,
                  "zcl_general_disc_cmd_rsp_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else {
    unaff_s4 = zcl_packet_to_message(&stack0xffffffc8,packet);
    if (unaff_s4 != 0) {
      uVar3 = 0x80;
      goto _L0;
    }
  }
  uStack_3a = 0;
  message._4_4_ = packet;
  uVar3 = zmsg_get_length(packet->payload);
  af_read_le8(packet->payload,&uStack_3a,(uint8_t *)((int)&message.in.header + 1));
  message.in.header =
       (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,(packet->header).cmd_id == '\x12');
  while (uStack_3a < uVar3) {
    value = (uint8_t *)calloc(1,8);
    af_read_le8(packet->payload,&uStack_3a,value);
    value[4] = message.in.is_recv;
    value[5] = message.in.is_completed;
    value[6] = message.in._6_1_;
    value[7] = message.in._7_1_;
    message.in._4_4_ = value;
  }
  message.in.variables = (ezb_zcl_disc_cmd_variable_t *)CONCAT31(message.in.variables._1_3_,0xfe);
  zcl_core_action_schedule(7,&stack0xffffffc8);
  uVar3 = (uint)message.in.variables & 0xff;
  if (((uint)message.in.variables & 0xff) == 0xfe) {
    uVar3 = unaff_s4;
  }
_L0:
  while (message.in._4_4_ != 0) {
    uVar1 = *(undefined4 *)(message.in._4_4_ + 4);
    mm_free();
    message.in._4_4_ = uVar1;
  }
  zVar2 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return zVar2;
}

