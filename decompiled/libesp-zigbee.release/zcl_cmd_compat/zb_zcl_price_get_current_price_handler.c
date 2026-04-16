/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_price_get_current_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_price_get_current_price_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  void *__src;
  undefined2 local_70;
  undefined2 uStack_6e;
  esp_zb_zcl_price_get_current_price_message_t app_message;
  ezb_zcl_price_publish_price_cmd_t cmd_req;
  
  uStack_6e = *(undefined2 *)((int)arg + 2);
                    /* WARNING: Load size is inaccurate */
  local_70 = *arg;
  app_message.command_options = '\0';
  app_message.resp_count = '\0';
  app_message._6_2_ = 0;
  app_message.info.dst_endpoint = '\0';
  app_message.info.cluster = 0;
  app_message.info.status = *(byte *)((int)arg + 0xc);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    (*cb)(ESP_ZB_CORE_PRICE_GET_CURRENT_PRICE_CB_ID,&local_70);
  }
  if (app_message.info.dst_endpoint == '\0') {
    *(undefined1 *)((int)arg + 0x10) = 0x8b;
  }
  else {
    *(undefined1 *)((int)arg + 0x10) = 0;
    memset((void *)((int)&cmd_req.cmd_ctrl.dst_addr.u + 6),0,0x48);
    __src = *(void **)((int)arg + 8);
    memcpy(&app_message.resp_info_offered,__src,10);
    cmd_req.cmd_ctrl.dst_addr.u._4_2_ = *(undefined2 *)((int)__src + 0x14);
    memcpy(&cmd_req.cmd_ctrl.cnf_ctx.user_ctx,(void *)app_message._4_4_,0x3b);
    ezb_zcl_price_publish_price_cmd_req(&app_message.resp_info_offered);
  }
  return;
}

