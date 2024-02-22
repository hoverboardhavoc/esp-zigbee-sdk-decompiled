/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 0x10) {
    device_scene_free_fields((&DAT_00018e64)[param_1 * 3]);
    (&DAT_00018e64)[param_1 * 3] = 0;
    (&DAT_00018e5e)[param_1 * 6] = 0xffff;
    (&DAT_00018e62)[param_1 * 0xc] = 0;
    (&DAT_00018e60)[param_1 * 6] = 0;
    (&DAT_00018e63)[param_1 * 0xc] = 0;
  }
  return;
}

