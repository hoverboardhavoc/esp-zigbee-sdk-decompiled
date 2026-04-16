/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_ieee_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_ieee_addr_req
               (esp_zb_zdo_ieee_addr_req_param_t *cmd_req,esp_zb_zdo_ieee_addr_callback_t user_cb,
               void *user_ctx)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  ezb_zdo_ieee_addr_req_t req;
  
  local_20 = 0;
  req.dst_nwk_addr = 0;
  req.field.nwk_addr_of_interest = 0;
  req.field.request_type = '\0';
  req.field.start_index = '\0';
  req._6_2_ = 0;
  req.cb = (ezb_zdo_ieee_addr_req_callback_t)0x0;
  if ((cmd_req != (esp_zb_zdo_ieee_addr_req_param_t *)0x0) &&
     (req.cb = (ezb_zdo_ieee_addr_req_callback_t)calloc(1,0xc), uVar3 = req._0_4_,
     req.cb != (ezb_zdo_ieee_addr_req_callback_t)0x0)) {
    local_20._0_2_ = cmd_req->dst_nwk_addr;
    local_20._2_2_ = cmd_req->addr_of_interest;
    *(esp_zb_zdo_ieee_addr_callback_t *)req.cb = user_cb;
    uVar1 = cmd_req->request_type;
    uVar2 = cmd_req->start_index;
    req.dst_nwk_addr._1_1_ = uVar2;
    req.dst_nwk_addr._0_1_ = uVar1;
    *(void **)(req.cb + 4) = user_ctx;
    req.field.nwk_addr_of_interest = SUB42(uVar3,2);
    req._4_4_ = esp_zb_zdo_ieee_addr_rsp_wrapper;
    ezb_zdo_ieee_addr_req(&local_20);
  }
  return;
}

