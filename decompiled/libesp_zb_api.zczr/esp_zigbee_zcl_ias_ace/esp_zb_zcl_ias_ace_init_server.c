/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_ias_ace.o -> esp_zb_zcl_ias_ace_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ias_ace_init_server(void)

{
  zb_zcl_ias_ace_init_server();
  zb_zcl_device_cb_register(0xb,zcl_ias_ace_device_cb_handler_srv);
  zb_zcl_device_cb_register(0xc,zcl_ias_ace_device_cb_handler_srv);
  zb_zcl_device_cb_register(0xd,zcl_ias_ace_device_cb_handler_srv);
  zb_zcl_device_cb_register(0xe,zcl_ias_ace_device_cb_handler_srv);
  zb_zcl_device_cb_register(0xf,zcl_ias_ace_device_cb_handler_srv);
  zb_zcl_device_cb_register(0x10,zcl_ias_ace_device_cb_handler_srv);
  zb_zcl_device_cb_register(0x11,zcl_ias_ace_device_cb_handler_srv);
  zb_zcl_device_cb_register(0x12,zcl_ias_ace_device_cb_handler_srv);
  return;
}

