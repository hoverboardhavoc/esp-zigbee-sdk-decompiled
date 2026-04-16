/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scenes_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_cli_cmd_proc_handler(void *arg)

{
  uint8_t uVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  byte bVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined4 *puVar6;
  uint8_t *value;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar7;
  uint8_t uStack_77;
  uint16_t uStack_76;
  ushort uStack_74;
  uint8_t status;
  uint16_t offset;
  ezb_zcl_scenes_view_scene_rsp_message_t message;
  zcl_scene_table_entry_t entry;
  zcl_packet_t rsp;
  
  iVar2 = 1;
  memset(&entry.extension_field,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar2 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar2 = zcl_packet_init(&entry.extension_field,*(byte *)((int)arg + 0x1a) >> 2 & 1),
     iVar2 != 0)) goto _L0;
  bVar4 = *(byte *)((int)arg + 0x20);
  if (bVar4 == 4) {
    eVar3 = scenes_cluster_add_scene_rsp_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)&entry.extension_field);
    iVar2 = CONCAT31(extraout_var_01,eVar3);
  }
  else if (bVar4 < 5) {
    if (bVar4 == 2) {
      eVar3 = scenes_cluster_add_scene_rsp_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)&entry.extension_field);
      iVar2 = CONCAT31(extraout_var_00,eVar3);
    }
    else {
      if (bVar4 != 3) {
        if (bVar4 != 0) goto _L0;
        goto _L0;
      }
      uStack_74 = 0;
      uStack_76 = uStack_76 & 0xff00;
      message.out.result = '\0';
      message._25_1_ = 0;
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,(uint8_t *)&uStack_76);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,(uint16_t *)&message.out);
      uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uVar5 = 0x80;
      if (uStack_74 <= uVar7) {
        bVar4 = zcl_message_scenes_op_scene_resp
                          ((zcl_packet_t *)arg,(uint8_t)uStack_76,message._24_2_,'\0');
        uVar5 = (uint)bVar4;
      }
_L0:
      iVar2 = zcl_packet_setup_default_response(&entry.extension_field,arg,uVar5);
    }
  }
  else {
    if (bVar4 != 0x40) {
      if (bVar4 != 0x41) {
        if (bVar4 != 6) {
          uVar5 = 0x81;
          goto _L0;
        }
        uStack_74 = 0;
        memset(&message.out,0,0x1c);
        uVar5 = zcl_packet_to_message(&message.out,arg);
        if (uVar5 == 0) {
          uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
          entry._4_4_ = arg;
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,(uint8_t *)entry.scene_name);
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,
                      (uint8_t *)(entry.scene_name + 1));
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,
                       (uint16_t *)(entry.scene_name + 2));
          if ((entry.scene_name[0] == '\0') && (uStack_74 < uVar7)) {
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,
                        (uint8_t *)(entry.scene_name + 4));
            if ((byte)entry.scene_name[4] != 0) {
              entry.scene_name._8_4_ = calloc((uint)(byte)entry.scene_name[4],1);
              if ((uint8_t *)entry.scene_name._8_4_ == (uint8_t *)0x0) {
                uVar5 = 0x89;
                goto _L0;
              }
              af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff8c,
                            (ushort)(byte)entry.scene_name[4],(uint8_t *)entry.scene_name._8_4_);
            }
          }
          if (uVar7 < uStack_74) {
            uVar5 = 0x80;
          }
          else {
            entry.scene_name[0xc] = -2;
            zcl_core_action_schedule(0x13,&message.out);
            if ((byte)entry.scene_name[0xc] != 0xfe) {
              uVar5 = (uint)(byte)entry.scene_name[0xc];
            }
          }
        }
_L0:
        if (entry.scene_name._8_4_ != 0) {
          mm_free();
        }
        goto _L0;
      }
_L0:
      uStack_76 = 0;
      uStack_77 = '\0';
      memset(&message.out,0,0x20);
      uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_76,&uStack_77);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint16_t *)&message.field_0x1a);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_76,&entry.is_used);
      if (uStack_77 == '\0') {
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_76,&entry.group_id);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_76,&entry.scene_id);
        uVar7 = entry._4_4_ & 0xff;
        if (0x11 < uVar7) goto _L0;
        value = &entry.field_0x5;
        do {
          af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint16_t)uVar7,value);
          do {
            if (uVar5 <= uStack_76) goto _L0;
            puVar6 = (undefined4 *)calloc(1,0xc);
            if (puVar6 == (undefined4 *)0x0) goto _L0;
            *puVar6 = entry._24_4_;
            entry._24_4_ = puVar6;
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint16_t *)(puVar6 + 1));
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_76,(uint8_t *)((int)puVar6 + 6));
            uVar7 = (uint)*(byte *)((int)puVar6 + 6);
          } while (uVar7 == 0);
          value = (uint8_t *)calloc(1,uVar7);
          puVar6[2] = value;
        } while (value != (uint8_t *)0x0);
_L0:
        uVar5 = 0x89;
      }
      else {
_L0:
        uVar1 = uStack_77;
        if (uVar5 < uStack_76) {
_L0:
          uVar5 = 0x80;
        }
        else {
          memset(&stack0xffffff8c,0,0x1c);
          uVar5 = zcl_packet_to_message(&stack0xffffff8c,arg);
          if (uVar5 == 0) {
            message.in.header._2_2_ = message._26_2_;
            message.in.header._0_1_ = uVar1;
            message.in.status = entry.is_used;
            message.in.group_id = entry.group_id;
            message.in.scene_id = entry.scene_name[0x10];
            message.in._9_1_ = entry.transition_time_100ms;
            message.in.transition_time = entry._26_2_;
            message.in.field_set._0_1_ = 0xfe;
            message._4_4_ = arg;
            zcl_core_action_schedule(0x12,&stack0xffffff8c);
            if ((byte)message.in.field_set != 0xfe) {
              uVar5 = (uint)(byte)message.in.field_set;
            }
          }
        }
      }
      if (entry._24_4_ != 0) {
        scene_entry_free_scene_extension_field((zcl_scene_table_entry_t *)&message.out);
      }
      goto _L0;
    }
_L0:
    eVar3 = scenes_cluster_add_scene_rsp_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)&entry.extension_field);
    iVar2 = CONCAT31(extraout_var,eVar3);
  }
  if (iVar2 == 0) {
    zcl_packet_send(&entry.extension_field,0);
  }
  else {
    zcl_packet_free(&entry.extension_field);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

