/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> ezb_zcl_scenes_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_scenes_cluster_server_init(uint8_t ep_id)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar5;
  zcl_attr_desc_t *pzVar6;
  zcl_attr_desc_t *pzVar7;
  void *__s;
  zcl_scene_table_entry_t *entry;
  int iVar8;
  ezb_zcl_scenes_extension_field_t *peVar9;
  uint8_t *__dest;
  size_t __size;
  byte *pbVar10;
  undefined1 *puVar11;
  undefined1 local_5c [4];
  zcl_scene_info_iterator_t itor;
  zcl_scene_info_iterator_t itor_1;
  zcl_cluster_template_t template;
  
  memcpy(&itor_1.blob,&_LANCHOR0,0x14);
  pzVar5 = scenes_srv_get_attr_desc(ep_id,0xeff0);
  pzVar6 = scenes_srv_get_attr_desc(ep_id,0);
  pzVar7 = scenes_srv_get_attr_desc(ep_id,0xeff1);
  if (((pzVar7 != (zcl_attr_desc_t *)0x0) && (pzVar5 != (zcl_attr_desc_t *)0x0)) &&
     (pzVar6 != (zcl_attr_desc_t *)0x0)) goto _L0;
  do {
    do {
      pzVar7 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L0:
                    /* WARNING: Load size is inaccurate */
      bVar1 = *pzVar5->data_p;
      pzVar5 = (zcl_attr_desc_t *)(uint)bVar1;
      __size = (int)pzVar5 * 0x20 + 8;
      __s = calloc(1,__size);
      pzVar7->data_p = __s;
    } while (__s == (void *)0x0);
    memset(__s,0,__size);
    pbVar10 = (byte *)pzVar7->data_p;
    *pbVar10 = bVar1;
    *(void **)(pbVar10 + 4) = pzVar6->data_p;
    local_5c = (undefined1  [4])0x0;
    itor.length = 0;
    itor.index = 0;
    itor.is_done = false;
    itor._5_3_ = 0;
    ds_zcl_scene_info_iterator_init((zcl_scene_info_iterator_t *)local_5c);
_L0:
    uVar3 = itor._4_4_;
    if ((char)itor.length == '\0') {
      if ((itor._4_4_ == 0) || ((uint)*(byte *)itor._4_4_ != CONCAT31(in_register_00002029,ep_id)))
      goto _L0;
      entry = scene_table_get_unused_entry(ep_id);
      if (entry != (zcl_scene_table_entry_t *)0x0) break;
_L0:
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (itor._4_4_ != 0) {
      mm_free();
    }
    local_5c._0_2_ = 0;
    local_5c._2_2_ = 0;
    itor.length = 0;
    itor.index = 0;
    itor.is_done = false;
    itor._5_3_ = 0;
    if (bVar2) {
      ds_zcl_scene_info_iterator_init((zcl_scene_info_iterator_t *)&itor.blob);
      while ((char)itor_1.length == '\0') {
        if ((uint)*(byte *)itor_1._4_4_ == CONCAT31(in_register_00002029,ep_id)) {
          ds_internal_remove_entry(0xb);
        }
        else {
          itor.blob._2_2_ = itor.blob._2_2_ + 1;
        }
        ds_zcl_scene_info_read((zcl_scene_info_iterator_t *)&itor.blob);
      }
      pzVar6 = (zcl_attr_desc_t *)scene_table_get(ep_id);
      for (uVar4 = 0; uVar4 < (byte)pzVar6->id; uVar4 = uVar4 + 1 & 0xff) {
        if (*(char *)&pzVar6[uVar4 * 2].data_p != '\0') {
          scene_table_store_scene(ep_id,(zcl_scene_table_entry_t *)&pzVar6[uVar4 * 2].data_p);
        }
      }
    }
    iVar8 = zcl_cluster_template_add(&itor_1.blob);
    if (iVar8 == 0) {
      return;
    }
  } while( true );
  entry->group_id = *(uint16_t *)(uVar3 + 1);
  entry->scene_id = *(uint8_t *)(uVar3 + 3);
  pzVar5 = (zcl_attr_desc_t *)0x0;
  entry->transition_time = *(uint16_t *)(uVar3 + 0x15);
  entry->transition_time_100ms = *(uint8_t *)(uVar3 + 0x17);
  strncpy(entry->scene_name,(char *)(uVar3 + 4),0x11);
  pzVar6 = (zcl_attr_desc_t *)(((uint)local_5c & 0xffff) - 0x18 & 0xffff);
  while (pzVar5 < pzVar6) {
    peVar9 = (ezb_zcl_scenes_extension_field_t *)calloc(1,0xc);
    if (peVar9 == (ezb_zcl_scenes_extension_field_t *)0x0) goto _L0;
    puVar11 = (undefined1 *)((int)&pzVar5[1].data_p + uVar3);
    *(undefined1 *)&peVar9->cluster_id = *puVar11;
    pzVar6 = (zcl_attr_desc_t *)((uint)((int)&pzVar6[-1].next + 1U) & 0xffff);
    *(undefined1 *)((int)&peVar9->cluster_id + 1) = puVar11[1];
    bVar1 = *(byte *)(((uint)&pzVar5->type & 0xffff) + uVar3 + 0x18);
    uVar4 = (uint)bVar1;
    peVar9->length = bVar1;
    pzVar5 = (zcl_attr_desc_t *)((uint)&pzVar5->access & 0xffff);
    if (uVar4 != 0) {
      __dest = (uint8_t *)calloc(1,uVar4);
      peVar9->value = __dest;
      if (__dest == (uint8_t *)0x0) goto _L0;
      memcpy(__dest,(void *)((int)&pzVar5[1].data_p + uVar3),uVar4);
      pzVar5 = (zcl_attr_desc_t *)((int)&pzVar5->id + uVar4 & 0xffff);
      pzVar6 = (zcl_attr_desc_t *)((int)pzVar6 - uVar4 & 0xffff);
    }
    peVar9->next = entry->extension_field;
    entry->extension_field = peVar9;
  }
  scene_table_add_entry(ep_id,entry,false);
  if ((char)itor.length == '\0') {
_L0:
    local_5c._2_2_ = local_5c._2_2_ + 1;
    ds_zcl_scene_info_read((zcl_scene_info_iterator_t *)local_5c);
  }
  goto _L0;
}

