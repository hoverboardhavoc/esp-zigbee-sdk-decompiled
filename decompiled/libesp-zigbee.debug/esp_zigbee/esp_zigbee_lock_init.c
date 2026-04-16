/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_lock_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_lock_init(void)

{
  esp_err_t eVar1;
  
  if (s_esp_zigbee_task_mutex == (SemaphoreHandle_t)0x0) {
    s_esp_zigbee_task_mutex = (SemaphoreHandle_t)xQueueCreateMutex(4);
    if (s_esp_zigbee_task_mutex == (SemaphoreHandle_t)0x0) {
      eVar1 = 0x101;
    }
    else {
      eVar1 = 0;
    }
  }
  else {
    eVar1 = 0x103;
  }
  return eVar1;
}

