/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_price.o -> esp_zb_zcl_price_init_client
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_price_init_client(void)

{
  zb_zcl_price_init_client();
  zb_zcl_device_cb_register(0x2c,zcl_price_publish_price_handler);
  zb_zcl_device_cb_register(0x2d,zcl_price_publish_tier_labels_handler);
  return;
}

