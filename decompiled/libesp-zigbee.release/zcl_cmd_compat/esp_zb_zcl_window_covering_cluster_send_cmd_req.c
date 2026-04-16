/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_window_covering_cluster_send_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t esp_zb_zcl_window_covering_cluster_send_cmd_req
                  (esp_zb_zcl_window_covering_cluster_send_cmd_req_t *cmd_req)

{
  uint8_t uVar1;
  int iVar2;
  void *pvVar3;
  undefined1 *puVar4;
  undefined1 auStack_30 [4];
  ezb_zcl_window_covering_movement_cmd_t req;
  
  memset(auStack_30,0,0x20);
  if (cmd_req == (esp_zb_zcl_window_covering_cluster_send_cmd_req_t *)0x0) {
    return 0xff;
  }
  convert_to_ezb_specific_cmd_ctrl
            ((ezb_zcl_cluster_cmd_ctrl_t *)auStack_30,(esp_zb_zcl_specific_cmd_header_t *)cmd_req);
  req.cmd_ctrl.cnf_ctx.user_ctx = (void *)(uint)cmd_req->cmd_id;
  puVar4 = (undefined1 *)cmd_req->value;
  if (puVar4 == (undefined1 *)0x0) goto _L0;
  if (req.cmd_ctrl.cnf_ctx.user_ctx == (void *)0x7) {
_L0:
    req.cmd_id._0_1_ = *puVar4;
    req.cmd_id._1_1_ = puVar4[1];
  }
  else {
    if (req.cmd_ctrl.cnf_ctx.user_ctx < (void *)0x8) {
      if (req.cmd_ctrl.cnf_ctx.user_ctx == (void *)0x4) goto _L0;
      pvVar3 = (void *)0x5;
    }
    else {
      pvVar3 = (void *)0x8;
    }
    if (req.cmd_ctrl.cnf_ctx.user_ctx == pvVar3) {
      req.cmd_id._0_1_ = *puVar4;
    }
  }
_L0:
  iVar2 = ezb_zcl_window_covering_movement_cmd_req(auStack_30);
  if (iVar2 != 0) {
    return 0xff;
  }
  uVar1 = zcl_get_current_tsn();
  return uVar1;
}

