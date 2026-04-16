/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_touchlink_send_ep_info_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_touchlink_send_ep_info_cmd_req
               (esp_zb_touchlink_send_endpoint_information_cmd_t *cmd_req)

{
  undefined2 uVar1;
  undefined1 auStack_3c [4];
  ezb_zcl_touchlink_ep_info_cmd_req_t req;
  
  auStack_3c = (undefined1  [4])0x0;
  req.cmd_ctrl.dst_addr._0_4_ = 0;
  req.cmd_ctrl.dst_addr.u._2_4_ = 0;
  req.cmd_ctrl._8_4_ = 0;
  req.cmd_ctrl.dis_default_rsp = false;
  req.cmd_ctrl._13_3_ = 0;
  req.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  req.cmd_ctrl.cnf_ctx.user_ctx = (void *)0x0;
  req.ieee_addr.field_0.u64._0_4_ = 0;
  req.ieee_addr.field_0.u64._4_4_ = 0;
  req.nwk_addr = 0;
  req.ep_id = '\0';
  req._35_1_ = 0;
  req.profile_id = 0;
  req.device_id = 0;
  if (cmd_req != (esp_zb_touchlink_send_endpoint_information_cmd_t *)0x0) {
    convert_to_ezb_specific_cmd_ctrl
              ((ezb_zcl_cluster_cmd_ctrl_t *)auStack_3c,(esp_zb_zcl_specific_cmd_header_t *)cmd_req)
    ;
    auStack_3c = (undefined1  [4])((uint)auStack_3c & 0xffffff00);
    uVar1 = ezb_nwk_get_short_address();
    req.ieee_addr.field_0.u64._4_2_ = uVar1;
    ezb_nwk_get_extended_address(&req.cmd_ctrl.cnf_ctx.user_ctx);
    req.ieee_addr.field_0.u8[6] = cmd_req->endpoint_id;
    req._32_4_ = *(undefined4 *)&cmd_req->profile_id;
    req.profile_id._0_1_ = cmd_req->device_version;
    ezb_zcl_touchlink_ep_info_cmd_req((ezb_zcl_cluster_cmd_ctrl_t *)auStack_3c);
  }
  return;
}

