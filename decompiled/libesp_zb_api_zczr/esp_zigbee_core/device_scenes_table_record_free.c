/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 0x10) {
    device_scene_free_fields((&DAT_00018dfc)[param_1 * 3]);
    (&DAT_00018dfc)[param_1 * 3] = 0;
    (&DAT_00018df6)[param_1 * 6] = 0xffff;
    (&DAT_00018dfa)[param_1 * 0xc] = 0;
    (&DAT_00018df8)[param_1 * 6] = 0;
    (&DAT_00018dfb)[param_1 * 0xc] = 0;
  }
  return;
}

