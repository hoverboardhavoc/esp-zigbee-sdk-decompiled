/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
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
    esp_zb_color_control_cluster_add_attr(3,&lu16_color_control_current_X_24);
    esp_zb_color_control_cluster_add_attr(uVar1,4,&lu16_color_control_current_Y_23);
    esp_zb_color_control_cluster_add_attr(uVar1,8,&lu8_color_mode_22);
    esp_zb_color_control_cluster_add_attr(uVar1,0xf,&lu8_options_21);
    esp_zb_color_control_cluster_add_attr(uVar1,0x4001,&eu8_enhanced_color_mode_20);
    esp_zb_color_control_cluster_add_attr(uVar1,0x400a,&lu16_color_capabilities_19);
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

