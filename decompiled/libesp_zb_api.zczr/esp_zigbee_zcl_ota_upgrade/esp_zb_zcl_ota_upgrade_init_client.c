/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_ota_upgrade.o -> esp_zb_zcl_ota_upgrade_init_client
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ota_upgrade_init_client(void)

{
  zb_zcl_ota_upgrade_init_cli();
  zb_zcl_device_cb_register(0x1c,zcl_ota_upgrade_handler);
  zb_zcl_device_cb_register(0x1d,zcl_ota_upgrade_query_image_resp_handler);
  return;
}

