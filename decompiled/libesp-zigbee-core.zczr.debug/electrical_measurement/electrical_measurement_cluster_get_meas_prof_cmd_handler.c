/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_get_meas_prof_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
electrical_measurement_cluster_get_meas_prof_cmd_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,ezb_zcl_cmd_cnf_ctx_t *cnf_ctx)

{
  uint16_t *offset_00;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_50;
  undefined4 uStack_4c;
  ezb_zcl_electrical_measurement_get_meas_prof_message_t message;
  uint16_t offset;
  
  message.out.cnf_ctx.user_ctx._2_2_ = 0;
  uStack_4c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.attr_id = 0;
  message.in.payload._2_2_ = 0;
  message.in.payload.start_time = 0;
  message.in.payload.num_of_intervals = '\0';
  message.in.payload._9_3_ = 0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload = (ezb_zcl_electrical_measurement_get_meas_prof_rsp_payload_t *)0x0;
  message.out.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement.c",0x7b,
                  "electrical_measurement_cluster_get_meas_prof_cmd_handler","packet && rsp");
_L0:
    uVar1 = zcl_packet_to_message(&uStack_4c,packet);
    if (uVar1 == 0) {
      message.in.payload.num_of_intervals = 0xfe;
      message._4_4_ = packet;
      zcl_core_action_schedule(0x3f,&uStack_4c);
      uVar1 = message.in.payload._8_4_ & 0xff;
      if (uVar1 == 0xfe) {
        uVar1 = 1;
      }
      else if (uVar1 == 0) {
        if (message.out._0_4_ == 0) {
          uVar1 = 1;
        }
        else if ((*(char *)(message.out._0_4_ + 6) == '\0') ||
                (*(int *)(message.out._0_4_ + 0xc) != 0)) {
          local_50 = *(undefined4 *)message.out._0_4_;
          iVar2 = zmsg_append_bytes(rsp->payload,4,&local_50);
          if (iVar2 == 0) {
            local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(message.out._0_4_ + 4));
            iVar2 = zmsg_append_bytes(rsp->payload,1,&local_50);
            if (iVar2 == 0) {
              local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(message.out._0_4_ + 5));
              iVar2 = zmsg_append_bytes(rsp->payload,1,&local_50);
              if (iVar2 == 0) {
                local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(message.out._0_4_ + 6));
                iVar2 = zmsg_append_bytes(rsp->payload,1,&local_50);
                if (iVar2 == 0) {
                  local_50 = CONCAT22(local_50._2_2_,*(undefined2 *)(message.out._0_4_ + 8));
                  iVar2 = zmsg_append_bytes(rsp->payload,2,&local_50);
                  if (iVar2 == 0) {
                    iVar2 = ezb_zcl_get_attr_desc
                                      ((packet->header).dst_ep,0xb04,1,
                                       *(undefined2 *)(message.out._0_4_ + 8),0);
                    uVar1 = 0;
                    if (iVar2 == 0) {
                      uVar1 = 0x8b;
                    }
                    else {
                      for (; uVar1 < *(byte *)(message.out._0_4_ + 6); uVar1 = uVar1 + 1 & 0xff) {
                        iVar3 = zcl_packet_append_variable_attr_value
                                          (rsp->payload,*(undefined1 *)(iVar2 + 2),
                                           *(int *)(message.out._0_4_ + 0xc) + uVar1);
                        if (iVar3 != 0) {
                          uVar1 = 0x89;
                          goto _L0;
                        }
                      }
                      cnf_ctx->cb = (ezb_af_user_cnf_callback_t)message.out.payload;
                      cnf_ctx->user_ctx = message.out.cnf_ctx.cb;
                      uVar1 = zcl_packet_setup_response(rsp,packet,1);
                      if (uVar1 == 0) goto _L0;
                    }
                  }
                  else {
                    uVar1 = 0x89;
                  }
                }
                else {
                  uVar1 = 0x89;
                }
              }
              else {
                uVar1 = 0x89;
              }
            }
            else {
              uVar1 = 0x89;
            }
          }
          else {
            uVar1 = 0x89;
          }
        }
        else {
          uVar1 = 1;
        }
      }
    }
  }
  else {
    offset_00 = (uint16_t *)((int)&message.out.cnf_ctx.user_ctx + 2);
    af_read_le16(packet->payload,offset_00,(uint16_t *)&message.in);
    af_read_le32(packet->payload,offset_00,(uint32_t *)&message.in.payload);
    af_read_le8(packet->payload,offset_00,(uint8_t *)&message.in.payload.start_time);
    uVar1 = zmsg_get_length(packet->payload);
    if (message.out.cnf_ctx.user_ctx._2_2_ <= uVar1) goto _L0;
    uVar1 = 0x80;
  }
_L0:
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

