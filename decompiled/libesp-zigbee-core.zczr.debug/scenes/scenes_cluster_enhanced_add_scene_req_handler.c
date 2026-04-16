/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_enhanced_add_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
scenes_cluster_enhanced_add_scene_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  byte bVar1;
  uint16_t unaff_s0;
  ezb_zcl_status_t eVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ezb_zcl_scenes_extension_field_t *peVar4;
  uint8_t *value;
  undefined3 extraout_var_01;
  zcl_scene_table_entry_t *entry;
  uint unaff_s4;
  undefined1 uVar5;
  int unaff_s6;
  uint16_t uStack_3a;
  uint16_t uStack_38;
  byte bStack_35;
  uint16_t transition_time;
  ushort uStack_32;
  uint8_t scene_id;
  uint16_t group_id;
  uint16_t offset;
  
  ep_id = (packet->header).dst_ep;
  uStack_32 = 0;
  transition_time = 0;
  bStack_35 = 0;
  uStack_38 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x41b,
                  "scenes_cluster_enhanced_add_scene_req_handler","packet && rsp");
_L0:
    uVar5 = (undefined1)unaff_s6;
    entry = scene_table_find_entry(ep_id,unaff_s0,(ushort)bStack_35);
    if (entry == (zcl_scene_table_entry_t *)0x0) {
      entry = scene_table_get_unused_entry(ep_id);
    }
    else {
      scene_entry_free_scene_extension_field(entry);
    }
    if (entry == (zcl_scene_table_entry_t *)0x0) {
      unaff_s6 = 0x89;
    }
    else {
      entry->group_id = transition_time;
      entry->scene_id = bStack_35;
      entry->transition_time = uStack_38;
      entry->transition_time_100ms = '\x01';
      af_read_le8(packet->payload,&stack0xffffffce,(uint8_t *)entry->scene_name);
      if ((byte)entry->scene_name[0] < 0x11) {
        af_read_bytes(packet->payload,&stack0xffffffce,(ushort)(byte)entry->scene_name[0],
                      (uint8_t *)(entry->scene_name + 1));
        _Var3 = scene_name_is_supported(ep_id);
        if (CONCAT31(extraout_var_00,_Var3) == 0) {
          entry->scene_name[0] = '\0';
        }
        while (uStack_32 < unaff_s4) {
          peVar4 = (ezb_zcl_scenes_extension_field_t *)calloc(1,0xc);
          if (peVar4 == (ezb_zcl_scenes_extension_field_t *)0x0) {
            unaff_s6 = 0x89;
            goto _L0;
          }
          peVar4->next = entry->extension_field;
          entry->extension_field = peVar4;
          af_read_le16(packet->payload,&stack0xffffffce,&peVar4->cluster_id);
          af_read_le8(packet->payload,&stack0xffffffce,&peVar4->length);
          bVar1 = peVar4->length;
          if (bVar1 != 0) {
            value = (uint8_t *)calloc(1,(uint)bVar1);
            peVar4->value = value;
            if (value == (uint8_t *)0x0) {
              unaff_s6 = 0x89;
              goto _L0;
            }
            af_read_bytes(packet->payload,&stack0xffffffce,(ushort)bVar1,value);
          }
        }
        if (unaff_s4 < uStack_32) {
          unaff_s6 = 0x80;
        }
        else {
          _Var3 = scene_table_add_entry(ep_id,entry,true);
          if (CONCAT31(extraout_var_01,_Var3) != 0) goto _L0;
          unaff_s6 = 1;
        }
      }
      else {
        unaff_s6 = 0x80;
      }
    }
  }
  else {
    unaff_s4 = zmsg_get_length(packet->payload);
    af_read_le16(packet->payload,&stack0xffffffce,&transition_time);
    af_read_le8(packet->payload,&stack0xffffffce,&bStack_35);
    af_read_le16(packet->payload,&stack0xffffffce,&uStack_38);
    unaff_s0 = transition_time;
    eVar2 = scenes_check_group_id(transition_time);
    unaff_s6 = CONCAT31(extraout_var,eVar2);
    if (unaff_s6 == 0) goto _L0;
    entry = (zcl_scene_table_entry_t *)0x0;
  }
_L0:
  uVar5 = (undefined1)unaff_s6;
  scene_entry_set_unused(entry);
_L0:
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    uStack_3a = CONCAT11(uStack_3a._1_1_,uVar5);
    zmsg_append_bytes(rsp->payload,1,&uStack_3a);
    uStack_3a = transition_time;
    zmsg_append_bytes(rsp->payload,2,&uStack_3a);
    uStack_3a = CONCAT11(uStack_3a._1_1_,bStack_35);
    zmsg_append_bytes(rsp->payload,1,&uStack_3a);
    eVar2 = zcl_packet_setup_response(rsp,packet,0x40);
  }
  else {
    eVar2 = 0xfe;
  }
  return eVar2;
}

