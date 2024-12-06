/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_identify_notify_handler_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_identify_notify_handler_register(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = zb_af_get_endpoint_desc();
  *(char *)(iVar1 + 7) = (char)param_1;
  *(char *)(iVar1 + 8) = (char)((uint)param_1 >> 8);
  *(char *)(iVar1 + 10) = (char)((uint)param_1 >> 0x18);
  *(char *)(iVar1 + 9) = (char)((uint)param_1 >> 0x10);
  return;
}

