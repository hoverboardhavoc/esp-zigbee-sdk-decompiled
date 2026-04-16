/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> groups.o -> groups_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t groups_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  undefined1 uVar2;
  bool bVar3;
  undefined4 msg;
  int iVar4;
  undefined2 *puVar5;
  ezb_zcl_status_t eVar6;
  uint8_t uVar7;
  void *pvVar8;
  undefined3 extraout_var;
  undefined4 uVar9;
  char cVar10;
  uint uVar11;
  uint16_t *puVar12;
  byte bStack_4d;
  uint16_t uStack_4c;
  uint16_t uStack_4a;
  uint8_t group_count;
  uint16_t offset_1;
  uint16_t offset;
  zcl_packet_t rsp;
  
  iVar4 = 1;
  memset(&offset_1,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar4 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar4 = zcl_packet_init(&offset_1,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar4 != 0)) goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 3) {
    uStack_4a = 0xffff;
    uStack_4c = 0;
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_4c,&stack0xffffffb6);
    uVar11 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    if (uVar11 < uStack_4c) {
      bVar3 = true;
    }
    else {
      uVar7 = 0x87;
      if ((ushort)(uStack_4a - 1) < 0xfff7) {
        iVar4 = aps_group_table_find(0x87);
        uVar7 = 0x8b;
        if (iVar4 != 0) {
          aps_group_table_remove_group(uStack_4a,0x8b);
          uVar7 = '\0';
        }
      }
      zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar7);
      zmsg_append_le16((zmsg_t *)rsp._32_4_,uStack_4a);
      bVar3 = false;
    }
    if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
      if (bVar3) {
_L0:
        uVar9 = 0x80;
        goto _L0;
      }
      uVar9 = 3;
_L0:
      iVar4 = zcl_packet_setup_response(&offset_1,arg,uVar9);
      goto _L0;
    }
_L0:
    iVar4 = 0xfe;
  }
  else {
    if (bVar1 < 4) {
      if (bVar1 == 1) {
        uStack_4a = 0xffff;
        uStack_4c = 0;
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_4c,&stack0xffffffb6);
        uVar11 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uVar11 < uStack_4c) goto _L0;
        if (*(ushort *)((int)arg + 0xc) < 0xfff8) {
          if ((ushort)(uStack_4a - 1) < 0xfff7) {
            iVar4 = aps_group_table_is_endpoint_in_group(*(undefined1 *)((int)arg + 0x15));
            uVar7 = '\0';
            if (iVar4 == 0) {
              uVar7 = 0x8b;
            }
          }
          else {
            uVar7 = 0x87;
          }
          zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar7);
          zmsg_append_le16((zmsg_t *)rsp._32_4_,uStack_4a);
          zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
          uVar9 = 1;
          goto _L0;
        }
      }
      else {
        if (bVar1 != 2) {
_L0:
          eVar6 = groups_cluster_add_group_cmd_handler
                            ((zcl_packet_t *)arg,(zcl_packet_t *)&offset_1);
          iVar4 = CONCAT31(extraout_var,eVar6);
          goto _L0;
        }
        uVar2 = *(undefined1 *)((int)arg + 0x15);
        uStack_4a = 0;
        bStack_4d = 0;
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb6,&bStack_4d);
        uVar11 = (uint)bStack_4d;
        pvVar8 = calloc(uVar11,2);
        if ((uVar11 == 0) || (uVar11 = 0, pvVar8 != (void *)0x0)) {
          for (; uVar11 < bStack_4d; uVar11 = uVar11 + 1 & 0xff) {
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffffb6,
                         (uint16_t *)(uVar11 * 2 + (int)pvVar8));
          }
          uVar11 = zmsg_get_length();
          msg = rsp._32_4_;
          uVar9 = 0x80;
          if (uVar11 < uStack_4a) goto _L0;
          uVar7 = aps_group_table_get_free_size(0x80);
          zmsg_append_u8((zmsg_t *)msg,uVar7);
          uVar9 = zmsg_get_length(rsp._32_4_);
          zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
          if (bStack_4d == 0) {
            puVar12 = (uint16_t *)0x0;
            cVar10 = '\0';
            while (puVar12 = (uint16_t *)aps_group_table_next_by_endpoint(uVar2,puVar12),
                  puVar12 != (uint16_t *)0x0) {
              cVar10 = cVar10 + '\x01';
              zmsg_append_le16((zmsg_t *)rsp._32_4_,*puVar12);
            }
          }
          else {
            cVar10 = '\0';
            for (uVar11 = 0; uVar11 < bStack_4d; uVar11 = uVar11 + 1 & 0xff) {
              puVar12 = (uint16_t *)(uVar11 * 2 + (int)pvVar8);
              iVar4 = aps_group_table_find(*puVar12);
              if ((iVar4 != 0) &&
                 (iVar4 = aps_group_table_is_endpoint_in_group(uVar2,*puVar12), iVar4 != 0)) {
                cVar10 = cVar10 + '\x01';
                zmsg_append_le16((zmsg_t *)rsp._32_4_,*puVar12);
              }
            }
            if ((cVar10 != '\0') && (0xfff7 < *(ushort *)((int)arg + 0xc))) goto _L0;
          }
          uStack_4c = CONCAT11(uStack_4c._1_1_,cVar10);
          zmsg_write_bytes(rsp._32_4_,uVar9,1,&uStack_4c);
          uVar9 = 2;
          goto _L0;
        }
      }
_L0:
      uVar9 = 0xfe;
    }
    else if (bVar1 == 4) {
      iVar4 = zcl_get_cluster_desc(*(undefined1 *)((int)arg + 0x15),5,1);
      puVar5 = (undefined2 *)0x0;
      if (iVar4 != 0) {
        while (puVar5 = (undefined2 *)
                        aps_group_table_next_by_endpoint(*(undefined1 *)((int)arg + 0x15),puVar5),
              puVar5 != (undefined2 *)0x0) {
          zcl_scenes_remove_all_associated_scene(*(undefined1 *)((int)arg + 0x15),*puVar5);
        }
      }
      aps_group_table_clear();
      if (0xfff7 < *(ushort *)((int)arg + 0xc)) goto _L0;
      uVar9 = 0;
    }
    else {
      if (bVar1 == 5) goto _L0;
      uVar9 = 0x81;
    }
_L0:
    iVar4 = zcl_packet_setup_default_response(&offset_1,arg,uVar9);
_L0:
    if (iVar4 == 0) {
      zcl_packet_send(&offset_1,0);
      goto _L0;
    }
  }
  zcl_packet_free(&offset_1);
_L0:
  return (ezb_zcl_status_t)iVar4;
}

