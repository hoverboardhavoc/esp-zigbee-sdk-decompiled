/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_alarm_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_alarm_handle_timer(undefined4 param_1)

{
  int iVar1;
  int *__ptr;
  undefined4 uVar2;
  
  iVar1 = esp_zigbee_task_queue_post(esp_zb_alarm_callback,param_1);
  if (iVar1 == 0) {
    return 0;
  }
  __ptr = (int *)_esp_error_check_failed
                           ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/compat.c"
                            ,0x90,"esp_zb_alarm_handle_timer",
                            "esp_zigbee_task_queue_post(esp_zb_alarm_callback, arg)");
  if (__ptr == (int *)0x0) {
    uVar2 = 0x102;
  }
  else if (*__ptr == 0) {
    uVar2 = 0x102;
  }
  else {
    iVar1 = esp_timer_is_active();
    if (iVar1 != 0) {
      esp_timer_stop(*__ptr);
    }
    esp_timer_delete(*__ptr);
    free(__ptr);
    uVar2 = 0;
  }
  return uVar2;
}

