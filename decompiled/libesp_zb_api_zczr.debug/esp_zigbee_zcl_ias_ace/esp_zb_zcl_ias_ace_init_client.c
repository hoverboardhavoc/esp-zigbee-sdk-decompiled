/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_ias_ace.o -> esp_zb_zcl_ias_ace_init_client
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ias_ace_init_client(void)

{
  zb_zcl_ias_ace_init_client();
  zb_zcl_device_cb_register(0x13,zcl_ias_ace_device_cb_handler_cli);
  zb_zcl_device_cb_register(0x14,zcl_ias_ace_device_cb_handler_cli);
  zb_zcl_device_cb_register(0x15,zcl_ias_ace_device_cb_handler_cli);
  zb_zcl_device_cb_register(0x16,zcl_ias_ace_device_cb_handler_cli);
  zb_zcl_device_cb_register(0x17,zcl_ias_ace_device_cb_handler_cli);
  zb_zcl_device_cb_register(0x18,zcl_ias_ace_device_cb_handler_cli);
  zb_zcl_device_cb_register(0x19,zcl_ias_ace_device_cb_handler_cli);
  zb_zcl_device_cb_register(0x1a,zcl_ias_ace_device_cb_handler_cli);
  zb_zcl_device_cb_register(0x1b,zcl_ias_ace_device_cb_handler_cli);
  return;
}

