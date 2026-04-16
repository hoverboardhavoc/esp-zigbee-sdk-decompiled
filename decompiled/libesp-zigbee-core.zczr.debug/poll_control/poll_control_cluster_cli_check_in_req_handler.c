/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_cli_check_in_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
poll_control_cluster_cli_check_in_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  ushort uStack_14;
  uint16_t auStack_12 [2];
  uint16_t fast_poll_timeout;
  
  auStack_12[0] = 0;
  if (packet == (zcl_packet_t *)0x0) {
    uVar3 = 0xfe;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    uVar3 = 0xfe;
  }
  else {
    eVar1 = zcl_message_notify_poll_control_check_in(packet,auStack_12);
    if (CONCAT31(extraout_var,eVar1) == 0) {
      auStack_12[0] = 0;
    }
    uStack_14 = CONCAT11(uStack_14._1_1_,CONCAT31(extraout_var,eVar1) == 0);
    iVar2 = zmsg_append_bytes(rsp->payload,1,&uStack_14);
    if (iVar2 == 0) {
      uStack_14 = auStack_12[0];
      iVar2 = zmsg_append_bytes(rsp->payload,2,&uStack_14);
      if (iVar2 == 0) {
        poll_control_cli_initiate_fast_poll_timeout(packet,(uint)auStack_12[0] * 0xfa);
        eVar1 = zcl_packet_setup_response(rsp,packet,0);
        return eVar1;
      }
      uVar3 = 0x89;
    }
    else {
      uVar3 = 0x89;
    }
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar1;
}

