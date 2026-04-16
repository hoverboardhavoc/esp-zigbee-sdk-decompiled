/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_set_bypassed_zone_list_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_ace_cluster_set_bypassed_zone_list_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  byte bVar1;
  ezb_zcl_status_t eVar2;
  uint16_t uVar3;
  undefined2 extraout_var;
  uint uVar4;
  undefined4 uStack_2c;
  ezb_zcl_ias_ace_set_bypassed_zone_list_rsp_message_t message;
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
  message.in.payload.zone_id = (uint8_t *)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x27c,
                  "ias_ace_cluster_set_bypassed_zone_list_rsp_handler","packet && rsp");
  }
  else {
    uVar3 = af_read_le8(packet->payload,(uint16_t *)&message.field_0x16,(uint8_t *)&message.in);
    if (CONCAT22(extraout_var,uVar3) != 1) {
      uVar4 = 0x80;
      goto _L0;
    }
    bVar1 = (byte)message.in.header;
    if (((uint)message.in.header & 0xff) != 0) {
      message.in.payload._0_4_ = calloc(1,(uint)message.in.header & 0xff);
      if ((uint8_t *)message.in.payload._0_4_ == (uint8_t *)0x0) {
        uVar4 = 0x89;
        goto _L0;
      }
      af_read_bytes(packet->payload,(uint16_t *)&message.field_0x16,(ushort)bVar1,
                    (uint8_t *)message.in.payload._0_4_);
    }
    uVar4 = zmsg_get_length(packet->payload);
    if (uVar4 < (ushort)message._22_2_) {
      uVar4 = 0x80;
      goto _L0;
    }
  }
  uVar4 = zcl_packet_to_message(&uStack_2c,packet);
  if (uVar4 == 0) {
    message.in.payload.zone_id = (uint8_t *)CONCAT31(message.in.payload.zone_id._1_3_,0xfe);
    message._4_4_ = packet;
    zcl_core_action_schedule(0x29,&uStack_2c);
    if (((uint)message.in.payload.zone_id & 0xff) != 0xfe) {
      uVar4 = (uint)message.in.payload.zone_id & 0xff;
    }
  }
_L0:
  if (message.in.payload._0_4_ != 0) {
    mm_free();
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar2;
}

