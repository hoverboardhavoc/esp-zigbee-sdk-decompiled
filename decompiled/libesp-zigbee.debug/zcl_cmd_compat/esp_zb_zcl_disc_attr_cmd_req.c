/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_disc_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t esp_zb_zcl_disc_attr_cmd_req(esp_zb_zcl_disc_attr_cmd_t *cmd_req)

{
  undefined3 uVar1;
  uint8_t uVar2;
  int iVar3;
  undefined1 local_30 [4];
  ezb_zcl_disc_attr_cmd_t req;
  
  local_30 = (undefined1  [4])0x0;
  req.cmd_ctrl.dst_addr._0_4_ = 0;
  req.cmd_ctrl.dst_addr.u._2_4_ = 0;
  req.cmd_ctrl._8_4_ = 0;
  req.cmd_ctrl.cluster_id = 0;
  req.cmd_ctrl.manuf_code = 0;
  req.cmd_ctrl.fc = (anon_struct_1_3_9083e743_for_fc)0x0;
  req.cmd_ctrl._17_3_ = 0;
  req.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  req.cmd_ctrl.cnf_ctx.user_ctx = (void *)0x0;
  if (cmd_req == (esp_zb_zcl_disc_attr_cmd_t *)0x0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","%s(%d): Invalid Argument","esp_zb_zcl_disc_attr_cmd_req",0x148);
    uVar2 = 0xff;
  }
  else {
    convert_to_ezb_general_cmd_ctrl
              ((ezb_zcl_cmd_ctrl_t *)local_30,(esp_zb_zcl_general_cmd_header_t *)cmd_req);
    uVar1._0_2_ = cmd_req->start_attr_id;
    uVar1._2_1_ = cmd_req->max_attr_number;
    req.cmd_ctrl.cnf_ctx.user_ctx = (void *)CONCAT13(req.cmd_ctrl.cnf_ctx.user_ctx._3_1_,uVar1);
    iVar3 = ezb_zcl_disc_attr_cmd_req(local_30);
    if (iVar3 == 0) {
      uVar2 = zcl_get_current_tsn();
    }
    else {
      uVar2 = 0xff;
    }
  }
  return uVar2;
}

