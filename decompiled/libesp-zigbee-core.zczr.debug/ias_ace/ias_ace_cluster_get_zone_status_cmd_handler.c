/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_status_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ias_ace_cluster_get_zone_status_cmd_handler(int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 uStack_4a;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  iStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  puStack_30 = (undefined1 *)0x0;
  uStack_2c = 0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x1cc,
                  "ias_ace_cluster_get_zone_status_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_3c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_3c + 1);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_3c + 2);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_38);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < auStack_22[0]) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  uVar1 = zcl_packet_to_message(&uStack_48,param_1);
  if (uVar1 == 0) {
    if ((uStack_3c & 0xff) + (uStack_3c >> 8 & 0xff) < 0xff) {
      uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
      iStack_40 = param_1;
      zcl_core_action_schedule(0x23,&uStack_48);
      uVar1 = uStack_34 & 0xff;
      if (uVar1 == 0xfe) {
        uVar1 = 0x8b;
      }
      else if (uVar1 == 0) {
        *param_3 = uStack_2c;
        param_3[1] = uStack_28;
        if (puStack_30 == (undefined1 *)0x0) {
          uVar1 = 1;
        }
        else {
          uStack_4a = CONCAT11(uStack_4a._1_1_,*puStack_30);
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_4a);
          if (iVar3 == 0) {
            uVar5 = uStack_3c >> 8 & 0xff;
            uVar1 = (uint)(byte)puStack_30[1];
            if (uVar5 < (byte)puStack_30[1]) {
              uVar1 = uVar5;
            }
            uStack_4a = CONCAT11(uStack_4a._1_1_,(char)uVar1);
            iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_4a);
            if (iVar3 == 0) {
              iVar3 = 0;
              if ((uVar1 == 0) || (*(int *)(puStack_30 + 4) != 0)) {
                for (; iVar3 < (int)uVar1; iVar3 = iVar3 + 1) {
                  uStack_4a = CONCAT11(uStack_4a._1_1_,
                                       *(undefined1 *)(*(int *)(puStack_30 + 4) + iVar3 * 4));
                  iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_4a);
                  if (iVar4 != 0) {
                    uVar1 = 0x89;
                    goto _L0;
                  }
                  uStack_4a = *(undefined2 *)(*(int *)(puStack_30 + 4) + iVar3 * 4 + 2);
                  iVar4 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_4a);
                  if (iVar4 != 0) {
                    uVar1 = 0x89;
                    goto _L0;
                  }
                }
                uVar1 = zcl_packet_setup_response(param_2,param_1,8);
                if (uVar1 == 0) {
                  return 0;
                }
              }
              else {
                uVar1 = 1;
              }
            }
            else {
              uVar1 = 0x89;
            }
          }
          else {
            uVar1 = 0x89;
          }
        }
      }
    }
    else {
      uVar1 = 0x87;
    }
  }
_L0:
  uVar2 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar2;
}

