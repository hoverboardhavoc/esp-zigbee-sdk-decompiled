/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_get_meas_prof_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
electrical_measurement_cluster_get_meas_prof_cmd_handler
          (int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 *puStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  iStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  puStack_30 = (undefined4 *)0x0;
  uStack_2c = 0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement.c"
                  ,0x7b,"electrical_measurement_cluster_get_meas_prof_cmd_handler","packet && rsp");
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_40);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_3c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_38);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < auStack_22[0]) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  uVar1 = zcl_packet_to_message(&uStack_4c,param_1);
  if (uVar1 == 0) {
    uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
    iStack_44 = param_1;
    zcl_core_action_schedule(0x40,&uStack_4c);
    uVar1 = uStack_34 & 0xff;
    if (uVar1 == 0xfe) {
      uVar1 = 1;
    }
    else if (uVar1 == 0) {
      if (puStack_30 == (undefined4 *)0x0) {
        uVar1 = 1;
      }
      else if ((*(char *)((int)puStack_30 + 6) == '\0') || (puStack_30[3] != 0)) {
        local_50 = *puStack_30;
        iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&local_50);
        if (iVar3 == 0) {
          local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)(puStack_30 + 1));
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&local_50);
          if (iVar3 == 0) {
            local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)((int)puStack_30 + 5));
            iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&local_50);
            if (iVar3 == 0) {
              local_50 = CONCAT31(local_50._1_3_,*(undefined1 *)((int)puStack_30 + 6));
              iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&local_50);
              if (iVar3 == 0) {
                local_50 = CONCAT22(local_50._2_2_,*(undefined2 *)(puStack_30 + 2));
                iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&local_50);
                if (iVar3 == 0) {
                  iVar3 = ezb_zcl_get_attr_desc
                                    (*(undefined1 *)(param_1 + 0x15),0xb04,1,
                                     *(undefined2 *)(puStack_30 + 2),0);
                  uVar1 = 0;
                  if (iVar3 == 0) {
                    uVar1 = 0x8b;
                  }
                  else {
                    for (; uVar1 < *(byte *)((int)puStack_30 + 6); uVar1 = uVar1 + 1 & 0xff) {
                      iVar4 = zcl_packet_append_variable_attr_value
                                        (*(undefined4 *)(param_2 + 0x24),*(undefined1 *)(iVar3 + 2),
                                         puStack_30[3] + uVar1);
                      if (iVar4 != 0) {
                        uVar1 = 0x89;
                        goto _L0;
                      }
                    }
                    *param_3 = uStack_2c;
                    param_3[1] = uStack_28;
                    uVar1 = zcl_packet_setup_response(param_2,param_1,1);
                    if (uVar1 == 0) {
                      return 0;
                    }
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
            else {
              uVar1 = 0x89;
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
      else {
        uVar1 = 1;
      }
    }
  }
_L0:
  uVar2 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar2;
}

