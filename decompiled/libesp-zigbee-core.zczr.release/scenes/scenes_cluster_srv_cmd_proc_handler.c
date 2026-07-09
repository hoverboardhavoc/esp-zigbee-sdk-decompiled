/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scenes_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int scenes_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  void *pvVar8;
  undefined4 uVar9;
  byte *pbVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  int *piVar14;
  char cVar15;
  undefined1 uStack_4f;
  undefined2 local_4e;
  ushort uStack_4c;
  ushort uStack_4a;
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar4 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar4 != 0) {
    return iVar4;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 5) {
    uStack_4a = 0xffff;
    local_4e = 0;
    uStack_4c = 0;
    uStack_4f = 0;
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,&uStack_4c);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,&uStack_4f);
    uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (local_4e < uVar5) {
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,&uStack_4a);
    }
    uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar13 = 0x80;
    if (local_4e <= uVar5) {
      uVar13 = zcl_scenes_recall_scene(param_1,uStack_4c,uStack_4f,uStack_4a);
    }
    if (0xfff7 < *(ushort *)(param_1 + 0xc)) goto _L0;
_L0:
    iVar4 = zcl_packet_setup_default_response(auStack_48,param_1,uVar13);
_L0:
    if (iVar4 == 0) {
      zcl_packet_send(auStack_48,0);
      return 0;
    }
  }
  else {
    if (bVar1 < 6) {
      uVar2 = *(undefined1 *)(param_1 + 0x15);
      if (bVar1 == 2) {
        uStack_4c = 0;
        uStack_4a = 0;
        local_4e = (ushort)local_4e._1_1_ << 8;
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&uStack_4a);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&local_4e);
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar5 < uStack_4c) {
          uVar13 = 0x80;
        }
        else if (uStack_4a < 0xfff8) {
          iVar4 = scene_table_find_entry(uVar2,(undefined1)local_4e);
          if (iVar4 == 0) {
            uVar13 = 0x8b;
          }
          else {
            scene_table_remove_entry(uVar2,iVar4);
            uVar13 = 0;
          }
        }
        else {
          uVar13 = 0x87;
        }
        if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
          zmsg_append_u8(uStack_24,uVar13);
          zmsg_append_le16(uStack_24,uStack_4a);
          zmsg_append_u8(uStack_24,(undefined1)local_4e);
          uVar13 = 2;
          goto _L0;
        }
        goto _L0;
      }
      if (2 < bVar1) {
        if (bVar1 == 3) {
          uStack_4c = 0;
          uStack_4a = 0;
          af_read_le16_isra_0(&uStack_4c,&uStack_4a);
          uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          uVar13 = 0x80;
          if ((uStack_4c <= uVar5) && (uVar13 = 0x87, uStack_4a < 0xfff8)) {
            uVar13 = scene_table_remove_all_associated_scene(uVar2,uStack_4a);
          }
          zmsg_append_u8(uStack_24,uVar13);
          zmsg_append_le16(uStack_24,uStack_4a);
          uVar13 = 3;
          if (*(ushort *)(param_1 + 0xc) < 0xfff8) goto _L0;
        }
        else {
          uStack_4c = 0;
          uStack_4a = 0;
          local_4e = (ushort)local_4e._1_1_ << 8;
          af_read_le16_isra_0(&uStack_4c,&uStack_4a);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&local_4e);
          uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          if (uVar5 < uStack_4c) {
            iVar4 = 0x80;
          }
          else if (uStack_4a < 0xfff8) {
            pbVar10 = (byte *)scene_table_get(uVar2);
            if (pbVar10 == (byte *)0x0) {
              iVar4 = 0x8b;
            }
            else {
              iVar4 = 0x89;
              if (**(byte **)(pbVar10 + 4) < *pbVar10) {
                iVar6 = scenes_srv_get_attr_desc(uVar2,3);
                iVar4 = iVar6;
                if (iVar6 == 0) {
                  iVar4 = __assert_func(0,0,0);
                }
                **(undefined1 **)(iVar4 + 8) = 0;
                iVar4 = zcl_message_scenes_store_scene(param_1,uStack_4a,(undefined1)local_4e);
                iVar11 = scene_table_find_entry(uVar2,uStack_4a,(undefined1)local_4e);
                if (iVar11 == 0) {
                  iVar4 = 1;
                }
                else if (iVar4 == 0) {
                  **(undefined1 **)(iVar6 + 8) = 1;
                }
              }
            }
          }
          else {
            iVar4 = 0x87;
          }
          if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
            zmsg_append_u8(uStack_24,iVar4);
            zmsg_append_le16(uStack_24,uStack_4a);
            zmsg_append_u8(uStack_24,(undefined1)local_4e);
            uVar13 = 4;
            goto _L0;
          }
        }
        goto _L0;
      }
      if (bVar1 != 0) {
        uStack_4c = 0;
        uStack_4a = 0;
        local_4e = (ushort)local_4e._1_1_ << 8;
        af_read_le16_isra_0(&uStack_4c,&uStack_4a);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&local_4e);
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar5 < uStack_4c) {
          iVar4 = 0x80;
        }
        else if (uStack_4a < 0xfff8) {
          iVar4 = scene_table_find_entry(uVar2,(undefined1)local_4e);
          if (iVar4 == 0) {
            iVar4 = 0x8b;
          }
          else {
            zmsg_append_u8(uStack_24,0);
            zmsg_append_le16(uStack_24,*(undefined2 *)(iVar4 + 2));
            zmsg_append_u8(uStack_24,*(undefined1 *)(iVar4 + 4));
            zmsg_append_le16(uStack_24,*(undefined2 *)(iVar4 + 6));
            iVar6 = scene_name_is_supported(uVar2);
            uVar13 = uStack_24;
            if (iVar6 == 0) {
              zmsg_append_u8(uStack_24,0);
            }
            else {
              uVar9 = ezb_zcl_get_attr_value_size(0x42,iVar4 + 8);
              zmsg_append_bytes(uVar13,uVar9,iVar4 + 8);
            }
            for (piVar14 = *(int **)(iVar4 + 0x1c); iVar4 = 0, piVar14 != (int *)0x0;
                piVar14 = (int *)*piVar14) {
              zmsg_append_le16(uStack_24,*(undefined2 *)(piVar14 + 1));
              zmsg_append_u8(uStack_24,*(undefined1 *)((int)piVar14 + 6));
              if (*(char *)((int)piVar14 + 6) != '\0') {
                zmsg_append_bytes(uStack_24,piVar14[2]);
              }
            }
          }
        }
        else {
          iVar4 = 0x87;
        }
        if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
          if (iVar4 != 0) {
            zmsg_append_u8(uStack_24,iVar4);
            zmsg_append_le16(uStack_24,uStack_4a);
            zmsg_append_u8(uStack_24,(undefined1)local_4e);
          }
          uVar13 = 1;
          goto _L0;
        }
        goto _L0;
      }
      uStack_4c = 0;
      uStack_4a = 0;
      local_4e = local_4e & 0xff00;
      uVar5 = zmsg_get_length();
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&uStack_4a);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&local_4e);
      if (uStack_4a < 0xfff8) {
        iVar4 = scene_table_find_entry(uVar2,(undefined1)local_4e);
        if (iVar4 == 0) {
          iVar4 = scene_table_get_unused_entry(uVar2);
          if (iVar4 == 0) {
_L0:
            uVar13 = 0x89;
            goto _L0;
          }
        }
        else {
          scene_entry_free_scene_extension_field();
        }
        *(ushort *)(iVar4 + 2) = uStack_4a;
        *(undefined1 *)(iVar4 + 4) = (undefined1)local_4e;
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,iVar4 + 6);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,iVar4 + 8);
        if (0x10 < *(byte *)(iVar4 + 8)) {
_L0:
          uVar13 = 0x80;
          goto _L0;
        }
        af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,iVar4 + 9);
        iVar6 = scene_name_is_supported(uVar2);
        if (iVar6 == 0) {
          *(undefined1 *)(iVar4 + 8) = 0;
        }
        while (uStack_4c < uVar5) {
          puVar7 = (undefined4 *)calloc(1,0xc);
          if (puVar7 == (undefined4 *)0x0) goto _L0;
          *puVar7 = *(undefined4 *)(iVar4 + 0x1c);
          *(undefined4 **)(iVar4 + 0x1c) = puVar7;
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,puVar7 + 1);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,(int)puVar7 + 6);
          uVar12 = (uint)*(byte *)((int)puVar7 + 6);
          if (uVar12 != 0) {
            pvVar8 = calloc(1,uVar12);
            puVar7[2] = pvVar8;
            if (pvVar8 == (void *)0x0) goto _L0;
            af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,uVar12,pvVar8);
          }
        }
        if (uVar5 < uStack_4c) goto _L0;
        iVar6 = scene_table_add_entry(uVar2,iVar4,1);
        uVar13 = 0;
        if (iVar6 == 0) {
          uVar13 = 1;
          goto _L0;
        }
      }
      else {
        iVar4 = 0;
        uVar13 = 0x87;
_L0:
        scene_entry_set_unused(iVar4);
      }
      if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
        zmsg_append_u8(uStack_24,uVar13);
        zmsg_append_le16(uStack_24,uStack_4a);
        zmsg_append_u8(uStack_24,(undefined1)local_4e);
        uVar13 = 0;
