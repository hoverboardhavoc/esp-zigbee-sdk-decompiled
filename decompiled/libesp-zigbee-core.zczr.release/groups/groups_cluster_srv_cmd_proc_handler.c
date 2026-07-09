/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> groups.o -> groups_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int groups_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  int iVar6;
  void *pvVar7;
  undefined4 uVar8;
  char cVar9;
  uint uVar10;
  undefined2 *puVar11;
  byte bStack_4d;
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
  iVar6 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar6 != 0) {
    return iVar6;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 3) {
    uStack_4a = 0xffff;
    uStack_4c = 0;
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&uStack_4a);
    uVar10 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar10 < uStack_4c) {
      bVar3 = true;
    }
    else {
      uVar8 = 0x87;
      if ((ushort)(uStack_4a - 1) < 0xfff7) {
        iVar6 = aps_group_table_find(0x87);
        uVar8 = 0x8b;
        if (iVar6 != 0) {
          aps_group_table_remove_group(uStack_4a,0x8b);
          uVar8 = 0;
        }
      }
      zmsg_append_u8(uStack_24,uVar8);
      zmsg_append_le16(uStack_24,uStack_4a);
      bVar3 = false;
    }
    if (0xfff7 < *(ushort *)(param_1 + 0xc)) {
_L0:
      iVar6 = 0xfe;
      goto _L0;
    }
    if (bVar3) {
_L0:
      uVar8 = 0x80;
      goto _L0;
    }
    uVar8 = 3;
_L0:
    iVar6 = zcl_packet_setup_response(auStack_48,param_1,uVar8);
  }
  else {
    if (bVar1 < 4) {
      if (bVar1 == 1) {
        uStack_4a = 0xffff;
        uStack_4c = 0;
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4c,&uStack_4a);
        uVar10 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar10 < uStack_4c) goto _L0;
        if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
          if ((ushort)(uStack_4a - 1) < 0xfff7) {
            iVar6 = aps_group_table_is_endpoint_in_group(*(undefined1 *)(param_1 + 0x15));
            uVar8 = 0;
            if (iVar6 == 0) {
              uVar8 = 0x8b;
            }
          }
          else {
            uVar8 = 0x87;
          }
          zmsg_append_u8(uStack_24,uVar8);
          zmsg_append_le16(uStack_24,uStack_4a);
          zmsg_append_u8(uStack_24,0);
          uVar8 = 1;
          goto _L0;
        }
      }
      else {
        if (bVar1 != 2) {
_L0:
          iVar6 = groups_cluster_add_group_cmd_handler(param_1,auStack_48);
          goto _L0;
        }
        uVar2 = *(undefined1 *)(param_1 + 0x15);
        uStack_4a = 0;
        bStack_4d = 0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4a,&bStack_4d);
        uVar10 = (uint)bStack_4d;
        pvVar7 = calloc(uVar10,2);
        if ((uVar10 == 0) || (uVar10 = 0, pvVar7 != (void *)0x0)) {
          for (; uVar10 < bStack_4d; uVar10 = uVar10 + 1 & 0xff) {
            af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_4a,
                                (void *)(uVar10 * 2 + (int)pvVar7));
          }
          uVar10 = zmsg_get_length();
          uVar4 = uStack_24;
          uVar8 = 0x80;
          if (uVar10 < uStack_4a) goto _L0;
          uVar5 = aps_group_table_get_free_size(0x80);
          zmsg_append_u8(uVar4,uVar5);
          uVar8 = zmsg_get_length(uStack_24);
          zmsg_append_u8(uStack_24,0);
          if (bStack_4d == 0) {
            puVar11 = (undefined2 *)0x0;
            cVar9 = '\0';
            while (puVar11 = (undefined2 *)aps_group_table_next_by_endpoint(uVar2,puVar11),
                  puVar11 != (undefined2 *)0x0) {
              cVar9 = cVar9 + '\x01';
              zmsg_append_le16(uStack_24,*puVar11);
            }
          }
          else {
            cVar9 = '\0';
            for (uVar10 = 0; uVar10 < bStack_4d; uVar10 = uVar10 + 1 & 0xff) {
              puVar11 = (undefined2 *)(uVar10 * 2 + (int)pvVar7);
              iVar6 = aps_group_table_find(*puVar11);
              if ((iVar6 != 0) &&
                 (iVar6 = aps_group_table_is_endpoint_in_group(uVar2,*puVar11), iVar6 != 0)) {
                cVar9 = cVar9 + '\x01';
                zmsg_append_le16(uStack_24,*puVar11);
              }
            }
            if ((cVar9 != '\0') && (0xfff7 < *(ushort *)(param_1 + 0xc))) goto _L0;
          }
          uStack_4c = CONCAT11(uStack_4c._1_1_,cVar9);
          zmsg_write_bytes(uStack_24,uVar8,1,&uStack_4c);
          uVar8 = 2;
          goto _L0;
        }
      }
_L0:
      uVar8 = 0xfe;
    }
    else if (bVar1 == 4) {
      iVar6 = zcl_get_cluster_desc(*(undefined1 *)(param_1 + 0x15),5,1);
      puVar11 = (undefined2 *)0x0;
      if (iVar6 != 0) {
        while (puVar11 = (undefined2 *)
                         aps_group_table_next_by_endpoint(*(undefined1 *)(param_1 + 0x15),puVar11),
              puVar11 != (undefined2 *)0x0) {
          zcl_scenes_remove_all_associated_scene(*(undefined1 *)(param_1 + 0x15),*puVar11);
        }
      }
      aps_group_table_clear();
      if (0xfff7 < *(ushort *)(param_1 + 0xc)) goto _L0;
      uVar8 = 0;
    }
    else {
      if (bVar1 == 5) goto _L0;
      uVar8 = 0x81;
    }
_L0:
    iVar6 = zcl_packet_setup_default_response(auStack_48,param_1,uVar8);
  }
_L0:
  if (iVar6 == 0) {
    zcl_packet_send(auStack_48,0);
    return 0;
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar6;
}

