/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ias_ace_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ias_ace_cluster_cli_cmd_proc_handler(int param_1)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uStack_84;
  ushort uStack_72;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined1 auStack_68 [40];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [12];
  byte bStack_1c;
  byte abStack_14 [4];
  
  memset(auStack_68,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar5 = zcl_packet_init(auStack_68,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar5 != 0) {
    return iVar5;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 4) {
    uStack_70 = (void *)((uint)uStack_70._2_2_ << 0x10);
    uStack_40 = 0;
    uStack_3c = 0;
    iStack_38 = 0;
    local_34 = 0;
    uStack_30 = (void *)0x0;
    iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,&local_34);
    if ((((iVar5 == 0) ||
         (iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&local_34 + 1),
         iVar5 == 0)) ||
        (iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&local_34 + 2),
        iVar5 == 0)) ||
       ((iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&local_34 + 3),
        iVar5 == 0 ||
        (uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)),
        uVar7 < ((uint)uStack_70 & 0xffff))))) goto _L0;
    uStack_84 = zcl_packet_to_message(&uStack_40,param_1);
    if (uStack_84 != 0) goto _L0;
    uStack_30 = (void *)CONCAT31(uStack_30._1_3_,0xfe);
    uVar6 = 0x28;
_L0:
    iStack_38 = param_1;
    zcl_core_action_schedule(uVar6,&uStack_40,uStack_84);
    uVar7 = (uint)uStack_30 & 0xff;
_L0:
    if (uVar7 != 0xfe) {
      uStack_84 = uVar7;
    }
    goto _L0;
  }
  if (bVar1 < 5) {
    if (bVar1 == 2) {
      uStack_70 = (void *)0x0;
      uStack_6c = 0;
      uStack_72 = 0;
      memset(&uStack_40,0,0x30);
      af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_72,&local_34);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&local_34 + 2);
      uVar2 = uStack_72;
      iVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uStack_72,8,&uStack_70);
      if (iVar5 == 0) {
        uStack_72 = 0xffff;
      }
      else {
        uStack_72 = uVar2 + (short)iVar5;
      }
      uStack_30 = uStack_70;
      uStack_2c = uStack_6c;
      iVar5 = read_zcl_string(*(undefined4 *)(param_1 + 0x24),&uStack_72,auStack_28,0x11);
      if ((iVar5 == 0) &&
         (uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)), uStack_72 <= uVar7)) {
        uStack_84 = zcl_packet_to_message(&uStack_40,param_1);
        if (uStack_84 != 0) goto _L0;
        uVar6 = 0x26;
        goto _L0;
      }
    }
    else {
      if (bVar1 != 3) {
        if (bVar1 == 0) {
          uStack_70 = (void *)((uint)uStack_70 & 0xffff0000);
          uStack_40 = 0;
          uStack_3c = 0;
          iStack_38 = 0;
          local_34 = 0;
          uStack_30 = (void *)0x0;
          iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,&local_34);
          uStack_84 = 0x80;
          if ((iVar5 != 1) ||
             (uStack_84 = zcl_packet_to_message(&uStack_40,param_1,0x80), uStack_84 != 0)) goto _L0;
          uStack_30 = (void *)CONCAT31(uStack_30._1_3_,0xfe);
          uVar6 = 0x24;
          goto _L0;
        }
        uStack_70 = (void *)((uint)uStack_70._2_2_ << 0x10);
        memset(&uStack_40,0,0x30);
        uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        uStack_84 = 0x80;
        if (uVar7 < 0x20) goto _L0;
        pbVar3 = (byte *)&local_34;
        do {
          pbVar4 = pbVar3 + 2;
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_70,pbVar3);
          pbVar3 = pbVar4;
        } while (abStack_14 != pbVar4);
        uStack_84 = zcl_packet_to_message(&uStack_40,param_1);
        if (uStack_84 != 0) goto _L0;
        uVar6 = 0x25;
_L0:
        abStack_14[0] = 0xfe;
        iStack_38 = param_1;
        zcl_core_action_schedule(uVar6,&uStack_40,uStack_84);
        uVar7 = (uint)abStack_14[0];
        goto _L0;
      }
      uStack_70 = (void *)((uint)uStack_70._2_2_ << 0x10);
      memset(&uStack_40,0,0x28);
      af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,&local_34);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&local_34 + 2);
      af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,&uStack_30);
      iVar5 = read_zcl_string(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&uStack_30 + 1,0x11);
      if ((iVar5 == 0) &&
         (uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)),
         ((uint)uStack_70 & 0xffff) <= uVar7)) {
        uStack_84 = zcl_packet_to_message(&uStack_40,param_1);
        if (uStack_84 != 0) goto _L0;
        bStack_1c = 0xfe;
        iStack_38 = param_1;
        zcl_core_action_schedule(0x27,&uStack_40,0);
        uVar7 = (uint)bStack_1c;
        goto _L0;
      }
    }
