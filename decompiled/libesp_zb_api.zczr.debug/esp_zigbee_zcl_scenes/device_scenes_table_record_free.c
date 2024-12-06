/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_table_record_free
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

