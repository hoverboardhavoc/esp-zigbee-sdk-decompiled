/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_alarm_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_alarm_callback(void *arg)

{
  if ((*(byte *)((int)arg + 0xc) & 1) != 0) {
    (**(code **)((int)arg + 4))(*(undefined4 *)((int)arg + 8));
    esp_zb_scheduler_user_alarm_cancel((esp_zb_alarm_t *)arg);
    return;
  }
  (**(code **)((int)arg + 4))(*(undefined1 *)((int)arg + 8));
  *(void **)((int)arg + 4) = arg;
  esp_zb_scheduler_alarm_cancel((esp_zb_callback_t)arg,*(uint8_t *)((int)arg + 8));
  return;
}

