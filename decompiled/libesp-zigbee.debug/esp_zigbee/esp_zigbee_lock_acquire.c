/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_lock_acquire
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool esp_zigbee_lock_acquire(TickType_t block_ticks)

{
  bool bVar1;
  int iVar2;
  
  if (s_esp_zigbee_task_mutex == (SemaphoreHandle_t)0x0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Failed to acquire the lock because the mutex is not ready",
            "esp_zigbee_lock_acquire",0x2b);
    bVar1 = false;
  }
  else {
    iVar2 = xQueueTakeMutexRecursive(block_ticks);
    bVar1 = iVar2 == 1;
  }
  return bVar1;
}

