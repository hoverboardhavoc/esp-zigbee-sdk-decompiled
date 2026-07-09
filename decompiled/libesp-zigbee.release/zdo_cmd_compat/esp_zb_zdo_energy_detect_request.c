/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_energy_detect_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_energy_detect_request(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined1 local_20;
  undefined1 uStack_1f;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  puStack_14 = (undefined4 *)calloc(1,0x28);
  if (puStack_14 != (undefined4 *)0x0) {
    *puStack_14 = param_3;
    local_20 = 0;
    pcStack_18 = esp_zb_zdo_ed_scan_wrapper;
    uStack_1f = param_2;
    uStack_1c = param_1;
    ezb_nwk_scan(&local_20);
  }
  return;
}

