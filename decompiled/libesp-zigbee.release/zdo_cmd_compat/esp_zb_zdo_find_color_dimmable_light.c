/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_find_color_dimmable_light
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
  uint16_t color_dimmable_clusters [3];
  esp_zb_zdo_match_desc_req_param_t req;
  
  color_dimmable_clusters[0] = 0x300;
  if (cmd_req != (esp_zb_zdo_match_desc_req_param_t *)0x0) {
    color_dimmable_clusters[2] = cmd_req->dst_nwk_addr;
    register0x0000203e = cmd_req->addr_of_interest;
    esp_zb_zdo_match_cluster
              ((esp_zb_zdo_match_desc_req_param_t *)(color_dimmable_clusters + 2),user_cb,user_ctx);
  }
  return;
}

