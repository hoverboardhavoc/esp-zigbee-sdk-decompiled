/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_bypass_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_ace_cluster_bypass_cmd_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,ezb_zcl_cmd_cnf_ctx_t *cnf_ctx)

{
  size_t unaff_s1;
  uint uVar1;
  ezb_zcl_status_t eVar2;
  undefined3 extraout_var;
  int iVar3;
  uint16_t *offset_00;
  byte bStack_55;
  undefined4 uStack_54;
  ezb_zcl_ias_ace_bypass_message_t message;
  uint16_t offset;
  
  message.out.cnf_ctx.user_ctx._2_2_ = 0;
  uStack_54 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.num_of_zones = '\0';
  message.in.payload._1_3_ = 0;
  message.in.payload.zone_id = (uint8_t *)0x0;
  message.in.payload.arm_disarm_code[0] = '\0';
  message.in.payload.arm_disarm_code[1] = '\0';
  message.in.payload.arm_disarm_code[2] = '\0';
  message.in.payload.arm_disarm_code[3] = '\0';
  message.in.payload.arm_disarm_code[4] = '\0';
  message.in.payload.arm_disarm_code[5] = '\0';
  message.in.payload.arm_disarm_code[6] = '\0';
  message.in.payload.arm_disarm_code[7] = '\0';
  message.in.payload.arm_disarm_code[8] = '\0';
  message.in.payload._17_3_ = 0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload = (ezb_zcl_ias_ace_bypass_rsp_payload_t *)0x0;
  message.out.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0xf7,
                  "ias_ace_cluster_bypass_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,(uint16_t *)((int)&message.out.cnf_ctx.user_ctx + 2),
                (uint8_t *)&message.in);
    unaff_s1 = (uint)message.in.header & 0xff;
    if (unaff_s1 == 0) {
      uVar1 = 0x87;
      goto _L0;
    }
  }
  message.in.payload._0_4_ = calloc(1,unaff_s1);
  if ((uint8_t *)message.in.payload._0_4_ == (uint8_t *)0x0) {
    uVar1 = 0x89;
  }
  else {
    offset_00 = (uint16_t *)((int)&message.out.cnf_ctx.user_ctx + 2);
    af_read_bytes(packet->payload,offset_00,(uint16_t)unaff_s1,(uint8_t *)message.in.payload._0_4_);
    eVar2 = read_zcl_string(packet->payload,offset_00,(uint8_t *)&message.in.payload.zone_id,'\t');
    if (CONCAT31(extraout_var,eVar2) == 0) {
      uVar1 = zcl_packet_to_message(&uStack_54,packet);
      if (uVar1 == 0) {
        message.in.payload.arm_disarm_code[8] = 0xfe;
        message._4_4_ = packet;
        zcl_core_action_schedule(0x1d,&uStack_54);
        uVar1 = message.in.payload._16_4_ & 0xff;
        if (uVar1 == 0xfe) {
          uVar1 = 1;
        }
        else if (uVar1 == 0) {
          cnf_ctx->cb = (ezb_af_user_cnf_callback_t)message.out.payload;
          cnf_ctx->user_ctx = message.out.cnf_ctx.cb;
          if (message.out._0_4_ == 0) {
            uVar1 = 1;
          }
          else if ((uint)*(byte *)message.out._0_4_ == ((uint)message.in.header & 0xff)) {
            if (*(int *)(message.out._0_4_ + 4) == 0) {
              uVar1 = 1;
            }
            else {
              bStack_55 = *(byte *)message.out._0_4_;
              iVar3 = zmsg_append_bytes(rsp->payload,1,&bStack_55);
              if (iVar3 == 0) {
                iVar3 = zmsg_append_bytes(rsp->payload,*(undefined1 *)message.out._0_4_,
                                          *(undefined4 *)(message.out._0_4_ + 4));
                if (iVar3 == 0) {
                  uVar1 = zcl_packet_setup_response(rsp,packet,7);
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
          else {
            uVar1 = 1;
          }
        }
      }
    }
    else {
      uVar1 = 0x80;
    }
  }
_L0:
  if (message.in.payload._0_4_ != 0) {
    mm_free();
  }
  if (uVar1 != 0) {
    uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
  }
  return (ezb_zcl_status_t)uVar1;
}

