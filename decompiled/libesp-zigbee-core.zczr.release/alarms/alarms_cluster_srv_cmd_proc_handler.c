/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarms_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int alarms_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  ushort uStack_6e;
  int aiStack_6c [3];
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_58 [36];
  undefined4 uStack_34;
  
  memset(auStack_58,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar5 = zcl_packet_init(auStack_58,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar5 != 0) {
    return iVar5;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 2) {
    iVar5 = alarm_table_pop_oldest(*(undefined1 *)(param_1 + 0x15));
    if (iVar5 == 0) {
      aiStack_6c[0] = CONCAT31(aiStack_6c[0]._1_3_,0x8b);
      uVar7 = 1;
_L0:
      iVar5 = zmsg_append_bytes(uStack_34,uVar7,aiStack_6c);
      if (iVar5 == 0) {
        uVar3 = zcl_packet_setup_response(auStack_58,param_1,1);
        if (uVar3 == 0) goto _L0;
        goto _L0;
      }
    }
    else {
      aiStack_6c[0] = (uint)aiStack_6c[0]._1_3_ << 8;
      iVar8 = zmsg_append_bytes(uStack_34,1,aiStack_6c);
      if (iVar8 == 0) {
        aiStack_6c[0] = CONCAT31(aiStack_6c[0]._1_3_,*(undefined1 *)(iVar5 + 4));
        iVar8 = zmsg_append_bytes(uStack_34,1,aiStack_6c);
        if (iVar8 == 0) {
          aiStack_6c[0] = CONCAT22(aiStack_6c[0]._2_2_,*(undefined2 *)(iVar5 + 6));
          iVar8 = zmsg_append_bytes(uStack_34,2,aiStack_6c);
          if (iVar8 == 0) {
            aiStack_6c[0] = *(int *)(iVar5 + 8);
            uVar7 = 4;
            goto _L0;
          }
        }
      }
    }
    uVar3 = 0x89;
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      aiStack_6c[0] = 0;
      aiStack_6c[1] = 0;
      aiStack_6c[2] = 0;
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_6e = 0;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_6e,&uStack_60);
      uVar3 = (uint)uStack_6e;
      iVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar3,2,(int)&uStack_60 + 2);
      if (iVar5 == 0) {
        uVar4 = 0xffff;
      }
      else {
        uVar4 = uVar3 + iVar5 & 0xffff;
      }
      uStack_6e = (ushort)uVar4;
      uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      uVar3 = 0x80;
      if ((uVar4 <= uVar6) && (uVar3 = zcl_packet_to_message(aiStack_6c,param_1,0x80), uVar3 == 0))
      {
        uVar2 = *(undefined1 *)(param_1 + 0x15);
        uVar4 = uStack_60 & 0xff;
        uVar3 = uStack_60 >> 0x10;
        iVar5 = get_alarm_table(uVar2,0);
        if (iVar5 != 0) {
          iVar8 = 5;
          puVar9 = (undefined4 *)(iVar5 + 4);
          while (puVar10 = puVar9, puVar9 = (undefined4 *)*puVar10, puVar9 != (undefined4 *)0x0) {
            if ((uVar4 == *(byte *)(puVar9 + 1)) && (uVar3 == *(ushort *)((int)puVar9 + 6))) {
              if (puVar9 == *(undefined4 **)(iVar5 + 8)) {
                *(uint *)(iVar5 + 8) = (uint)puVar10 & -(uint)((undefined4 *)(iVar5 + 4) != puVar10)
                ;
              }
              uVar7 = puVar9[2];
              *puVar10 = *(undefined4 *)*puVar10;
              *puVar9 = puVar9;
              alarm_table_remove_stored_entry(uVar2,uVar7);
              iVar8 = 0;
              *(char *)(iVar5 + 0xd) = *(char *)(iVar5 + 0xd) + -1;
              puVar9 = puVar10;
            }
          }
          if (iVar8 == 0) {
            uStack_5c = CONCAT31(uStack_5c._1_3_,0xfe);
            aiStack_6c[2] = param_1;
            zcl_core_action_schedule(0x36,aiStack_6c);
            uVar3 = uStack_5c & 0xff;
            if ((uStack_5c & 0xff) == 0xfe) {
              uVar3 = 1;
            }
            goto _L0;
          }
        }
        uVar3 = 0x8b;
      }
    }
    else {
      aiStack_6c[0] = 0;
      aiStack_6c[1] = 0;
      aiStack_6c[2] = 0;
      uStack_60 = 0;
      uVar3 = zcl_packet_to_message(aiStack_6c,param_1);
      if (uVar3 == 0) {
        uStack_60 = CONCAT31(uStack_60._1_3_,0xfe);
        aiStack_6c[2] = param_1;
        zcl_core_action_schedule(0x37,aiStack_6c,0);
        uVar4 = uStack_60 & 0xff;
        if (uVar4 == 0xfe) {
          uVar4 = 0;
        }
        iVar5 = alarm_table_reset(*(undefined1 *)(param_1 + 0x15));
        uVar3 = 0x8b;
        if (iVar5 == 0) {
          uVar3 = 1;
          if ((char)uStack_60 != -2) {
            uVar3 = uVar4;
          }
        }
      }
    }
  }
  else if (bVar1 == 3) {
    alarm_table_reset(*(undefined1 *)(param_1 + 0x15));
    uVar3 = 0;
  }
  else {
    uVar3 = 0x81;
  }
_L0:
  iVar5 = zcl_packet_setup_default_response(auStack_58,param_1,uVar3);
  if (iVar5 != 0) {
    zcl_packet_free(auStack_58);
    return iVar5;
  }
_L0:
  zcl_packet_send(auStack_58,0);
  return 0;
}

