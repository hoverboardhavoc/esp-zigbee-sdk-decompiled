/*
 * Last changed at upstream commit b278a1511ed728943e19c371f88a01e9d130f19f
 * https://github.com/espressif/esp-zigbee-sdk/commit/b278a1511ed728943e19c371f88a01e9d130f19f
 * Upstream date: 2023-02-27 14:43:05 +0800
 * Upstream subject: zcl: add ZCL API for color and report attribute(af3fa1e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_add_cli_resp_handler_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_add_cli_resp_handler_cb(undefined4 param_1)

{
  int iVar1;
  
  if (zb_endpoint_handler_initialized == '\0') {
    iVar1 = zb_af_get_endpoint_desc();
    *(undefined1 *)(iVar1 + 3) = 0x98;
    *(undefined1 *)(iVar1 + 4) = 0x16;
    *(undefined1 *)(iVar1 + 5) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
    zb_endpoint_handler_initialized = '\x01';
  }
  zcl_cli_resp_user_cb = param_1;
  return;
}

