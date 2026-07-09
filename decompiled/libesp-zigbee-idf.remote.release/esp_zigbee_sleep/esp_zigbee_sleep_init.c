/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_sleep.o -> esp_zigbee_sleep_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_sleep_init(void)

{
  int iVar1;
  
  iVar1 = esp_pm_lock_create(1,0,0x10000,&s_pm_lock);
  if (iVar1 == 0) {
    if (s_pm_locked == '\0') {
      esp_pm_lock_acquire(s_pm_lock);
      s_pm_locked = '\x01';
    }
  }
  else if (iVar1 != 0x106) {
    esp_pm_lock_delete(s_pm_lock);
    s_pm_lock = 0;
    return iVar1;
  }
  return 0;
}

