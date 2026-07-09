/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_reset_alarm_log_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarms_cluster_reset_alarm_log_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int extraout_a1;
  uint unaff_s2;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  uint uStack_34;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    alarm_table_reset(*(undefined1 *)(param_1 + 0x15));
    zcl_packet_setup_default_response(param_2,param_1,0);
    return;
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",500,
                        "alarms_cluster_reset_alarm_log_cmd_handler","packet && rsp");
  uStack_40 = 0;
  uStack_3c = 0;
  iStack_38 = 0;
  uStack_34 = 0;
  if ((iVar2 == 0) || (extraout_a1 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1e7,
                  "alarms_cluster_reset_all_alarms_cmd_handler","packet && rsp");
  }
  else {
    unaff_s2 = zcl_packet_to_message(&uStack_40,iVar2);
    if (unaff_s2 != 0) goto _L0;
  }
  uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
  iStack_38 = iVar2;
  zcl_core_action_schedule(0x37,&uStack_40);
  uVar1 = uStack_34 & 0xff;
  if ((uStack_34 & 0xff) == 0xfe) {
    uVar1 = unaff_s2;
  }
  unaff_s2 = uVar1;
  iVar3 = alarm_table_reset(*(undefined1 *)(iVar2 + 0x15));
  if (iVar3 == 0) {
    if ((char)uStack_34 == -2) {
      unaff_s2 = 1;
    }
  }
  else {
    unaff_s2 = 0x8b;
  }
_L0:
  zcl_packet_setup_default_response(extraout_a1,iVar2,unaff_s2);
  return;
}

