/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_HA_standard.o -> esp_zb_basic_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_basic_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(0);
  if (param_1 == 0) {
    esp_zb_basic_cluster_add_attr(0,&lu8_zcl_version_default_16);
    esp_zb_basic_cluster_add_attr(uVar1,7,&lu8_power_source_default_15);
  }
  else {
    esp_zb_basic_cluster_add_attr(0,param_1);
    esp_zb_basic_cluster_add_attr(uVar1,7,param_1 + 1);
  }
  return uVar1;
}

