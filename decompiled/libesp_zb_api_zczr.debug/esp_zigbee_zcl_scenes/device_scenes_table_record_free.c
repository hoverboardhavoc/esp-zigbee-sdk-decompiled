/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_table_record_free
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
  device_scene_free_fields((&DAT_00012c00)[param_1 * 3]);
  (&DAT_00012c00)[param_1 * 3] = 0;
  (&DAT_00012bfa)[param_1 * 6] = 0xffff;
  (&DAT_00012bfe)[param_1 * 0xc] = 0;
  (&DAT_00012bfc)[param_1 * 6] = 0;
  (&DAT_00012bff)[param_1 * 0xc] = 0;
  return;
}

