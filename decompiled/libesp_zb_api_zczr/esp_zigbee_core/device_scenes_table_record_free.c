/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
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
  device_scene_free_fields((&DAT_00014680)[param_1 * 3]);
  (&DAT_00014680)[param_1 * 3] = 0;
  (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
  (&DAT_0001467c)[iVar1] = 0;
  *(undefined2 *)(&DAT_0001467a + iVar1) = 0;
  (&DAT_0001467d)[iVar1] = 0;
  return;
}

