/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_touchlink_send_get_group_identifiers_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_touchlink_send_get_group_identifiers_cmd_req
               (esp_zb_touchlink_send_get_group_identifiers_cmd_t *cmd_req)

{
  undefined1 auStack_2c [4];
  ezb_zcl_touchlink_get_group_ids_cmd_req_t req;
  
  memset(auStack_2c,0,0x1c);
  if (cmd_req != (esp_zb_touchlink_send_get_group_identifiers_cmd_t *)0x0) {
    convert_to_ezb_specific_cmd_ctrl
              ((ezb_zcl_cluster_cmd_ctrl_t *)auStack_2c,(esp_zb_zcl_specific_cmd_header_t *)cmd_req)
    ;
    req.cmd_ctrl.cnf_ctx.user_ctx._0_1_ = cmd_req->start_index;
    auStack_2c[0] = '\0';
    ezb_zcl_touchlink_get_group_ids_cmd_req(auStack_2c);
  }
  return;
}

