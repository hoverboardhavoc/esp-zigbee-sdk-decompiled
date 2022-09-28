/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_shade_config_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_shade_config_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(0x100);
  if (param_1 == 0) {
    esp_zb_shade_config_cluster_add_attr(2,&lu8_status_8);
    esp_zb_shade_config_cluster_add_attr(uVar1,0x10,&lu8_closed_limit_7);
    esp_zb_shade_config_cluster_add_attr(uVar1,0x11,&lu8_mode_6);
  }
  else {
    esp_zb_shade_config_cluster_add_attr(2,param_1);
    esp_zb_shade_config_cluster_add_attr(uVar1,0x10,param_1 + 2);
    esp_zb_shade_config_cluster_add_attr(uVar1,0x11,param_1 + 4);
  }
  return uVar1;
}

