/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_scan_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_scan_req(zcl_touchlink_scan_req_t *cmd_req)

{
  ezb_err_t eVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined1 auStack_60 [28];
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined2 uStack_42;
  ezb_address_t dst_addr;
  zcl_packet_t packet;
  
  memset((void *)((int)&dst_addr.u + 6),0,0x28);
  if ((cmd_req == (zcl_touchlink_scan_req_t *)0x0) ||
     (iVar2 = zcl_packet_init((undefined1 *)((int)&dst_addr.u + 6),0), iVar2 != 0)) {
    eVar1 = -1;
  }
  else {
    memset(&uStack_43,0,9);
    eVar1 = 2;
    uStack_44 = 2;
    uStack_42 = 0xffff;
    memcpy(auStack_60,&uStack_44,10);
    eVar3 = zcl_touchlink_cmd_to_packet
                      ((zcl_packet_t *)((int)&dst_addr.u + 6),'\0','\0',(ezb_address_t *)cmd_req);
    if ((((eVar3 == 0) &&
         (eVar1 = zmsg_append_le32((zmsg_t *)packet._32_4_,cmd_req->transaction_id), eVar1 == 0)) &&
        (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_req->zigbee_info), eVar1 == 0)) &&
       (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_req->touchlink_info), eVar1 == 0)) {
      zcl_packet_intrp_send((undefined1 *)((int)&dst_addr.u + 6),&cmd_req->cnf_ctx);
      eVar1 = zcl_status_to_err();
      if (eVar1 == 0) {
        return 0;
      }
    }
  }
  zcl_packet_free((undefined1 *)((int)&dst_addr.u + 6));
  return eVar1;
}

