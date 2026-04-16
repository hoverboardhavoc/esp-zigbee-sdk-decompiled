/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_scheduler_user_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_user_cb_handle_t
esp_zb_scheduler_user_alarm(esp_zb_user_callback_t cb,void *param,uint32_t time)

{
  anon_union_4_2_34b25e97_for_esp_zb_alarm_params_s_0 local_20;
  esp_zb_alarm_params_t params;
  esp_zb_alarm_t *alarm;
  
  params._8_4_ = 0;
  params.field_1.param = params.field_1.param | 1;
  local_20.user_cb = cb;
  params.field_0 = (anon_union_4_2_34b25e97_for_esp_zb_alarm_params_s_0)param;
  esp_zb_run_alarm((esp_zb_alarm_params_t *)&local_20,time,(esp_zb_alarm_t **)&params.field_0x8);
  return (esp_zb_user_cb_handle_t)params._8_4_;
}

