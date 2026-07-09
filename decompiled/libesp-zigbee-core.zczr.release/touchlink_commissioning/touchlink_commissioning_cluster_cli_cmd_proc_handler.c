/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_commissioning.o -> touchlink_commissioning_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_commissioning_cluster_cli_cmd_proc_handler(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  ushort uStack_72;
  undefined4 uStack_70;
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined2 auStack_60 [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 *puStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [40];
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  cVar1 = *(char *)(param_1 + 0x20);
  if (cVar1 == 'A') {
    uStack_72 = 0;
    uStack_70 = 0;
    pvStack_6c = (void *)0x0;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_70);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_70 + 1);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_70 + 2);
    if (uVar4 < uStack_72) goto _L0;
    uVar5 = 0x89;
    pvStack_6c = calloc(uStack_70 >> 0x10 & 0xff,2);
    uVar2 = 0;
    if (pvStack_6c != (void *)0x0) {
      for (; uVar2 < (uStack_70 >> 0x10 & 0xff); uVar2 = uVar2 + 1 & 0xff) {
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,
                            (void *)((int)pvStack_6c + uVar2 * 2));
      }
      if (uVar4 < uStack_72) goto _L0;
      uStack_5c = 0;
      uStack_58 = 0;
      iStack_54 = 0;
      puStack_50 = (undefined4 *)0x0;
      uStack_4c = 0;
      uVar5 = zcl_packet_to_message(&uStack_5c,param_1);
      if (uVar5 == 0) {
        uVar6 = 0x52;
_L0:
        puStack_50 = &uStack_70;
        uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
        iStack_54 = param_1;
        zcl_core_action_schedule(uVar6,&uStack_5c);
        if ((uStack_4c & 0xff) != 0xfe) {
          uVar5 = uStack_4c & 0xff;
        }
      }
    }
  }
  else {
    if (cVar1 != 'B') {
      uVar5 = 0x81;
      if (cVar1 == '@') {
        uStack_70 = 0;
        pvStack_6c = (void *)0x0;
        uStack_68 = 0;
        uStack_64 = 0;
        auStack_60[0] = 0;
        uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24),0x81);
        iVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,8,&uStack_70);
        if (iVar3 == 0) {
          iVar3 = 0xffff;
        }
        uStack_72 = (ushort)iVar3;
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_68);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_68 + 2);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_64);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_64 + 2);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,auStack_60);
        uVar5 = 0x80;
        if (uStack_72 <= uVar4) {
          uStack_5c = 0;
          uStack_58 = 0;
          iStack_54 = 0;
          puStack_50 = (undefined4 *)0x0;
          uStack_4c = 0;
          uVar5 = zcl_packet_to_message(&uStack_5c,param_1,0x80);
          if (uVar5 == 0) {
            uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
            iStack_54 = param_1;
            puStack_50 = &uStack_70;
            zcl_core_action_schedule(0x51,&uStack_5c,0);
            if ((uStack_4c & 0xff) != 0xfe) {
              uVar5 = uStack_4c & 0xff;
            }
          }
        }
      }
      goto _L0;
    }
    uStack_72 = 0;
    uStack_70 = 0;
    pvStack_6c = (void *)0x0;
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_70);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_70 + 1);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_70 + 2);
    if (uStack_72 <= uVar4) {
      pvStack_6c = calloc(uStack_70 >> 0x10 & 0xff,10);
      uVar2 = 0;
      uVar5 = 0x89;
      if (pvStack_6c != (void *)0x0) {
        for (; uVar2 < (uStack_70 >> 0x10 & 0xff); uVar2 = uVar2 + 1 & 0xff) {
          iVar3 = uVar2 * 10;
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,
                              (void *)((int)pvStack_6c + iVar3));
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)pvStack_6c + iVar3 + 2)
          ;
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)pvStack_6c + iVar3 + 4
                             );
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)pvStack_6c + iVar3 + 6
                             );
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)pvStack_6c + iVar3 + 8)
          ;
        }
        if (uVar4 < uStack_72) goto _L0;
        uStack_5c = 0;
        uStack_58 = 0;
        iStack_54 = 0;
        puStack_50 = (undefined4 *)0x0;
        uStack_4c = 0;
        uVar5 = zcl_packet_to_message(&uStack_5c,param_1);
        if (uVar5 == 0) {
          uVar6 = 0x53;
          goto _L0;
        }
      }
      goto _L0;
    }
_L0:
    uVar5 = 0x80;
  }
_L0:
  if (pvStack_6c != (void *)0x0) {
    mm_free();
  }
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_48,param_1,uVar5);
  if (iVar3 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
  return iVar3;
}

