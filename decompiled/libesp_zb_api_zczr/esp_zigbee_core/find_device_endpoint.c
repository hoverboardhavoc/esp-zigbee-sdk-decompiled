/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> find_device_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * find_device_endpoint(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  
  if (esp_zb_device_ctx == (byte *)0x0) {
    return (byte *)0x0;
  }
  iVar2 = 0;
  while( true ) {
    if ((int)(uint)*esp_zb_device_ctx <= iVar2) {
      return (byte *)0x0;
    }
    pbVar1 = *(byte **)(*(int *)(esp_zb_device_ctx + 1) + iVar2 * 4);
    if (*pbVar1 == param_1) break;
    iVar2 = iVar2 + 1;
  }
  return pbVar1;
}

