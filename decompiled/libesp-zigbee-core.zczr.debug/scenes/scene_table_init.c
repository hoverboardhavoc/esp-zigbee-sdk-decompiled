/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t scene_table_init(uint8_t ep_id)

{
  byte bVar1;
  uint uVar2;
  size_t __size;
  ezb_zcl_scenes_extension_field_t *peVar3;
  uint8_t ep_id_00;
  uint16_t uVar4;
  zcl_attr_desc_t *pzVar5;
  zcl_attr_desc_t *pzVar6;
  zcl_attr_desc_t *pzVar7;
  void *__s;
  uint8_t *puVar8;
  ezb_err_t eVar9;
  zcl_scene_table_entry_t *entry;
  byte *pbVar10;
  uint __size_00;
  
  pzVar5 = scenes_srv_get_attr_desc(ep_id,0xeff0);
  pzVar6 = scenes_srv_get_attr_desc(ep_id,0);
  pzVar7 = scenes_srv_get_attr_desc(ep_id,0xeff1);
  if (((pzVar7 == (zcl_attr_desc_t *)0x0) || (pzVar5 == (zcl_attr_desc_t *)0x0)) ||
     (pzVar6 == (zcl_attr_desc_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x117,
                  "scene_table_init",
                  "scene_table_attr_desc && scene_total_attr_desc && scene_count_attr_desc");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    bVar1 = *pzVar5->data_p;
    __size = (uint)bVar1 * 0x20 + 8;
    __s = calloc(1,__size);
    pzVar7->data_p = __s;
    if (__s != (void *)0x0) {
      memset(__s,0,__size);
      pbVar10 = (byte *)pzVar7->data_p;
      *pbVar10 = bVar1;
      *(void **)(pbVar10 + 4) = pzVar6->data_p;
      return 0;
    }
  }
  entry = (zcl_scene_table_entry_t *)
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x11c,
                        "scene_table_init","scene_table_attr_desc->data_p");
  if (entry == (zcl_scene_table_entry_t *)0x0) {
    eVar9 = 2;
  }
  else {
    uVar4 = scene_entry_get_extended_field_length(entry);
    __size_00 = uVar4 + 0x18 & 0xffff;
    puVar8 = (uint8_t *)calloc(1,__size_00);
    if (puVar8 == (uint8_t *)0x0) {
      eVar9 = 1;
    }
    else {
      *puVar8 = ep_id_00;
      uVar4 = entry->group_id;
      puVar8[1] = (uint8_t)uVar4;
      puVar8[2] = (uint8_t)(uVar4 >> 8);
      puVar8[3] = entry->scene_id;
      strncpy((char *)(puVar8 + 4),entry->scene_name,0x11);
      uVar4 = entry->transition_time;
      puVar8[0x15] = (uint8_t)uVar4;
      puVar8[0x16] = (uint8_t)(uVar4 >> 8);
      puVar8[0x17] = entry->transition_time_100ms;
      uVar2 = 0;
      for (peVar3 = entry->extension_field; peVar3 != (ezb_zcl_scenes_extension_field_t *)0x0;
          peVar3 = peVar3->next) {
        puVar8[uVar2 + 0x18] = (uint8_t)peVar3->cluster_id;
        (puVar8 + uVar2 + 0x18)[1] = *(uint8_t *)((int)&peVar3->cluster_id + 1);
        bVar1 = peVar3->length;
        puVar8[(uVar2 + 2 & 0xffff) + 0x18] = bVar1;
        uVar2 = uVar2 + 3 & 0xffff;
        if (bVar1 != 0) {
          memcpy(puVar8 + uVar2 + 0x18,peVar3->value,(uint)bVar1);
          uVar2 = peVar3->length + uVar2 & 0xffff;
        }
      }
      scene_table_remove_stored_scene(ep_id_00,entry->group_id,entry->scene_id);
      eVar9 = ds_internal_add_entry(0xb,puVar8,__size_00);
      mm_free(puVar8);
    }
  }
  return eVar9;
}

