/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_ias_ace.o -> esp_zb_zcl_ias_ace_init_server
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

