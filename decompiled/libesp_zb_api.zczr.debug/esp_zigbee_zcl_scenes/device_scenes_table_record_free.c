/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  int iVar1;
  
  if (param_1 < esp_zb_zcl_scenes_table_capacity) {
    iVar1 = param_1 * 0xc;
    if (*(short *)((undefined1 *)(esp_zb_zcl_scenes_table + iVar1) + 2) != -1) {
      zb_zcl_scenes_add_scene_count(*(undefined1 *)(esp_zb_zcl_scenes_table + iVar1),0xffffffff);
      device_scene_free_fields(*(undefined4 *)(esp_zb_zcl_scenes_table + iVar1 + 8));
      iVar1 = esp_zb_zcl_scenes_table + iVar1;
      *(undefined4 *)(iVar1 + 8) = 0;
      *(undefined2 *)(iVar1 + 2) = 0xffff;
      *(undefined1 *)(iVar1 + 6) = 0;
      *(undefined2 *)(iVar1 + 4) = 0;
      *(undefined1 *)(iVar1 + 7) = 0;
    }
  }
  return;
}

