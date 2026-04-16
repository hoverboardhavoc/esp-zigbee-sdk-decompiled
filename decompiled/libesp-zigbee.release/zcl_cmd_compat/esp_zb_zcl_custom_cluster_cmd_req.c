/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t esp_zb_zcl_custom_cluster_cmd_req(esp_zb_zcl_custom_cluster_cmd_req_t *cmd_req)

{
  uint8_t uVar1;
  int iVar2;
  uint uVar3;
  esp_zb_zcl_address_mode_t aeStack_34 [2];
  undefined1 auStack_32 [2];
  ezb_zcl_custom_cmd_t req;
  
  memset(aeStack_34,0,0x24);
  if (cmd_req != (esp_zb_zcl_custom_cluster_cmd_req_t *)0x0) {
    req.cmd_ctrl._16_4_ = get_zcl_send_status_cb_handle();
    uVar3._0_1_ = cmd_req->field_4;
    uVar3._1_1_ = cmd_req->field_0x11;
    uVar3._2_2_ = cmd_req->manuf_code;
    req.cmd_ctrl.cluster_id._0_1_ =
         (byte)(uVar3 >> 1) & 2 | (byte)uVar3 & 1 | (byte)(uVar3 >> 1) & 4 |
         (byte)req.cmd_ctrl.cluster_id & 0xf8;
    req.cmd_ctrl._10_2_ = cmd_req->manuf_code;
    aeStack_34[0] = cmd_req->address_mode;
    req.cmd_ctrl.dst_addr.u._4_1_ = (cmd_req->zcl_basic_cmd).dst_endpoint;
    req.cmd_ctrl.dst_addr.u._5_1_ = (cmd_req->zcl_basic_cmd).src_endpoint;
    req.cmd_ctrl.dst_addr.u._6_2_ = cmd_req->cluster_id;
    memcpy(auStack_32,cmd_req,8);
    req.cmd_ctrl.cnf_ctx.user_ctx._0_1_ = (undefined1)cmd_req->custom_cmd_id;
    req.cmd_ctrl.cnf_ctx.user_ctx._2_2_ = (cmd_req->data).size;
    req._28_4_ = (cmd_req->data).value;
    iVar2 = ezb_zcl_custom_cmd_req(aeStack_34);
    if (iVar2 == 0) {
      uVar1 = zcl_get_current_tsn();
      return uVar1;
    }
  }
  return 0xff;
}

