/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_sleep.o -> esp_zigbee_sleep_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_sleep_init(void)

{
  int iVar1;
  
  iVar1 = esp_pm_lock_create(1,0,0x10000,&s_pm_lock);
  if (iVar1 == 0) {
    if (s_pm_locked == false) {
      esp_pm_lock_acquire(s_pm_lock);
      s_pm_locked = true;
    }
  }
  else if (iVar1 != 0x106) {
    esp_pm_lock_delete(s_pm_lock);
    s_pm_lock = (esp_pm_lock_handle_t)0x0;
    return iVar1;
  }
  return 0;
}

