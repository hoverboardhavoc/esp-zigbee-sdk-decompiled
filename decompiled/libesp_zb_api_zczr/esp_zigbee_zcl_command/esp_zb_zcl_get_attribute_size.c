/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_get_attribute_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_get_attribute_size(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 == 0) && (param_1 != 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_get_attribute_size",0x7d);
    iVar1 = 0xffff;
  }
  else {
    iVar1 = zb_zcl_get_attribute_size();
    if (iVar1 == 0xffff) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC2,uVar2,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_get_attribute_size",0x7e);
    }
  }
  return iVar1;
}

