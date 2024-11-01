/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_data_size_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort zb_nvram_app1_data_size_cb(void)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = &esp_zb_zcl_scenes_table;
  sVar1 = 0;
  do {
    if (*(short *)(puVar2 + 2) != -1) {
      sVar1 = sVar1 + 8 + (ushort)(byte)puVar2[7];
    }
    puVar2 = puVar2 + 0xc;
  } while (puVar2 != (undefined1 *)0x11668);
  return sVar1 + 0x11U & 0xfff0;
}

