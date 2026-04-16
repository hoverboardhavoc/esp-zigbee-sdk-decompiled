/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_request_fast_poll_mode_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_metering_request_fast_poll_mode_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined2 local_20;
  undefined2 uStack_1e;
  esp_zb_zcl_metering_request_fast_poll_mode_message_t app_message;
  
  uStack_1e = *(undefined2 *)((int)arg + 2);
                    /* WARNING: Load size is inaccurate */
  local_20 = *arg;
  app_message.info._0_2_ = *(undefined2 *)((int)arg + 0xc);
  app_message.info.cluster = 0;
  app_message.fast_poll_update_period = '\0';
  app_message.duration = '\0';
  app_message._6_2_ = 0;
  app_message.resp_info_offered.applied_update_period_in_seconds = '\0';
  app_message.resp_info_offered._1_1_ = 0;
  app_message.resp_info_offered._2_2_ = 0;
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_METERING_REQ_FAST_POLL_MODE_CB_ID,&local_20);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x10) = eVar1;
  }
  if (*(char *)((int)arg + 0x10) == '\0') {
    memcpy((void *)((int)arg + 0x14),&app_message.fast_poll_update_period,8);
  }
  return;
}

