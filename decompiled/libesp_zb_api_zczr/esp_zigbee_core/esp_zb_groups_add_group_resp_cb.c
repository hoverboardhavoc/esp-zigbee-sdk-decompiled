/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
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
    *(undefined1 *)(iVar1 + 3) = 0xec;
    *(undefined1 *)(iVar1 + 4) = 4;
    *(undefined1 *)(iVar1 + 5) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
    zb_endpoint_handler_initialized = '\x01';
  }
  zcl_add_group_resp_user_cb = param_1;
  return;
}

