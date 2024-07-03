/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_window_covering.o -> esp_zb_zcl_window_covering_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_window_covering_init_server(void)

{
  zb_zcl_window_covering_init_server();
  zb_zcl_device_cb_register(0x4e,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x4f,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x50,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x51,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x52,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x53,zcl_window_covering_cmd_handler);
  zb_zcl_device_cb_register(0x54,zcl_window_covering_cmd_handler);
  return;
}

