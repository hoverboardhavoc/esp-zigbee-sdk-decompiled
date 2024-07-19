/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_door_lock.o -> esp_zb_zcl_door_lock_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_door_lock_init_server(void)

{
  zb_zcl_door_lock_init_server();
  zb_zcl_device_cb_register(0x62,0x10000);
  zb_zcl_device_cb_register(99,0x10000);
  return;
}

