/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zb_zcl_scenes_add_scene_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_scenes_add_scene_count(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = zb_zcl_get_attr_desc_a(5,1,0);
  if (iVar2 != 0) {
    bVar1 = **(byte **)(iVar2 + 6);
    if ((int)(param_1 + (uint)bVar1) < 0) {
      uVar3 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_scenes.c"
                        ,0xef);
      if (uVar3 < esp_zb_zcl_scenes_table_capacity) {
        iVar2 = uVar3 * 0xc;
        if (*(short *)((undefined1 *)(esp_zb_zcl_scenes_table + iVar2) + 2) != -1) {
          zb_zcl_scenes_add_scene_count(*(undefined1 *)(esp_zb_zcl_scenes_table + iVar2),0xffffffff)
          ;
          device_scene_free_fields(*(undefined4 *)(esp_zb_zcl_scenes_table + iVar2 + 8));
          iVar2 = esp_zb_zcl_scenes_table + iVar2;
          *(undefined4 *)(iVar2 + 8) = 0;
          *(undefined2 *)(iVar2 + 2) = 0xffff;
          *(undefined1 *)(iVar2 + 6) = 0;
          *(undefined2 *)(iVar2 + 4) = 0;
          *(undefined1 *)(iVar2 + 7) = 0;
        }
      }
      return;
    }
    **(byte **)(iVar2 + 6) = bVar1 + (char)param_1;
  }
  return;
}

