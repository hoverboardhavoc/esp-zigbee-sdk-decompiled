/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_price_get_scheduled_prices_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_price_get_scheduled_prices_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  void *__src;
  uint uVar1;
  undefined2 uStack_74;
  undefined2 uStack_72;
  esp_zb_zcl_price_get_scheduled_prices_message_t app_message;
  ezb_zcl_price_publish_price_cmd_t cmd_req;
  
  uStack_72 = *(undefined2 *)((int)arg + 2);
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0xc);
                    /* WARNING: Load size is inaccurate */
  uStack_74 = *arg;
  app_message.number_of_events = '\0';
  app_message.resp_count = '\0';
  app_message._10_2_ = 0;
  app_message.start_time = (uint32_t)*(byte *)((int)arg + 0x10);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    (*cb)(ESP_ZB_CORE_PRICE_GET_SCHEDULED_PRICES_CB_ID,&uStack_74);
  }
  if (app_message.start_time._1_1_ == '\0') {
    *(undefined1 *)((int)arg + 0x14) = 0x8b;
  }
  else {
    *(undefined1 *)((int)arg + 0x14) = 0;
    memset((void *)((int)&cmd_req.cmd_ctrl.dst_addr.u + 6),0,0x48);
    __src = *(void **)((int)arg + 8);
    memcpy(&app_message.resp_info_offered,__src,10);
    cmd_req.cmd_ctrl.dst_addr.u._4_2_ = *(undefined2 *)((int)__src + 0x14);
    for (uVar1 = 0; (uVar1 & 0xffff) < (app_message.start_time >> 8 & 0xff); uVar1 = uVar1 + 1) {
      memcpy(&cmd_req.cmd_ctrl.cnf_ctx.user_ctx,(void *)(app_message._8_4_ + uVar1 * 0x3b),0x3b);
      ezb_zcl_price_publish_price_cmd_req(&app_message.resp_info_offered);
    }
  }
  return;
}

