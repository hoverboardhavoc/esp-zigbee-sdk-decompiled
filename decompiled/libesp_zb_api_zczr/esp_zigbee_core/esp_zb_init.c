/*
 * Last changed at upstream commit 1f6b611e278a00f885edde9cb38294c3c08373a5
 * https://github.com/espressif/esp-zigbee-sdk/commit/1f6b611e278a00f885edde9cb38294c3c08373a5
 * Upstream date: 2023-08-01 20:17:41 +0800
 * Upstream subject: esp-zigbee-sdk: fix zigbee zcl scenes extension field implementation
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 auStack_14 [6];
  
  zb_init();
  esp_zb_zcl_scenes_table_parameter();
  cVar1 = *param_1;
  if (cVar1 == '\x01') {
    iVar3 = zb_production_configuration_check_presence();
    if (iVar3 == 0) {
      zb_set_network_router_role(0x7fff800);
      zb_set_installcode_policy(param_1[4]);
    }
    else {
      zb_set_network_router_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zr_config_set(param_1 + 6);
  }
  else if (cVar1 == '\x02') {
    iVar3 = zb_production_configuration_check_presence();
    if (iVar3 == 0) {
      zb_set_network_ed_role(0x7fff800);
      zb_set_installcode_policy(param_1[4]);
    }
    else {
      zb_set_network_ed_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zed_config_set(param_1 + 6);
  }
  else if (cVar1 == '\0') {
    iVar3 = zb_production_configuration_check_presence();
    if (iVar3 == 0) {
      zb_set_network_coordinator_role(0x7fff800);
      zb_set_installcode_policy(param_1[4]);
    }
    else {
      zb_set_network_coordinator_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zc_config_set(param_1 + 6);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar2,"ESP_ZIGBEE_CORE");
  }
  return;
}

