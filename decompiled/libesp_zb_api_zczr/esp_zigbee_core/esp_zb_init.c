/*
 * Last changed at upstream commit 4d04940dfac4dc79b166836b46beea711ac71a6a
 * https://github.com/espressif/esp-zigbee-sdk/commit/4d04940dfac4dc79b166836b46beea711ac71a6a
 * Upstream date: 2023-12-08 17:14:31 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.6(654c5874)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 auStack_14 [6];
  
  zb_init();
  esp_zb_zcl_scenes_table_init();
  cVar1 = *param_1;
  if (cVar1 == '\x01') {
    iVar2 = zb_production_configuration_check_presence();
    if (iVar2 == 0) {
      zb_set_network_router_role(0x7fff800);
      zb_set_installcode_policy(param_1[4]);
    }
    else {
      zb_set_network_router_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zr_config_set(param_1 + 8);
  }
  else if (cVar1 == '\x02') {
    iVar2 = zb_production_configuration_check_presence();
    if (iVar2 == 0) {
      zb_set_network_ed_role(0x7fff800);
      zb_set_installcode_policy(param_1[4]);
    }
    else {
      zb_set_network_ed_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zed_config_set(param_1 + 8);
  }
  else if (cVar1 == '\0') {
    iVar2 = zb_production_configuration_check_presence();
    if (iVar2 == 0) {
      zb_set_network_coordinator_role(0x7fff800);
      zb_set_installcode_policy(param_1[4]);
    }
    else {
      zb_set_network_coordinator_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zc_config_set(param_1 + 8);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC69,uVar3,"ESP_ZIGBEE_CORE");
  }
  return;
}

