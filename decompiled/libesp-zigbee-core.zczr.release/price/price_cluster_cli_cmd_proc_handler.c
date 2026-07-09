/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> price.o -> price_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int price_cluster_cli_cmd_proc_handler(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  byte bStack_ad;
  ushort uStack_ac;
  undefined2 uStack_aa;
  uint uStack_a8;
  undefined1 auStack_a4 [36];
  undefined4 uStack_80;
  undefined1 auStack_7c [8];
  int iStack_74;
  uint uStack_70;
  byte bStack_6c;
  undefined1 auStack_6b [3];
  undefined1 auStack_68 [4];
  undefined1 uStack_64;
  undefined1 uStack_63;
  byte abStack_62 [2];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  byte bStack_58;
  undefined1 uStack_57;
  undefined2 uStack_56;
  byte bStack_54;
  byte bStack_53;
  undefined2 uStack_52;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  uint uStack_4c;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined1 uStack_3c;
  byte bStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 auStack_36 [2];
  byte bStack_34;
  
  memset(auStack_a4,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar4 = zcl_packet_init(auStack_a4,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar4 != 0) {
    return iVar4;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    memset(auStack_7c,0,0x4c);
    uStack_ac = 0;
    bStack_ad = 0;
    uStack_a8 = 0;
    uStack_aa = 0;
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_a8);
    uStack_70 = uStack_a8;
    iVar4 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&bStack_6c);
    uVar2 = uStack_ac;
    if (iVar4 == 0) {
_L0:
      uVar5 = 0x80;
    }
    else {
      uVar5 = 0x87;
      if (bStack_6c < 0xd) {
        iVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uStack_ac,bStack_6c,auStack_6b);
        if ((iVar4 == 0) && (bStack_6c != 0)) {
          uStack_ac = 0xffff;
        }
        else {
          uStack_ac = uVar2 + (short)iVar4;
        }
        af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_a8);
        uStack_60 = (void *)CONCAT13((char)(uStack_a8 >> 0x10),
                                     CONCAT12((char)(uStack_a8 >> 8),
                                              CONCAT11((char)uStack_a8,(undefined1)uStack_60)));
        uStack_5c = CONCAT31(uStack_5c._1_3_,(char)(uStack_a8 >> 0x18));
        af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_a8);
        uStack_5c = CONCAT13((char)(uStack_a8 >> 0x10),
                             CONCAT12((char)(uStack_a8 >> 8),
                                      CONCAT11((char)uStack_a8,(undefined1)uStack_5c)));
        bStack_58 = (byte)(uStack_a8 >> 0x18);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_57);
        uVar2 = uStack_ac;
        iVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uStack_ac,2,&uStack_aa);
        if (iVar4 == 0) {
          uStack_ac = 0xffff;
        }
        else {
          uStack_ac = uVar2 + (short)iVar4;
        }
        uStack_56 = uStack_aa;
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&bStack_ad);
        bStack_54 = bStack_ad >> 4 | bStack_ad << 4;
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&bStack_ad);
        bStack_53 = bStack_ad >> 4 | bStack_ad << 4;
        af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_a8);
        uVar2 = uStack_ac;
        uStack_52 = (undefined2)uStack_a8;
        uStack_50 = (undefined2)(uStack_a8 >> 0x10);
        iVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uStack_ac,2,&uStack_aa);
        if (iVar4 == 0) {
          uStack_ac = 0xffff;
        }
        else {
          uStack_ac = uVar2 + (short)iVar4;
        }
        uStack_4e = uStack_aa;
        af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_a8);
        uStack_4c = uStack_a8;
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_48);
        af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_a8);
        uStack_47 = (undefined1)uStack_a8;
        uStack_46 = (undefined1)(uStack_a8 >> 8);
        uStack_45 = (undefined1)(uStack_a8 >> 0x10);
        uStack_44 = (undefined1)(uStack_a8 >> 0x18);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_43);
        af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_a8);
        uStack_42 = (undefined2)uStack_a8;
        uStack_40 = (undefined2)(uStack_a8 >> 0x10);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_3e);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_3d);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_3c);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&bStack_3b);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_3a);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_39);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_38);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,&uStack_37);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_ac,auStack_36);
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar5 < uStack_ac) goto _L0;
        uVar5 = zcl_packet_to_message(auStack_7c,param_1);
        if (uVar5 == 0) {
          bStack_34 = 0xfe;
          iStack_74 = param_1;
          zcl_core_action_schedule(0x4f,auStack_7c,0);
          uVar5 = (uint)bStack_34;
          if (uVar5 == 0xfe) {
            uVar5 = 1;
          }
          else if ((bStack_3b & 1) != 0) {
            iVar4 = zmsg_append_le32(uStack_80,uStack_70);
            if ((iVar4 == 0) &&
               (iVar4 = zmsg_append_le32(uStack_80,uStack_5c << 0x18 | (uint)uStack_60 >> 8),
               iVar4 == 0)) {
              uVar5 = zcl_time_get_utc_time(*(undefined1 *)(param_1 + 0x15));
              if (uVar5 == 0xffffffff) {
                uVar5 = (uint)bStack_58 << 0x18 | uStack_5c >> 8;
              }
              iVar4 = zmsg_append_le32(uStack_80,uVar5);
              if ((iVar4 == 0) && (iVar4 = zmsg_append_u8(uStack_80,bStack_3b), iVar4 == 0)) {
                uVar5 = zcl_packet_setup_response(auStack_a4,param_1,2);
                if (uVar5 == 0) goto _L0;
                goto _L0;
              }
            }
            uVar5 = 0x89;
          }
        }
      }
    }
  }
  else {
    if (*(char *)(param_1 + 0x20) != '\b') {
      uVar5 = 0x81;
      goto _L0;
    }
    memset(auStack_7c,0,0x24);
    uStack_a8 = uStack_a8 & 0xffff0000;
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a8,&uStack_70);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a8,&bStack_6c);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a8,auStack_68);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a8,&uStack_64);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a8,&uStack_63);
    iVar4 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a8,abStack_62);
    if (iVar4 == 1) {
      if (abStack_62[0] == 0) {
_L0:
        uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar5 < (uStack_a8 & 0xffff)) goto _L0;
        uVar5 = zcl_packet_to_message(auStack_7c,param_1);
        if (uVar5 == 0) {
          uStack_5c = CONCAT31(uStack_5c._1_3_,0xfe);
          iStack_74 = param_1;
          zcl_core_action_schedule(0x50,auStack_7c);
          if ((uStack_5c & 0xff) != 0xfe) {
            uVar5 = uStack_5c & 0xff;
          }
        }
      }
      else {
        uStack_60 = calloc((uint)abStack_62[0],0xe);
        uVar5 = 0x89;
        if (uStack_60 != (void *)0x0) {
          for (uVar5 = 0; uVar5 < abStack_62[0]; uVar5 = uVar5 + 1 & 0xff) {
            iVar4 = uVar5 * 0xe;
            af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a8,(void *)((int)uStack_60 + iVar4))
            ;
            af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a8,(int)uStack_60 + iVar4 + 1);
            bVar1 = *(byte *)((int)uStack_60 + iVar4 + 1);
            if (0xc < bVar1) {
              uVar5 = 0x87;
              goto _L0;
            }
            sVar3 = (short)uStack_a8;
            iVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uStack_a8 & 0xffff,bVar1,
                                    (int)uStack_60 + iVar4 + 2);
            if ((iVar4 != 0) || (sVar6 = -1, bVar1 == 0)) {
              sVar6 = sVar3 + (short)iVar4;
            }
            uStack_a8 = CONCAT22(uStack_a8._2_2_,sVar6);
          }
          goto _L0;
        }
      }
    }
    else {
_L0:
      uVar5 = 0x80;
    }
_L0:
    if (uStack_60 != (void *)0x0) {
      mm_free();
    }
  }
_L0:
  iVar4 = zcl_packet_setup_default_response(auStack_a4,param_1,uVar5);
  if (iVar4 != 0) {
    zcl_packet_free(auStack_a4);
    return iVar4;
  }
_L0:
  zcl_packet_send(auStack_a4,0);
  return 0;
}

