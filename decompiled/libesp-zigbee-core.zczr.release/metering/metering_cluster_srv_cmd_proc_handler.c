/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> metering_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int metering_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort local_80;
  ushort uStack_7e;
  undefined4 *puStack_7c;
  undefined4 *puStack_78;
  undefined1 auStack_74 [36];
  undefined4 uStack_50;
  char acStack_4c [8];
  int iStack_44;
  undefined1 auStack_40 [4];
  byte abStack_3c [4];
  byte abStack_38 [2];
  ushort uStack_36;
  uint uStack_34;
  ushort *puStack_30;
  undefined4 *puStack_2c;
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  
  memset(auStack_74,0,0x28);
  puStack_7c = (undefined4 *)0x0;
  puStack_78 = (undefined4 *)0x0;
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar2 = zcl_packet_init(auStack_74,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar2 != 0) {
    return iVar2;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 6) {
    memset(acStack_4c,0,0x2c);
    uStack_7e = 0;
    iVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_7e,auStack_40);
    if ((((iVar2 == 0) ||
         (iVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_7e,abStack_3c), iVar2 == 0))
        || (iVar2 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_7e,abStack_38), iVar2 == 0))
       || ((iVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_7e,&uStack_34), iVar2 == 0
           || (uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)), uVar4 < uStack_7e)))) {
      uVar4 = 0x80;
    }
    else {
      uVar4 = zcl_packet_to_message(acStack_4c,param_1);
      if (uVar4 == 0) {
        puStack_30 = (ushort *)CONCAT31(puStack_30._1_3_,0xfe);
        iStack_44 = param_1;
        zcl_core_action_schedule(0x47,acStack_4c);
        uVar4 = (uint)puStack_30 & 0xff;
        if (uVar4 == 0xfe) {
          uVar4 = 0;
        }
        if (acStack_4c[0] == -2) {
          uVar4 = 0x8b;
        }
        else if (uVar4 == 0) {
          iVar2 = zmsg_append_le32(uStack_50,*puStack_2c);
          if ((((iVar2 == 0) && (iVar2 = zmsg_append_le32(uStack_50,puStack_2c[1]), iVar2 == 0)) &&
              ((iVar2 = zmsg_append_u8(uStack_50,*(undefined1 *)(puStack_2c + 2)), iVar2 == 0 &&
               (((iVar2 = zmsg_append_u8(uStack_50,*(undefined1 *)((int)puStack_2c + 9)), iVar2 == 0
                 && (iVar2 = zmsg_append_u8(uStack_50,*(undefined1 *)((int)puStack_2c + 10)),
                    iVar2 == 0)) && (iVar2 = zmsg_append_le32(uStack_50,puStack_2c[3]), iVar2 == 0))
               )))) && (iVar2 = zmsg_append_u8(uStack_50,*(undefined1 *)(puStack_2c + 4)),
                       iVar2 == 0)) {
            bVar1 = *(byte *)(puStack_2c + 4);
            if (bVar1 == 4) {
_L0:
              uVar4 = append_tou_info_no_billing_set_to_payload(uStack_50,puStack_2c + 6);
            }
            else if (bVar1 < 5) {
              if ((bVar1 == 2) || (bVar1 == 3)) {
                uVar4 = append_block_info_set_to_payload(uStack_50,puStack_2c + 6);
              }
              else {
                uVar4 = append_tou_info_set_to_payload();
              }
            }
            else {
              if ((bVar1 != 6) && (bVar1 != 7)) {
                uVar4 = 1;
                if (bVar1 != 5) goto _L0;
                goto _L0;
              }
              uVar4 = append_block_info_no_billing_set_to_payload(uStack_50,puStack_2c + 6);
            }
            if (uVar4 == 0) {
              puStack_7c = puStack_28;
              puStack_78 = puStack_24;
              uVar4 = zcl_packet_setup_response(auStack_74,param_1,6);
joined_r0x000111a0:
              if (uVar4 == 0) goto _L0;
            }
          }
          else {
            uVar4 = 0x89;
          }
        }
      }
    }
  }
  else if (bVar1 < 7) {
    if (bVar1 == 0) {
      memset(acStack_4c,0,0x28);
      uStack_7e = 0;
      iVar2 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_7e,auStack_40);
      if ((((iVar2 == 0) ||
           (iVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_7e,abStack_3c), iVar2 == 0)
           ) || (iVar2 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_7e,abStack_38),
                iVar2 == 0)) ||
         (uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)), uVar4 < uStack_7e)) {
_L0:
        uVar4 = 0x80;
      }
      else {
        uVar4 = 0x87;
        if ((abStack_38[0] != 0) &&
           (uVar4 = zcl_packet_to_message(acStack_4c,param_1,0x87), uVar4 == 0)) {
          uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
          iStack_44 = param_1;
          zcl_core_action_schedule(0x43,acStack_4c,0);
          uVar4 = uStack_34 & 0xff;
          if (uVar4 == 0xfe) {
            uVar4 = 0;
          }
          if (acStack_4c[0] == -2) goto _L0;
          if (uVar4 == 0) {
            if (puStack_30 == (ushort *)0x0) {
_L0:
              uVar4 = 1;
            }
            else {
              iVar2 = zmsg_append_le32(uStack_50,*(undefined4 *)puStack_30);
              if (((iVar2 == 0) &&
                  (iVar2 = zmsg_append_u8(uStack_50,(char)puStack_30[2]), iVar2 == 0)) &&
                 ((iVar2 = zmsg_append_u8(uStack_50,(char)puStack_30[4]), iVar2 == 0 &&
                  (iVar2 = zmsg_append_u8(uStack_50,(char)puStack_30[6]), iVar2 == 0)))) {
                uVar4 = (uint)(byte)puStack_30[6];
                if ((uVar4 != 0) && (*(int *)(puStack_30 + 8) == 0)) goto _L0;
                uVar3 = (uint)abStack_38[0];
                if (uVar4 < abStack_38[0]) {
                  uVar3 = uVar4;
                }
                uVar4 = 0;
                do {
                  if (uVar3 <= (uVar4 & 0xff)) {
                    uVar5 = 0;
                    puStack_7c = puStack_2c;
                    puStack_78 = puStack_28;
                    goto _L0;
                  }
                  iVar2 = uVar4 * 4;
                  uVar4 = uVar4 + 1;
                  iVar2 = zcl_packet_append_variable_attr_value
                                    (uStack_50,0x22,*(int *)(puStack_30 + 8) + iVar2);
                } while (iVar2 == 0);
              }
_L0:
              uVar4 = 0x89;
            }
          }
        }
      }
    }
    else {
      if (bVar1 != 3) goto _L0;
      memset(acStack_4c,0,0x1c);
      uVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,2,auStack_40);
      if ((uVar4 == 0) || (uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)), uVar3 < uVar4))
      goto _L0;
      uVar4 = zcl_packet_to_message(acStack_4c,param_1);
      if (uVar4 == 0) {
        abStack_3c[0] = 0xfe;
        iStack_44 = param_1;
        zcl_core_action_schedule(0x45,acStack_4c,0);
        uVar4 = (uint)abStack_3c[0];
        if (uVar4 == 0xfe) {
          uVar4 = 0;
        }
        if (acStack_4c[0] == -2) goto _L0;
        if (uVar4 == 0) {
          iVar2 = zmsg_append_u8(uStack_50,abStack_38[0]);
          if ((iVar2 != 0) || (iVar2 = zmsg_append_le32(uStack_50,uStack_34), iVar2 != 0)) goto _L0;
          uVar5 = 3;
_L0:
          uVar4 = zcl_packet_setup_response(auStack_74,param_1,uVar5);
          goto joined_r0x000111a0;
        }
      }
    }
  }
  else if (bVar1 == 8) {
    memset(acStack_4c,0,0x28);
    local_80 = 0;
    iVar2 = af_read_le16(*(undefined4 *)(param_1 + 0x24),&local_80,auStack_40);
    if ((((iVar2 == 0) ||
         (iVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&local_80,abStack_3c), iVar2 == 0))
        || (iVar2 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&local_80,abStack_38), iVar2 == 0))
       || ((iVar2 = af_read_le16(*(undefined4 *)(param_1 + 0x24),&local_80,&uStack_36), iVar2 == 0
           || (uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)), uVar4 < local_80))))
    goto _L0;
    uVar4 = 0x87;
    if ((uStack_36 != 0) && (uVar4 = zcl_packet_to_message(acStack_4c,param_1,0x87), uVar4 == 0)) {
      uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
      iStack_44 = param_1;
      zcl_core_action_schedule(0x49,acStack_4c,0);
      uVar4 = uStack_34 & 0xff;
      if (uVar4 == 0xfe) {
        uVar4 = 0;
      }
      if (acStack_4c[0] != -2) {
        if (uVar4 != 0) goto _L0;
        if ((puStack_30[6] != 0) && (*(int *)(puStack_30 + 8) != 0)) {
          uStack_7e = *puStack_30;
          iVar2 = zmsg_append_bytes(uStack_50,2,&uStack_7e);
          if ((iVar2 == 0) &&
             ((iVar2 = zmsg_append_le32(uStack_50,*(undefined4 *)(puStack_30 + 2)), iVar2 == 0 &&
              (iVar2 = zmsg_append_u8(uStack_50,(char)puStack_30[4]), iVar2 == 0)))) {
            uStack_7e = puStack_30[5];
            iVar2 = zmsg_append_bytes(uStack_50,2,&uStack_7e);
            if (iVar2 == 0) {
              uStack_7e = puStack_30[6];
              iVar2 = zmsg_append_bytes(uStack_50,2,&uStack_7e);
              if (iVar2 == 0) {
                uVar4 = (uint)puStack_30[6];
                if ((uint)uStack_36 < (uint)puStack_30[6]) {
                  uVar4 = (uint)uStack_36;
                }
                uVar3 = 0;
                do {
                  if (uVar4 <= (uVar3 & 0xffff)) {
                    uVar5 = 7;
                    puStack_7c = puStack_2c;
                    puStack_78 = puStack_28;
                    goto _L0;
                  }
                  iVar2 = uVar3 * 4;
                  uVar3 = uVar3 + 1;
                  iVar2 = zcl_packet_append_variable_attr_value
                                    (uStack_50,0x22,*(int *)(puStack_30 + 8) + iVar2);
                } while (iVar2 == 0);
              }
            }
          }
          goto _L0;
        }
      }
_L0:
      uVar4 = 0x8b;
    }
  }
  else {
_L0:
    uVar4 = 0x81;
  }
_L0:
  iVar2 = zcl_packet_setup_default_response(auStack_74,param_1,uVar4);
  if (iVar2 != 0) {
    zcl_packet_free(auStack_74);
    return iVar2;
  }
_L0:
  zcl_packet_send(auStack_74,&puStack_7c);
  return 0;
}

