/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_add_custom_cluster_command_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_add_custom_cluster_command_cb(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  if (zb_endpoint_handler_initialized == '\0') {
    iVar1 = zb_af_get_endpoint_desc();
    *(undefined1 *)(iVar1 + 3) = 0xa4;
    *(undefined1 *)(iVar1 + 4) = 0x16;
    *(undefined1 *)(iVar1 + 5) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
    zb_endpoint_handler_initialized = '\x01';
  }
  zcl_custom_cluster_cmd_cb = param_2;
  esp_zb_set_global_custom_cluster_id(param_1);
  return;
}

