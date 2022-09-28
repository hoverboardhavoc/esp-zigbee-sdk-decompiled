/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_device_add_set_attr_value_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_device_add_set_attr_value_cb(undefined4 param_1)

{
  int iVar1;
  
  if (zb_device_cb_initialized == '\0') {
    iVar1 = zb_zcl_get_ctx();
    *(code **)(iVar1 + 0x9c) = zcl_device_callback_entry;
    zb_device_cb_initialized = '\x01';
  }
  zcl_set_attr_user_cb = param_1;
  return;
}

