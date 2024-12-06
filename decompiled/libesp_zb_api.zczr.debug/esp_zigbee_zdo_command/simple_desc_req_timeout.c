/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> simple_desc_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void simple_desc_req_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"ESP_ZIGBEE_API_ZDO",&_LC7,uVar1,"ESP_ZIGBEE_API_ZDO");
  iVar2 = esp_zb_zdo_callback_find(param_1);
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    (**(code **)(iVar2 + 4))(0x85,0,*(undefined4 *)(iVar2 + 8));
  }
  esp_zb_zdo_callback_remove(param_1);
  return;
}

