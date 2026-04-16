/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_read_report_config_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t esp_zb_zcl_read_report_config_cmd_req(esp_zb_zcl_read_report_config_cmd_t *cmd_req)

{
  uint8_t uVar1;
  int iVar2;
  undefined1 auStack_34 [4];
  ezb_zcl_read_report_config_cmd_t req;
  
  auStack_34 = (undefined1  [4])0x0;
  req.cmd_ctrl.dst_addr._0_4_ = 0;
  req.cmd_ctrl.dst_addr.u._2_4_ = 0;
  req.cmd_ctrl._8_4_ = 0;
  req.cmd_ctrl.cluster_id = 0;
  req.cmd_ctrl.manuf_code = 0;
  req.cmd_ctrl.fc = (anon_struct_1_3_9083e743_for_fc)0x0;
  req.cmd_ctrl._17_3_ = 0;
  req.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  req.cmd_ctrl.cnf_ctx.user_ctx = (void *)0x0;
  req.payload.record_number = 0;
  req.payload._2_2_ = 0;
  if (cmd_req == (esp_zb_zcl_read_report_config_cmd_t *)0x0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","%s(%d): Invalid Argument","esp_zb_zcl_read_report_config_cmd_req"
            ,0x12d);
    uVar1 = 0xff;
  }
  else {
    convert_to_ezb_general_cmd_ctrl
              ((ezb_zcl_cmd_ctrl_t *)auStack_34,(esp_zb_zcl_general_cmd_header_t *)cmd_req);
    req.cmd_ctrl.cnf_ctx.user_ctx =
         (void *)CONCAT22(req.cmd_ctrl.cnf_ctx.user_ctx._2_2_,cmd_req->record_number);
    req.payload._0_4_ = cmd_req->record_field;
    iVar2 = ezb_zcl_read_report_config_cmd_req((ezb_zcl_cmd_ctrl_t *)auStack_34);
    if (iVar2 == 0) {
      uVar1 = zcl_get_current_tsn();
    }
    else {
      uVar1 = 0xff;
    }
  }
  return uVar1;
}

