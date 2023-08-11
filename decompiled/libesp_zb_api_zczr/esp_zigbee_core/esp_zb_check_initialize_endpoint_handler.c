/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_check_initialize_endpoint_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_check_initialize_endpoint_handler(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = zb_af_get_endpoint_desc();
  if (*(int *)(iVar1 + 3) == 0) {
    iVar1 = zb_af_get_endpoint_desc(param_1);
    *(undefined1 *)(iVar1 + 3) = 0x22;
    *(undefined1 *)(iVar1 + 4) = 0x19;
    *(undefined1 *)(iVar1 + 5) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
  }
  return;
}

