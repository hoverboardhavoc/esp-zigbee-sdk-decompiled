/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_profile_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
metering_cluster_get_profile_cmd_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,ezb_zcl_cmd_cnf_ctx_t *cnf_ctx)

{
  uint uVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  int iVar3;
  uint uVar4;
  undefined4 local_50;
  uint16_t uStack_4a;
  uint uStack_48;
  uint16_t offset;
  ezb_zcl_metering_get_profile_req_message_t message;
  
  uStack_48 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.interval_channel = '\0';
  message.in.payload._1_3_ = 0;
  message.in.payload.end_time = 0;
  message.in.payload.num_of_periods = '\0';
  message.in.payload._9_3_ = 0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload = (ezb_zcl_metering_get_profile_rsp_t *)0x0;
  message.out.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  uStack_4a = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x10a,
                  "metering_cluster_get_profile_cmd_handler","packet && rsp");
_L0:
    uVar2 = af_read_le32(packet->payload,&uStack_4a,(uint32_t *)&message.in.payload);
    if (CONCAT22(extraout_var_00,uVar2) == 0) {
      uVar1 = 0x80;
    }
    else {
      uVar2 = af_read_le8(packet->payload,&uStack_4a,(uint8_t *)&message.in.payload.end_time);
      if (CONCAT22(extraout_var_01,uVar2) == 0) {
        uVar1 = 0x80;
      }
      else {
        uVar1 = zmsg_get_length(packet->payload);
        if (uVar1 < uStack_4a) {
          uVar1 = 0x80;
        }
        else if ((message.in.payload.end_time & 0xff) == 0) {
          uVar1 = 0x87;
        }
        else {
          uVar1 = zcl_packet_to_message(&stack0xffffffb8,packet);
          if (uVar1 == 0) {
            message.in.payload.num_of_periods = 0xfe;
            message._4_4_ = packet;
            zcl_core_action_schedule(0x42,&stack0xffffffb8);
            uVar4 = message.in.payload._8_4_ & 0xff;
            if ((message.in.payload._8_4_ & 0xff) == 0xfe) {
              uVar4 = uVar1;
            }
            uVar1 = uVar4;
            if ((uStack_48 & 0xff) == 0xfe) {
              uVar1 = 0x8b;
            }
            else if (uVar1 == 0) {
              if (message.out._0_4_ == 0) {
                uVar1 = 1;
              }
              else {
                local_50 = *(undefined4 *)message.out._0_4_;
                iVar3 = zmsg_append_bytes(rsp->payload,4,&local_50);
                if (iVar3 == 0) {
                  local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(message.out._0_4_ + 4));
                  iVar3 = zmsg_append_bytes(rsp->payload,1,&local_50);
                  if (iVar3 == 0) {
                    local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(message.out._0_4_ + 8));
                    iVar3 = zmsg_append_bytes(rsp->payload,1,&local_50);
                    if (iVar3 == 0) {
                      local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(message.out._0_4_ + 0xc));
                      iVar3 = zmsg_append_bytes(rsp->payload,1,&local_50);
                      if (iVar3 == 0) {
                        uVar1 = (uint)*(byte *)(message.out._0_4_ + 0xc);
                        if ((uVar1 == 0) || (*(int *)(message.out._0_4_ + 0x10) != 0)) {
                          if ((message.in.payload.end_time & 0xff) < uVar1) {
                            uVar1 = message.in.payload.end_time & 0xff;
                          }
                          for (uVar4 = 0; uVar4 < uVar1; uVar4 = uVar4 + 1 & 0xff) {
                            iVar3 = zcl_packet_append_variable_attr_value
                                              (rsp->payload,0x22,
                                               *(int *)(message.out._0_4_ + 0x10) + uVar4 * 4);
                            if (iVar3 != 0) {
                              uVar1 = 0x89;
                              goto _L0;
                            }
                          }
                          cnf_ctx->cb = (ezb_af_user_cnf_callback_t)message.out.payload;
                          cnf_ctx->user_ctx = message.out.cnf_ctx.cb;
                          uVar1 = zcl_packet_setup_response(rsp,packet,0);
                          if (uVar1 == 0) goto _L0;
                        }
                        else {
                          uVar1 = 1;
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
  else {
    uVar2 = af_read_le8(packet->payload,&uStack_4a,(uint8_t *)&message.in);
    if (CONCAT22(extraout_var,uVar2) != 0) goto _L0;
    uVar1 = 0x80;
  }
_L0:
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

