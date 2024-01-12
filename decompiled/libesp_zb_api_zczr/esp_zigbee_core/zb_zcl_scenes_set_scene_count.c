/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_scenes_set_scene_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_scenes_set_scene_count(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_zcl_get_attr_desc_a(5,1,0);
  if (iVar1 != 0) {
    **(char **)(iVar1 + 6) = **(char **)(iVar1 + 6) + param_1;
    if (0xf < **(byte **)(iVar1 + 6)) {
      uVar2 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC1,uVar2,"ESP_ZIGBEE_CORE",**(undefined1 **)(iVar1 + 6));
    }
  }
  return;
}

