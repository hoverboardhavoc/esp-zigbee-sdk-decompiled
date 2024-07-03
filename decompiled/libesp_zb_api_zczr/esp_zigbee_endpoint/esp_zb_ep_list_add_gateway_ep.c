/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> esp_zb_ep_list_add_gateway_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_ep_list_add_gateway_ep(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_zcl_add_gateway_endpoint(param_3 & 0xff);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      param_2 = esp_zb_zcl_cluster_list_create();
      uVar2 = esp_zb_basic_cluster_create(0);
      esp_zb_cluster_list_add_basic_cluster(param_2,uVar2,1);
      uVar2 = esp_zb_identify_cluster_create(0);
      esp_zb_cluster_list_add_identify_cluster(param_2,uVar2,1);
    }
    iVar1 = esp_zb_ep_list_add_ep(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      zb_zcl_basic_init_client();
      zb_zcl_identify_init_client();
      esp_zb_zcl_groups_init_client();
      esp_zb_zcl_scenes_init_client();
      zb_zcl_on_off_init_client();
      zb_zcl_level_control_init_client();
      esp_zb_zcl_commissioning_init_client();
      esp_zb_zcl_door_lock_init_client();
      zb_zcl_window_covering_init_client();
      zb_zcl_thermostat_init_client();
      zb_zcl_color_control_init_client();
      esp_zb_zcl_ias_zone_init_client();
      esp_zb_zcl_ias_ace_init_client();
      esp_zb_zcl_custom_cluster_init_client();
    }
  }
  else {
    iVar1 = 0x101;
  }
  return iVar1;
}

