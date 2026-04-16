/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_get_profile_resp_handler
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
  undefined4 local_30;
  esp_zb_zcl_metering_get_profile_resp_message_t app_message;
  
  app_message.status = '\0';
  app_message.profile_interval_period = '\0';
  app_message.number_of_periods_delivered = '\0';
  app_message._11_1_ = 0;
                    /* WARNING: Load size is inaccurate */
  local_30 = *arg;
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0xc);
  __nmemb = (uint)*(byte *)((int)arg + 0x18);
  app_message.end_time =
       CONCAT13(0,CONCAT12(*(byte *)((int)arg + 0x18),
                           CONCAT11((char)*(undefined4 *)((int)arg + 0x14),
                                    (char)*(undefined4 *)((int)arg + 0x10))));
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
    err = (*cb)(ESP_ZB_CORE_METERING_GET_PROFILE_RESP_CB_ID,&local_30);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x20) = eVar1;
  }
  if (app_message._8_4_ != 0) {
    free((void *)app_message._8_4_);
  }
  return;
}

