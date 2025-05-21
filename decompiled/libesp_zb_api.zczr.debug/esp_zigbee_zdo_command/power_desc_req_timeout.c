/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> power_desc_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_desc_req_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"ESP_ZIGBEE_API_ZDO",&_LC5,uVar1,"ESP_ZIGBEE_API_ZDO");
  uStack_18 = 0;
  uStack_14 = 0;
  iVar2 = esp_zb_zdo_callback_find(param_1);
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    uStack_18 = CONCAT31(uStack_18._1_3_,0x85);
    (**(code **)(iVar2 + 4))(&uStack_18,*(undefined4 *)(iVar2 + 8));
  }
  esp_zb_zdo_callback_remove(param_1);
  return;
}

