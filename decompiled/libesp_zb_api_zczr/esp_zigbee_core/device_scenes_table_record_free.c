/*
 * Last changed at upstream commit 3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * https://github.com/espressif/esp-zigbee-sdk/commit/3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * Upstream date: 2023-11-24 19:53:05 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.5(909d273b)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 10) {
    device_scene_free_fields((&DAT_00016f40)[param_1 * 3]);
    (&DAT_00016f40)[param_1 * 3] = 0;
    (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
    (&DAT_00016f3c)[param_1 * 0xc] = 0;
    (&DAT_00016f3a)[param_1 * 6] = 0;
    (&DAT_00016f3d)[param_1 * 0xc] = 0;
  }
  return;
}

