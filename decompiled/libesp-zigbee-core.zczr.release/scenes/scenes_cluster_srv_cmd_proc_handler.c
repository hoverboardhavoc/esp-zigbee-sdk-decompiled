/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scenes_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  uint8_t val;
  int iVar2;
  _Bool _Var3;
  ezb_zcl_status_t eVar4;
  zmsg_t *payload;
  uint uVar5;
  zcl_scene_table_entry_t *pzVar6;
  undefined3 extraout_var;
  ezb_zcl_scenes_extension_field_t *peVar7;
  uint8_t *puVar8;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 uVar9;
  zcl_scene_table_t *pzVar10;
  zcl_attr_desc_t *pzVar11;
  zcl_attr_desc_t *pzVar12;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  uint8_t val_00;
  undefined4 uVar13;
  uint8_t uVar14;
  char cVar15;
  byte bStack_4f;
  undefined2 local_4e;
  uint16_t uStack_4c;
  uint8_t scene_id_5;
  uint8_t scene_id;
  uint16_t offset;
  uint16_t group_id;
  zcl_packet_t rsp;
  
  memset(&offset,0,0x28);
  if (arg == (void *)0x0) {
    iVar2 = 1;
    goto _L0;
  }
  iVar2 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar2 = zcl_packet_init(&offset,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar2 != 0)) goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 5) {
    _scene_id = 0xffff;
    local_4e = 0;
    uStack_4c = 0;
    bStack_4f = 0;
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&local_4e,&stack0xffffffb4);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&local_4e,&bStack_4f);
    uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    if (local_4e < uVar5) {
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&local_4e,(uint16_t *)&scene_id);
    }
    uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    eVar4 = 0x80;
    if (local_4e <= uVar5) {
      eVar4 = zcl_scenes_recall_scene((zcl_packet_t *)arg,uStack_4c,bStack_4f,_scene_id);
    }
    if (0xfff7 < *(ushort *)((int)arg + 0xc)) goto _L0;
_L0:
    iVar2 = zcl_packet_setup_default_response(&offset,arg,eVar4);
