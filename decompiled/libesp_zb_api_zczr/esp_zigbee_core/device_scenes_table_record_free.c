/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  int iVar1;
  
  if (param_1 < 10) {
    iVar1 = param_1 * 0xc;
    device_scene_free_fields((&DAT_00016f14)[param_1 * 3]);
    (&DAT_00016f14)[param_1 * 3] = 0;
    (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
    (&DAT_00016f10)[iVar1] = 0;
    *(undefined2 *)(&DAT_00016f0e + iVar1) = 0;
    (&DAT_00016f11)[iVar1] = 0;
  }
  return;
}

