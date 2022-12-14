/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
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
    esp_zb_shade_config_cluster_add_attr(2,&lu8_status_16);
    esp_zb_shade_config_cluster_add_attr(uVar1,0x10,&lu8_closed_limit_15);
    esp_zb_shade_config_cluster_add_attr(uVar1,0x11,&lu8_mode_14);
  }
  else {
    esp_zb_shade_config_cluster_add_attr(2,param_1);
    esp_zb_shade_config_cluster_add_attr(uVar1,0x10,param_1 + 2);
    esp_zb_shade_config_cluster_add_attr(uVar1,0x11,param_1 + 4);
  }
  return uVar1;
}

