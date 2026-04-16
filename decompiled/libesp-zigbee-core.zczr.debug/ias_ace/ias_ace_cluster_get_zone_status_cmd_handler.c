/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_status_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_ace_cluster_get_zone_status_cmd_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,ezb_zcl_cmd_cnf_ctx_t *cnf_ctx)

{
  uint16_t *offset_00;
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 uStack_4a;
  undefined4 uStack_48;
  ezb_zcl_ias_ace_get_zone_status_message_t message;
  uint16_t offset;
  
  message.out.cnf_ctx.user_ctx._2_2_ = 0;
  uStack_48 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.starting_zone_id = '\0';
  message.in.payload.max_num_zone_ids = '\0';
  message.in.payload.zone_status_mask_flag = '\0';
  message.in.payload._3_1_ = 0;
  message.in.payload.zone_status_mask = 0;
  message.in._10_2_ = 0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload = (ezb_zcl_ias_ace_get_zone_status_rsp_payload_t *)0x0;
  message.out.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x1cc,
                  "ias_ace_cluster_get_zone_status_cmd_handler","packet && rsp");
_L0:
    uVar1 = zcl_packet_to_message(&uStack_48,packet);
    if (uVar1 == 0) {
      if (((uint)message.in.header & 0xff) + ((uint)message.in.header >> 8 & 0xff) < 0xff) {
        message.in.payload.zone_status_mask._0_1_ = 0xfe;
        message._4_4_ = packet;
        zcl_core_action_schedule(0x22,&uStack_48);
        uVar1 = message.in._8_4_ & 0xff;
        if (uVar1 == 0xfe) {
          uVar1 = 0x8b;
        }
        else if (uVar1 == 0) {
          cnf_ctx->cb = (ezb_af_user_cnf_callback_t)message.out.payload;
          cnf_ctx->user_ctx = message.out.cnf_ctx.cb;
          if (message.out._0_4_ == 0) {
            uVar1 = 1;
          }
          else {
            uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)message.out._0_4_);
            iVar2 = zmsg_append_bytes(rsp->payload,1,&uStack_4a);
            if (iVar2 == 0) {
              uVar4 = (uint)message.in.header >> 8 & 0xff;
              uVar1 = (uint)*(byte *)(message.out._0_4_ + 1);
              if (uVar4 < *(byte *)(message.out._0_4_ + 1)) {
                uVar1 = uVar4;
              }
              uStack_4a = CONCAT11(uStack_4a._1_1_,(char)uVar1);
              iVar2 = zmsg_append_bytes(rsp->payload,1,&uStack_4a);
              if (iVar2 == 0) {
                iVar2 = 0;
                if ((uVar1 == 0) || (*(int *)(message.out._0_4_ + 4) != 0)) {
                  for (; iVar2 < (int)uVar1; iVar2 = iVar2 + 1) {
                    uStack_4a = CONCAT11(uStack_4a._1_1_,
                                         *(undefined1 *)
                                          (*(int *)(message.out._0_4_ + 4) + iVar2 * 4));
                    iVar3 = zmsg_append_bytes(rsp->payload,1,&uStack_4a);
                    if (iVar3 != 0) {
                      uVar1 = 0x89;
                      goto _L0;
                    }
                    uStack_4a = *(undefined2 *)(*(int *)(message.out._0_4_ + 4) + iVar2 * 4 + 2);
                    iVar3 = zmsg_append_bytes(rsp->payload,2,&uStack_4a);
                    if (iVar3 != 0) {
                      uVar1 = 0x89;
                      goto _L0;
                    }
                  }
                  uVar1 = zcl_packet_setup_response(rsp,packet,8);
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
        }
      }
      else {
        uVar1 = 0x87;
      }
    }
  }
  else {
    offset_00 = (uint16_t *)((int)&message.out.cnf_ctx.user_ctx + 2);
    af_read_le8(packet->payload,offset_00,(uint8_t *)&message.in);
    af_read_le8(packet->payload,offset_00,(uint8_t *)((int)&message.in.header + 1));
    af_read_le8(packet->payload,offset_00,(uint8_t *)((int)&message.in.header + 2));
    af_read_le16(packet->payload,offset_00,(uint16_t *)&message.in.payload);
    uVar1 = zmsg_get_length(packet->payload);
    if (message.out.cnf_ctx.user_ctx._2_2_ <= uVar1) goto _L0;
    uVar1 = 0x80;
  }
_L0:
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