_L0:
    if (iVar2 == 0) {
      zcl_packet_send(&offset,0);
      goto _L0;
    }
  }
  else {
    if (bVar1 < 6) {
      uVar14 = *(uint8_t *)((int)arg + 0x15);
      payload = *(zmsg_t **)((int)arg + 0x24);
      if (bVar1 == 2) {
        uStack_4c = 0;
        _scene_id = 0;
        local_4e = (ushort)local_4e._1_1_ << 8;
        af_read_le16(payload,&stack0xffffffb4,(uint16_t *)&scene_id);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint8_t *)&local_4e);
        uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uVar5 < uStack_4c) {
          uVar14 = 0x80;
        }
        else if (_scene_id < 0xfff8) {
          pzVar6 = scene_table_find_entry(uVar14,_scene_id,local_4e & 0xff);
          if (pzVar6 == (zcl_scene_table_entry_t *)0x0) {
            uVar14 = 0x8b;
          }
          else {
            scene_table_remove_entry(uVar14,pzVar6);
            uVar14 = '\0';
          }
        }
        else {
          uVar14 = 0x87;
        }
        if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
          zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar14);
          zmsg_append_le16((zmsg_t *)rsp._32_4_,_scene_id);
          zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)local_4e);
          uVar13 = 2;
          goto _L0;
        }
        goto _L0;
      }
      if (2 < bVar1) {
        if (bVar1 == 3) {
          uStack_4c = 0;
          _scene_id = 0;
          af_read_le16(payload,&stack0xffffffb4,(uint16_t *)&scene_id);
          uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
          eVar4 = 0x80;
          if ((uStack_4c <= uVar5) && (eVar4 = 0x87, _scene_id < 0xfff8)) {
            eVar4 = scene_table_remove_all_associated_scene(uVar14,_scene_id);
          }
          zmsg_append_u8((zmsg_t *)rsp._32_4_,eVar4);
          zmsg_append_le16((zmsg_t *)rsp._32_4_,_scene_id);
          uVar13 = 3;
          if (*(ushort *)((int)arg + 0xc) < 0xfff8) goto _L0;
        }
        else {
          uStack_4c = 0;
          _scene_id = 0;
          local_4e = (ushort)local_4e._1_1_ << 8;
          af_read_le16(payload,&stack0xffffffb4,(uint16_t *)&scene_id);
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint8_t *)&local_4e);
          uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
          if (uVar5 < uStack_4c) {
            iVar2 = 0x80;
          }
          else if (_scene_id < 0xfff8) {
            pzVar10 = scene_table_get(uVar14);
            if (pzVar10 == (zcl_scene_table_t *)0x0) {
              iVar2 = 0x8b;
            }
            else {
              iVar2 = 0x89;
              if (*pzVar10->count < pzVar10->total) {
                pzVar11 = scenes_srv_get_attr_desc(uVar14,3);
                pzVar12 = pzVar11;
                if (pzVar11 == (zcl_attr_desc_t *)0x0) {
                  pzVar12 = (zcl_attr_desc_t *)__assert_func(0,0,0);
                }
                *(undefined1 *)pzVar12->data_p = 0;
                eVar4 = zcl_message_scenes_store_scene
                                  ((zcl_packet_t *)arg,_scene_id,(uint8_t)local_4e);
                iVar2 = CONCAT31(extraout_var_02,eVar4);
                pzVar6 = scene_table_find_entry(uVar14,_scene_id,local_4e & 0xff);
                if (pzVar6 == (zcl_scene_table_entry_t *)0x0) {
                  iVar2 = 1;
                }
                else if (iVar2 == 0) {
                  *(undefined1 *)pzVar11->data_p = 1;
                }
              }
            }
          }
          else {
            iVar2 = 0x87;
          }
          if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
            zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)iVar2);
            zmsg_append_le16((zmsg_t *)rsp._32_4_,_scene_id);
            zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)local_4e);
            uVar13 = 4;
            goto _L0;
          }
        }
        goto _L0;
      }
      if (bVar1 != 0) {
        uStack_4c = 0;
        _scene_id = 0;
        local_4e = (ushort)local_4e._1_1_ << 8;
        af_read_le16(payload,&stack0xffffffb4,(uint16_t *)&scene_id);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint8_t *)&local_4e);
        uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uVar5 < uStack_4c) {
          uVar14 = 0x80;
        }
        else if (_scene_id < 0xfff8) {
          pzVar6 = scene_table_find_entry(uVar14,_scene_id,local_4e & 0xff);
          if (pzVar6 == (zcl_scene_table_entry_t *)0x0) {
            uVar14 = 0x8b;
          }
          else {
            zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
            zmsg_append_le16((zmsg_t *)rsp._32_4_,pzVar6->group_id);
            zmsg_append_u8((zmsg_t *)rsp._32_4_,pzVar6->scene_id);
            zmsg_append_le16((zmsg_t *)rsp._32_4_,pzVar6->transition_time);
            _Var3 = scene_name_is_supported(uVar14);
            uVar13 = rsp._32_4_;
            if (CONCAT31(extraout_var_01,_Var3) == 0) {
              zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
            }
            else {
              uVar9 = ezb_zcl_get_attr_value_size(0x42,pzVar6->scene_name);
              zmsg_append_bytes(uVar13,uVar9,pzVar6->scene_name);
            }
            for (peVar7 = pzVar6->extension_field; uVar14 = '\0',
                peVar7 != (ezb_zcl_scenes_extension_field_t *)0x0; peVar7 = peVar7->next) {
              zmsg_append_le16((zmsg_t *)rsp._32_4_,peVar7->cluster_id);
              zmsg_append_u8((zmsg_t *)rsp._32_4_,peVar7->length);
              if (peVar7->length != '\0') {
                zmsg_append_bytes(rsp._32_4_,peVar7->value);
              }
            }
          }
        }
        else {
          uVar14 = 0x87;
        }
        if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
          if (uVar14 != '\0') {
            zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar14);
            zmsg_append_le16((zmsg_t *)rsp._32_4_,_scene_id);
            zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)local_4e);
          }
          uVar13 = 1;
          goto _L0;
        }
        goto _L0;
      }
      uStack_4c = 0;
      _scene_id = 0;
      local_4e = local_4e & 0xff00;
      uVar5 = zmsg_get_length();
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint16_t *)&scene_id);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint8_t *)&local_4e);
      if (_scene_id < 0xfff8) {
        pzVar6 = scene_table_find_entry(uVar14,_scene_id,local_4e & 0xff);
        if (pzVar6 == (zcl_scene_table_entry_t *)0x0) {
          pzVar6 = scene_table_get_unused_entry(uVar14);
          if (pzVar6 == (zcl_scene_table_entry_t *)0x0) {
_L0:
            uVar14 = 0x89;
            goto _L0;
          }
        }
        else {
          scene_entry_free_scene_extension_field(pzVar6);
        }
        pzVar6->group_id = _scene_id;
        pzVar6->scene_id = (uint8_t)local_4e;
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,&pzVar6->transition_time);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint8_t *)pzVar6->scene_name);
        if (0x10 < (byte)pzVar6->scene_name[0]) {
_L0:
          uVar14 = 0x80;
          goto _L0;
        }
        af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,
                      (ushort)(byte)pzVar6->scene_name[0],(uint8_t *)(pzVar6->scene_name + 1));
        _Var3 = scene_name_is_supported(uVar14);
        if (CONCAT31(extraout_var,_Var3) == 0) {
          pzVar6->scene_name[0] = '\0';
        }
        while (uStack_4c < uVar5) {
          peVar7 = (ezb_zcl_scenes_extension_field_t *)calloc(1,0xc);
          if (peVar7 == (ezb_zcl_scenes_extension_field_t *)0x0) goto _L0;
          peVar7->next = pzVar6->extension_field;
          pzVar6->extension_field = peVar7;
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,&peVar7->cluster_id);
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,&peVar7->length);
          bVar1 = peVar7->length;
          if (bVar1 != 0) {
            puVar8 = (uint8_t *)calloc(1,(uint)bVar1);
            peVar7->value = puVar8;
            if (puVar8 == (uint8_t *)0x0) goto _L0;
            af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(ushort)bVar1,puVar8);
          }
        }
        if (uVar5 < uStack_4c) goto _L0;
        _Var3 = scene_table_add_entry(uVar14,pzVar6,true);
        uVar14 = '\0';
        if (CONCAT31(extraout_var_00,_Var3) == 0) {
          uVar14 = '\x01';
          goto _L0;
        }
      }
      else {
        pzVar6 = (zcl_scene_table_entry_t *)0x0;
        uVar14 = 0x87;
_L0:
        scene_entry_set_unused(pzVar6);
      }
      if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
        zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar14);
        zmsg_append_le16((zmsg_t *)rsp._32_4_,_scene_id);
        zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)local_4e);
        uVar13 = 0;
