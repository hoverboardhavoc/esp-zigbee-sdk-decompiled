/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_sleep.o -> esp_zigbee_sleep_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_sleep_init(void)

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
    s_pm_lock = 0;
    pcVar2 = "failed";
  }
  esp_log(0x13,"esp zigbee sleep","light sleap %s",pcVar2);
  return iVar1;
}

