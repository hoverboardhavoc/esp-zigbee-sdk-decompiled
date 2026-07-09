/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> convert_to_radio_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void convert_to_radio_frame(undefined1 *param_1,byte *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_3 = param_1 + 1;
  *(undefined1 *)(param_3 + 1) = *param_1;
  *(byte *)((int)param_3 + 5) = param_2[2];
  *(byte *)(param_3 + 4) = param_2[3];
  *(byte *)((int)param_3 + 0x11) = param_2[4];
  *(byte *)((int)param_3 + 0x12) = *(byte *)((int)param_3 + 0x12) & 0xfe | *param_2 & 1;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  param_3[2] = *(undefined4 *)(param_2 + 8);
  param_3[3] = uVar1;
  return;
}

