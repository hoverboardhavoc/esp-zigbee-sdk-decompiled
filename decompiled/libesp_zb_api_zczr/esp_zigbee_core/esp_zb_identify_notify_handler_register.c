/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_identify_notify_handler_register
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
  *(char *)(iVar1 + 9) = (char)((uint)param_1 >> 0x10);
  *(char *)(iVar1 + 10) = (char)((uint)param_1 >> 0x18);
  return;
}

