/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_nwk_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_nwk_addr_req
               (esp_zb_zdo_nwk_addr_req_param_t *cmd_req,esp_zb_zdo_nwk_addr_callback_t user_cb,
               void *user_ctx)

{
  undefined4 uStack_24;
  ezb_zdo_nwk_addr_req_t req;
  
  uStack_24 = 0;
  req._0_4_ = 0;
  req.field.ieee_addr_of_interest.field_0.u64._2_4_ = 0;
  req.field._6_4_ = 0;
  req.cb = (ezb_zdo_nwk_addr_req_callback_t)0x0;
  if ((cmd_req != (esp_zb_zdo_nwk_addr_req_param_t *)0x0) &&
     (req.cb = (ezb_zdo_nwk_addr_req_callback_t)calloc(1,0xc),
     req.cb != (ezb_zdo_nwk_addr_req_callback_t)0x0)) {
    *(esp_zb_zdo_nwk_addr_callback_t *)req.cb = user_cb;
    *(void **)(req.cb + 4) = user_ctx;
    req._0_4_ = *(undefined4 *)(cmd_req->ieee_addr_of_interest + 2);
    req.field.ieee_addr_of_interest.field_0.u64._2_4_ =
         *(undefined4 *)(cmd_req->ieee_addr_of_interest + 6);
    uStack_24._0_2_ = cmd_req->dst_nwk_addr;
    uStack_24._2_1_ = cmd_req->ieee_addr_of_interest[0];
    uStack_24._3_1_ = cmd_req->ieee_addr_of_interest[1];
    req.field._6_4_ = esp_zb_zdo_nwk_addr_rsp_wrapper;
    ezb_zdo_nwk_addr_req(&uStack_24);
  }
  return;
}

