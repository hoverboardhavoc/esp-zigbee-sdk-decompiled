/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_get_snapshot_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
metering_cluster_get_snapshot_cmd_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,ezb_zcl_cmd_cnf_ctx_t *cnf_ctx)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  ezb_zcl_status_t eVar4;
  uint16_t uVar5;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  int iVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined4 uStack_54;
  uint16_t uStack_4e;
  uint uStack_4c;
  uint16_t offset;
  ezb_zcl_metering_get_snapshot_req_message_t message;
  
  uStack_4c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.earliest_start_time = 0;
  message.in.payload.latest_end_time = 0;
  message.in.payload.snapshot_offset = '\0';
  message.in.payload._9_3_ = 0;
  message.in.payload.snapshot_cause = 0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload = (ezb_zcl_metering_publish_snapshot_payload_t *)0x0;
  message.out.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  uStack_4e = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x156,
                  "metering_cluster_get_snapshot_cmd_handler","packet && rsp");
_L0:
    uVar5 = af_read_le32(packet->payload,&uStack_4e,&message.in.payload.earliest_start_time);
    if (CONCAT22(extraout_var_08,uVar5) == 0) {
      uVar3 = 0x80;
    }
    else {
      uVar5 = af_read_le8(packet->payload,&uStack_4e,(uint8_t *)&message.in.payload.latest_end_time)
      ;
      if (CONCAT22(extraout_var_09,uVar5) == 0) {
        uVar3 = 0x80;
      }
      else {
        uVar5 = af_read_le32(packet->payload,&uStack_4e,
                             (uint32_t *)&message.in.payload.snapshot_offset);
        if (CONCAT22(extraout_var_10,uVar5) == 0) {
          uVar3 = 0x80;
        }
        else {
          uVar3 = zmsg_get_length(packet->payload);
          if (uVar3 < uStack_4e) {
            uVar3 = 0x80;
          }
          else {
            uVar3 = zcl_packet_to_message(&stack0xffffffb4,packet);
            if (uVar3 == 0) {
              message.in.payload.snapshot_cause =
                   CONCAT31(message.in.payload.snapshot_cause._1_3_,0xfe);
              message._4_4_ = packet;
              zcl_core_action_schedule(0x46,&stack0xffffffb4);
              uVar2 = message.in.payload.snapshot_cause & 0xff;
              if ((message.in.payload.snapshot_cause & 0xff) == 0xfe) {
                uVar2 = uVar3;
              }
              uVar3 = uVar2;
              if ((uStack_4c & 0xff) == 0xfe) {
                uVar3 = 0x8b;
              }
              else if (uVar3 == 0) {
                uStack_54 = *(undefined4 *)message.out._0_4_;
                iVar6 = zmsg_append_bytes(rsp->payload,4,&uStack_54);
                if (iVar6 == 0) {
                  uStack_54 = *(undefined4 *)(message.out._0_4_ + 4);
                  iVar6 = zmsg_append_bytes(rsp->payload,4,&uStack_54);
                  if (iVar6 == 0) {
                    uStack_54 = CONCAT31(uStack_54._1_3_,*(undefined1 *)(message.out._0_4_ + 8));
                    iVar6 = zmsg_append_bytes(rsp->payload,1,&uStack_54);
                    if (iVar6 == 0) {
                      uStack_54 = CONCAT31(uStack_54._1_3_,*(undefined1 *)(message.out._0_4_ + 9));
                      iVar6 = zmsg_append_bytes(rsp->payload,1,&uStack_54);
                      if (iVar6 == 0) {
                        uStack_54 = CONCAT31(uStack_54._1_3_,*(undefined1 *)(message.out._0_4_ + 10)
                                            );
                        iVar6 = zmsg_append_bytes(rsp->payload,1,&uStack_54);
                        if (iVar6 == 0) {
                          uStack_54 = *(undefined4 *)(message.out._0_4_ + 0xc);
                          iVar6 = zmsg_append_bytes(rsp->payload,4,&uStack_54);
                          if (iVar6 == 0) {
                            uStack_54 = CONCAT31(uStack_54._1_3_,
                                                 *(undefined1 *)(message.out._0_4_ + 0x10));
                            iVar6 = zmsg_append_bytes(rsp->payload,1,&uStack_54);
                            if (iVar6 == 0) {
                              bVar1 = *(byte *)(message.out._0_4_ + 0x10);
                              if (bVar1 == 4) {
                                eVar4 = append_tou_info_no_billing_set_to_payload
                                                  (rsp->payload,
                                                   (ezb_zcl_metering_tou_info_no_billing_set_t *)
                                                   (message.out._0_4_ + 0x18));
                                uVar3 = CONCAT31(extraout_var_04,eVar4);
                              }
                              else if (bVar1 < 5) {
                                if (bVar1 == 2) {
                                  eVar4 = append_block_info_set_to_payload
                                                    (rsp->payload,
                                                     (ezb_zcl_metering_block_info_set_t *)
                                                     (message.out._0_4_ + 0x18));
                                  uVar3 = CONCAT31(extraout_var_03,eVar4);
                                }
                                else if (bVar1 < 3) {
                                  if (bVar1 == 0) {
                                    eVar4 = append_tou_info_set_to_payload
                                                      (rsp->payload,
                                                       (ezb_zcl_metering_tou_info_set_t *)
                                                       (message.out._0_4_ + 0x18));
                                    uVar3 = CONCAT31(extraout_var_02,eVar4);
                                  }
                                  else {
                                    if (bVar1 != 1) {
                                      uVar3 = 1;
                                      goto _L0;
                                    }
                                    eVar4 = append_tou_info_set_to_payload
                                                      (rsp->payload,
                                                       (ezb_zcl_metering_tou_info_set_t *)
                                                       (message.out._0_4_ + 0x18));
                                    uVar3 = CONCAT31(extraout_var,eVar4);
                                  }
                                }
                                else {
                                  if (bVar1 != 3) {
                                    uVar3 = 1;
                                    goto _L0;
                                  }
                                  eVar4 = append_block_info_set_to_payload
                                                    (rsp->payload,
                                                     (ezb_zcl_metering_block_info_set_t *)
                                                     (message.out._0_4_ + 0x18));
                                  uVar3 = CONCAT31(extraout_var_00,eVar4);
                                }
                              }
                              else if (bVar1 == 6) {
                                eVar4 = append_block_info_no_billing_set_to_payload
                                                  (rsp->payload,
                                                   (ezb_zcl_metering_block_info_no_billing_set_t *)
                                                   (message.out._0_4_ + 0x18));
                                uVar3 = CONCAT31(extraout_var_05,eVar4);
                              }
                              else if (bVar1 == 7) {
                                eVar4 = append_block_info_no_billing_set_to_payload
                                                  (rsp->payload,
                                                   (ezb_zcl_metering_block_info_no_billing_set_t *)
                                                   (message.out._0_4_ + 0x18));
                                uVar3 = CONCAT31(extraout_var_06,eVar4);
                              }
                              else {
                                if (bVar1 != 5) {
                                  uVar3 = 1;
                                  goto _L0;
                                }
                                eVar4 = append_tou_info_no_billing_set_to_payload
                                                  (rsp->payload,
                                                   (ezb_zcl_metering_tou_info_no_billing_set_t *)
                                                   (message.out._0_4_ + 0x18));
                                uVar3 = CONCAT31(extraout_var_01,eVar4);
                              }
                              if (uVar3 == 0) {
                                cnf_ctx->cb = (ezb_af_user_cnf_callback_t)message.out.payload;
                                cnf_ctx->user_ctx = message.out.cnf_ctx.cb;
                                uVar3 = zcl_packet_setup_response(rsp,packet,6);
                                if (uVar3 == 0) goto _L0;
                              }
                            }
                            else {
                              uVar3 = 0x89;
                            }
                          }
                          else {
                            uVar3 = 0x89;
                          }
                        }
                        else {
                          uVar3 = 0x89;
                        }
                      }
                      else {
                        uVar3 = 0x89;
                      }
                    }
                    else {
                      uVar3 = 0x89;
                    }
                  }
                  else {
                    uVar3 = 0x89;
                  }
                }
                else {
                  uVar3 = 0x89;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    uVar5 = af_read_le32(packet->payload,&uStack_4e,(uint32_t *)&message.in);
    if (CONCAT22(extraout_var_07,uVar5) != 0) goto _L0;
    uVar3 = 0x80;
  }
_L0:
  uVar3 = zcl_packet_setup_default_response(rsp,packet,uVar3);
_L0:
  return (ezb_zcl_status_t)uVar3;
}

