/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
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
  device_scene_free_fields((&DAT_000145cc)[param_1 * 3]);
  (&DAT_000145cc)[param_1 * 3] = 0;
  (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
  (&DAT_000145c8)[iVar1] = 0;
  *(undefined2 *)(&DAT_000145c6 + iVar1) = 0;
  (&DAT_000145c9)[iVar1] = 0;
  return;
}

