/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_bypass_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_bypass_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  uint uVar3;
  size_t in_a5;
  size_t unaff_s2;
  undefined4 uStack_2c;
  ezb_zcl_ias_ace_bypass_rsp_message_t message;
  uint16_t offset;
  
  message._22_2_ = 0;
  uStack_2c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.num_of_zones = '\0';
  message.in.payload._1_3_ = 0;
  message.in.payload.bypass_result = (uint8_t *)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x297,
                  "ias_ace_cluster_bypass_rsp_handler","packet && rsp");
  }
  else {
    uVar2 = af_read_le8(packet->payload,(uint16_t *)&message.field_0x16,(uint8_t *)&message.in);
    in_a5 = 1;
    if (CONCAT22(extraout_var,uVar2) != 1) {
      uVar3 = 0x80;
      goto _L0;
    }
    unaff_s2 = (uint)message.in.header & 0xff;
    if (unaff_s2 == 0) {
      uVar3 = 0x87;
      goto _L0;
    }
  }
  message.in.payload._0_4_ = calloc(in_a5,unaff_s2);
  if ((uint8_t *)message.in.payload._0_4_ == (uint8_t *)0x0) {
    uVar3 = 0x89;
  }
  else {
    af_read_bytes(packet->payload,(uint16_t *)&message.field_0x16,(uint16_t)unaff_s2,
                  (uint8_t *)message.in.payload._0_4_);
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < (ushort)message._22_2_) {
      uVar3 = 0x80;
    }
    else {
      uVar3 = zcl_packet_to_message(&uStack_2c,packet);
      if (uVar3 == 0) {
        message.in.payload.bypass_result =
             (uint8_t *)CONCAT31(message.in.payload.bypass_result._1_3_,0xfe);
        message._4_4_ = packet;
        zcl_core_action_schedule(0x2a,&uStack_2c);
        if (((uint)message.in.payload.bypass_result & 0xff) != 0xfe) {
          uVar3 = (uint)message.in.payload.bypass_result & 0xff;
        }
      }
    }
  }
_L0:
  if (message.in.payload._0_4_ != 0) {
    mm_free();
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar1;
}

