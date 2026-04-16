/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_device_bind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_device_bind_req
               (esp_zb_zdo_bind_req_param_t *cmd_req,esp_zb_zdo_bind_callback_t user_cb,
               void *user_ctx)

{
  ezb_zdo_bind_req_callback_t p_Var1;
  uint16_t uStack_44;
  undefined1 auStack_42 [2];
  ezb_zdo_bind_req_t req;
  
  memset(&uStack_44,0,0x24);
  if ((cmd_req != (esp_zb_zdo_bind_req_param_t *)0x0) &&
     (p_Var1 = (ezb_zdo_bind_req_callback_t)calloc(1,0xc),
     p_Var1 != (ezb_zdo_bind_req_callback_t)0x0)) {
    uStack_44 = cmd_req->req_dst_addr;
    *(void **)(p_Var1 + 4) = user_ctx;
    *(esp_zb_zdo_bind_callback_t *)p_Var1 = user_cb;
    memcpy(auStack_42,cmd_req,8);
    req.field.src_addr.field_0.u8[4] = cmd_req->src_endp;
    req.field.src_ep = cmd_req->dst_addr_mode;
    req.field.src_addr.field_0.u64._6_2_ = cmd_req->cluster_id;
    if (req.field.src_ep == '\x01') {
      req.field.cluster_id = (cmd_req->dst_address_u).addr_short;
    }
    else {
      memcpy(&req.field.cluster_id,&cmd_req->dst_address_u,8);
    }
    req.field.dst_addr._4_1_ = cmd_req->dst_endp;
    req._24_4_ = esp_zb_zdo_bind_rsp_wrapper;
    req.cb = p_Var1;
    ezb_zdo_bind_req(&uStack_44);
  }
  return;
}

