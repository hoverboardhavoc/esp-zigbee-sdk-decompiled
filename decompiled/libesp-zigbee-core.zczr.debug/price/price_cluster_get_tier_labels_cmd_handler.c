/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_get_tier_labels_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
price_cluster_get_tier_labels_cmd_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,ezb_zcl_cmd_cnf_ctx_t *cnf_ctx)

{
  uint uVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  int iVar3;
  undefined4 uStack_48;
  uint16_t uStack_42;
  undefined4 uStack_40;
  uint16_t offset;
  ezb_zcl_price_get_tier_labels_message_t message;
  
  uStack_40 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.issuer_tariff_id = 0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload = (ezb_zcl_price_publish_tier_labels_payload_t *)0x0;
  message.out.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  uStack_42 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0x8d,
                  "price_cluster_get_tier_labels_cmd_handler","packet && rsp");
_L0:
    uVar1 = zcl_packet_to_message(&stack0xffffffc0,packet);
    if (uVar1 == 0) {
      message.in.issuer_tariff_id = CONCAT31(message.in.issuer_tariff_id._1_3_,0xfe);
      message._4_4_ = packet;
      zcl_core_action_schedule(0x4c,&stack0xffffffc0);
      uVar1 = message.in.issuer_tariff_id & 0xff;
      if (uVar1 == 0xfe) {
        uVar1 = 0x8b;
      }
      else if (uVar1 == 0) {
        cnf_ctx->cb = (ezb_af_user_cnf_callback_t)message.out.payload;
        cnf_ctx->user_ctx = message.out.cnf_ctx.cb;
        if (message.out._0_4_ == 0) {
          uVar1 = 0x8b;
        }
        else {
          uStack_48 = *(undefined4 *)message.out._0_4_;
          iVar3 = zmsg_append_bytes(rsp->payload,4,&uStack_48);
          if (iVar3 == 0) {
            uStack_48 = *(undefined4 *)(message.out._0_4_ + 4);
            iVar3 = zmsg_append_bytes(rsp->payload,4,&uStack_48);
            if (iVar3 == 0) {
              uStack_48 = *(undefined4 *)(message.out._0_4_ + 8);
              iVar3 = zmsg_append_bytes(rsp->payload,4,&uStack_48);
              if (iVar3 == 0) {
                uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(message.out._0_4_ + 0xc));
                iVar3 = zmsg_append_bytes(rsp->payload,1,&uStack_48);
                if (iVar3 == 0) {
                  uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(message.out._0_4_ + 0xd));
                  iVar3 = zmsg_append_bytes(rsp->payload,1,&uStack_48);
                  if (iVar3 == 0) {
                    uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(message.out._0_4_ + 0xe));
                    iVar3 = zmsg_append_bytes(rsp->payload,1,&uStack_48);
                    if (iVar3 == 0) {
                      if (*(char *)(message.out._0_4_ + 0xe) == '\0') {
                        uVar1 = 0;
                      }
                      else {
                        uVar1 = 0;
                        if (*(int *)(message.out._0_4_ + 0x10) == 0) {
                          uVar1 = 1;
                          goto _L0;
                        }
                      }
                      for (; uVar1 < *(byte *)(message.out._0_4_ + 0xe); uVar1 = uVar1 + 1 & 0xff) {
                        uStack_48 = CONCAT31(uStack_48._1_3_,
                                             *(undefined1 *)
                                              (*(int *)(message.out._0_4_ + 0x10) + uVar1 * 0xe));
                        iVar3 = zmsg_append_bytes(rsp->payload,1,&uStack_48);
                        if (iVar3 != 0) {
                          uVar1 = 0x89;
                          goto _L0;
                        }
                        iVar3 = *(int *)(message.out._0_4_ + 0x10) + uVar1 * 0xe;
                        iVar3 = zmsg_append_bytes(rsp->payload,*(byte *)(iVar3 + 1) + 1,iVar3 + 1);
                        if (iVar3 != 0) {
                          uVar1 = 0x89;
                          goto _L0;
                        }
                      }
                      uVar1 = zcl_packet_setup_response(rsp,packet,8);
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
          else {
            uVar1 = 0x89;
          }
        }
      }
    }
  }
  else {
    uVar2 = af_read_le32(packet->payload,&uStack_42,(uint32_t *)&message.in);
    if (CONCAT22(extraout_var,uVar2) == 4) goto _L0;
    uVar1 = 0x80;
  }
_L0:
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

