/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_binary_input_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_binary_input_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(0xf);
  if (param_1 == 0) {
    esp_zb_binary_input_cluster_add_attr(0x51,&lb_out_service_20);
    esp_zb_binary_input_cluster_add_attr(uVar1,0x6f,&lu8_status_flag_19);
  }
  else {
    esp_zb_binary_input_cluster_add_attr(0x51,param_1);
    esp_zb_binary_input_cluster_add_attr(uVar1,0x6f,param_1 + 1);
  }
  return uVar1;
}

