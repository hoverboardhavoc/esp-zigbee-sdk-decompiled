/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_alarm.o -> esp_zigbee_platform_alarm_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_platform_alarm_process(esp_zigbee_mainloop_context_t *ctx)

{
  uint32_t uVar1;
  uint32_t uVar2;
  
  uVar1 = s_alarm_us;
  if (s_is_us_running) {
    uVar2 = ezb_plat_micro_alarm_get_now();
    if (-1 < (int)(uVar2 - uVar1)) {
      s_is_us_running = false;
      ezb_plat_signal_micro_alarm_fired();
    }
  }
  uVar1 = s_alarm_ms;
  if (s_is_ms_running != false) {
    uVar2 = ezb_plat_milli_alarm_get_now();
    if (-1 < (int)(uVar2 - uVar1)) {
      s_is_ms_running = false;
      ezb_plat_signal_milli_alarm_fired();
    }
  }
  return 0;
}

