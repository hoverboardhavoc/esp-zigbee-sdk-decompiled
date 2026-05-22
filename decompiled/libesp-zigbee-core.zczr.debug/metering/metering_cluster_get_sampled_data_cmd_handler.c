/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_sampled_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
metering_cluster_get_sampled_data_cmd_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,ezb_zcl_cmd_cnf_ctx_t *cnf_ctx)

{
  uint uVar1;
  uint uVar2;
  uint16_t uVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  int iVar4;
  undefined4 local_50;
  uint16_t uStack_4a;
  uint uStack_48;
  uint16_t offset;
  ezb_zcl_metering_get_sampled_data_req_message_t message;
  
  uStack_48 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.sample_id = 0;
  message.in.payload._2_2_ = 0;
  message.in.payload.earliest_start_time = 0;
  message.in.payload.sample_type = '\0';
  message.in.payload._9_1_ = 0;
  message.in.payload.num_of_samples = 0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload = (ezb_zcl_metering_get_sampled_data_rsp_t *)0x0;
  message.out.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  uStack_4a = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x1ad,
                  "metering_cluster_get_sampled_data_cmd_handler","packet && rsp");
_L0:
    uVar3 = af_read_le32(packet->payload,&uStack_4a,(uint32_t *)&message.in.payload);
    if (CONCAT22(extraout_var_00,uVar3) == 0) {
      uVar1 = 0x80;
    }
    else {
      uVar3 = af_read_le8(packet->payload,&uStack_4a,
                          (uint8_t *)&message.in.payload.earliest_start_time);
      if (CONCAT22(extraout_var_01,uVar3) == 0) {
        uVar1 = 0x80;
      }
      else {
        uVar3 = af_read_le16(packet->payload,&uStack_4a,
                             (uint16_t *)((int)&message.in.payload.earliest_start_time + 2));
        if (CONCAT22(extraout_var_02,uVar3) == 0) {
          uVar1 = 0x80;
        }
        else {
          uVar1 = zmsg_get_length(packet->payload);
          if (uVar1 < uStack_4a) {
            uVar1 = 0x80;
          }
          else if (message.in.payload.earliest_start_time >> 0x10 == 0) {
            uVar1 = 0x87;
          }
          else {
            uVar1 = zcl_packet_to_message(&stack0xffffffb8,packet);
            if (uVar1 == 0) {
              message.in.payload.sample_type = 0xfe;
              message._4_4_ = packet;
              zcl_core_action_schedule(0x48,&stack0xffffffb8);
              uVar2 = message.in.payload._8_4_ & 0xff;
              if ((message.in.payload._8_4_ & 0xff) == 0xfe) {
                uVar2 = uVar1;
              }
              uVar1 = uVar2;
              if ((uStack_48 & 0xff) == 0xfe) {
                uVar1 = 0x8b;
              }
              else if (uVar1 == 0) {
                if (*(short *)(message.out._0_4_ + 0xc) == 0) {
                  uVar1 = 0x8b;
                }
                else if (*(int *)(message.out._0_4_ + 0x10) == 0) {
                  uVar1 = 0x8b;
                }
                else {
                  local_50 = CONCAT22(local_50._2_2_,*(undefined2 *)message.out._0_4_);
                  iVar4 = zmsg_append_bytes(rsp->payload,2,&local_50);
                  if (iVar4 == 0) {
                    local_50 = *(undefined4 *)(message.out._0_4_ + 4);
                    iVar4 = zmsg_append_bytes(rsp->payload,4,&local_50);
                    if (iVar4 == 0) {
                      local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(message.out._0_4_ + 8));
                      iVar4 = zmsg_append_bytes(rsp->payload,1,&local_50);
                      if (iVar4 == 0) {
                        local_50 = CONCAT22(local_50._2_2_,*(undefined2 *)(message.out._0_4_ + 10));
                        iVar4 = zmsg_append_bytes(rsp->payload,2,&local_50);
                        if (iVar4 == 0) {
                          local_50 = CONCAT22(local_50._2_2_,
                                              *(undefined2 *)(message.out._0_4_ + 0xc));
                          iVar4 = zmsg_append_bytes(rsp->payload,2,&local_50);
                          if (iVar4 == 0) {
                            uVar1 = message.in.payload.earliest_start_time >> 0x10;
                            if ((uint)*(ushort *)(message.out._0_4_ + 0xc) <
                                message.in.payload.earliest_start_time >> 0x10) {
                              uVar1 = (uint)*(ushort *)(message.out._0_4_ + 0xc);
                            }
                            for (uVar2 = 0; uVar2 < uVar1; uVar2 = uVar2 + 1 & 0xffff) {
                              iVar4 = zcl_packet_append_variable_attr_value
                                                (rsp->payload,0x22,
                                                 *(int *)(message.out._0_4_ + 0x10) + uVar2 * 4);
                              if (iVar4 != 0) {
                                uVar1 = 0x89;
                                goto _L0;
                              }
                            }
                            cnf_ctx->cb = (ezb_af_user_cnf_callback_t)message.out.payload;
                            cnf_ctx->user_ctx = message.out.cnf_ctx.cb;
                            uVar1 = zcl_packet_setup_response(rsp,packet,7);
                            if (uVar1 == 0) goto _L0;
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
              }
            }
          }
        }
      }
    }
  }
  else {
    uVar3 = af_read_le16(packet->payload,&uStack_4a,(uint16_t *)&message.in);
    if (CONCAT22(extraout_var,uVar3) != 0) goto _L0;
    uVar1 = 0x80;
  }
_L0:
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

