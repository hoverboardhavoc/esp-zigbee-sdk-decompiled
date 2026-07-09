/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> aps_compat.o -> esp_zb_apsde_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_apsde_data_confirm_handler(void *param_1)

{
  code *pcVar1;
  undefined1 auStack_30 [40];
  
  pcVar1 = s_esp_zb_data_confirm_handler;
  if (s_esp_zb_data_confirm_handler == (code *)0x0) {
    param_1 = (void *)__assert_func(0,0,0,0);
  }
  if (param_1 == (void *)0x0) {
    param_1 = (void *)esp_zb_apsde_data_confirm_handler_part_0(0);
  }
  memcpy(auStack_30,param_1,0x18);
  (*pcVar1)(auStack_30);
  return;
}

