/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_groups_add_group_resp_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_groups_add_group_resp_cb(undefined4 param_1)

{
  int iVar1;
  
  if (zb_endpoint_handler_initialized == '\0') {
    iVar1 = zb_af_get_endpoint_desc();
    *(undefined1 *)(iVar1 + 3) = 0xb4;
    *(undefined1 *)(iVar1 + 4) = 0x16;
    *(undefined1 *)(iVar1 + 5) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
    zb_endpoint_handler_initialized = '\x01';
  }
  zcl_add_group_resp_user_cb = param_1;
  return;
}

