/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_metering.o -> esp_zb_zcl_metering_init_client
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_init_client(void)

{
  zb_zcl_metering_init_client();
  zb_zcl_device_cb_register(0x47,zcl_metering_get_profile_cb_handler);
  zb_zcl_device_cb_register(0x48,zcl_metering_request_fast_poll_mode_cb_handler);
  zb_zcl_device_cb_register(0x49,zcl_metering_get_snapshot_cb_handler);
  zb_zcl_device_cb_register(0x4a,zcl_metering_get_sampled_data_cb_handler);
  return;
}

