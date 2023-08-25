/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_group_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_scenes_group_check(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 0xfff8) {
    iVar1 = zb_aps_is_endpoint_in_group();
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC25,uVar2,"ESP_ZIGBEE_CORE",param_2,param_1);
      uVar2 = 0x85;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC24,uVar2,"ESP_ZIGBEE_CORE",param_1);
    uVar2 = 0x87;
  }
  return uVar2;
}

