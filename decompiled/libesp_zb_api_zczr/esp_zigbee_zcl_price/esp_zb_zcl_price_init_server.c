/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_price.o -> esp_zb_zcl_price_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_price_init_server(void)

{
  zb_zcl_price_init_server();
  zb_zcl_device_cb_register(0x2a,zcl_price_get_current_price_handler);
  zb_zcl_device_cb_register(0x2b,zcl_price_get_scheduled_prices_handler);
  zb_zcl_device_cb_register(0x2c,zcl_price_get_tier_labels_handler);
  zb_zcl_device_cb_register(0x2f,0x10000);
  return;
}

