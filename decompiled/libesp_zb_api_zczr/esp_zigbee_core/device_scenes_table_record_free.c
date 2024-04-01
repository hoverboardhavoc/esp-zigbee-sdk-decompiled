/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 0x10) {
    device_scene_free_fields((&DAT_00015ba8)[param_1 * 3]);
    *(undefined4 *)(&DAT_00015ba4 + param_1 * 6) = 0;
    (&DAT_00015ba2)[param_1 * 6] = 0xffff;
    (&DAT_00015ba8)[param_1 * 3] = 0;
    return;
  }
  return;
}

