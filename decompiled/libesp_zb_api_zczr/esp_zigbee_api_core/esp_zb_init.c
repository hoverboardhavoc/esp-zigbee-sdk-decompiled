/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 auStack_14 [6];
  
  zb_init();
  zb_nwk_type = *param_1;
  uVar3 = zb_nwk_type & 0xff;
  if (uVar3 == 1) {
    iVar2 = zb_production_configuration_check_presence();
    if (iVar2 == 0) {
      zb_set_network_router_role(0x2000);
      zb_set_installcode_policy((char)param_1[1]);
    }
    else {
      zb_set_network_router_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zr_config_set((int)param_1 + 6);
  }
  else if (uVar3 == 2) {
    iVar2 = zb_production_configuration_check_presence();
    if (iVar2 == 0) {
      zb_set_network_ed_role(0x2000);
      zb_set_installcode_policy((char)param_1[1]);
    }
    else {
      zb_set_network_ed_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zed_config_set((int)param_1 + 6);
  }
  else if (uVar3 == 0) {
    iVar2 = zb_production_configuration_check_presence();
    if (iVar2 == 0) {
      zb_set_network_coordinator_role(0x2000);
      zb_set_installcode_policy((char)param_1[1]);
    }
    else {
      zb_set_network_coordinator_role(0x7fff800);
      zb_set_installcode_policy(1);
      zb_production_cfg_read(auStack_14,2,0xc0);
      zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
    }
    zb_zc_config_set((int)param_1 + 6);
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_L0,uVar1,"ESP_ZIGBEE_API_CORE");
  }
  return;
}

