/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_status_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_get_zone_status_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  int iVar1;
  ezb_zcl_status_t eVar2;
  uint16_t uVar3;
  undefined2 extraout_var;
  uint uVar4;
  size_t in_a5;
  uint16_t uStack_3e;
  undefined4 uStack_3c;
  uint16_t zone_status_tmp;
  ezb_zcl_ias_ace_get_zone_status_rsp_message_t message;
  uint16_t offset;
  
  message._22_2_ = 0;
  uStack_3c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.zone_status_complete = '\0';
  message.in.payload.num_of_zones = '\0';
  message.in.payload._2_2_ = 0;
  message.in.payload.zone_id_status = (ezb_zcl_ias_ace_zone_status_t *)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x2b1,
                  "ias_ace_cluster_get_zone_status_rsp_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,(uint16_t *)&message.field_0x16,(uint8_t *)&message.in);
    uVar3 = af_read_le8(packet->payload,(uint16_t *)&message.field_0x16,
                        (uint8_t *)((int)&message.in.header + 1));
    in_a5 = 1;
    if (CONCAT22(extraout_var,uVar3) != 1) {
      uVar4 = 0x80;
      goto _L0;
    }
  }
  message.in.payload._0_4_ = calloc(in_a5,((uint)message.in.header >> 8 & 0xff) << 2);
  if ((void *)message.in.payload._0_4_ == (void *)0x0) {
    uVar4 = 0x89;
  }
  else {
    for (iVar1 = 0; iVar1 < (int)((uint)message.in.header >> 8 & 0xff); iVar1 = iVar1 + 1) {
      uStack_3e = 0;
      af_read_le8(packet->payload,(uint16_t *)&message.field_0x16,
                  (uint8_t *)(message.in.payload._0_4_ + iVar1 * 4));
      af_read_le16(packet->payload,(uint16_t *)&message.field_0x16,&uStack_3e);
      *(uint16_t *)(message.in.payload._0_4_ + iVar1 * 4 + 2) = uStack_3e;
    }
    uVar4 = zmsg_get_length(packet->payload);
    if (uVar4 < (ushort)message._22_2_) {
      uVar4 = 0x80;
    }
    else {
      uVar4 = zcl_packet_to_message(&stack0xffffffc4,packet);
      if (uVar4 == 0) {
        message.in.payload.zone_id_status =
             (ezb_zcl_ias_ace_zone_status_t *)CONCAT31(message.in.payload.zone_id_status._1_3_,0xfe)
        ;
        message._4_4_ = packet;
        zcl_core_action_schedule(0x2b,&stack0xffffffc4);
        if (((uint)message.in.payload.zone_id_status & 0xff) != 0xfe) {
          uVar4 = (uint)message.in.payload.zone_id_status & 0xff;
        }
      }
    }
  }
_L0:
  if (message.in.payload._0_4_ != 0) {
    mm_free();
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar2;
}

