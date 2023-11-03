/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
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
    device_scene_free_fields((&DAT_00016d00)[param_1 * 3]);
    (&DAT_00016d00)[param_1 * 3] = 0;
    *(undefined2 *)(&esp_zb_zcl_scenes_table + iVar1) = 0xffff;
    (&DAT_00016cfc)[iVar1] = 0;
    *(undefined2 *)(&DAT_00016cfa + iVar1) = 0;
    (&DAT_00016cfd)[iVar1] = 0;
  }
  return;
}

