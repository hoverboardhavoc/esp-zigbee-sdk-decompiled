/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> ieee_addr_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ieee_addr_req_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"ESP_ZIGBEE_API_ZDO",&_LC2,uVar1,"ESP_ZIGBEE_API_ZDO");
  iVar2 = esp_zb_zdo_callback_find(param_1);
  if (iVar2 != 0) {
    if (*(code **)(iVar2 + 4) != (code *)0x0) {
      (**(code **)(iVar2 + 4))(0x85,0,*(undefined4 *)(iVar2 + 8));
    }
    esp_zb_zdo_callback_remove(param_1);
  }
  return;
}

