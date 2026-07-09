/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> door_lock_cluster_lock_door_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void door_lock_cluster_lock_door_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined1 uStack_21;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  iStack_18 = 0;
  uStack_14 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/door_lock.c",0x72,
                  "door_lock_cluster_lock_door_cmd_handler","packet && rsp");
  }
  else {
    uVar1 = zcl_packet_to_message(&uStack_20,param_1);
    if (uVar1 != 0) goto _L0;
  }
  uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
  iStack_18 = param_1;
  zcl_core_action_schedule(0x17,&uStack_20);
  uStack_21 = (char)uStack_14 != '\0';
  uVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_21);
  uVar1 = uVar1 & 0xff;
  if ((uVar1 == 0) && (uVar1 = zcl_packet_setup_response(param_2,param_1,0), uVar1 == 0)) {
    return;
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

