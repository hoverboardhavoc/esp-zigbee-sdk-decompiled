/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_ias_wd_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_wd_cluster_add_attr(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = esp_zb_internal_cluster_add_attr(0x502,0,0x21,3,0xffff);
  }
  else {
    uVar1 = esp_log_timestamp(param_2);
    esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar1,0x10000);
    uVar1 = 0x102;
  }
  return uVar1;
}

