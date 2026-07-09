/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_lock_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zigbee_lock_init(void)

{
  undefined4 uVar1;
  
  if (s_esp_zigbee_task_mutex == 0) {
    s_esp_zigbee_task_mutex = xQueueCreateMutex(4);
    if (s_esp_zigbee_task_mutex == 0) {
      uVar1 = 0x101;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x103;
  }
  return uVar1;
}

