/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 10) {
    device_scene_free_fields((&DAT_0001716c)[param_1 * 3]);
    (&DAT_0001716c)[param_1 * 3] = 0;
    (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
    (&DAT_00017168)[param_1 * 0xc] = 0;
    (&DAT_00017166)[param_1 * 6] = 0;
    (&DAT_00017169)[param_1 * 0xc] = 0;
  }
  return;
}

