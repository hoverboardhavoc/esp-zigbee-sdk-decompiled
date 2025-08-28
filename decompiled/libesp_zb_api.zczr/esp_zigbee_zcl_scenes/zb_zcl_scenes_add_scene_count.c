/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zb_zcl_scenes_add_scene_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_scenes_add_scene_count(int param_1)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = zb_zcl_get_attr_desc_a(5,1,0);
  if (iVar1 != 0) {
    pbVar2 = *(byte **)(iVar1 + 6);
    param_1 = (uint)*pbVar2 + param_1;
    if (param_1 == -1) {
      param_1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_scenes.c"
                          ,0xef);
    }
    *pbVar2 = (byte)param_1;
  }
  return;
}

