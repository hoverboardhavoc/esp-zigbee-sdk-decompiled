/*
 * Last changed at upstream commit 2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * https://github.com/espressif/esp-zigbee-sdk/commit/2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * Upstream date: 2023-01-31 10:56:39 +0800
 * Upstream subject: example: Support new zdo API(0d9da4e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_callback_find
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

