/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_alarm_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_alarm_callback(int param_1)

{
  if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
    (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 8));
    esp_zb_scheduler_user_alarm_cancel(param_1);
    return;
  }
  (**(code **)(param_1 + 4))(*(undefined1 *)(param_1 + 8));
  *(int *)(param_1 + 4) = param_1;
  esp_zb_scheduler_alarm_cancel(param_1,*(undefined1 *)(param_1 + 8));
  return;
}

