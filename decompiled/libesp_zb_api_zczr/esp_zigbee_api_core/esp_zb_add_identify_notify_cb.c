/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_add_identify_notify_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_add_identify_notify_cb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = zb_af_get_endpoint_desc();
  *(char *)(iVar1 + 7) = (char)param_1;
  *(char *)(iVar1 + 8) = (char)((uint)param_1 >> 8);
  *(char *)(iVar1 + 9) = (char)((uint)param_1 >> 0x10);
  *(char *)(iVar1 + 10) = (char)((uint)param_1 >> 0x18);
  return;
}

