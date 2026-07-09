/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ias_ace_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ias_ace_cluster_srv_cmd_proc_handler(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint extraout_a1;
  undefined4 uVar7;
  ushort *puVar8;
  undefined2 uVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint *__s;
  char cVar13;
  uint uStack_94;
  ushort uStack_84;
  ushort uStack_82;
  undefined4 uStack_80;
  uint uStack_7c;
  undefined1 auStack_78 [36];
  undefined4 uStack_54;
  uint local_50 [3];
  undefined4 local_44;
  void *pvStack_40;
  byte abStack_3c [2];
  char acStack_3a [2];
  undefined1 *puStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  byte *pbStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  memset(auStack_78,0,0x28);
  uStack_80 = 0;
  uStack_7c = 0;
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_78,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 5) {
    __s = local_50;
    memset(__s,0,0x20);
    piVar6 = (int *)ezb_zcl_ias_ace_get_zone_table(*(undefined1 *)(param_1 + 0x15));
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
      iVar3 = 0;
      uVar12 = __assert_func(0);
      uVar4 = extraout_a1;
      goto _L0;
    }
    uVar12 = (uint)*(byte *)(piVar6 + 1);
    param_2 = 0x1e;
    uVar4 = 0xffff;
    param_3 = 1;
    for (iVar3 = 0; iVar3 < (int)uVar12; iVar3 = iVar3 + 1) {
_L0:
      pbVar10 = (byte *)(*piVar6 + iVar3 * param_2);
      if (*(ushort *)(pbVar10 + 2) != uVar4) {
        bVar1 = *pbVar10;
        puVar8 = (ushort *)((int)__s + (uint)(bVar1 >> 4) * 2);
        *puVar8 = (ushort)(param_3 << (bVar1 & 0xf)) | *puVar8;
      }
    }
    do {
      uStack_82 = (ushort)*__s;
      iVar3 = zmsg_append_bytes(uStack_54,2,&uStack_82);
      if (iVar3 != 0) goto _L0;
      __s = (uint *)((int)__s + 2);
    } while (&uStack_30 != __s);
    uVar7 = 1;
_L0:
    uStack_94 = zcl_packet_setup_response(auStack_78,param_1,uVar7);
