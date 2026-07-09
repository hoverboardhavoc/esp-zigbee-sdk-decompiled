/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_emergency_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_ace_cluster_emergency_cmd_handler(int param_1,undefined4 param_2)

{
  uint unaff_s1;
  undefined4 local_20;
  undefined4 uStack_1c;
  int iStack_18;
  uint uStack_14;
  
  local_20 = 0;
  uStack_1c = 0;
  iStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x123,
                  "ias_ace_cluster_emergency_cmd_handler","packet");
  }
  else {
    unaff_s1 = zcl_packet_to_message(&local_20,param_1);
    if (unaff_s1 != 0) goto _L0;
  }
  uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
  iStack_18 = param_1;
  zcl_core_action_schedule(0x1f,&local_20);
  if ((uStack_14 & 0xff) != 0xfe) {
    unaff_s1 = uStack_14 & 0xff;
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,unaff_s1);
  return;
}

