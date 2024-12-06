/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_touchlink.o -> esp_zb_zll_identify_req_handler_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zll_identify_req_handler_register(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = zb_zll_get_device_info();
  *(undefined4 *)(iVar1 + 0x50) = 0x10000;
  zll_identify_req_handler = param_1;
  return;
}

