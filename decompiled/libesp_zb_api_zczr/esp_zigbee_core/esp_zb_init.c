/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
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
  
  zb_init();
  esp_zb_zcl_scenes_table_init();
  zb_set_installcode_policy(param_1[4]);
  esp_zb_set_manufacturer_code();
  cVar1 = *param_1;
  if (cVar1 == '\x01') {
    zb_set_network_router_role(0x7fff800);
    zb_zr_config_set(param_1 + 8);
  }
  else if (cVar1 == '\x02') {
    zb_set_network_ed_role(0x7fff800);
    zb_zed_config_set(param_1 + 8);
  }
  else if (cVar1 == '\0') {
    zb_set_network_coordinator_role(0x7fff800);
    zb_zc_config_set(param_1 + 8);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar2,"ESP_ZIGBEE_CORE");
  }
  return;
}

