/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_remove_stored_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: itor */
/* WARNING: Unknown calling convention */

void scene_table_remove_stored_scene(uint8_t ep_id,uint16_t group_id,uint8_t scene_id)

{
  undefined3 in_register_00002029;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  undefined1 auStack_1c [4];
  zcl_scene_info_iterator_t itor;
  
  auStack_1c._0_2_ = 0;
  auStack_1c._2_2_ = 0;
  itor.length = 0;
  itor.index = 0;
  itor.is_done = false;
  itor._5_3_ = 0;
  ds_zcl_scene_info_iterator_init((zcl_scene_info_iterator_t *)auStack_1c);
  do {
    if ((char)itor.length != '\0') {
_L0:
      ds_zcl_scene_info_iterator_deinit((zcl_scene_info_iterator_t *)auStack_1c);
      return;
    }
    if ((((uint)*(byte *)itor._4_4_ == CONCAT31(in_register_00002029,ep_id)) &&
        ((uint)*(ushort *)(itor._4_4_ + 1) == CONCAT22(in_register_0000202e,group_id))) &&
       ((uint)*(byte *)(itor._4_4_ + 3) == CONCAT31(in_register_00002031,scene_id))) {
      ds_zcl_scene_info_delete((zcl_scene_info_iterator_t *)auStack_1c);
      goto _L0;
    }
    ds_zcl_scene_info_next((zcl_scene_info_iterator_t *)auStack_1c);
  } while( true );
}

