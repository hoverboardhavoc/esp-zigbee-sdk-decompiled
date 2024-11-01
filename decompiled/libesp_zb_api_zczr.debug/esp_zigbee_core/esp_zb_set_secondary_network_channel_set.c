/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_set_secondary_network_channel_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_set_secondary_network_channel_set(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 0x800U < 0x7fff001) {
    zb_set_bdb_secondary_channel_set();
    uVar1 = 0;
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}

