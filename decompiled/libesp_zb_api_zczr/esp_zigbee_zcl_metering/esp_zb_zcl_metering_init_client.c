/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_metering.o -> esp_zb_zcl_metering_init_client
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_init_client(void)

{
  zb_zcl_metering_init_client();
  zb_zcl_device_cb_register(0x45,zcl_metering_get_profile_cb_handler);
  zb_zcl_device_cb_register(0x46,zcl_metering_request_fast_poll_mode_cb_handler);
  zb_zcl_device_cb_register(0x47,zcl_metering_get_snapshot_cb_handler);
  zb_zcl_device_cb_register(0x48,zcl_metering_get_sampled_data_cb_handler);
  return;
}