_L0:
        iVar4 = zcl_packet_setup_response(auStack_48,param_1,uVar13);
        goto _L0;
      }
    }
    else {
      if (bVar1 == 0x41) {
        uVar2 = *(undefined1 *)(param_1 + 0x15);
        uStack_4c = 0;
        uStack_4a = 0;
        local_4e = (ushort)local_4e._1_1_ << 8;
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&uStack_4a);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&local_4e);
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar5 < uStack_4c) {
          iVar4 = 0x80;
        }
        else if (uStack_4a < 0xfff8) {
          iVar4 = scene_table_find_entry(uVar2,(undefined1)local_4e);
          if (iVar4 == 0) {
            iVar4 = 0x8b;
          }
          else {
            zmsg_append_u8(uStack_24,0);
            zmsg_append_le16(uStack_24,*(undefined2 *)(iVar4 + 2));
            zmsg_append_u8(uStack_24,*(undefined1 *)(iVar4 + 4));
            zmsg_append_le16(uStack_24,*(undefined2 *)(iVar4 + 6));
            zmsg_append_u8(uStack_24,*(char *)(iVar4 + 0x19) != '\0');
            iVar6 = scene_name_is_supported(uVar2);
            uVar13 = uStack_24;
            if (iVar6 == 0) {
              zmsg_append_u8(uStack_24,0);
            }
            else {
              uVar9 = ezb_zcl_get_attr_value_size(0x42,iVar4 + 8);
              zmsg_append_bytes(uVar13,uVar9,iVar4 + 8);
            }
            for (piVar14 = *(int **)(iVar4 + 0x1c); iVar4 = 0, piVar14 != (int *)0x0;
                piVar14 = (int *)*piVar14) {
              zmsg_append_le16(uStack_24,*(undefined2 *)(piVar14 + 1));
              zmsg_append_u8(uStack_24,*(undefined1 *)((int)piVar14 + 6));
              if (*(char *)((int)piVar14 + 6) != '\0') {
                zmsg_append_bytes(uStack_24,piVar14[2]);
              }
            }
          }
        }
        else {
          iVar4 = 0x87;
        }
        if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
          if (iVar4 != 0) {
            zmsg_append_u8(uStack_24,iVar4);
            zmsg_append_le16(uStack_24,uStack_4a);
            zmsg_append_u8(uStack_24,(undefined1)local_4e);
          }
          uVar13 = 0x41;
          goto _L0;
        }
        goto _L0;
      }
      if (0x41 < bVar1) {
        uVar13 = 0x81;
        if (bVar1 != 0x42) {
          return 0x81;
        }
        goto _L0;
      }
      if (bVar1 == 6) {
        uVar2 = *(undefined1 *)(param_1 + 0x15);
        uStack_4c = 0;
        uStack_4a = 0;
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&uStack_4a);
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        iVar4 = 0x80;
        cVar3 = '\0';
        if (uStack_4c <= uVar5) {
          pbVar10 = (byte *)scene_table_get(uVar2);
          iVar4 = 0x8b;
          if (pbVar10 != (byte *)0x0) {
            iVar4 = 0x87;
            cVar3 = *pbVar10 - **(char **)(pbVar10 + 4);
            if (uStack_4a < 0xfff8) {
              zmsg_append_u8(uStack_24,0);
              zmsg_append_u8(uStack_24,cVar3);
              zmsg_append_le16(uStack_24,uStack_4a);
              zmsg_append_u8(uStack_24,0);
              if (**(char **)(pbVar10 + 4) != '\0') {
                cVar15 = '\0';
                uVar13 = zmsg_get_length(uStack_24);
                zmsg_append_u8(uStack_24,0);
                for (uVar5 = 0; uVar5 < *pbVar10; uVar5 = uVar5 + 1 & 0xff) {
                  if (*(ushort *)(pbVar10 + uVar5 * 0x20 + 10) == uStack_4a) {
                    cVar15 = cVar15 + '\x01';
                    zmsg_append_u8(uStack_24,pbVar10[uVar5 * 0x20 + 0xc]);
                  }
                }
                local_4e = CONCAT11(local_4e._1_1_,cVar15);
                zmsg_write_bytes(uVar13,1,&local_4e);
              }
              iVar4 = 0;
            }
          }
        }
        if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
          if (iVar4 != 0) {
            zmsg_append_u8(uStack_24);
            zmsg_append_u8(uStack_24,cVar3);
            zmsg_append_le16(uStack_24,uStack_4a);
          }
          uVar13 = 6;
          goto _L0;
        }
        goto _L0;
      }
      if (bVar1 != 0x40) {
        return 0x81;
      }
      uVar2 = *(undefined1 *)(param_1 + 0x15);
      local_4e = 0;
      uStack_4c = 0;
      uStack_4f = 0;
      uStack_4a = 0;
      uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,&uStack_4c);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,&uStack_4f);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,&uStack_4a);
      if (uStack_4c < 0xfff8) {
        iVar4 = scene_table_find_entry(uVar2,uStack_4f);
        if (iVar4 == 0) {
          iVar4 = scene_table_get_unused_entry(uVar2);
          if (iVar4 == 0) {
_L0:
            uVar13 = 0x89;
            goto _L0;
          }
        }
        else {
          scene_entry_free_scene_extension_field();
        }
        *(ushort *)(iVar4 + 2) = uStack_4c;
        *(undefined1 *)(iVar4 + 4) = uStack_4f;
        *(ushort *)(iVar4 + 6) = uStack_4a;
        *(undefined1 *)(iVar4 + 0x19) = 1;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,iVar4 + 8);
        if (0x10 < *(byte *)(iVar4 + 8)) {
_L0:
          uVar13 = 0x80;
          goto _L0;
        }
        af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,iVar4 + 9);
        iVar6 = scene_name_is_supported(uVar2);
        if (iVar6 == 0) {
          *(undefined1 *)(iVar4 + 8) = 0;
        }
        while (local_4e < uVar5) {
          puVar7 = (undefined4 *)calloc(1,0xc);
          if (puVar7 == (undefined4 *)0x0) goto _L0;
          *puVar7 = *(undefined4 *)(iVar4 + 0x1c);
          *(undefined4 **)(iVar4 + 0x1c) = puVar7;
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,puVar7 + 1);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,(int)puVar7 + 6);
          uVar12 = (uint)*(byte *)((int)puVar7 + 6);
          if (uVar12 != 0) {
            pvVar8 = calloc(1,uVar12);
            puVar7[2] = pvVar8;
            if (pvVar8 == (void *)0x0) goto _L0;
            af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),&local_4e,uVar12,pvVar8);
          }
        }
        if (uVar5 < local_4e) goto _L0;
        iVar6 = scene_table_add_entry(uVar2,iVar4,1);
        uVar13 = 0;
        if (iVar6 == 0) {
          uVar13 = 1;
          goto _L0;
        }
      }
      else {
        iVar4 = 0;
        uVar13 = 0x87;
_L0:
        scene_entry_set_unused(iVar4);
      }
      if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
        zmsg_append_u8(uStack_24,uVar13);
        zmsg_append_le16(uStack_24,uStack_4c);
        zmsg_append_u8(uStack_24,uStack_4f);
        uVar13 = 0x40;
        goto _L0;
      }
    }
_L0:
    iVar4 = 0xfe;
  }
  zcl_packet_free(auStack_48);
  return iVar4;
}

