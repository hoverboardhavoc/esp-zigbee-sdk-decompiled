/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_nwk_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_nwk_addr_req
               (esp_zb_zdo_nwk_addr_req_param_t *cmd_req,esp_zb_zdo_nwk_addr_callback_t user_cb,
               void *user_ctx)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  ezb_zdo_nwk_addr_req_callback_t p_Var4;
  undefined4 uStack_34;
  ezb_zdo_nwk_addr_req_t req;
  
  uStack_34 = 0;
  req._0_4_ = 0;
  req.field.ieee_addr_of_interest.field_0.u64._2_4_ = 0;
  req.field._6_4_ = 0;
  req.cb = (ezb_zdo_nwk_addr_req_callback_t)0x0;
  if ((cmd_req != (esp_zb_zdo_nwk_addr_req_param_t *)0x0) &&
     (p_Var4 = (ezb_zdo_nwk_addr_req_callback_t)calloc(1,0xc),
     p_Var4 != (ezb_zdo_nwk_addr_req_callback_t)0x0)) {
    *(esp_zb_zdo_nwk_addr_callback_t *)p_Var4 = user_cb;
    *(void **)(p_Var4 + 4) = user_ctx;
    memcpy((void *)((int)&uStack_34 + 2),cmd_req->ieee_addr_of_interest,8);
    uVar3 = req.field.ieee_addr_of_interest.field_0.u64._2_4_;
    uVar1 = cmd_req->request_type;
    uVar2 = cmd_req->start_index;
    req.field.ieee_addr_of_interest.field_0.u8[5] = uVar2;
    req.field.ieee_addr_of_interest.field_0.u8[4] = uVar1;
    req.field.ieee_addr_of_interest.field_0.u64._2_2_ = (undefined2)uVar3;
    uStack_34 = CONCAT22(uStack_34._2_2_,cmd_req->dst_nwk_addr);
    req.field._6_4_ = esp_zb_zdo_nwk_addr_rsp_wrapper;
    req.cb = p_Var4;
    ezb_zdo_nwk_addr_req(&uStack_34);
  }
  return;
}

