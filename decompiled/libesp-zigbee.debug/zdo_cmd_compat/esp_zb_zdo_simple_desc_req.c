/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_simple_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_simple_desc_req
               (esp_zb_zdo_simple_desc_req_param_t *cmd_req,
               esp_zb_zdo_simple_desc_callback_t user_cb,void *user_ctx)

{
  undefined4 local_20;
  ezb_zdo_simple_desc_req_t req;
  
  local_20 = 0;
  req.dst_nwk_addr = 0;
  req.field.nwk_addr_of_interest = 0;
  req.field.endpoint = '\0';
  req.field._3_1_ = 0;
  req._6_2_ = 0;
  req.cb = (ezb_zdo_simple_desc_req_callback_t)0x0;
  if ((cmd_req != (esp_zb_zdo_simple_desc_req_param_t *)0x0) &&
     (req.cb = (ezb_zdo_simple_desc_req_callback_t)calloc(1,0xc),
     req.cb != (ezb_zdo_simple_desc_req_callback_t)0x0)) {
    *(esp_zb_zdo_simple_desc_callback_t *)req.cb = user_cb;
    *(void **)(req.cb + 4) = user_ctx;
    req.dst_nwk_addr._0_1_ = cmd_req->endpoint;
    local_20 = CONCAT22(cmd_req->addr_of_interest,cmd_req->addr_of_interest);
    req._4_4_ = esp_zb_zdo_simple_desc_rsp_wrapper;
    ezb_zdo_simple_desc_req(&local_20);
  }
  return;
}

