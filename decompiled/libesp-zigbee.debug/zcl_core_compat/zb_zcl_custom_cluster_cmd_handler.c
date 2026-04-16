/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_core_compat.o -> zb_zcl_custom_cluster_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zb_zcl_custom_cluster_cmd_handler
          (ezb_zcl_cmd_hdr_t *header,uint8_t *payload,uint16_t payload_length)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined4 uStack_68;
  ezb_zcl_default_rsp_cmd_t default_rsp;
  esp_zb_zcl_custom_cluster_command_message_t message;
  
  if (s_core_action == (esp_zb_core_action_callback_t)0x0) {
    eVar1 = 0x81;
  }
  else {
    default_rsp.payload.tsn = '\0';
    default_rsp.payload.rsp_to_cmd = '\0';
    default_rsp.payload.status_code = '\0';
    default_rsp._31_1_ = 0;
    convert_to_esp_zb_zcl_cmd_info((esp_zb_zcl_cmd_info_t *)&default_rsp.payload,header);
    err = (*s_core_action)(ESP_ZB_CORE_CMD_CUSTOM_CLUSTER_REQ_CB_ID,&default_rsp.payload);
    eVar1 = esp_err_to_zcl_status(err);
    if ((header->fc & 0x10) == 0) {
      default_rsp.cmd_ctrl.fc = (anon_struct_1_3_9083e743_for_fc)0x0;
      default_rsp.cmd_ctrl._17_3_ = 0;
      default_rsp.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      default_rsp.cmd_ctrl.cnf_ctx.user_ctx = (void *)0x0;
      uStack_68 = *(undefined4 *)&header->src_addr;
      default_rsp.cmd_ctrl.dst_addr._0_4_ = *(undefined4 *)((int)&(header->src_addr).u + 2);
      default_rsp.cmd_ctrl.dst_addr.u._4_1_ = header->src_ep;
      default_rsp.cmd_ctrl.dst_addr.u.group_addr.bcast =
           *(undefined2 *)((int)&(header->src_addr).u + 6);
      default_rsp.cmd_ctrl.dst_addr.u._5_1_ = header->dst_ep;
      default_rsp.cmd_ctrl._10_2_ = header->manuf_code;
      default_rsp.cmd_ctrl.dst_addr.u._6_2_ = header->cluster_id;
      default_rsp.cmd_ctrl._12_4_ = (header->fc >> 3 & 1 ^ 1) << 1 | header->fc >> 2 & 1 | 4;
      ezb_zcl_default_rsp_cmd_req(&uStack_68);
    }
  }
  return eVar1;
}

