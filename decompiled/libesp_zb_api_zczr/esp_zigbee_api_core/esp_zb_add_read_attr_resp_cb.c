/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_add_read_attr_resp_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_add_read_attr_resp_cb(undefined4 param_1)

{
  int iVar1;
  
  if (zb_endpoint_handler_initialized == '\0') {
    iVar1 = zb_af_get_endpoint_desc();
    *(undefined1 *)(iVar1 + 3) = 0xbc;
    *(undefined1 *)(iVar1 + 4) = 2;
    *(undefined1 *)(iVar1 + 5) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
    zb_endpoint_handler_initialized = '\x01';
  }
  zcl_read_attr_user_cb = param_1;
  return;
}

