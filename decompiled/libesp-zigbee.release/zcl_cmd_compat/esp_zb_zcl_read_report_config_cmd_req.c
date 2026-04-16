/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_read_report_config_cmd_req
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
  
  memset(auStack_34,0,0x24);
  if (cmd_req != (esp_zb_zcl_read_report_config_cmd_t *)0x0) {
    convert_to_ezb_general_cmd_ctrl
              ((ezb_zcl_cmd_ctrl_t *)auStack_34,(esp_zb_zcl_general_cmd_header_t *)cmd_req);
    req.cmd_ctrl.cnf_ctx.user_ctx._0_2_ = cmd_req->record_number;
    req.payload._0_4_ = cmd_req->record_field;
    iVar2 = ezb_zcl_read_report_config_cmd_req(auStack_34);
    if (iVar2 == 0) {
      uVar1 = zcl_get_current_tsn();
      return uVar1;
    }
  }
  return 0xff;
}

