/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_profile_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_metering_get_profile_resp_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  uint __nmemb;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  esp_zb_zcl_metering_get_profile_resp_message_t app_message;
  
  uStack_1e = *(undefined2 *)((int)arg + 2);
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0xc);
  app_message.end_time._2_1_ = *(byte *)((int)arg + 0x18);
  __nmemb = (uint)app_message.end_time._2_1_;
                    /* WARNING: Load size is inaccurate */
  uStack_20 = *arg;
  app_message.end_time._0_1_ = (undefined1)*(undefined4 *)((int)arg + 0x10);
  app_message.end_time._3_1_ = 0;
  app_message.end_time._1_1_ = (undefined1)*(undefined4 *)((int)arg + 0x14);
  app_message._8_4_ = calloc(__nmemb,3);
  if (__nmemb != 0) {
    if ((esp_zb_uint24_t *)app_message._8_4_ == (esp_zb_uint24_t *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
      return;
    }
    array_copy_u32_to_u24
              ((esp_zb_uint24_t *)app_message._8_4_,*(uint32_t **)((int)arg + 0x1c),__nmemb);
  }
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_METERING_GET_PROFILE_RESP_CB_ID,&uStack_20);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x20) = eVar1;
  }
  if (app_message._8_4_ != 0) {
    free((void *)app_message._8_4_);
  }
  return;
}

