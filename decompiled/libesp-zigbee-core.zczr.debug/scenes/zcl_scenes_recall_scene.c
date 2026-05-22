/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> zcl_scenes_recall_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_scenes_recall_scene
          (zcl_packet_t *packet,uint16_t group_id,uint8_t scene_id,uint16_t transition_time)

{
  ezb_zcl_status_t eVar1;
  undefined3 extraout_var;
  int iVar2;
  zcl_scene_table_entry_t *entry;
  zcl_attr_desc_t *pzVar3;
  zcl_attr_desc_t *pzVar4;
  zcl_attr_desc_t *pzVar5;
  undefined3 extraout_var_00;
  undefined3 in_register_00002031;
  undefined2 in_register_00002036;
  uint8_t unaff_s2;
  uint uVar6;
  
  uVar6 = CONCAT22(in_register_00002036,transition_time);
  if (packet == (zcl_packet_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x397,
                  "zcl_scenes_recall_scene","packet");
  }
  else {
    unaff_s2 = (packet->header).dst_ep;
    eVar1 = scenes_check_group_id(group_id);
    iVar2 = CONCAT31(extraout_var,eVar1);
    if (iVar2 != 0) goto _L0;
  }
  entry = scene_table_find_entry
                    (unaff_s2,group_id,(uint16_t)CONCAT31(in_register_00002031,scene_id));
  if (entry != (zcl_scene_table_entry_t *)0x0) {
    if (uVar6 == 0xffff) {
      uVar6 = (uint)entry->transition_time;
    }
    pzVar3 = scenes_srv_get_attr_desc(unaff_s2,1);
    pzVar4 = scenes_srv_get_attr_desc(unaff_s2,2);
    pzVar5 = scenes_srv_get_attr_desc(unaff_s2,3);
    if (((pzVar3 != (zcl_attr_desc_t *)0x0) && (pzVar4 != (zcl_attr_desc_t *)0x0)) &&
       (pzVar5 != (zcl_attr_desc_t *)0x0)) {
      *(uint8_t *)pzVar3->data_p = scene_id;
      *(uint16_t *)pzVar4->data_p = group_id;
      *(undefined1 *)pzVar5->data_p = 0;
      eVar1 = zcl_message_scenes_recall_scene(packet,(uint16_t)uVar6,entry);
      iVar2 = CONCAT31(extraout_var_00,eVar1);
      if (iVar2 == 0) {
        *(undefined1 *)pzVar5->data_p = 1;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x3a7,
                  "zcl_scenes_recall_scene",
                  "curr_scene_attr_desc && curr_group_attr_desc && scene_valid_attr_desc");
  }
  iVar2 = 0x8b;
_L0:
  return (ezb_zcl_status_t)iVar2;
}

