/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_table_clear_by_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_scenes_table_clear_by_index(uint param_1)

{
  int iVar1;
  
  if (param_1 < 0x10) {
    if ((&DAT_000114de)[param_1 * 6] != -1) {
      zb_zcl_scenes_set_scene_count((&esp_zb_zcl_scenes_table)[param_1 * 0xc],0xffffffff);
      device_scenes_table_record_free(param_1 & 0xff);
    }
    iVar1 = zb_nvram_write_dataset(9);
    return -(uint)(iVar1 != 0);
  }
  return 0x102;
}

