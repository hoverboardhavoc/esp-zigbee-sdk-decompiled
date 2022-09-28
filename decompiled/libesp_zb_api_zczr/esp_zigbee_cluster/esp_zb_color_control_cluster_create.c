/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_color_control_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_color_control_cluster_create(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = esp_zb_zcl_attr_list_create(0x300);
  if (param_1 == 0) {
    esp_zb_color_control_cluster_add_attr(3,&lu16_color_control_current_X_16);
    esp_zb_color_control_cluster_add_attr(uVar1,4,&lu16_color_control_current_Y_15);
    esp_zb_color_control_cluster_add_attr(uVar1,8,&lu8_color_mode_14);
    esp_zb_color_control_cluster_add_attr(uVar1,0xf,&lu8_options_13);
    esp_zb_color_control_cluster_add_attr(uVar1,0x4001,&eu8_enhanced_color_mode_12);
    esp_zb_color_control_cluster_add_attr(uVar1,0x400a,&lu16_color_capabilities_11);
  }
  else {
    esp_zb_color_control_cluster_add_attr(3,param_1);
    esp_zb_color_control_cluster_add_attr(uVar1,4,param_1 + 2);
    esp_zb_color_control_cluster_add_attr(uVar1,8,param_1 + 4);
    esp_zb_color_control_cluster_add_attr(uVar1,0xf,param_1 + 5);
    esp_zb_color_control_cluster_add_attr(uVar1,0x4001,param_1 + 6);
    esp_zb_color_control_cluster_add_attr(uVar1,0x400a,param_1 + 8);
  }
  return uVar1;
}

