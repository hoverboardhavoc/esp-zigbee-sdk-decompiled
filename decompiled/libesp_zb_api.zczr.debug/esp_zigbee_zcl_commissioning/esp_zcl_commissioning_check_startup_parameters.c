/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
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
  
  if ((_DAT_000117a8 >> 8 & 0xff) == 2) {
    if ((_DAT_000117a8 & 0xff) == 2) {
      if ((_DAT_000117a8 & 0xffff00) == 0x100) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_LC2,uVar1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                    "esp_zcl_commissioning_check_startup_parameters",0xed,_DAT_000117a8 & 0xff);
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_LC1,uVar1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                  "esp_zcl_commissioning_check_startup_parameters",0xea,_DAT_000117a8 >> 8 & 0xff);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

