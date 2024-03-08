/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
  device_scene_free_fields((&DAT_00018efc)[param_1 * 3]);
  (&DAT_00018efc)[param_1 * 3] = 0;
  (&DAT_00018ef6)[param_1 * 6] = 0xffff;
  (&DAT_00018efa)[param_1 * 0xc] = 0;
  (&DAT_00018ef8)[param_1 * 6] = 0;
  (&DAT_00018efb)[param_1 * 0xc] = 0;
  return;
}

