/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_get_attribute_size
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

