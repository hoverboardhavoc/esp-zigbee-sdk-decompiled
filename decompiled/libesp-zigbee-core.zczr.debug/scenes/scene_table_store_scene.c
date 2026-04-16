/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_store_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t scene_table_store_scene(uint8_t ep_id,zcl_scene_table_entry_t *entry)

{
  byte bVar1;
  uint uVar2;
  ezb_zcl_scenes_extension_field_t *peVar3;
  uint16_t uVar4;
  uint8_t *puVar5;
  ezb_err_t eVar6;
  uint __size;
  
  if (entry == (zcl_scene_table_entry_t *)0x0) {
    eVar6 = 2;
  }
  else {
    uVar4 = scene_entry_get_extended_field_length(entry);
    __size = uVar4 + 0x18 & 0xffff;
    puVar5 = (uint8_t *)calloc(1,__size);
    if (puVar5 == (uint8_t *)0x0) {
      eVar6 = 1;
    }
    else {
      *puVar5 = ep_id;
      uVar4 = entry->group_id;
      puVar5[1] = (uint8_t)uVar4;
      puVar5[2] = (uint8_t)(uVar4 >> 8);
      puVar5[3] = entry->scene_id;
      strncpy((char *)(puVar5 + 4),entry->scene_name,0x11);
      uVar4 = entry->transition_time;
      puVar5[0x15] = (uint8_t)uVar4;
      puVar5[0x16] = (uint8_t)(uVar4 >> 8);
      puVar5[0x17] = entry->transition_time_100ms;
      uVar2 = 0;
      for (peVar3 = entry->extension_field; peVar3 != (ezb_zcl_scenes_extension_field_t *)0x0;
          peVar3 = peVar3->next) {
        puVar5[uVar2 + 0x18] = (uint8_t)peVar3->cluster_id;
        (puVar5 + uVar2 + 0x18)[1] = *(uint8_t *)((int)&peVar3->cluster_id + 1);
        bVar1 = peVar3->length;
        puVar5[(uVar2 + 2 & 0xffff) + 0x18] = bVar1;
        uVar2 = uVar2 + 3 & 0xffff;
        if (bVar1 != 0) {
          memcpy(puVar5 + uVar2 + 0x18,peVar3->value,(uint)bVar1);
          uVar2 = peVar3->length + uVar2 & 0xffff;
        }
      }
      scene_table_remove_stored_scene(ep_id,entry->group_id,entry->scene_id);
      eVar6 = ds_internal_add_entry(0xb,puVar5,__size);
      mm_free(puVar5);
    }
  }
  return eVar6;
}

