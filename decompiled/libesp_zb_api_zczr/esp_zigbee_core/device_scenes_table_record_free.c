/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (0xf < param_1) {
    return;
  }
  device_scene_free_fields((&DAT_00018f14)[param_1 * 3]);
  (&DAT_00018f14)[param_1 * 3] = 0;
  (&DAT_00018f0e)[param_1 * 6] = 0xffff;
  (&DAT_00018f12)[param_1 * 0xc] = 0;
  (&DAT_00018f10)[param_1 * 6] = 0;
  (&DAT_00018f13)[param_1 * 0xc] = 0;
  return;
}

