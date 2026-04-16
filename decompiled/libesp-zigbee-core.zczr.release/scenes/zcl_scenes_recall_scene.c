/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> zcl_scenes_recall_scene
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
  uint8_t ep_id;
  zcl_scene_table_entry_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  zcl_attr_desc_t *pzVar4;
  uint uVar5;
  undefined2 in_register_0000202e;
  uint extraout_a1;
  uint16_t scene_id_00;
  undefined3 in_register_00002031;
  undefined2 in_register_00002036;
  uint uVar6;
  undefined1 auStack_4c [4];
  ezb_zcl_scenes_recall_scene_message_t message;
  
  uVar6 = CONCAT22(in_register_00002036,transition_time);
  scene_id_00 = (uint16_t)CONCAT31(in_register_00002031,scene_id);
  uVar5 = CONCAT22(in_register_0000202e,group_id);
  if (packet != (zcl_packet_t *)0x0) goto _L0;
  do {
    uVar6 = 0;
    scene_id_00 = 0;
    packet = (zcl_packet_t *)__assert_func(0,0);
    uVar5 = extraout_a1;
_L0:
    if (0xfff7 < uVar5) {
      uVar5 = 0x87;
      goto _L0;
    }
    ep_id = (packet->header).dst_ep;
    pzVar1 = scene_table_find_entry(ep_id,(uint16_t)uVar5,scene_id_00);
    if (pzVar1 == (zcl_scene_table_entry_t *)0x0) {
      uVar5 = 0x8b;
      goto _L0;
    }
    if (uVar6 == 0xffff) {
      uVar6 = (uint)pzVar1->transition_time;
    }
    pzVar2 = scenes_srv_get_attr_desc(ep_id,1);
    pzVar3 = scenes_srv_get_attr_desc(ep_id,2);
    pzVar4 = scenes_srv_get_attr_desc(ep_id,3);
  } while (((pzVar2 == (zcl_attr_desc_t *)0x0) || (pzVar3 == (zcl_attr_desc_t *)0x0)) ||
          (pzVar4 == (zcl_attr_desc_t *)0x0));
  *(char *)pzVar2->data_p = (char)scene_id_00;
  *(uint16_t *)pzVar3->data_p = (uint16_t)uVar5;
  *(undefined1 *)pzVar4->data_p = 0;
  memset(auStack_4c,0,0x1c);
  uVar5 = zcl_packet_to_message(auStack_4c,packet);
  if (uVar5 == 0) {
    message.in.header._0_2_ = pzVar1->group_id;
    message.in.header._2_1_ = pzVar1->scene_id;
    message.in.group_id = (uint16_t)uVar6;
    message.in._8_4_ = pzVar1->extension_field;
    message.in.field_set._0_1_ = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x15,auStack_4c);
    uVar5 = (uint)(byte)message.in.field_set;
    if ((uVar5 == 0xfe) || (uVar5 == 0)) {
      uVar5 = 0;
      *(undefined1 *)pzVar4->data_p = 1;
    }
  }
_L0:
  return (ezb_zcl_status_t)uVar5;
}

