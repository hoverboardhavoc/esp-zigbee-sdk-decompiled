/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 10) {
    device_scene_free_fields((&DAT_00016f3c)[param_1 * 3]);
    (&DAT_00016f3c)[param_1 * 3] = 0;
    (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
    (&DAT_00016f38)[param_1 * 0xc] = 0;
    (&DAT_00016f36)[param_1 * 6] = 0;
    (&DAT_00016f39)[param_1 * 0xc] = 0;
  }
  return;
}

