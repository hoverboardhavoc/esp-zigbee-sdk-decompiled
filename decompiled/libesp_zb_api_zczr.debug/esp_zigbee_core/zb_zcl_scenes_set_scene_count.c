/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zb_zcl_scenes_set_scene_count
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

