/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_add_scenes_recall_cmd_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_add_scenes_recall_cmd_cb(undefined4 param_1)

{
  int iVar1;
  
  if (zb_device_cb_initialized == '\0') {
    iVar1 = zb_zcl_get_ctx();
    *(code **)(iVar1 + 0x9c) = zcl_device_callback_entry;
    zb_device_cb_initialized = '\x01';
  }
  zcl_scenes_recall_user_cb = param_1;
  return;
}

