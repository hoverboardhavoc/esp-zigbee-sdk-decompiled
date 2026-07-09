/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_lock_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void esp_zigbee_lock_release(void)

{
  int iVar1;
  
  if (s_esp_zigbee_task_mutex == 0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Failed to release the lock because the mutex is not ready",
            "esp_zigbee_lock_release",0x33);
  }
  else {
    iVar1 = xQueueGiveMutexRecursive();
    if (iVar1 != 1) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/src/esp_zigbee.c"
                    ,0x36,"esp_zigbee_lock_release","ret == pdTRUE");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return;
}

