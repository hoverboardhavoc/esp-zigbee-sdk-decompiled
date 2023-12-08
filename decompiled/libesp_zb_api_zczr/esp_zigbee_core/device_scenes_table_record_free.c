/*
 * Last changed at upstream commit 4d04940dfac4dc79b166836b46beea711ac71a6a
 * https://github.com/espressif/esp-zigbee-sdk/commit/4d04940dfac4dc79b166836b46beea711ac71a6a
 * Upstream date: 2023-12-08 17:14:31 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.6(654c5874)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 10) {
    device_scene_free_fields((&DAT_00017018)[param_1 * 3]);
    (&DAT_00017018)[param_1 * 3] = 0;
    (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
    (&DAT_00017014)[param_1 * 0xc] = 0;
    (&DAT_00017012)[param_1 * 6] = 0;
    (&DAT_00017015)[param_1 * 0xc] = 0;
  }
  return;
}

