/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_get_attribute_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_get_attribute_size(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) && (param_1 != 0)) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar1,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_get_attribute_size",0x5c);
    uVar1 = 0xffff;
  }
  else {
    uVar1 = zb_zcl_get_attribute_size();
  }
  return uVar1;
}

