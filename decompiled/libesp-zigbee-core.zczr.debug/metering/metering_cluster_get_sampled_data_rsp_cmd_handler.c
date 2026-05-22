/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_sampled_data_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
metering_cluster_get_sampled_data_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  int iVar3;
  uint uVar4;
  uint16_t uStack_36;
  undefined4 uStack_34;
  uint16_t offset;
  ezb_zcl_metering_get_sampled_data_rsp_message_t message;
  
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.sample_id = 0;
  message.in.payload._2_2_ = 0;
  message.in.payload.start_time = 0;
  message.in.payload.sample_type = '\0';
  message.in.payload._9_1_ = 0;
  message.in.payload.req_interval = 0;
  message.in.payload.num_of_samples = 0;
  message.in.payload._14_2_ = 0;
  message.in.payload.samples = (uint32_t *)0x0;
  uStack_36 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x262,
                  "metering_cluster_get_sampled_data_rsp_cmd_handler","packet && rsp");
  }
  else {
    uVar2 = af_read_le16(packet->payload,&uStack_36,(uint16_t *)&message.in);
    if (CONCAT22(extraout_var,uVar2) == 0) {
      uVar4 = 0x80;
      goto _L0;
    }
  }
  uVar2 = af_read_le32(packet->payload,&uStack_36,(uint32_t *)&message.in.payload);
  if (CONCAT22(extraout_var_00,uVar2) == 0) {
    uVar4 = 0x80;
  }
  else {
    uVar2 = af_read_le8(packet->payload,&uStack_36,(uint8_t *)&message.in.payload.start_time);
    if (CONCAT22(extraout_var_01,uVar2) == 0) {
      uVar4 = 0x80;
    }
    else {
      uVar2 = af_read_le16(packet->payload,&uStack_36,
                           (uint16_t *)((int)&message.in.payload.start_time + 2));
      if (CONCAT22(extraout_var_02,uVar2) == 0) {
        uVar4 = 0x80;
      }
      else {
        uVar2 = af_read_le16(packet->payload,&uStack_36,(uint16_t *)&message.in.payload.sample_type)
        ;
        if (CONCAT22(extraout_var_03,uVar2) == 0) {
          uVar4 = 0x80;
        }
        else {
          iVar3 = zmsg_get_length(packet->payload);
          uVar4 = message.in.payload._8_4_ & 0xffff;
          if (iVar3 < (int)((uint)uStack_36 + uVar4 * 3)) {
            uVar4 = 0x80;
          }
          else {
            if (uVar4 != 0) {
              message.in.payload._12_4_ = calloc(uVar4,4);
              if ((void *)message.in.payload._12_4_ == (void *)0x0) {
                uVar4 = 0x89;
                goto _L0;
              }
              for (uVar4 = 0; uVar4 < (message.in.payload._8_4_ & 0xffff);
                  uVar4 = uVar4 + 1 & 0xffff) {
                iVar3 = zcl_packet_read_variable_attr_value
                                  (packet->payload,&uStack_36,0x22,
                                   uVar4 * 4 + message.in.payload._12_4_);
                if (iVar3 == 0) {
                  uVar4 = 0x80;
                  goto _L0;
                }
              }
            }
            uVar4 = zmsg_get_length(packet->payload);
            if (uVar4 < uStack_36) {
              uVar4 = 0x80;
            }
            else {
              uVar4 = zcl_packet_to_message(&stack0xffffffcc,packet);
              if (uVar4 == 0) {
                message.in.payload.samples =
                     (uint32_t *)CONCAT31(message.in.payload.samples._1_3_,0xfe);
                message._4_4_ = packet;
                zcl_core_action_schedule(0x49,&stack0xffffffcc);
                if (((uint)message.in.payload.samples & 0xff) != 0xfe) {
                  uVar4 = (uint)message.in.payload.samples & 0xff;
                }
              }
            }
          }
        }
      }
    }
  }
_L0:
  if (message.in.payload._12_4_ != 0) {
    mm_free();
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar1;
}

