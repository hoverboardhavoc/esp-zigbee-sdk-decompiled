/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_err_to_zcl_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_err_to_zcl_status(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x102) {
    uVar1 = 0x85;
  }
  else if (param_1 < 0x103) {
    uVar1 = 0;
    if ((param_1 != 0) && (uVar1 = 1, param_1 == 0x101)) {
      return 0x89;
    }
  }
  else {
    uVar1 = 0x81;
    if ((param_1 != 0x106) && (uVar1 = 1, param_1 == 0x107)) {
      return 0x94;
    }
  }
  return uVar1;
}

