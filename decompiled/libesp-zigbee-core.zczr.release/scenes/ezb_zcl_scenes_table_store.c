/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> ezb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_scenes_table_store
                    (uint8_t ep_id,uint16_t group_id,uint8_t scene_id,uint16_t transition_time,
                    ezb_zcl_scenes_extension_field_t *field)

{
  _Bool _Var1;
  zcl_scene_table_entry_t *entry;
  ezb_zcl_scenes_extension_field_t *peVar2;
  uint8_t *__dest;
  undefined3 in_register_00002031;
  uint __size;
  
  entry = scene_table_find_entry(ep_id,group_id,(uint16_t)CONCAT31(in_register_00002031,scene_id));
  if (entry == (zcl_scene_table_entry_t *)0x0) {
    entry = scene_table_get_unused_entry(ep_id);
    if (entry == (zcl_scene_table_entry_t *)0x0) {
      return 1;
    }
  }
  else {
    scene_entry_free_scene_extension_field(entry);
  }
  entry->group_id = group_id;
  entry->scene_id = scene_id;
  entry->scene_name[0] = '\0';
  entry->transition_time = transition_time;
  entry->transition_time_100ms = '\0';
  while( true ) {
    if (field == (ezb_zcl_scenes_extension_field_t *)0x0) {
      _Var1 = scene_table_add_entry(ep_id,entry,true);
      return _Var1 ^ 1;
    }
    peVar2 = (ezb_zcl_scenes_extension_field_t *)calloc(1,0xc);
    if (peVar2 == (ezb_zcl_scenes_extension_field_t *)0x0) break;
    peVar2->cluster_id = field->cluster_id;
    __size = (uint)field->length;
    peVar2->length = field->length;
    __dest = (uint8_t *)calloc(1,__size);
    peVar2->value = __dest;
    if (__dest == (uint8_t *)0x0) {
      return 1;
    }
    if (__size != 0) {
      memcpy(__dest,field->value,__size);
    }
    peVar2->next = entry->extension_field;
    field = field->next;
    entry->extension_field = peVar2;
  }
  return 1;
}

