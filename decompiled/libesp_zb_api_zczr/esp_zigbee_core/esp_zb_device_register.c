/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_device_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_device_register(void)

{
  int iVar1;
  
  esp_zb_device_ctx = zcl_get_ep_lists();
  iVar1 = zb_zcl_get_ctx();
  *(code **)(iVar1 + 0x9c) = zcl_device_callback_entry;
  zb_af_register_device_ctx(esp_zb_device_ctx);
  return 0;
}

