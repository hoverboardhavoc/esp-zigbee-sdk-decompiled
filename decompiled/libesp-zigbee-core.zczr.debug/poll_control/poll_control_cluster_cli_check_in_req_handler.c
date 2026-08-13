/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_cli_check_in_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cluster_cli_check_in_req_handler(int param_1,int param_2)

{
  int iVar1;
  ushort uStack_16;
  ushort uStack_14;
  char acStack_11 [5];
  
  acStack_11[0] = '\0';
  uStack_14 = 0;
  if (param_1 == 0) {
    iVar1 = 0xfe;
  }
  else if (param_2 == 0) {
    iVar1 = 0xfe;
  }
  else {
    iVar1 = zcl_message_notify_poll_control_check_in(acStack_11,&uStack_14);
    if (iVar1 == 0) {
      uStack_16 = CONCAT11(uStack_16._1_1_,acStack_11[0]);
      iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_16);
      if (iVar1 == 0) {
        uStack_16 = uStack_14;
        iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_16);
        if (iVar1 == 0) {
          if ((acStack_11[0] != '\0') && (uStack_14 != 0)) {
            poll_control_cli_initiate_fast_poll_timeout(param_1,(uint)uStack_14 * 0xfa);
          }
          zcl_packet_setup_response(param_2,param_1,0);
          return;
        }
        iVar1 = 0x89;
      }
      else {
        iVar1 = 0x89;
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,iVar1);
  return;
}

