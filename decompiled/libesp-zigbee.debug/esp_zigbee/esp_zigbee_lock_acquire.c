/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_lock_acquire
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool esp_zigbee_lock_acquire(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  
  if (s_esp_zigbee_task_mutex == 0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Failed to acquire the lock because the mutex is not ready",
            "esp_zigbee_lock_acquire",0x2d);
    bVar1 = false;
  }
  else {
    iVar2 = xQueueTakeMutexRecursive(param_1);
    bVar1 = iVar2 == 1;
  }
  return bVar1;
}

