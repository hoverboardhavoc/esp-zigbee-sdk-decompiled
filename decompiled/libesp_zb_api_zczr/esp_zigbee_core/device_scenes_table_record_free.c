/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (9 < param_1) {
    return;
  }
  device_scene_free_fields((&DAT_000156a8)[param_1 * 3]);
  (&DAT_000156a8)[param_1 * 3] = 0;
  (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
  (&DAT_000156a4)[param_1 * 0xc] = 0;
  (&DAT_000156a2)[param_1 * 6] = 0;
  (&DAT_000156a5)[param_1 * 0xc] = 0;
  return;
}

