/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_touchlink_send_ep_info_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_touchlink_send_ep_info_cmd_req
               (esp_zb_touchlink_send_endpoint_information_cmd_t *cmd_req)

{
  undefined1 auStack_3c [4];
  ezb_zcl_touchlink_ep_info_cmd_req_t req;
  
  memset(auStack_3c,0,0x2c);
  if (cmd_req != (esp_zb_touchlink_send_endpoint_information_cmd_t *)0x0) {
    convert_to_ezb_specific_cmd_ctrl
              ((ezb_zcl_cluster_cmd_ctrl_t *)auStack_3c,(esp_zb_zcl_specific_cmd_header_t *)cmd_req)
    ;
    auStack_3c[0] = '\0';
    req.ieee_addr.field_0.u64._4_2_ = ezb_nwk_get_short_address();
    ezb_nwk_get_extended_address(&req.cmd_ctrl.cnf_ctx.user_ctx);
    req.ieee_addr.field_0.u8[6] = cmd_req->endpoint_id;
    req.nwk_addr = cmd_req->profile_id;
    req._34_2_ = cmd_req->device_id;
    req.profile_id._0_1_ = cmd_req->device_version;
    ezb_zcl_touchlink_ep_info_cmd_req(auStack_3c);
  }
  return;
}