_L0:
        iVar2 = zcl_packet_setup_response(&offset,arg,uVar13);
        goto _L0;
      }
    }
    else {
      if (bVar1 == 0x41) {
        uVar14 = *(uint8_t *)((int)arg + 0x15);
        uStack_4c = 0;
        _scene_id = 0;
        local_4e = (ushort)local_4e._1_1_ << 8;
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint16_t *)&scene_id);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint8_t *)&local_4e);
        uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uVar5 < uStack_4c) {
          uVar14 = 0x80;
        }
        else if (_scene_id < 0xfff8) {
          pzVar6 = scene_table_find_entry(uVar14,_scene_id,local_4e & 0xff);
          if (pzVar6 == (zcl_scene_table_entry_t *)0x0) {
            uVar14 = 0x8b;
          }
          else {
            zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
            zmsg_append_le16((zmsg_t *)rsp._32_4_,pzVar6->group_id);
            zmsg_append_u8((zmsg_t *)rsp._32_4_,pzVar6->scene_id);
            zmsg_append_le16((zmsg_t *)rsp._32_4_,pzVar6->transition_time);
            zmsg_append_u8((zmsg_t *)rsp._32_4_,pzVar6->transition_time_100ms != '\0');
            _Var3 = scene_name_is_supported(uVar14);
            uVar13 = rsp._32_4_;
            if (CONCAT31(extraout_var_05,_Var3) == 0) {
              zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
            }
            else {
              uVar9 = ezb_zcl_get_attr_value_size(0x42,pzVar6->scene_name);
              zmsg_append_bytes(uVar13,uVar9,pzVar6->scene_name);
            }
            for (peVar7 = pzVar6->extension_field; uVar14 = '\0',
                peVar7 != (ezb_zcl_scenes_extension_field_t *)0x0; peVar7 = peVar7->next) {
              zmsg_append_le16((zmsg_t *)rsp._32_4_,peVar7->cluster_id);
              zmsg_append_u8((zmsg_t *)rsp._32_4_,peVar7->length);
              if (peVar7->length != '\0') {
                zmsg_append_bytes(rsp._32_4_,peVar7->value);
              }
            }
          }
        }
        else {
          uVar14 = 0x87;
        }
        if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
          if (uVar14 != '\0') {
            zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar14);
            zmsg_append_le16((zmsg_t *)rsp._32_4_,_scene_id);
            zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)local_4e);
          }
          uVar13 = 0x41;
          goto _L0;
        }
        goto _L0;
      }
      if (0x41 < bVar1) {
        eVar4 = 0x81;
        if (bVar1 == 0x42) goto _L0;
_L405:
        iVar2 = 0x81;
        goto _L0;
      }
      if (bVar1 == 6) {
        uVar14 = *(uint8_t *)((int)arg + 0x15);
        uStack_4c = 0;
        _scene_id = 0;
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb4,(uint16_t *)&scene_id);
        uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        val_00 = 0x80;
        val = '\0';
        if (uStack_4c <= uVar5) {
          pzVar10 = scene_table_get(uVar14);
          val_00 = 0x8b;
          if (pzVar10 != (zcl_scene_table_t *)0x0) {
            val_00 = 0x87;
            val = pzVar10->total - *pzVar10->count;
            if (_scene_id < 0xfff8) {
              zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
              zmsg_append_u8((zmsg_t *)rsp._32_4_,val);
              zmsg_append_le16((zmsg_t *)rsp._32_4_,_scene_id);
              zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
              if (*pzVar10->count != '\0') {
                cVar15 = '\0';
                uVar13 = zmsg_get_length(rsp._32_4_);
                zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
                for (uVar5 = 0; uVar5 < pzVar10->total; uVar5 = uVar5 + 1 & 0xff) {
                  if (*(uint16_t *)&pzVar10[uVar5 * 4 + 1].field_0x2 == _scene_id) {
                    cVar15 = cVar15 + '\x01';
                    zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)&pzVar10[uVar5 * 4 + 1].count);
                  }
                }
                local_4e = CONCAT11(local_4e._1_1_,cVar15);
                zmsg_write_bytes(uVar13,1,&local_4e);
              }
              val_00 = '\0';
            }
          }
        }
        if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
          if (val_00 != '\0') {
            zmsg_append_u8((zmsg_t *)rsp._32_4_,val_00);
            zmsg_append_u8((zmsg_t *)rsp._32_4_,val);
            zmsg_append_le16((zmsg_t *)rsp._32_4_,_scene_id);
          }
          uVar13 = 6;
          goto _L0;
        }
        goto _L0;
      }
      if (bVar1 != 0x40) goto _L405;
      uVar14 = *(uint8_t *)((int)arg + 0x15);
      local_4e = 0;
      uStack_4c = 0;
      bStack_4f = 0;
      _scene_id = 0;
      uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&local_4e,&stack0xffffffb4);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&local_4e,&bStack_4f);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&local_4e,(uint16_t *)&scene_id);
      if (uStack_4c < 0xfff8) {
        pzVar6 = scene_table_find_entry(uVar14,uStack_4c,(ushort)bStack_4f);
        if (pzVar6 == (zcl_scene_table_entry_t *)0x0) {
          pzVar6 = scene_table_get_unused_entry(uVar14);
          if (pzVar6 == (zcl_scene_table_entry_t *)0x0) {
_L0:
            uVar14 = 0x89;
            goto _L0;
          }
        }
        else {
          scene_entry_free_scene_extension_field(pzVar6);
        }
        pzVar6->group_id = uStack_4c;
        pzVar6->scene_id = bStack_4f;
        pzVar6->transition_time = _scene_id;
        pzVar6->transition_time_100ms = '\x01';
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&local_4e,(uint8_t *)pzVar6->scene_name);
        if (0x10 < (byte)pzVar6->scene_name[0]) {
_L0:
          uVar14 = 0x80;
          goto _L0;
        }
        af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&local_4e,(ushort)(byte)pzVar6->scene_name[0],
                      (uint8_t *)(pzVar6->scene_name + 1));
        _Var3 = scene_name_is_supported(uVar14);
        if (CONCAT31(extraout_var_03,_Var3) == 0) {
          pzVar6->scene_name[0] = '\0';
        }
        while (local_4e < uVar5) {
          peVar7 = (ezb_zcl_scenes_extension_field_t *)calloc(1,0xc);
          if (peVar7 == (ezb_zcl_scenes_extension_field_t *)0x0) goto _L0;
          peVar7->next = pzVar6->extension_field;
          pzVar6->extension_field = peVar7;
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&local_4e,&peVar7->cluster_id);
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&local_4e,&peVar7->length);
          bVar1 = peVar7->length;
          if (bVar1 != 0) {
            puVar8 = (uint8_t *)calloc(1,(uint)bVar1);
            peVar7->value = puVar8;
            if (puVar8 == (uint8_t *)0x0) goto _L0;
            af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&local_4e,(ushort)bVar1,puVar8);
          }
        }
        if (uVar5 < local_4e) goto _L0;
        _Var3 = scene_table_add_entry(uVar14,pzVar6,true);
        uVar14 = '\0';
        if (CONCAT31(extraout_var_04,_Var3) == 0) {
          uVar14 = '\x01';
          goto _L0;
        }
      }
      else {
        pzVar6 = (zcl_scene_table_entry_t *)0x0;
        uVar14 = 0x87;
_L0:
        scene_entry_set_unused(pzVar6);
      }
      if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
        zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar14);
        zmsg_append_le16((zmsg_t *)rsp._32_4_,uStack_4c);
        zmsg_append_u8((zmsg_t *)rsp._32_4_,bStack_4f);
        uVar13 = 0x40;
        goto _L0;
      }
    }
_L0:
    iVar2 = 0xfe;
  }
  zcl_packet_free(&offset);
_L0:
  return (ezb_zcl_status_t)iVar2;
}

