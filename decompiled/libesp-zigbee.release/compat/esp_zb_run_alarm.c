/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_run_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_run_alarm(esp_zb_alarm_params_t *params,uint32_t time_ms,esp_zb_alarm_t **p_alarm)

{
  esp_zb_alarm_t *__ptr;
  int iVar1;
  esp_err_t extraout_a0;
  undefined4 uStack_34;
  esp_timer_create_args_t timer_args;
  
  __ptr = (esp_zb_alarm_t *)malloc(0x10);
  if (__ptr == (esp_zb_alarm_t *)0x0) {
    return 0;
  }
  memcpy(&__ptr->params,params,0xc);
  timer_args.arg = (void *)0x0;
  timer_args.dispatch_method = ESP_TIMER_TASK;
  timer_args.name = (char *)0x0;
  uStack_34 = 0x10000;
  timer_args.callback = (esp_timer_cb_t)__ptr;
  iVar1 = esp_timer_create(&uStack_34,__ptr);
  if (iVar1 == 0) {
    iVar1 = esp_timer_start_once(__ptr->timer,time_ms * 1000,0);
    if (iVar1 == 0) {
      if (p_alarm == (esp_zb_alarm_t **)0x0) {
        return 0;
      }
      *p_alarm = __ptr;
      return 0;
    }
    esp_timer_delete(__ptr->timer);
  }
  free(__ptr);
  return extraout_a0;
}

