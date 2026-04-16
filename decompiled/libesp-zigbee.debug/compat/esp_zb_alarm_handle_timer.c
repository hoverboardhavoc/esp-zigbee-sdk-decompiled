/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_alarm_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_alarm_handle_timer(void *arg)

{
  int iVar1;
  int *__ptr;
  
  iVar1 = esp_zigbee_task_queue_post(esp_zb_alarm_callback,arg);
  if (iVar1 != 0) {
    __ptr = (int *)_esp_error_check_failed
                             ("/build/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/compat.c",
                              0x90,"esp_zb_alarm_handle_timer",
                              "esp_zigbee_task_queue_post(esp_zb_alarm_callback, arg)");
    if ((__ptr != (int *)0x0) && (*__ptr != 0)) {
      iVar1 = esp_timer_is_active();
      if (iVar1 != 0) {
        esp_timer_stop(*__ptr);
      }
      esp_timer_delete(*__ptr);
      free(__ptr);
    }
    return;
  }
  return;
}