_L0:
    uStack_84 = 0x80;
    goto _L0;
  }
  if (bVar1 == 7) {
    uStack_70 = (void *)((uint)uStack_70._2_2_ << 0x10);
    memset(&uStack_40,0,0x18);
    iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,&local_34);
    if (iVar5 == 1) {
      uVar7 = local_34 & 0xff;
      uStack_84 = 0x87;
      if (uVar7 != 0) {
        uStack_30 = calloc(1,uVar7);
        uStack_84 = 0x89;
        if (uStack_30 != (void *)0x0) {
          af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_70,uVar7,uStack_30);
          uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          if (uVar7 < ((uint)uStack_70 & 0xffff)) goto _L0;
          uStack_84 = zcl_packet_to_message(&uStack_40,param_1);
          if (uStack_84 == 0) {
            uStack_2c = CONCAT31(uStack_2c._1_3_,0xfe);
            uVar6 = 0x2b;
            goto _L0;
          }
        }
      }
      goto _L0;
    }
_L0:
    uStack_84 = 0x80;
  }
  else {
    if (bVar1 < 8) {
      if (bVar1 == 5) {
        uStack_70 = (void *)((uint)uStack_70._2_2_ << 0x10);
        uStack_40 = 0;
        uStack_3c = 0;
        iStack_38 = 0;
        local_34 = 0;
        uStack_30 = (void *)0x0;
        iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,&local_34);
        if (((iVar5 != 0) &&
            (iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&local_34 + 1),
            iVar5 != 0)) &&
           ((iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&local_34 + 2),
            iVar5 != 0 &&
            ((iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&local_34 + 3),
             iVar5 != 0 &&
             (uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)),
             ((uint)uStack_70 & 0xffff) <= uVar7)))))) {
          uStack_84 = zcl_packet_to_message(&uStack_40,param_1);
          if (uStack_84 != 0) goto _L0;
          uStack_30 = (void *)CONCAT31(uStack_30._1_3_,0xfe);
          uVar6 = 0x29;
          goto _L0;
        }
        goto _L0;
      }
      uStack_70 = (void *)((uint)uStack_70._2_2_ << 0x10);
      memset(&uStack_40,0,0x18);
      iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_70,&local_34);
      if (iVar5 == 1) {
        uVar7 = local_34 & 0xff;
        if (uVar7 != 0) {
          uStack_30 = calloc(1,uVar7);
          uStack_84 = 0x89;
          if (uStack_30 == (void *)0x0) goto _L0;
          af_read_bytes_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_70,uVar7,uStack_30);
        }
        uVar7 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (((uint)uStack_70 & 0xffff) <= uVar7) {
          uStack_84 = zcl_packet_to_message(&uStack_40,param_1);
          if (uStack_84 == 0) {
            uStack_2c = CONCAT31(uStack_2c._1_3_,0xfe);
            uVar6 = 0x2a;
_L0:
            iStack_38 = param_1;
            zcl_core_action_schedule(uVar6,&uStack_40);
            if ((uStack_2c & 0xff) != 0xfe) {
              uStack_84 = uStack_2c & 0xff;
            }
          }
          goto _L0;
        }
      }
      goto _L0;
    }
    if (bVar1 != 8) {
      uStack_84 = 0x81;
      goto _L0;
    }
    uStack_72 = 0;
    memset(&uStack_40,0,0x18);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_72,&local_34);
    iVar5 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&local_34 + 1);
    if (iVar5 != 1) goto _L0;
    uStack_84 = 0x89;
    uStack_30 = calloc(1,(local_34 >> 8 & 0xff) << 2);
    if (uStack_30 != (void *)0x0) {
      for (iVar5 = 0; iVar5 < (int)(local_34 >> 8 & 0xff); iVar5 = iVar5 + 1) {
        uStack_70 = (void *)((uint)uStack_70 & 0xffff0000);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_72,(void *)((int)uStack_30 + iVar5 * 4))
        ;
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_70);
        *(undefined2 *)((int)uStack_30 + iVar5 * 4 + 2) = (undefined2)uStack_70;
      }
      uVar7 = zmsg_get_length();
      if (uVar7 < uStack_72) goto _L0;
      uStack_84 = zcl_packet_to_message(&uStack_40,param_1);
      if (uStack_84 == 0) {
        uStack_2c = CONCAT31(uStack_2c._1_3_,0xfe);
        uVar6 = 0x2c;
        goto _L0;
      }
    }
  }
_L0:
  if (uStack_30 != (void *)0x0) {
    mm_free();
  }
_L0:
  iVar5 = zcl_packet_setup_default_response(auStack_68,param_1,uStack_84);
  if (iVar5 == 0) {
    zcl_packet_send(auStack_68,0);
  }
  else {
    zcl_packet_free(auStack_68);
  }
  return iVar5;
}

