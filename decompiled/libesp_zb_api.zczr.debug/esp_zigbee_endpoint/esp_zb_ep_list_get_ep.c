/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_endpoint.o -> esp_zb_ep_list_get_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_zb_ep_list_get_ep(int param_1,uint param_2)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_L0,uVar3,"ESP_ZIGBEE_ENDPOINT","esp_zb_ep_list_get_ep",
                  0x9d);
    uVar2 = 0;
  }
  else {
    for (pbVar1 = *(byte **)(param_1 + 0x24); (pbVar1 != (byte *)0x0 && (*pbVar1 != param_2));
        pbVar1 = *(byte **)(pbVar1 + 0x24)) {
    }
    if (pbVar1 == (byte *)0x0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC8,uVar3,"ESP_ZIGBEE_ENDPOINT",param_2);
      uVar2 = 0;
    }
    else {
      uVar2 = (uint)pbVar1[0x14] << 0x18 | *(uint *)(pbVar1 + 0x10) >> 8;
    }
  }
  return uVar2;
}

