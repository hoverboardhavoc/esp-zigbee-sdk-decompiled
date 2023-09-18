/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  int iVar1;
  
  if (9 < param_1) {
    return;
  }
  iVar1 = param_1 * 0xc;
  device_scene_free_fields((&DAT_00015948)[param_1 * 3]);
  (&DAT_00015948)[param_1 * 3] = 0;
  (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
  (&DAT_00015944)[iVar1] = 0;
  *(undefined2 *)(&DAT_00015942 + iVar1) = 0;
  (&DAT_00015945)[iVar1] = 0;
  return;
}

