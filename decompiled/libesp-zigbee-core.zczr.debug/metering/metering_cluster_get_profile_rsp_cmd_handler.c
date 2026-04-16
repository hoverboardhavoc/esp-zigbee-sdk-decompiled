/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_profile_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
metering_cluster_get_profile_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  int iVar3;
  uint uVar4;
  ezb_zcl_metering_profile_interval_period_t eVar5;
  uint16_t uStack_36;
  undefined4 uStack_34;
  uint16_t offset;
  ezb_zcl_metering_get_profile_rsp_message_t message;
  
  uStack_34 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.end_time = 0;
  message.in.payload.status = EZB_ZCL_METERING_SUCCESS;
  message.in.payload.profile_interval_period = EZB_ZCL_METERING_INTERVAL_PERIOD_DAILY;
  message.in.payload.num_of_periods_delivered = '\0';
  message.in.payload._13_3_ = 0;
  message.in.payload.intervals = (uint32_t *)0x0;
  uStack_36 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x1d8,
                  "metering_cluster_get_profile_rsp_cmd_handler","packet && rsp");
  }
  else {
    uVar2 = af_read_le32(packet->payload,&uStack_36,(uint32_t *)&message.in);
    if (CONCAT22(extraout_var,uVar2) == 0) {
      uVar4 = 0x80;
      goto _L0;
    }
  }
  uVar2 = af_read_le8(packet->payload,&uStack_36,(uint8_t *)&message.in.payload);
  if (CONCAT22(extraout_var_00,uVar2) == 0) {
    uVar4 = 0x80;
  }
  else {
    uVar2 = af_read_le8(packet->payload,&uStack_36,(uint8_t *)&message.in.payload.status);
    if (CONCAT22(extraout_var_01,uVar2) == 0) {
      uVar4 = 0x80;
    }
    else {
      uVar2 = af_read_le8(packet->payload,&uStack_36,
                          (uint8_t *)&message.in.payload.profile_interval_period);
      if (CONCAT22(extraout_var_02,uVar2) == 0) {
        uVar4 = 0x80;
      }
      else {
        iVar3 = zmsg_get_length(packet->payload);
        eVar5 = message.in.payload.profile_interval_period & 0xff;
        if (iVar3 < (int)((uint)uStack_36 + eVar5 * 3)) {
          uVar4 = 0x80;
        }
        else {
          if (eVar5 != EZB_ZCL_METERING_INTERVAL_PERIOD_DAILY) {
            message.in.payload._12_4_ = calloc(eVar5,4);
            if ((void *)message.in.payload._12_4_ == (void *)0x0) {
              uVar4 = 0x89;
              goto _L0;
            }
            for (eVar5 = EZB_ZCL_METERING_INTERVAL_PERIOD_DAILY;
                eVar5 < (message.in.payload.profile_interval_period & 0xff);
                eVar5 = eVar5 + EZB_ZCL_METERING_INTERVAL_PERIOD_60_MINUTES & 0xff) {
              iVar3 = zcl_packet_read_variable_attr_value
                                (packet->payload,&uStack_36,0x22,
                                 eVar5 * 4 + message.in.payload._12_4_);
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
              message.in.payload.intervals =
                   (uint32_t *)CONCAT31(message.in.payload.intervals._1_3_,0xfe);
              message._4_4_ = packet;
              zcl_core_action_schedule(0x43,&stack0xffffffcc);
              if (((uint)message.in.payload.intervals & 0xff) != 0xfe) {
                uVar4 = (uint)message.in.payload.intervals & 0xff;
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

