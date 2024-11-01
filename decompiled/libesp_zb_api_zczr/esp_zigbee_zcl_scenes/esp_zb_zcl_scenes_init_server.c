/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_scenes.o -> esp_zb_zcl_scenes_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_init_server(void)

{
  undefined1 *puVar1;
  
  zb_zcl_scenes_init_server();
  zb_nvram_register_app1_read_cb(zb_nvram_app1_read_cb);
  zb_nvram_register_app1_write_cb(zb_nvram_app1_write_cb,0x10000);
  puVar1 = &esp_zb_zcl_scenes_table;
  do {
    *(undefined2 *)(puVar1 + 2) = 0xffff;
    puVar1 = puVar1 + 0xc;
  } while (puVar1 != (undefined1 *)0x11668);
  zb_zcl_device_cb_register(0x57,zcl_scenes_add_scene_handler);
  zb_zcl_device_cb_register(0x5a,zcl_scenes_remove_scene_handler);
  zb_zcl_device_cb_register(0x5b,zcl_scenes_remove_all_scenes_handler);
  zb_zcl_device_cb_register(0x59,zcl_scenes_view_scene_handler);
  zb_zcl_device_cb_register(0x58,zcl_scenes_store_scene_handler);
  zb_zcl_device_cb_register(0x5c,zcl_scenes_recall_scene_handler);
  zb_zcl_device_cb_register(0x5d,zcl_scenes_get_scene_membership_handler);
  return;
}

