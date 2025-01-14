/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  if (param_1 < 0x10) {
    device_scene_free_fields((&DAT_000114e4)[param_1 * 3]);
    *(undefined4 *)(&DAT_000114e0 + param_1 * 6) = 0;
    (&DAT_000114de)[param_1 * 6] = 0xffff;
    (&DAT_000114e4)[param_1 * 3] = 0;
    return;
  }
  return;
}

