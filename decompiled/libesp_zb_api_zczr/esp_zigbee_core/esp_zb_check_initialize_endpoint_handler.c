/*
 * Last changed at upstream commit 6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * https://github.com/espressif/esp-zigbee-sdk/commit/6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * Upstream date: 2023-04-06 16:02:34 +0800
 * Upstream subject: example: support single C6 gateway example and other API support(a1884f9)
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
  *(undefined1 *)(iVar1 + 3) = 0x32;
  *(undefined1 *)(iVar1 + 4) = 0x17;
  *(undefined1 *)(iVar1 + 5) = 1;
  *(undefined1 *)(iVar1 + 6) = 0;
  zb_endpoint_handler_initialized_0 = 1;
  return;
}

