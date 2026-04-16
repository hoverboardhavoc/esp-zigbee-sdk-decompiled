/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_reset_to_factory_new_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_reset_to_factory_new_req(zcl_touchlink_reset_to_factory_new_req_t *cmd_req)

{
  ezb_err_t eVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (zcl_touchlink_reset_to_factory_new_req_t *)0x0) ||
     (iVar2 = zcl_packet_init(auStack_38,0), iVar2 != 0)) {
    eVar1 = -1;
  }
  else {
    memcpy(auStack_50,cmd_req,10);
    eVar3 = zcl_touchlink_cmd_to_packet
                      ((zcl_packet_t *)auStack_38,'\0','\a',(ezb_address_t *)cmd_req);
    eVar1 = 2;
    if ((eVar3 == 0) &&
       (eVar1 = zmsg_append_le32((zmsg_t *)packet._32_4_,cmd_req->transaction_id), eVar1 == 0)) {
      zcl_packet_intrp_send(auStack_38,&cmd_req->cnf_ctx);
      eVar1 = zcl_status_to_err();
      if (eVar1 == 0) {
        return 0;
      }
    }
  }
  zcl_packet_free(auStack_38);
  return eVar1;
}

