/*
 * Last changed at upstream commit 3ee1c52790580ff8c3ec33b61f57334e0f637dc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/3ee1c52790580ff8c3ec33b61f57334e0f637dc8
 * Upstream date: 2023-05-26 18:12:14 +0800
 * Upstream subject: esp-zboss: Provide zboss APIs to fix github issues(70cea8e)
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
  *(undefined1 *)(iVar1 + 3) = 0x9a;
  *(undefined1 *)(iVar1 + 4) = 0x18;
  *(undefined1 *)(iVar1 + 5) = 1;
  *(undefined1 *)(iVar1 + 6) = 0;
  zb_endpoint_handler_initialized_0 = 1;
  return;
}

