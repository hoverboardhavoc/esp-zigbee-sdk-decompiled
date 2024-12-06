/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_drlc.o -> esp_zb_zcl_drlc_init_client
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_drlc_init_client(void)

{
  zb_zcl_drlc_init_client();
  zb_zcl_device_cb_register(0x32,zcl_drlc_load_control_event_cb_handler);
  zb_zcl_device_cb_register(0x33,zcl_drlc_cancel_load_control_event_cb_handler);
  zb_zcl_device_cb_register(0x34,zcl_drlc_cancel_all_load_control_events_cb_handler);
  return;
}

