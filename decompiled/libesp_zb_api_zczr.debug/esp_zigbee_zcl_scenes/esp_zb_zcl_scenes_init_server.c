/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
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
  zb_zcl_device_cb_register(0x53,zcl_scenes_add_scene_handler);
  zb_zcl_device_cb_register(0x56,zcl_scenes_remove_scene_handler);
  zb_zcl_device_cb_register(0x57,zcl_scenes_remove_all_scenes_handler);
  zb_zcl_device_cb_register(0x55,zcl_scenes_view_scene_handler);
  zb_zcl_device_cb_register(0x54,zcl_scenes_store_scene_handler);
  zb_zcl_device_cb_register(0x58,zcl_scenes_recall_scene_handler);
  zb_zcl_device_cb_register(0x59,zcl_scenes_get_scene_membership_handler);
  return;
}

