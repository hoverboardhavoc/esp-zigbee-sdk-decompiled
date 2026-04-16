/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t scene_table_restore(uint8_t ep_id)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined3 in_register_00002029;
  ezb_zcl_scenes_extension_field_t *peVar4;
  uint8_t *__dest;
  zcl_scene_table_entry_t *entry;
  uint uVar5;
  uint __size;
  int iVar6;
  undefined1 auStack_3c [4];
  zcl_scene_info_iterator_t itor;
  
  auStack_3c = (undefined1  [4])0x0;
  itor.length = 0;
  itor.index = 0;
  itor.is_done = false;
  itor._5_3_ = 0;
  ds_zcl_scene_info_iterator_init((zcl_scene_info_iterator_t *)auStack_3c);
  do {
    uVar2 = itor._4_4_;
    if ((char)itor.length != '\0') {
      iVar6 = 0;
_L0:
      ds_zcl_scene_info_iterator_deinit((zcl_scene_info_iterator_t *)auStack_3c);
      if (iVar6 != 0) {
        scene_table_refresh_stored_scenes(ep_id);
      }
      return iVar6;
    }
    if ((itor._4_4_ != 0) && ((uint)*(byte *)itor._4_4_ == CONCAT31(in_register_00002029,ep_id))) {
      entry = scene_table_get_unused_entry(ep_id);
      if (entry == (zcl_scene_table_entry_t *)0x0) {
        iVar6 = 1;
        goto _L0;
      }
      entry->group_id = *(uint16_t *)(uVar2 + 1);
      entry->scene_id = *(uint8_t *)(uVar2 + 3);
      entry->transition_time = *(uint16_t *)(uVar2 + 0x15);
      entry->transition_time_100ms = *(uint8_t *)(uVar2 + 0x17);
      strncpy(entry->scene_name,(char *)(uVar2 + 4),0x11);
      uVar5 = ((uint)auStack_3c & 0xffff) - 0x18 & 0xffff;
      uVar3 = 0;
      while ((uVar5 != 0 && (uVar3 < uVar5))) {
        peVar4 = (ezb_zcl_scenes_extension_field_t *)calloc(1,0xc);
        if (peVar4 == (ezb_zcl_scenes_extension_field_t *)0x0) {
          iVar6 = 1;
          goto _L0;
        }
        iVar6 = uVar2 + 0x18;
        *(undefined1 *)&peVar4->cluster_id = *(undefined1 *)(iVar6 + uVar3);
        *(undefined1 *)((int)&peVar4->cluster_id + 1) = ((undefined1 *)(iVar6 + uVar3))[1];
        bVar1 = *(byte *)((uVar3 + 2 & 0xffff) + iVar6);
        __size = (uint)bVar1;
        peVar4->length = bVar1;
        uVar3 = uVar3 + 3 & 0xffff;
        uVar5 = uVar5 - 3 & 0xffff;
        if (__size != 0) {
          __dest = (uint8_t *)calloc(1,__size);
          peVar4->value = __dest;
          if (__dest == (uint8_t *)0x0) {
            iVar6 = 1;
            goto _L0;
          }
          memcpy(__dest,(void *)(iVar6 + uVar3),__size);
          uVar3 = uVar3 + peVar4->length & 0xffff;
          uVar5 = uVar5 - peVar4->length & 0xffff;
        }
        peVar4->next = entry->extension_field;
        entry->extension_field = peVar4;
      }
      scene_table_add_entry(ep_id,entry,false);
    }
    ds_zcl_scene_info_next((zcl_scene_info_iterator_t *)auStack_3c);
  } while( true );
}

