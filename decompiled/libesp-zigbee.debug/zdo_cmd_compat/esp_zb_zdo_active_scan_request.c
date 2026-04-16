/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_active_scan_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void esp_zb_zdo_active_scan_request
               (uint32_t channel_mask,uint8_t scan_duration,
               esp_zb_zdo_scan_complete_callback_t user_cb)

{
  undefined1 local_20;
  uint8_t uStack_1f;
  ezb_nwk_scan_req_t req;
  
  req.field_3.active_scan_cb = (ezb_nwk_active_scan_callback_t)calloc(1,0x1c8);
  if (req.field_3.active_scan_cb != (ezb_nwk_active_scan_callback_t)0x0) {
    *(esp_zb_zdo_scan_complete_callback_t *)req.field_3.active_scan_cb = user_cb;
    local_20 = 1;
    req.scan_channels = (uint32_t)esp_zb_zdo_active_scan_wrapper;
    uStack_1f = scan_duration;
    req._0_4_ = channel_mask;
    ezb_nwk_scan(&local_20);
  }
  return;
}

