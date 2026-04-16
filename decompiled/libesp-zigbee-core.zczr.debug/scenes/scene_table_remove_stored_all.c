/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_remove_stored_all
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void scene_table_remove_stored_all(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  undefined1 auStack_1c [4];
  zcl_scene_info_iterator_t itor;
  
  ds_zcl_scene_info_iterator_init((zcl_scene_info_iterator_t *)auStack_1c);
  while ((char)itor.length == '\0') {
    if ((uint)*(byte *)itor._4_4_ == CONCAT31(in_register_00002029,ep_id)) {
      ds_zcl_scene_info_delete((zcl_scene_info_iterator_t *)auStack_1c);
      ds_zcl_scene_info_read((zcl_scene_info_iterator_t *)auStack_1c);
    }
    else {
      ds_zcl_scene_info_next((zcl_scene_info_iterator_t *)auStack_1c);
    }
  }
  return;
}

