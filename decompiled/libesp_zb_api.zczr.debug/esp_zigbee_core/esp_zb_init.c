/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = esp_log_timestamp();
  uVar3 = esp_zb_get_version_string();
  esp_log_write(3,"ESP_ZIGBEE_CORE",&_L0,uVar2,"ESP_ZIGBEE_CORE",uVar3);
  zb_init();
  zb_set_installcode_policy(param_1[4]);
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC27,uVar2,"ESP_ZIGBEE_CORE");
  }
  return;
}

