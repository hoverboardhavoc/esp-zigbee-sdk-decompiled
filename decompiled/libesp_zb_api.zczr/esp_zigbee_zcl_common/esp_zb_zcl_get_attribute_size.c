/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_common.o -> esp_zb_zcl_get_attribute_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_get_attribute_size(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) && (param_1 != 0)) {
    return 0xffff;
  }
  uVar1 = zb_zcl_get_attribute_size();
  return uVar1;
}

