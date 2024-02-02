/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 0x10) {
    device_scene_free_fields((&DAT_00017f7c)[param_1 * 3]);
    (&DAT_00017f7c)[param_1 * 3] = 0;
    (&DAT_00017f76)[param_1 * 6] = 0xffff;
    (&DAT_00017f7a)[param_1 * 0xc] = 0;
    (&DAT_00017f78)[param_1 * 6] = 0;
    (&DAT_00017f7b)[param_1 * 0xc] = 0;
  }
  return;
}

