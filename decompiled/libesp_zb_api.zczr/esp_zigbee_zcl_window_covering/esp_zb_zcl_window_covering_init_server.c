/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_window_covering.o -> esp_zb_zcl_window_covering_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_window_covering_init_server(void)

{
  zb_zcl_window_covering_init_server();
  zb_zcl_device_cb_register(0x50,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x51,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x52,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x53,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x54,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x55,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x56,zcl_window_covering_cmd_handler);
  return;
}

