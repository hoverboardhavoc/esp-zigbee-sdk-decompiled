/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_scan_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_scan_req(zcl_touchlink_scan_req_t *cmd_req)

{
  ezb_address_t *unaff_s1;
  ezb_err_t eVar1;
  int iVar2;
  uint32_t auStack_48 [2];
  ezb_address_t dst_addr;
  zcl_packet_t packet;
  
  stack0xffffffc8 = 0;
  if (cmd_req == (zcl_touchlink_scan_req_t *)0x0) {
    eVar1 = -1;
  }
  else {
    iVar2 = zcl_packet_init((undefined1 *)((int)&dst_addr.u + 6),0);
    if (iVar2 == 0) {
      dst_addr._0_4_ = 0;
      dst_addr.u.group_addr.bcast = 0;
      auStack_48[1] = 0xffff0002;
      eVar1 = zcl_touchlink_cmd_to_packet((zcl_packet_t *)((int)&dst_addr.u + 6),'\0','\0',unaff_s1)
      ;
      if (eVar1 == 0) {
        auStack_48[0] = cmd_req->transaction_id;
        eVar1 = zmsg_append_bytes(0,4,auStack_48);
        if (eVar1 == 0) {
          auStack_48[0] = CONCAT31(auStack_48[0]._1_3_,cmd_req->zigbee_info);
          eVar1 = zmsg_append_bytes(0,1,auStack_48);
          if (eVar1 == 0) {
            auStack_48[0] = CONCAT31(auStack_48[0]._1_3_,cmd_req->touchlink_info);
            eVar1 = zmsg_append_bytes(0,1,auStack_48);
            if (eVar1 == 0) {
              zcl_packet_intrp_send((undefined1 *)((int)&dst_addr.u + 6),&cmd_req->cnf_ctx);
              eVar1 = zcl_status_to_err();
              if (eVar1 == 0) {
                return 0;
              }
            }
          }
        }
      }
    }
    else {
      eVar1 = -1;
    }
  }
  zcl_packet_free((undefined1 *)((int)&dst_addr.u + 6));
  return eVar1;
}

