/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
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
    device_scene_free_fields((&DAT_00015ad4)[param_1 * 3]);
    (&DAT_00015ad4)[param_1 * 3] = 0;
    *(undefined2 *)(&esp_zb_zcl_scenes_table + iVar1) = 0xffff;
    (&DAT_00015ad0)[iVar1] = 0;
    *(undefined2 *)(&DAT_00015ace + iVar1) = 0;
    (&DAT_00015ad1)[iVar1] = 0;
  }
  return;
}

