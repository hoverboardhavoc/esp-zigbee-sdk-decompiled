/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_device_add_set_attr_value_cb
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

