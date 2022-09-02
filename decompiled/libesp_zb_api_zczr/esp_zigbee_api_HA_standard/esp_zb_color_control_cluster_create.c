/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_HA_standard.o -> esp_zb_color_control_cluster_create
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
    esp_zb_color_control_cluster_add_attr(3,&lu16_color_control_current_X_5);
    esp_zb_color_control_cluster_add_attr(uVar1,4,&lu16_color_control_current_Y_4);
    esp_zb_color_control_cluster_add_attr(uVar1,8,&lu8_color_mode_3);
    esp_zb_color_control_cluster_add_attr(uVar1,0xf,&lu8_options_2);
    esp_zb_color_control_cluster_add_attr(uVar1,0x4001,&eu8_enhanced_color_mode_1);
    esp_zb_color_control_cluster_add_attr(uVar1,0x400a,&lu16_color_capabilities_0);
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

