/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_lock_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zigbee_lock_release(void)

{
  int iVar1;
  
  if (s_esp_zigbee_task_mutex == 0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Failed to release the lock because the mutex is not ready",
            "esp_zigbee_lock_release",0x35);
  }
  else {
    iVar1 = xQueueGiveMutexRecursive();
    if (iVar1 != 1) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/src/esp_zigbee.c"
                    ,0x38,"esp_zigbee_lock_release","ret == pdTRUE");
      ezb_core_deinit();
      esp_zigbee_lock_deinit();
      esp_zigbee_sleep_deinit();
      esp_zigbee_platform_deinit();
      return;
    }
  }
  return;
}

