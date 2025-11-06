/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_check_startup_parameters
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zcl_commissioning_check_startup_parameters(void)

{
  undefined4 uVar1;
  
  if ((_DAT_00011728 >> 8 & 0xff) == 2) {
    if ((_DAT_00011728 & 0xff) == 2) {
      if ((_DAT_00011728 & 0xffff00) == 0x100) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
              "E (%lu) %s: %s(%d): Protocol Version(%d) is not supported!\n",uVar1,
              "ESP_ZIGBEE_ZCL_COMMISSIONING","esp_zcl_commissioning_check_startup_parameters",0xed,
              _DAT_00011728 & 0xff);
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
            "E (%lu) %s: %s(%d): Stack Profile(%d) is not supported!\n",uVar1,
            "ESP_ZIGBEE_ZCL_COMMISSIONING","esp_zcl_commissioning_check_startup_parameters",0xea,
            _DAT_00011728 >> 8 & 0xff);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

