/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_endpoint.o -> esp_zb_ep_list_add_gateway_ep
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
      esp_zb_zcl_thermostat_init_client();
      zb_zcl_color_control_init_client();
      esp_zb_zcl_ias_zone_init_client();
      esp_zb_zcl_ias_ace_init_client();
      esp_zb_zcl_custom_cluster_init_client();
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ENDPOINT","E (%lu) %s: %s(%d): Failed to add cluster list to endpoint\n"
              ,uVar2,"ESP_ZIGBEE_ENDPOINT","esp_zb_ep_list_add_gateway_ep",0x7d);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ENDPOINT",
            "E (%lu) %s: %s(%d): Gateway endpoints have reached its limit or invalid endpoint value\n"
            ,uVar2,"ESP_ZIGBEE_ENDPOINT","esp_zb_ep_list_add_gateway_ep",0x74);
    iVar1 = 0x101;
  }
  return iVar1;
}

