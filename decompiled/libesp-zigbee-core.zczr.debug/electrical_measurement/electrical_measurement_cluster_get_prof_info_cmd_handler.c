/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_get_prof_info_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
electrical_measurement_cluster_get_prof_info_cmd_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,ezb_zcl_cmd_cnf_ctx_t *cnf_ctx)

{
  uint uVar1;
  int iVar2;
  undefined2 uStack_42;
  undefined4 uStack_40;
  ezb_zcl_electrical_measurement_get_prof_info_message_t message;
  
  uStack_40 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.out.result = '\0';
  message.out._1_3_ = 0;
  message.out.payload = (ezb_zcl_electrical_measurement_get_prof_info_rsp_payload_t *)0x0;
  message.out.num_of_attr_being_profiled = '\0';
  message.out._9_3_ = 0;
  message.out.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement.c",0x57,
                  "electrical_measurement_cluster_get_prof_info_cmd_handler","packet && rsp");
_L0:
    message.in.header._0_1_ = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x3e,&uStack_40);
    uVar1 = (uint)message.in.header & 0xff;
    if (uVar1 == 0xfe) {
      uVar1 = 1;
    }
    else if (uVar1 == 0) {
      if (message.out._0_4_ == 0) {
        uVar1 = 1;
      }
      else if ((((uint)message.out.payload & 0xff) == 0) || (*(int *)(message.out._0_4_ + 4) != 0))
      {
        uStack_42 = CONCAT11(uStack_42._1_1_,*(undefined1 *)message.out._0_4_);
        iVar2 = zmsg_append_bytes(rsp->payload,1,&uStack_42);
        if (iVar2 == 0) {
          uStack_42 = CONCAT11(uStack_42._1_1_,*(undefined1 *)(message.out._0_4_ + 1));
          iVar2 = zmsg_append_bytes(rsp->payload,1,&uStack_42);
          if (iVar2 == 0) {
            uStack_42 = CONCAT11(uStack_42._1_1_,*(undefined1 *)(message.out._0_4_ + 2));
            iVar2 = zmsg_append_bytes(rsp->payload,1,&uStack_42);
            uVar1 = 0;
            if (iVar2 == 0) {
              for (; uVar1 < ((uint)message.out.payload & 0xff); uVar1 = uVar1 + 1 & 0xff) {
                uStack_42 = *(undefined2 *)(*(int *)(message.out._0_4_ + 4) + uVar1 * 2);
                iVar2 = zmsg_append_bytes(rsp->payload,2,&uStack_42);
                if (iVar2 != 0) {
                  uVar1 = 0x89;
                  goto _L0;
                }
              }
              cnf_ctx->cb = (ezb_af_user_cnf_callback_t)message.out._8_4_;
              cnf_ctx->user_ctx = message.out.cnf_ctx.cb;
              uVar1 = zcl_packet_setup_response(rsp,packet,0);
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
        uVar1 = 1;
      }
    }
  }
  else {
    uVar1 = zcl_packet_to_message(&uStack_40,packet);
    if (uVar1 == 0) goto _L0;
  }
_L0:
  uVar1 = zcl_packet_setup_default_response(rsp,packet,uVar1);
_L0:
  return (ezb_zcl_status_t)uVar1;
}

