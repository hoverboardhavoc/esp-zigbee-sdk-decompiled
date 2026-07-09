/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> esp_zigbee.o -> esp_zigbee_lock_acquire
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool esp_zigbee_lock_acquire(undefined4 param_1)

{
  int iVar1;
  
  if (s_esp_zigbee_task_mutex != 0) {
    iVar1 = xQueueTakeMutexRecursive(param_1);
    return iVar1 == 1;
  }
  return false;
}

