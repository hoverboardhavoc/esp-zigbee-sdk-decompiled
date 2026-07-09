/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_alarm.o -> esp_zigbee_platform_alarm_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zigbee_platform_alarm_process(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = s_alarm_us;
  if (s_is_us_running != '\0') {
    iVar2 = ezb_plat_micro_alarm_get_now();
    if (-1 < iVar2 - iVar1) {
      s_is_us_running = '\0';
      ezb_plat_signal_micro_alarm_fired();
    }
  }
  iVar1 = s_alarm_ms;
  if (s_is_ms_running != '\0') {
    iVar2 = ezb_plat_milli_alarm_get_now();
    if (-1 < iVar2 - iVar1) {
      s_is_ms_running = '\0';
      ezb_plat_signal_milli_alarm_fired();
    }
  }
  return 0;
}

