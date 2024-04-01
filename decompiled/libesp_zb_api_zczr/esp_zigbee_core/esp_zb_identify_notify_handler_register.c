/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
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
  *(char *)(iVar1 + 10) = (char)((uint)param_1 >> 0x18);
  *(char *)(iVar1 + 9) = (char)((uint)param_1 >> 0x10);
  return;
}

