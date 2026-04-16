/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_cancel_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_cancel_alarm(esp_zb_alarm_t *alarm)

{
  int iVar1;
  esp_err_t eVar2;
  
  if (alarm == (esp_zb_alarm_t *)0x0) {
    eVar2 = 0x102;
  }
  else if (alarm->timer == (esp_timer_handle_t)0x0) {
    eVar2 = 0x102;
  }
  else {
    iVar1 = esp_timer_is_active();
    if (iVar1 != 0) {
      esp_timer_stop(alarm->timer);
    }
    esp_timer_delete(alarm->timer);
    free(alarm);
    eVar2 = 0;
  }
  return eVar2;
}

