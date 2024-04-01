/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_callback_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * esp_zb_zdo_callback_find(uint param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = zdo_resp_cb_list_head;
  while( true ) {
    if (pbVar1 == (byte *)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(2,0x10000,&_LC1,uVar2,0x10000);
      return (byte *)0x0;
    }
    if (*pbVar1 == param_1) break;
    pbVar1 = *(byte **)(pbVar1 + 0xc);
  }
  return pbVar1;
}

