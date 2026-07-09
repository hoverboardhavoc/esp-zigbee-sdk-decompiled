/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_get_alarm_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarms_cluster_get_alarm_cmd_handler(int param_1,int param_2)

{
  int unaff_s1;
  int iVar1;
  int iStack_14;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1a4,
                  "alarms_cluster_get_alarm_cmd_handler","packet && rsp");
_L0:
    iStack_14 = CONCAT31(iStack_14._1_3_,*(undefined1 *)(unaff_s1 + 4));
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&iStack_14);
    if (iVar1 != 0) {
      iVar1 = 0x89;
      goto _L0;
    }
    iStack_14 = CONCAT22(iStack_14._2_2_,*(undefined2 *)(unaff_s1 + 6));
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&iStack_14);
    if (iVar1 != 0) {
      iVar1 = 0x89;
      goto _L0;
    }
    iStack_14 = *(int *)(unaff_s1 + 8);
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),4,&iStack_14);
    if (iVar1 != 0) {
      iVar1 = 0x89;
      goto _L0;
    }
  }
  else {
    unaff_s1 = alarm_table_pop_oldest(*(undefined1 *)(param_1 + 0x15));
    if (unaff_s1 != 0) {
      iStack_14 = (uint)iStack_14._1_3_ << 8;
      iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&iStack_14);
      if (iVar1 != 0) {
        iVar1 = 0x89;
        goto _L0;
      }
      goto _L0;
    }
    iStack_14 = CONCAT31(iStack_14._1_3_,0x8b);
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&iStack_14);
    if (iVar1 != 0) {
      iVar1 = 0x89;
      goto _L0;
    }
  }
  iVar1 = zcl_packet_setup_response(param_2,param_1,1);
  if (iVar1 == 0) {
    return;
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,iVar1);
  return;
}

