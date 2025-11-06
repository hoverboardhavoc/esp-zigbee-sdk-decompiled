/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_common.o -> esp_zb_zcl_get_attribute_size
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
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Invalid type or value\n",uVar1,0x10000,
            "esp_zb_zcl_get_attribute_size",0x2f);
    uVar1 = 0xffff;
  }
  else {
    uVar1 = zb_zcl_get_attribute_size();
  }
  return uVar1;
}

