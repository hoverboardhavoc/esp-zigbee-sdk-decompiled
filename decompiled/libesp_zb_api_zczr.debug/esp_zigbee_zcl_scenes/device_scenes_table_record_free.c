/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  int iVar1;
  
  if (0xf < param_1) {
    return;
  }
  iVar1 = param_1 * 0xc;
  device_scene_free_fields((&DAT_00012bfc)[param_1 * 3]);
  (&DAT_00012bfc)[param_1 * 3] = 0;
  (&DAT_00012bf6)[param_1 * 6] = 0xffff;
  (&DAT_00012bfa)[iVar1] = 0;
  *(undefined2 *)(&DAT_00012bf8 + iVar1) = 0;
  (&DAT_00012bfb)[iVar1] = 0;
  return;
}

