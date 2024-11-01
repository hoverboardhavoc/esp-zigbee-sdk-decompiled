/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 0x10) {
    device_scene_free_fields((&DAT_00012c00)[param_1 * 3]);
    (&DAT_00012c00)[param_1 * 3] = 0;
    (&DAT_00012bfa)[param_1 * 6] = 0xffff;
    (&DAT_00012bfe)[param_1 * 0xc] = 0;
    (&DAT_00012bfc)[param_1 * 6] = 0;
    (&DAT_00012bff)[param_1 * 0xc] = 0;
  }
  return;
}

