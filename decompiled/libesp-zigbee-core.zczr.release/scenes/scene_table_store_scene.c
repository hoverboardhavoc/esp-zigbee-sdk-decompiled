/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_store_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t scene_table_store_scene(uint8_t ep_id,zcl_scene_table_entry_t *entry)

{
  uint8_t scene_id;
  byte bVar1;
  uint16_t group_id;
  uint16_t uVar2;
  uint uVar3;
  uint8_t *puVar4;
  uint uVar5;
  ezb_zcl_scenes_extension_field_t *peVar6;
  ezb_zcl_scenes_extension_field_t *peVar7;
  ezb_err_t eVar8;
  
  eVar8 = 2;
  if (entry != (zcl_scene_table_entry_t *)0x0) {
    uVar5 = 0;
    peVar7 = entry->extension_field;
    for (peVar6 = peVar7; peVar6 != (ezb_zcl_scenes_extension_field_t *)0x0; peVar6 = peVar6->next)
    {
      uVar5 = uVar5 + 3 + (uint)peVar6->length & 0xffff;
    }
    uVar5 = uVar5 + 0x18 & 0xffff;
    puVar4 = (uint8_t *)calloc(1,uVar5);
    eVar8 = 1;
    if (puVar4 != (uint8_t *)0x0) {
      group_id = entry->group_id;
      scene_id = entry->scene_id;
      *puVar4 = ep_id;
      puVar4[2] = (uint8_t)(group_id >> 8);
      puVar4[1] = (uint8_t)group_id;
      puVar4[3] = scene_id;
      strncpy((char *)(puVar4 + 4),entry->scene_name,0x11);
      uVar2 = entry->transition_time;
      puVar4[0x15] = (uint8_t)uVar2;
      puVar4[0x16] = (uint8_t)(uVar2 >> 8);
      uVar3 = 0;
      puVar4[0x17] = entry->transition_time_100ms;
      for (; peVar7 != (ezb_zcl_scenes_extension_field_t *)0x0; peVar7 = peVar7->next) {
        puVar4[uVar3 + 0x18] = (uint8_t)peVar7->cluster_id;
        (puVar4 + uVar3 + 0x18)[1] = *(uint8_t *)((int)&peVar7->cluster_id + 1);
        bVar1 = peVar7->length;
        puVar4[(uVar3 + 2 & 0xffff) + 0x18] = bVar1;
        uVar3 = uVar3 + 3 & 0xffff;
        if (bVar1 != 0) {
          memcpy(puVar4 + uVar3 + 0x18,peVar7->value,(uint)bVar1);
          uVar3 = uVar3 + peVar7->length & 0xffff;
        }
      }
      scene_table_remove_stored_scene(ep_id,group_id,scene_id);
      eVar8 = ds_internal_add_entry(0xb,puVar4,uVar5);
      mm_free(puVar4);
    }
  }
  return eVar8;
}

