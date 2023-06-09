/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_check_initialize_endpoint_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_check_initialize_endpoint_handler(void)

{
  int iVar1;
  
  if (zb_endpoint_handler_initialized_0 != '\0') {
    return;
  }
  iVar1 = zb_af_get_endpoint_desc();
  *(undefined1 *)(iVar1 + 3) = 0x36;
  *(undefined1 *)(iVar1 + 4) = 0x1a;
  *(undefined1 *)(iVar1 + 5) = 1;
  *(undefined1 *)(iVar1 + 6) = 0;
  zb_endpoint_handler_initialized_0 = 1;
  return;
}

