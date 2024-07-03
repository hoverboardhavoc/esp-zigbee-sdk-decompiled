/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_init_server(void)

{
  zb_zcl_scenes_init_server();
  esp_zb_zcl_scenes_table_init();
  zb_zcl_device_cb_register(0x55,zcl_scenes_add_scene_handler);
  zb_zcl_device_cb_register(0x58,zcl_scenes_remove_scene_handler);
  zb_zcl_device_cb_register(0x59,zcl_scenes_remove_all_scenes_handler);
  zb_zcl_device_cb_register(0x57,zcl_scenes_view_scene_handler);
  zb_zcl_device_cb_register(0x56,zcl_scenes_store_scene_handler);
  zb_zcl_device_cb_register(0x5a,zcl_scenes_recall_scene_handler);
  zb_zcl_device_cb_register(0x5b,zcl_scenes_get_scene_membership_handler);
  return;
}

