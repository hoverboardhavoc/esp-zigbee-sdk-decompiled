/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_find_color_dimmable_light
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_find_color_dimmable_light(undefined4 *param_1)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 *puStack_1c;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  uStack_18 = 6;
  uStack_16 = 8;
  uStack_14 = 0x300;
  if (param_1 != (undefined4 *)0x0) {
    uStack_24 = *param_1;
    uStack_20 = 0x30104;
    puStack_1c = &uStack_18;
    esp_zb_zdo_match_cluster(&uStack_24);
  }
  return;
}

