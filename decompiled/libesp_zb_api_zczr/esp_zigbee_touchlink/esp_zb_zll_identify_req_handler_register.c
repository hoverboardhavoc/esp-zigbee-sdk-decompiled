/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_api_zczr -> esp_zigbee_touchlink.o -> esp_zb_zll_identify_req_handler_register
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

