/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_lqi_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_mgmt_lqi_req
               (esp_zb_zdo_mgmt_lqi_req_param_t *cmd_req,esp_zb_zdo_mgmt_lqi_rsp_callback_t user_cb,
               void *user_ctx)

{
  uint8_t uVar1;
  undefined4 uStack_1c;
  ezb_zdo_nwk_mgmt_lqi_req_t req;
  
  uStack_1c = 0;
  req.dst_nwk_addr = 0;
  req.field.start_index = '\0';
  req._3_1_ = 0;
  req.cb = (ezb_zdo_nwk_mgmt_lqi_req_callback_t)0x0;
  if ((cmd_req != (esp_zb_zdo_mgmt_lqi_req_param_t *)0x0) &&
     (req.cb = (ezb_zdo_nwk_mgmt_lqi_req_callback_t)calloc(1,0xc),
     req.cb != (ezb_zdo_nwk_mgmt_lqi_req_callback_t)0x0)) {
    uVar1 = cmd_req->start_index;
    *(esp_zb_zdo_mgmt_lqi_rsp_callback_t *)req.cb = user_cb;
    *(void **)(req.cb + 4) = user_ctx;
    uStack_1c = CONCAT22(CONCAT11(uStack_1c._3_1_,uVar1),cmd_req->dst_addr);
    req._0_4_ = esp_zb_zdo_mgmt_lqi_rsp_wrapper;
    ezb_zdo_nwk_mgmt_lqi_req(&uStack_1c);
  }
  return;
}

