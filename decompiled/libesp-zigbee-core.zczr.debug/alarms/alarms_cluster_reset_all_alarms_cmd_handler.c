/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_reset_all_alarms_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarms_cluster_reset_all_alarms_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint unaff_s2;
  undefined4 local_30;
  undefined4 uStack_2c;
  int iStack_28;
  uint uStack_24;
  
  local_30 = 0;
  uStack_2c = 0;
  iStack_28 = 0;
  uStack_24 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1e7,
                  "alarms_cluster_reset_all_alarms_cmd_handler","packet && rsp");
  }
  else {
    unaff_s2 = zcl_packet_to_message(&local_30,param_1);
    if (unaff_s2 != 0) goto _L0;
  }
  uStack_24 = CONCAT31(uStack_24._1_3_,0xfe);
  iStack_28 = param_1;
  zcl_core_action_schedule(0x37,&local_30);
  uVar1 = uStack_24 & 0xff;
  if ((uStack_24 & 0xff) == 0xfe) {
    uVar1 = unaff_s2;
  }
  unaff_s2 = uVar1;
  iVar2 = alarm_table_reset(*(undefined1 *)(param_1 + 0x15));
  if (iVar2 == 0) {
    if ((char)uStack_24 == -2) {
      unaff_s2 = 1;
    }
  }
  else {
    unaff_s2 = 0x8b;
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,unaff_s2);
  return;
}

