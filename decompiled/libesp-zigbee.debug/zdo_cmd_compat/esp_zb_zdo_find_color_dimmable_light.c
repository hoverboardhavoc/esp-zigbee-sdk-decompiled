/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_find_color_dimmable_light
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_find_color_dimmable_light
               (esp_zb_zdo_match_desc_req_param_t *cmd_req,esp_zb_zdo_match_desc_callback_t user_cb,
               void *user_ctx)

{
  undefined1 auStack_24 [4];
  esp_zb_zdo_match_desc_req_param_t req;
  uint16_t color_dimmable_clusters [3];
  
  req.cluster_list._0_2_ = 6;
  req.cluster_list._2_2_ = 8;
  if (cmd_req != (esp_zb_zdo_match_desc_req_param_t *)0x0) {
    auStack_24._0_2_ = cmd_req->dst_nwk_addr;
    auStack_24._2_2_ = cmd_req->addr_of_interest;
    req.dst_nwk_addr = 0x104;
    req.addr_of_interest = 3;
    req._4_4_ = &req.cluster_list;
    esp_zb_zdo_match_cluster((esp_zb_zdo_match_desc_req_param_t *)auStack_24,user_cb,user_ctx);
  }
  return;
}

