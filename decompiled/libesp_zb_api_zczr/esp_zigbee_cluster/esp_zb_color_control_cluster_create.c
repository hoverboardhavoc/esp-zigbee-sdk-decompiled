/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
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
    esp_zb_color_control_cluster_add_attr(3,&lu16_color_control_current_X_31);
    esp_zb_color_control_cluster_add_attr(uVar1,4,&lu16_color_control_current_Y_30);
    esp_zb_color_control_cluster_add_attr(uVar1,8,&lu8_color_mode_29);
    esp_zb_color_control_cluster_add_attr(uVar1,0xf,&lu8_options_28);
    esp_zb_color_control_cluster_add_attr(uVar1,0x4001,&eu8_enhanced_color_mode_27);
    esp_zb_color_control_cluster_add_attr(uVar1,0x400a,&lu16_color_capabilities_26);
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

