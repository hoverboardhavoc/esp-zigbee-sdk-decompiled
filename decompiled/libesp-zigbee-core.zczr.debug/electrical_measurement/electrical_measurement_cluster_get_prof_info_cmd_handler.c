/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_get_prof_info_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
electrical_measurement_cluster_get_prof_info_cmd_handler
          (int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uStack_42;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  uint uStack_34;
  undefined1 *puStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_40 = 0;
  uStack_3c = 0;
  iStack_38 = 0;
  uStack_34 = 0;
  puStack_30 = (undefined1 *)0x0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/electrical_measurement.c"
                  ,0x57,"electrical_measurement_cluster_get_prof_info_cmd_handler","packet && rsp");
  }
  else {
    uVar1 = zcl_packet_to_message(&uStack_40,param_1);
    if (uVar1 != 0) goto _L0;
  }
  uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
  iStack_38 = param_1;
  zcl_core_action_schedule(0x3f,&uStack_40);
  uVar1 = uStack_34 & 0xff;
  if (uVar1 == 0xfe) {
    uVar1 = 1;
  }
  else if (uVar1 == 0) {
    if (puStack_30 == (undefined1 *)0x0) {
      uVar1 = 1;
    }
    else if (((uStack_2c & 0xff) == 0) || (*(int *)(puStack_30 + 4) != 0)) {
      uStack_42 = CONCAT11(uStack_42._1_1_,*puStack_30);
      iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_42);
      if (iVar3 == 0) {
        uStack_42 = CONCAT11(uStack_42._1_1_,puStack_30[1]);
        iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_42);
        if (iVar3 == 0) {
          uStack_42 = CONCAT11(uStack_42._1_1_,puStack_30[2]);
          iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_42);
          uVar1 = 0;
          if (iVar3 == 0) {
            for (; uVar1 < (uStack_2c & 0xff); uVar1 = uVar1 + 1 & 0xff) {
              uStack_42 = *(undefined2 *)(*(int *)(puStack_30 + 4) + uVar1 * 2);
              iVar3 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_42);
              if (iVar3 != 0) {
                uVar1 = 0x89;
                goto _L0;
              }
            }
            *param_3 = uStack_28;
            param_3[1] = uStack_24;
            uVar1 = zcl_packet_setup_response(param_2,param_1,0);
            if (uVar1 == 0) {
              return 0;
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
_L0:
  uVar2 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar2;
}