joined_r0x00010b02:
    if (uStack_94 == 0) goto _L0;
  }
  else if (bVar1 < 6) {
    if (bVar1 == 2) {
      local_50[0] = 0;
      local_50[1] = 0;
      local_50[2] = 0;
      local_44 = 0;
      uStack_94 = zcl_packet_to_message(local_50,param_1);
      if (uStack_94 == 0) {
        local_44 = CONCAT31(local_44._1_3_,0xfe);
        uVar7 = 0x1f;
        goto _L0;
      }
    }
    else {
      if (bVar1 < 3) {
        if (bVar1 == 0) {
          uStack_82 = 0;
          memset(local_50,0,0x1c);
          af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_82,&local_44);
          iVar3 = read_zcl_string(*(undefined4 *)(param_1 + 0x24),&uStack_82,(int)&local_44 + 1,9);
          if (iVar3 == 0) {
            af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_82,acStack_3a);
            uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
            if (uStack_82 <= uVar4) {
              if ((3 < (byte)local_44) || (acStack_3a[0] == -1)) goto _L0;
              uStack_94 = zcl_packet_to_message(local_50,param_1);
              if (uStack_94 == 0) {
                puStack_38 = (undefined1 *)CONCAT31(puStack_38._1_3_,0xfe);
                local_50[2] = param_1;
                zcl_core_action_schedule(0x1d,local_50,0);
                uStack_94 = (uint)puStack_38 & 0xff;
                if (uStack_94 == 0xfe) goto _L0;
                if (uStack_94 == 0) {
                  iVar3 = zmsg_append_u8(uStack_54,(uint)puStack_38 >> 8 & 0xff);
                  uStack_94 = 0x89;
                  if (iVar3 == 0) {
                    uVar7 = 0;
                    goto _L0;
                  }
                }
              }
              goto _L0;
            }
          }
          goto _L0;
        }
        uStack_82 = 0;
        memset(local_50,0,0x30);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_82,&local_44);
        uVar4 = local_44 & 0xff;
        uStack_94 = 0x87;
        if (uVar4 != 0) {
          pvStack_40 = calloc(1,uVar4);
          if (pvStack_40 == (void *)0x0) {
_L0:
            uStack_94 = 0x89;
          }
          else {
            uStack_94 = 0x80;
            af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_82,uVar4,pvStack_40);
            iVar3 = read_zcl_string(*(undefined4 *)(param_1 + 0x24),&uStack_82,abStack_3c,9);
            if ((iVar3 == 0) &&
               (uStack_94 = zcl_packet_to_message(local_50,param_1), uStack_94 == 0)) {
              uStack_30 = CONCAT31(uStack_30._1_3_,0xfe);
              local_50[2] = param_1;
              zcl_core_action_schedule(0x1e,local_50);
              uStack_94 = uStack_30 & 0xff;
              if (uStack_94 == 0xfe) {
_L0:
                uStack_94 = 1;
              }
              else if (uStack_94 == 0) {
                uStack_80 = uStack_28;
                uStack_7c = uStack_24;
                if (((pbStack_2c == (byte *)0x0) || ((local_44 & 0xff) != (uint)*pbStack_2c)) ||
                   (*(int *)(pbStack_2c + 4) == 0)) goto _L0;
                iVar3 = zmsg_append_u8(uStack_54);
                if ((iVar3 != 0) ||
                   (iVar3 = zmsg_append_bytes(uStack_54,*pbStack_2c,*(undefined4 *)(pbStack_2c + 4))
                   , iVar3 != 0)) goto _L0;
                uStack_94 = zcl_packet_setup_response(auStack_78,param_1,7);
              }
            }
          }
        }
        if (pvStack_40 != (void *)0x0) {
          mm_free();
        }
        goto joined_r0x00010b02;
      }
      if (bVar1 == 3) {
        local_50[0] = 0;
        local_50[1] = 0;
        local_50[2] = 0;
        local_44 = 0;
        uStack_94 = zcl_packet_to_message(local_50,param_1);
        if (uStack_94 == 0) {
          local_44 = CONCAT31(local_44._1_3_,0xfe);
          uVar7 = 0x20;
_L0:
          local_50[2] = param_1;
          zcl_core_action_schedule(uVar7,local_50,uStack_94);
          if ((local_44 & 0xff) != 0xfe) {
            uStack_94 = local_44 & 0xff;
          }
        }
      }
      else {
        local_50[0] = 0;
        local_50[1] = 0;
        local_50[2] = 0;
        local_44 = 0;
        uStack_94 = zcl_packet_to_message(local_50,param_1);
        if (uStack_94 == 0) {
          local_44 = CONCAT31(local_44._1_3_,0xfe);
          uVar7 = 0x21;
          goto _L0;
        }
      }
    }
  }
  else if (bVar1 == 8) {
    piVar6 = (int *)ezb_zcl_ias_ace_get_zone_table(*(undefined1 *)(param_1 + 0x15));
    if (piVar6 != (int *)0x0) {
      cVar13 = '\0';
      iVar3 = zmsg_append_u8(uStack_54,0);
      if (iVar3 != 0) goto _L0;
      for (; iVar3 < (int)(uint)*(byte *)(piVar6 + 1); iVar3 = iVar3 + 1) {
        puVar11 = (undefined1 *)(*piVar6 + iVar3 * 0x1e);
        if ((puVar11[0xc] & 1) != 0) {
          cVar13 = cVar13 + '\x01';
          iVar5 = zmsg_append_u8(uStack_54,*puVar11);
          if (iVar5 != 0) goto _L0;
        }
      }
      local_50[0] = CONCAT31(local_50[0]._1_3_,cVar13);
      zmsg_write_bytes(0,1,local_50);
      uVar7 = 6;
      goto _L0;
    }
_L0:
    uStack_94 = 0x8b;
  }
  else if (bVar1 < 9) {
    if (bVar1 == 6) {
      uStack_82 = 0;
      uStack_84 = uStack_84 & 0xff00;
      iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_82,&uStack_84);
      if (iVar3 == 1) {
        if ((char)uStack_84 == -1) {
_L0:
          uStack_94 = 0x87;
          goto _L0;
        }
        iVar3 = ezb_zcl_ias_ace_get_zone_table(*(undefined1 *)(param_1 + 0x15));
        if (iVar3 != 0) {
          uVar2 = (char)uStack_84;
          iVar3 = ias_ace_zone_table_get_zone();
          iVar5 = zmsg_append_u8(uStack_54,uVar2);
          if (iVar5 == 0) {
            if (iVar3 == 0) {
              uVar9 = 0xffff;
            }
            else {
              uVar9 = *(undefined2 *)(iVar3 + 2);
            }
            local_50[0] = CONCAT22(local_50[0]._2_2_,uVar9);
            iVar5 = zmsg_append_bytes(uStack_54,2,local_50);
            if (iVar5 == 0) {
              if (iVar3 == 0) {
                local_50[0] = 0xffffffff;
                local_50[1] = 0xffffffff;
              }
              else {
                local_50[0] = *(uint *)(iVar3 + 4);
                local_50[1] = *(undefined4 *)(iVar3 + 8);
              }
              iVar5 = zmsg_append_bytes(uStack_54,8,local_50);
              if (iVar5 == 0) {
                if ((iVar3 == 0) || (*(byte *)(iVar3 + 0xd) == 0)) {
                  iVar3 = zmsg_append_u8(uStack_54,0);
                }
                else {
                  iVar3 = zmsg_append_bytes(*(byte *)(iVar3 + 0xd) + 1,iVar3 + 0xd);
                }
                uVar7 = 2;
                goto joined_r0x00010f42;
              }
            }
          }
          goto _L0;
        }
      }
_L0:
      uStack_94 = 0x80;
    }
    else {
      local_50[0] = 0;
      local_50[1] = 0;
      local_50[2] = 0;
      local_44 = 0;
      pvStack_40 = (void *)0x0;
      uStack_94 = zcl_packet_to_message(local_50,param_1);
      if (uStack_94 == 0) {
        local_44 = CONCAT31(local_44._1_3_,0xfe);
        local_50[2] = param_1;
        zcl_core_action_schedule(0x22,local_50,0);
        uStack_94 = local_44 & 0xff;
        if (uStack_94 == 0xfe) goto _L0;
        if (uStack_94 == 0) {
          iVar3 = zmsg_append_u8(uStack_54,local_44 >> 8 & 0xff);
          if (((iVar3 == 0) &&
              (iVar3 = zmsg_append_u8(uStack_54,local_44 >> 0x10 & 0xff), iVar3 == 0)) &&
             (iVar3 = zmsg_append_u8(uStack_54,local_44 >> 0x18), iVar3 == 0)) {
            iVar3 = zmsg_append_u8(uStack_54,(uint)pvStack_40 & 0xff);
            uVar7 = 5;
joined_r0x00010f42:
            if (iVar3 == 0) goto _L0;
          }
          goto _L0;
        }
      }
    }
  }
  else if (bVar1 == 9) {
    uStack_84 = 0;
    memset(local_50,0,0x24);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_84,&local_44);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_84,(int)&local_44 + 1);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_84,(int)&local_44 + 2);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_84,&pvStack_40);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uStack_94 = 0x80;
    if (((uStack_84 <= uVar4) &&
        (uStack_94 = zcl_packet_to_message(local_50,param_1,0x80), uStack_94 == 0)) &&
       (uStack_94 = 0x87, (local_44 & 0xff) + (local_44 >> 8 & 0xff) < 0xff)) {
      abStack_3c[0] = 0xfe;
      local_50[2] = param_1;
      zcl_core_action_schedule(0x23,local_50,0x87);
      uStack_94 = (uint)abStack_3c[0];
      if (uStack_94 == 0xfe) goto _L0;
      if (uStack_94 == 0) {
        uStack_80 = uStack_34;
        uStack_7c = uStack_30;
        if (puStack_38 == (undefined1 *)0x0) {
_L0:
          uStack_94 = 1;
        }
        else {
          iVar3 = zmsg_append_u8(uStack_54,*puStack_38);
          if (iVar3 == 0) {
            uVar12 = local_44 >> 8 & 0xff;
            uVar4 = (uint)(byte)puStack_38[1];
            if (uVar12 < (byte)puStack_38[1]) {
              uVar4 = uVar12;
            }
            iVar3 = zmsg_append_u8(uStack_54,uVar4);
            if (iVar3 == 0) {
              iVar3 = 0;
              if ((uVar4 == 0) || (*(int *)(puStack_38 + 4) != 0)) {
                for (; iVar3 < (int)uVar4; iVar3 = iVar3 + 1) {
                  iVar5 = zmsg_append_u8(uStack_54,
                                         *(undefined1 *)(*(int *)(puStack_38 + 4) + iVar3 * 4));
                  if (iVar5 != 0) goto _L0;
                  uStack_82 = *(ushort *)(*(int *)(puStack_38 + 4) + iVar3 * 4 + 2);
                  iVar5 = zmsg_append_bytes(uStack_54,2,&uStack_82);
                  if (iVar5 != 0) goto _L0;
                }
                uVar7 = 8;
                goto _L0;
              }
              goto _L0;
            }
          }
_L0:
          uStack_94 = 0x89;
        }
      }
    }
  }
  else {
    uStack_94 = 0x81;
  }
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_78,param_1,uStack_94);
  if (iVar3 != 0) {
    zcl_packet_free(auStack_78);
    return iVar3;
  }
_L0:
  zcl_packet_send(auStack_78,&uStack_80);
  return 0;
}

