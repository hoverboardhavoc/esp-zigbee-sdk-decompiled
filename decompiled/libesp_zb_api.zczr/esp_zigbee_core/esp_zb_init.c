/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_init
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
  zb_set_installcode_policy(param_1[4]);
  cVar1 = *param_1;
  if (cVar1 == '\x01') {
    zb_set_network_router_role(0x7fff800);
  }
  else {
    if (cVar1 == '\x02') {
      zb_set_network_ed_role(0x7fff800);
      zb_set_ed_timeout(param_1[8]);
      zb_set_keepalive_timeout(*(int *)(param_1 + 0xc) * 1000);
      if (*(int *)(param_1 + 0xc) != 0) {
        esp_zb_set_default_long_poll_interval();
      }
      zb_set_nvram_erase_at_start(0);
      return;
    }
    if (cVar1 != '\0') {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC2,uVar2,"ESP_ZIGBEE_CORE");
      return;
    }
    zb_set_network_coordinator_role(0x7fff800);
  }
  zb_set_max_children(param_1[8]);
  zb_set_nvram_erase_at_start(0);
  return;
}

