/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> nwk_update_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_update_req_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"ESP_ZIGBEE_API_ZDO",&_LC13,uVar1,"ESP_ZIGBEE_API_ZDO");
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  iVar2 = esp_zb_zdo_callback_find(param_1);
  uStack_38 = CONCAT31(uStack_38._1_3_,0x85);
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    (**(code **)(iVar2 + 4))(&uStack_38,*(undefined4 *)(iVar2 + 8));
  }
  esp_zb_zdo_callback_remove(param_1);
  return;
}

