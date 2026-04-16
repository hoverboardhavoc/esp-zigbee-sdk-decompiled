/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_get_prof_info_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
electrical_measurement_cluster_get_prof_info_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  int iVar3;
  uint16_t attr_num;
  uint __nmemb;
  uint16_t uStack_3a;
  undefined4 uStack_38;
  uint16_t offset;
  ezb_zcl_electrical_measurement_get_prof_info_rsp_message_t message;
  
  uStack_38 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.prof_count = '\0';
  message.in.payload.prof_interval_period = '\0';
  message.in.payload.max_num_of_intervals = '\0';
  message.in.payload._3_1_ = 0;
  message.in.payload.list_of_attributes = (uint16_t *)0x0;
  uStack_3a = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement.c",0xa6,
                  "electrical_measurement_cluster_get_prof_info_rsp_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,&uStack_3a,(uint8_t *)&message.in);
    af_read_le8(packet->payload,&uStack_3a,(uint8_t *)((int)&message.in.header + 1));
    af_read_le8(packet->payload,&uStack_3a,(uint8_t *)((int)&message.in.header + 2));
    uVar2 = zmsg_get_length(packet->payload);
    if (uVar2 < uStack_3a) {
      uVar2 = 0x80;
      goto _L0;
    }
  }
  iVar3 = zmsg_get_length(packet->payload);
  uVar2 = iVar3 - (uint)uStack_3a >> 1;
  __nmemb = uVar2 & 0xffff;
  if ((uVar2 & 0xffff) != 0) {
    message.in.payload._0_4_ = calloc(__nmemb,2);
    if ((void *)message.in.payload._0_4_ == (void *)0x0) {
      uVar2 = 0x89;
      goto _L0;
    }
    for (uVar2 = 0; uVar2 < __nmemb; uVar2 = uVar2 + 1 & 0xffff) {
      af_read_le16(packet->payload,&uStack_3a,(uint16_t *)(message.in.payload._0_4_ + uVar2 * 2));
    }
  }
  uVar2 = zcl_packet_to_message(&stack0xffffffc8,packet);
  if (uVar2 == 0) {
    message.in.payload.list_of_attributes =
         (uint16_t *)CONCAT31(message.in.payload.list_of_attributes._1_3_,0xfe);
    message._4_4_ = packet;
    zcl_core_action_schedule(0x40,&stack0xffffffc8);
    if (((uint)message.in.payload.list_of_attributes & 0xff) != 0xfe) {
      uVar2 = (uint)message.in.payload.list_of_attributes & 0xff;
    }
  }
_L0:
  if (message.in.payload._0_4_ != 0) {
    mm_free();
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar1;
}

