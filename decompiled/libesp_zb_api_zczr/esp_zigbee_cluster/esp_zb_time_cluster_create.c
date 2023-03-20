/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_time_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_time_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(10);
  if (param_1 == 0) {
    esp_zb_time_cluster_add_attr(0,&lu32_time_default_25);
    esp_zb_time_cluster_add_attr(uVar1,1,&lu8_time_status_default_24);
  }
  else {
    esp_zb_time_cluster_add_attr(0,param_1);
    esp_zb_time_cluster_add_attr(uVar1,1,param_1 + 2);
  }
  return uVar1;
}

