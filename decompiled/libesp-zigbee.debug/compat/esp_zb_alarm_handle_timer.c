/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
                             ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/compat.c"
                              ,0x90,"esp_zb_alarm_handle_timer",
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

