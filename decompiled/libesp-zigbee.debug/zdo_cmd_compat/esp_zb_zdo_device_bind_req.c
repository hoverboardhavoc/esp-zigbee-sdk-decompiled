/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_device_bind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_device_bind_req
               (esp_zb_zdo_bind_req_param_t *cmd_req,esp_zb_zdo_bind_callback_t user_cb,
               void *user_ctx)

{
  undefined4 uStack_34;
  ezb_zdo_bind_req_t req;
  
  uStack_34 = 0;
  req._0_4_ = 0;
  req.field.src_addr.field_0.u64._2_4_ = 0;
  req.field._6_4_ = 0;
  req.field.cluster_id = 0;
  req.field.dst_addr_mode = '\0';
  req.field._13_1_ = 0;
  req.field.dst_addr._0_2_ = 0;
  req.field.dst_addr._2_2_ = 0;
  req.field.dst_addr._4_4_ = 0;
  req.field.dst_ep = '\0';
  req.field._23_1_ = 0;
  req._26_2_ = 0;
  req.cb = (ezb_zdo_bind_req_callback_t)0x0;
  if ((cmd_req != (esp_zb_zdo_bind_req_param_t *)0x0) &&
     (req.cb = (ezb_zdo_bind_req_callback_t)calloc(1,0xc),
     req.cb != (ezb_zdo_bind_req_callback_t)0x0)) {
    *(esp_zb_zdo_bind_callback_t *)req.cb = user_cb;
    *(void **)(req.cb + 4) = user_ctx;
    req._0_4_ = *(undefined4 *)(cmd_req->src_address + 2);
    uStack_34 = CONCAT13(cmd_req->src_address[1],
                         CONCAT12(cmd_req->src_address[0],cmd_req->req_dst_addr));
    req.field.src_addr.field_0.u64._2_3_ = *(undefined3 *)(cmd_req->src_address + 6);
    if (cmd_req->dst_addr_mode == '\x01') {
      req.field.cluster_id = (cmd_req->dst_address_u).addr_short;
    }
    else {
      req.field._10_4_ = *(undefined4 *)&cmd_req->dst_address_u;
      req.field.dst_addr.group_addr = *(ezb_grpaddr_t *)((int)&cmd_req->dst_address_u + 4);
    }
    req.field.src_ep = cmd_req->dst_addr_mode;
    req.field.src_addr.field_0.u64._6_2_ = cmd_req->cluster_id;
    req.field.dst_addr._4_1_ = cmd_req->dst_endp;
    req._24_4_ = esp_zb_zdo_bind_rsp_wrapper;
    ezb_zdo_bind_req(&uStack_34);
  }
  return;
}

