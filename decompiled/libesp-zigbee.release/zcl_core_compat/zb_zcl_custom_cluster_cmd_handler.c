/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> zb_zcl_custom_cluster_cmd_handler
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
  byte bVar1;
  esp_zb_core_action_callback_t p_Var2;
  esp_err_t eVar3;
  ezb_zcl_status_t eVar4;
  undefined1 auStack_68 [4];
  ezb_zcl_default_rsp_cmd_t default_rsp;
  esp_zb_zcl_custom_cluster_command_message_t message;
  
  p_Var2 = s_core_action;
  eVar4 = 0x81;
  if (s_core_action != (esp_zb_core_action_callback_t)0x0) {
    memset(&default_rsp.payload,0,0x24);
    message.info.header.manuf_code._0_1_ = (header->src_addr).addr_mode;
    memcpy(&message.info.src_address,&(header->src_addr).u,8);
    message.info.dst_address = header->cluster_id;
    message.info._22_2_ = header->profile_id;
    message.info.src_address.u._6_1_ = header->src_ep;
    message.info.src_address.u._7_1_ = header->dst_ep;
    message.info._0_2_ = header->manuf_code;
    default_rsp.payload.status_code = header->fc;
    message.info.header.fc = header->tsn;
    message.info.header._1_1_ = header->rssi;
    message.info.cluster._0_1_ = header->cmd_id;
    message.info.cluster._1_1_ = default_rsp.payload.status_code >> 3 & 1;
    message.info.profile._0_1_ = (default_rsp.payload.status_code & 3) == 0;
    message.info.command._0_2_ = payload_length;
    message.data._0_4_ = payload;
    eVar3 = (*p_Var2)(ESP_ZB_CORE_CMD_CUSTOM_CLUSTER_REQ_CB_ID,&default_rsp.payload);
    eVar4 = '\0';
    if ((((eVar3 != 0) && (eVar4 = 0x89, eVar3 != 0x101)) && (eVar4 = 0x87, eVar3 != 0x102)) &&
       ((eVar4 = 0x8b, eVar3 != 0x105 && (eVar4 = 0x94, eVar3 != 0x107)))) {
      eVar4 = '\x01';
    }
    bVar1 = header->fc;
    if ((bVar1 & 0x10) == 0) {
      default_rsp.cmd_ctrl.cluster_id = 0;
      default_rsp.cmd_ctrl.manuf_code = 0;
      default_rsp.cmd_ctrl.fc = (anon_struct_1_3_9083e743_for_fc)0x0;
      default_rsp.cmd_ctrl._17_3_ = 0;
      default_rsp.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      default_rsp.cmd_ctrl.cnf_ctx.user_ctx = (void *)0x0;
      memcpy(auStack_68,header,10);
      default_rsp.cmd_ctrl.dst_addr.u._6_2_ = header->cluster_id;
      default_rsp.cmd_ctrl.dst_addr.u._4_1_ = header->src_ep;
      default_rsp.cmd_ctrl.dst_addr.u._5_1_ = header->dst_ep;
      default_rsp.cmd_ctrl._10_2_ = header->manuf_code;
      default_rsp.cmd_ctrl.cluster_id._0_1_ =
           (byte)((bVar1 >> 3 & 1 ^ 1) << 1) | bVar1 >> 2 & 1 | 4 |
           (byte)default_rsp.cmd_ctrl._12_4_ & 0xf8;
      ezb_zcl_default_rsp_cmd_req(auStack_68);
    }
  }
  return eVar4;
}

