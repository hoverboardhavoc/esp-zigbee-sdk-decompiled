/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_nwk_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_zdo_mgmt_nwk_update_req
               (esp_zb_zdo_mgmt_nwk_update_req_param_t *cmd_req,
               esp_zb_zdo_mgmt_nwk_update_notify_callback_t user_cb,void *user_ctx)

{
  uint16_t auStack_38 [2];
  ezb_zdo_nwk_mgmt_nwk_update_req_t req;
  
  memset(auStack_38,0,0x18);
  if ((cmd_req != (esp_zb_zdo_mgmt_nwk_update_req_param_t *)0x0) &&
     (req.cb = (ezb_zdo_nwk_mgmt_nwk_update_req_callback_t)calloc(1,0xc),
     req.cb != (ezb_zdo_nwk_mgmt_nwk_update_req_callback_t)0x0)) {
    req._0_4_ = cmd_req->scan_channels;
    *(esp_zb_zdo_mgmt_nwk_update_notify_callback_t *)req.cb = user_cb;
    *(void **)(req.cb + 4) = user_ctx;
    req.field.scan_channels._0_1_ = cmd_req->scan_duration;
    req.field.scan_channels._1_1_ = cmd_req->scan_count;
    req.field.scan_channels._2_1_ = ezb_nwk_get_update_id();
    req.field._4_2_ = cmd_req->nwk_manager_addr;
    auStack_38[0] = cmd_req->dst_addr;
    req.field._8_4_ = esp_zb_zdo_mgmt_nwk_update_notify_wrapper;
    ezb_zdo_nwk_mgmt_nwk_update_req(auStack_38);
  }
  return;
}

