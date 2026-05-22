/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_nwk_update_req
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
  undefined2 uVar1;
  undefined1 uVar2;
  ezb_zdo_nwk_mgmt_nwk_update_req_callback_t p_Var3;
  undefined4 uStack_38;
  ezb_zdo_nwk_mgmt_nwk_update_req_t req;
  
  uStack_38 = 0;
  req.dst_nwk_addr = 0;
  req._2_2_ = 0;
  req.field.scan_channels = 0;
  req.field.scan_duration = '\0';
  req.field.scan_count = '\0';
  req.field.nwk_update_id = '\0';
  req.field._7_1_ = 0;
  req.field.nwk_mgmt_addr = 0;
  req.field._10_2_ = 0;
  req.cb = (ezb_zdo_nwk_mgmt_nwk_update_req_callback_t)0x0;
  if ((cmd_req != (esp_zb_zdo_mgmt_nwk_update_req_param_t *)0x0) &&
     (p_Var3 = (ezb_zdo_nwk_mgmt_nwk_update_req_callback_t)calloc(1,0xc),
     p_Var3 != (ezb_zdo_nwk_mgmt_nwk_update_req_callback_t)0x0)) {
    *(esp_zb_zdo_mgmt_nwk_update_notify_callback_t *)p_Var3 = user_cb;
    *(void **)(p_Var3 + 4) = user_ctx;
    req._0_4_ = cmd_req->scan_channels;
    uVar1._0_1_ = cmd_req->scan_duration;
    uVar1._1_1_ = cmd_req->scan_count;
    req.field.scan_channels = CONCAT22(req.field.scan_channels._2_2_,uVar1);
    uVar2 = ezb_nwk_get_update_id();
    req.field.scan_channels._0_3_ = CONCAT12(uVar2,(undefined2)req.field.scan_channels);
    req.field._4_2_ = cmd_req->nwk_manager_addr;
    uStack_38 = CONCAT22(uStack_38._2_2_,cmd_req->dst_addr);
    req.field._8_4_ = esp_zb_zdo_mgmt_nwk_update_notify_wrapper;
    req.cb = p_Var3;
    ezb_zdo_nwk_mgmt_nwk_update_req(&uStack_38);
  }
  return;
}

