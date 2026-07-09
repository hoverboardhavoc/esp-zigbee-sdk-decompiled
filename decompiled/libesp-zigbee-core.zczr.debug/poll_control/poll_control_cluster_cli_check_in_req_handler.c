/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_cli_check_in_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cluster_cli_check_in_req_handler(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  ushort uStack_14;
  ushort auStack_12 [3];
  
  auStack_12[0] = 0;
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar2 = 0xfe;
  }
  else {
    iVar1 = zcl_message_notify_poll_control_check_in(auStack_12);
    if (iVar1 == 0) {
      auStack_12[0] = 0;
    }
    uStack_14 = CONCAT11(uStack_14._1_1_,iVar1 == 0);
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_14);
    if (iVar1 == 0) {
      uStack_14 = auStack_12[0];
      iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_14);
      if (iVar1 == 0) {
        poll_control_cli_initiate_fast_poll_timeout(param_1,(uint)auStack_12[0] * 0xfa);
        zcl_packet_setup_response(param_2,param_1,0);
        return;
      }
      uVar2 = 0x89;
    }
    else {
      uVar2 = 0x89;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

