/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> price.o -> price_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int price_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uStack_72;
  undefined4 uStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  int iStack_5c;
  uint uStack_58;
  undefined4 *puStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  uStack_70 = 0;
  uStack_6c = 0;
  if (((param_1 == 0) || ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0)) ||
     (iVar2 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1), iVar2 != 0)) {
    return 1;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 2) {
    memset(&uStack_68,0,0x20);
    uStack_72 = 0;
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_72,&iStack_5c);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_58);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_72,&puStack_54);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_50);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar3 = 0x80;
    if ((uStack_72 <= uVar4) && (uVar3 = zcl_packet_to_message(&uStack_68,param_1,0x80), uVar3 == 0)
       ) {
      uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
      iStack_60 = param_1;
      zcl_core_action_schedule(0x4e,&uStack_68,0);
      if ((uStack_4c & 0xff) != 0xfe) {
        uVar3 = uStack_4c & 0xff;
      }
    }
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      uStack_68 = 0;
      uStack_64 = 0;
      iStack_60 = 0;
      iStack_5c = 0;
      uStack_58 = 0;
      uStack_72 = 0;
      iVar2 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_72,&iStack_5c);
      uVar3 = 0x80;
      if ((iVar2 != 0) && (uVar3 = zcl_packet_to_message(&uStack_68,param_1,0x80), uVar3 == 0)) {
        uStack_58 = CONCAT31(uStack_58._1_3_,0xfe);
        iStack_60 = param_1;
        zcl_core_action_schedule(0x4b,&uStack_68,0);
        bVar1 = (byte)uStack_58;
_L0:
        uVar3 = (uint)bVar1;
        if (uVar3 == 0xfe) goto _L0;
_L0:
        if (uVar3 == 0) goto _L0;
      }
    }
    else {
      memset(&uStack_68,0,0x18);
      uStack_72 = 0;
      af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_72,&iStack_5c);
      af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_58);
      uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (uVar3 < uStack_72) {
        uVar3 = 0x80;
      }
      else {
        if ((iStack_5c == 0) &&
           (iVar2 = zcl_time_get_utc_time(*(undefined1 *)(param_1 + 0x15)), iVar2 != -1)) {
          iStack_5c = iVar2;
        }
        uVar3 = zcl_packet_to_message(&uStack_68,param_1);
        if (uVar3 == 0) {
          puStack_54 = (undefined4 *)CONCAT31(puStack_54._1_3_,0xfe);
          iStack_60 = param_1;
          zcl_core_action_schedule(0x4c,&uStack_68,0);
          bVar1 = (byte)puStack_54;
          goto _L0;
        }
      }
    }
  }
  else if (bVar1 == 10) {
    memset(&uStack_68,0,0x20);
    uStack_72 = 0;
    iVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_72,&iStack_5c);
    uVar3 = 0x80;
    if ((iVar2 == 4) && (uVar3 = zcl_packet_to_message(&uStack_68,param_1,0x80), uVar3 == 0)) {
      uStack_58 = CONCAT31(uStack_58._1_3_,0xfe);
      iStack_60 = param_1;
      zcl_core_action_schedule(0x4d,&uStack_68,0);
      uVar3 = uStack_58 & 0xff;
      if (uVar3 == 0xfe) {
_L0:
        uVar3 = 0x8b;
      }
      else if (uVar3 == 0) {
        uStack_70 = uStack_50;
        uStack_6c = uStack_4c;
        if (puStack_54 == (undefined4 *)0x0) goto _L0;
        iVar2 = zmsg_append_le32(uStack_24,*puStack_54);
        if (((((iVar2 == 0) && (iVar2 = zmsg_append_le32(uStack_24,puStack_54[1]), iVar2 == 0)) &&
             (iVar2 = zmsg_append_le32(uStack_24,puStack_54[2]), iVar2 == 0)) &&
            ((iVar2 = zmsg_append_u8(uStack_24,*(undefined1 *)(puStack_54 + 3)), iVar2 == 0 &&
             (iVar2 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)puStack_54 + 0xd)), iVar2 == 0))
            )) && (iVar2 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)puStack_54 + 0xe)),
                  iVar2 == 0)) {
          uVar3 = (uint)*(byte *)((int)puStack_54 + 0xe);
          if ((uVar3 == 0) || (uVar3 = 0, puStack_54[4] != 0)) {
            for (; uVar3 < *(byte *)((int)puStack_54 + 0xe); uVar3 = uVar3 + 1 & 0xff) {
              iVar2 = zmsg_append_u8(uStack_24,*(undefined1 *)(puStack_54[4] + uVar3 * 0xe));
              if ((iVar2 != 0) ||
                 (iVar2 = puStack_54[4] + uVar3 * 0xe,
                 iVar2 = zmsg_append_bytes(uStack_24,*(byte *)(iVar2 + 1) + 1,iVar2 + 1), iVar2 != 0
                 )) goto _L0;
            }
            uVar3 = zcl_packet_setup_response(auStack_48,param_1,8);
            goto _L0;
          }
          uVar3 = 1;
        }
        else {
_L0:
          uVar3 = 0x89;
        }
      }
    }
  }
  else {
    uVar3 = 0x81;
  }
  iVar2 = zcl_packet_setup_default_response(auStack_48,param_1,uVar3);
  if (iVar2 != 0) {
    zcl_packet_free(auStack_48);
    return iVar2;
  }
_L0:
  zcl_packet_send(auStack_48,&uStack_70);
  return 0;
}

