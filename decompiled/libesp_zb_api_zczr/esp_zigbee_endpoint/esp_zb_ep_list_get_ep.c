/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> esp_zb_ep_list_get_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_zb_ep_list_get_ep(int param_1,uint param_2)

{
  undefined4 uVar1;
  byte *pbVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  pbVar2 = *(byte **)(param_1 + 0x24);
  while( true ) {
    if (pbVar2 == (byte *)0x0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC2,uVar1,"ESP_ZIGBEE_ENDPOINT",param_2);
      return 0;
    }
    if (*pbVar2 == param_2) break;
    pbVar2 = *(byte **)(pbVar2 + 0x24);
  }
  return (uint)pbVar2[0x14] << 0x18 | *(uint *)(pbVar2 + 0x10) >> 8;
}

