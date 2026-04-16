/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_sleep.o -> esp_zigbee_sleep_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_sleep_init(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = esp_pm_lock_create(1,0,"esp_zigbee_sleep",&s_pm_lock);
  if (iVar1 == 0) {
    esp_zigbee_sleep_lock();
    pcVar2 = "unsupported";
  }
  else if (iVar1 == 0x106) {
    pcVar2 = "disabled";
    iVar1 = 0;
  }
  else {
    esp_pm_lock_delete(s_pm_lock);
    s_pm_lock = (esp_pm_lock_handle_t)0x0;
    pcVar2 = "failed";
  }
  esp_log(0x13,"esp zigbee sleep","light sleap %s",pcVar2);
  return iVar1;
}

