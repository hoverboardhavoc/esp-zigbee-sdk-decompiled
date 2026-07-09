/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_cluster_srv_cmd_proc_handler(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  int iVar8;
  uint uVar9;
  undefined2 uStack_76;
  undefined4 uStack_74;
  uint uStack_70;
  int iStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  byte bStack_4c;
  undefined1 auStack_4a [2];
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  cVar1 = *(char *)(param_1 + 0x20);
  if (cVar1 == '\x03') {
    uStack_74 = uStack_74 & 0xffff0000;
    memset(&uStack_64,0,0x1c);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_74,&uStack_64);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_74,(int)&uStack_64 + 2);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_74,&uStack_60);
    af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_74,&iStack_5c);
    af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_74,&uStack_58);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_74,&uStack_54);
    if ((uStack_64 & 1) != 0) {
      sVar2 = (short)uStack_74;
      iVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uStack_74 & 0xffff,8,
                              (int)&uStack_54 + 1);
      if (iVar3 == 0) {
        sVar2 = -1;
      }
      else {
        sVar2 = sVar2 + (short)iVar3;
      }
      uStack_74 = CONCAT22(uStack_74._2_2_,sVar2);
    }
    if ((uStack_64 & 2) != 0) {
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_74,auStack_4a);
    }
    uVar6 = 0x80;
    if ((uStack_74 & 0xffff) <= uVar4) {
      iVar3 = 0;
      pbVar5 = (byte *)ota_upgrade_get_file_table(*(undefined1 *)(param_1 + 0x15),0x80);
      for (uVar4 = 0; (uVar4 & 0xff) < (uint)*pbVar5; uVar4 = uVar4 + 1) {
        iVar3 = *(int *)(pbVar5 + 4) + uVar4 * 0x4c;
        if ((((uint)*(ushort *)(iVar3 + 10) == uStack_64 >> 0x10) &&
            ((uint)*(ushort *)(iVar3 + 0xc) == (uStack_60 & 0xffff))) &&
           (*(int *)(iVar3 + 0xe) == iStack_5c)) {
          if ((uStack_64 & 1) == 0) break;
          if ((*(uint *)(iVar3 + 0x39) == (uStack_50 << 0x18 | uStack_54 >> 8)) &&
             (*(uint *)(iVar3 + 0x3d) == ((uint)bStack_4c << 0x18 | uStack_50 >> 8))) goto _L0;
        }
      }
      if (iVar3 == 0) {
        uVar6 = 0x98;
      }
      else {
_L0:
        zcl_message_ota_upgrade_server_progress(param_1,2,&uStack_64,0);
        uVar4 = *(uint *)(iVar3 + 0x34);
        if (uStack_58 < uVar4) {
          if (uVar4 < (uStack_54 & 0xff) + uStack_58) {
            uStack_54 = CONCAT31(uStack_54._1_3_,(char)uVar4 - (char)uStack_58);
          }
          uStack_76 = (ushort)uStack_76._1_1_ << 8;
          iVar8 = zmsg_append_bytes(uStack_24,1,&uStack_76);
          if (((iVar8 == 0) && (iVar8 = zmsg_append_le16(uStack_24,uStack_64 >> 0x10), iVar8 == 0))
             && ((iVar8 = zmsg_append_le16(uStack_24,uStack_60 & 0xffff), iVar8 == 0 &&
                 ((iVar8 = zmsg_append_le32(uStack_24,iStack_5c), iVar8 == 0 &&
                  (iVar8 = zmsg_append_le32(uStack_24,uStack_58), iVar8 == 0)))))) {
            uStack_76 = CONCAT11(uStack_76._1_1_,(undefined1)uStack_54);
            iVar8 = zmsg_append_bytes(uStack_24,1,&uStack_76);
            if (iVar8 == 0) {
              uVar4 = uStack_54 & 0xff;
              puVar7 = (undefined2 *)(*(int *)(iVar3 + 0x48) + uStack_58);
              goto _L0;
            }
          }
        }
        else {
          uStack_76 = CONCAT11(uStack_76._1_1_,0x98);
          puVar7 = &uStack_76;
          uVar4 = 1;
_L0:
          iVar3 = zmsg_append_bytes(uStack_24,uVar4,puVar7);
          if (iVar3 == 0) {
            uVar6 = 5;
            goto _L0;
          }
        }
        uVar6 = 0x89;
      }
    }
    goto _L0;
  }
  if (cVar1 == '\x06') {
    uStack_76 = 0;
    uStack_64 = 0;
    uStack_60 = 0;
    iStack_5c = 0;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&uStack_64);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,(int)&uStack_64 + 2);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&uStack_60);
    af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&iStack_5c);
    uVar6 = 0x80;
    if (uVar4 < uStack_76) goto _L0;
    uStack_74 = 0;
    zcl_message_ota_upgrade_server_progress(param_1,5,&uStack_64,&uStack_74);
    if ((uStack_64 & 0xff) == 0) {
      uVar9 = uStack_74 & 0xffff;
      uVar4 = uStack_74 >> 0x10;
      iVar3 = zmsg_append_le16(uStack_24,uStack_64 >> 0x10);
      if ((((iVar3 == 0) && (iVar3 = zmsg_append_le16(uStack_24,uStack_60 & 0xffff), iVar3 == 0)) &&
          (iVar3 = zmsg_append_le32(uStack_24,iStack_5c), iVar3 == 0)) &&
         (iVar3 = zmsg_append_le32(uStack_24,uVar9), iVar3 == 0)) {
        zmsg_append_le32(uStack_24,uVar4);
      }
      if ((char)uStack_64 == '\0') {
        uVar6 = 7;
        goto _L0;
      }
    }
    uVar6 = 0;
  }
  else if (cVar1 == '\x01') {
    uStack_76 = 0;
    uStack_74 = 0;
    uStack_70 = 0;
    iStack_6c = 0;
    uStack_68 = 0;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&uStack_74);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,(int)&uStack_74 + 2);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&uStack_70);
    af_read_le32_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&iStack_6c);
    if ((uStack_74 & 1) != 0) {
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_76,&uStack_68);
    }
    if (uStack_76 <= uVar4) {
      pbVar5 = (byte *)ota_upgrade_get_file_table(*(undefined1 *)(param_1 + 0x15));
      if (pbVar5 == (byte *)0x0) {
_L0:
        uStack_64 = CONCAT31(uStack_64._1_3_,0x98);
        iVar3 = zmsg_append_bytes(uStack_24,1,&uStack_64);
_L0:
        if (iVar3 != 0) {
_L0:
          uVar6 = 0x89;
          goto _L0;
        }
      }
      else {
        iVar3 = 1;
        for (uVar4 = 0; uVar4 < *pbVar5; uVar4 = uVar4 + 1 & 0xff) {
          iVar8 = *(int *)(pbVar5 + 4) + uVar4 * 0x4c;
          if ((*(short *)(iVar8 + 10) == uStack_74._2_2_) &&
             ((uint)*(ushort *)(iVar8 + 0xc) == (uStack_70 & 0xffff))) {
            if ((((uStack_74 & 1) == 0) || ((*(ushort *)(iVar8 + 8) & 4) == 0)) ||
               (((*(uint *)(iVar8 + 0x40) >> 8 & 0xffff) <= (uStack_68 & 0xffff) &&
                ((uStack_68 & 0xffff) <=
                 ((uint)*(byte *)(iVar8 + 0x44) << 8 | *(uint *)(iVar8 + 0x40) >> 0x18))))) {
              uStack_60 = CONCAT22((undefined2)uStack_70,uStack_74._2_2_);
              uStack_58 = CONCAT22(uStack_58._2_2_,(undefined2)uStack_68);
              uStack_64._0_3_ =
                   CONCAT12(*(undefined1 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 2));
              iStack_5c = iStack_6c;
              uStack_54 = *(uint *)(iVar8 + 0xe);
              iVar3 = zcl_message_ota_upgrade_server_progress(param_1,0,&uStack_64,0);
              if (iVar3 == 0) {
                uVar6 = *(undefined4 *)(iVar8 + 0xe);
                iVar3 = *(int *)(iVar8 + 0x34);
              }
              else {
                if (iVar3 != 0xfe) goto _L0;
                uVar6 = 0;
                iVar3 = 0;
              }
              if (iVar3 == 0) goto _L0;
              uStack_64 = uStack_64 & 0xffffff00;
              iVar8 = zmsg_append_bytes(uStack_24,1,&uStack_64);
              if ((((iVar8 != 0) ||
                   (iVar8 = zmsg_append_le16(uStack_24,uStack_74 >> 0x10), iVar8 != 0)) ||
                  (iVar8 = zmsg_append_le16(uStack_24,uStack_70 & 0xffff), iVar8 != 0)) ||
                 (iVar8 = zmsg_append_le32(uStack_24,uVar6), iVar8 != 0)) goto _L0;
              iVar3 = zmsg_append_le32(uStack_24,iVar3);
              goto _L0;
            }
          }
_L0:
        }
        if (iVar3 != 0x7e) goto _L0;
        uStack_64 = CONCAT31(uStack_64._1_3_,0x7e);
        iVar3 = zmsg_append_bytes(uStack_24,1,&uStack_64);
        uVar6 = 0x7e;
        if (iVar3 != 0) goto _L0;
      }
      uVar6 = 2;
_L0:
      iVar3 = zcl_packet_setup_response_with_extension(auStack_48,param_1,uVar6,0,1);
      goto _L0;
    }
    uVar6 = 0x80;
  }
  else {
    uVar6 = 0x81;
  }
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_48,param_1,uVar6);
_L0:
  if (iVar3 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
  return iVar3;
}

