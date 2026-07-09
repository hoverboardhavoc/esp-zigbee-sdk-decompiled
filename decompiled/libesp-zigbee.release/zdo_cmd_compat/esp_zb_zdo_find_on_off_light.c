/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_find_on_off_light
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_find_on_off_light(undefined4 *param_1)

{
  undefined2 local_20 [2];
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)local_20;
  uStack_15 = 0;
  local_20[0] = 6;
  if (param_1 != (undefined4 *)0x0) {
    uStack_1c = *param_1;
    uStack_18 = 0x104;
    uStack_16 = 1;
    esp_zb_zdo_match_cluster(&uStack_1c);
  }
  return;
}

