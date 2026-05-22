/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_lock_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void esp_zigbee_lock_release(void)

{
  int iVar1;
  
  if (s_esp_zigbee_task_mutex == (SemaphoreHandle_t)0x0) {
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

