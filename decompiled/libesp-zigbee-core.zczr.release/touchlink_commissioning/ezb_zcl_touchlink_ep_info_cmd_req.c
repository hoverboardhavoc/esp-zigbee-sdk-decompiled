/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_commissioning.o -> ezb_zcl_touchlink_ep_info_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_touchlink_ep_info_cmd_req(ezb_zcl_touchlink_ep_info_cmd_req_t *cmd_req)

{
  int iVar1;
  undefined1 auStack_50 [16];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (ezb_zcl_touchlink_ep_info_cmd_req_t *)0x0) ||
     (iVar1 = zcl_packet_init(auStack_38,0), iVar1 != 0)) {
    iVar1 = 2;
  }
  else {
    memcpy(auStack_50,cmd_req,10);
    iVar1 = zcl_cmd_to_packet(auStack_38,1,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,0x40,0x1000);
    if (iVar1 == 0) {
      uStack_40 = *(undefined4 *)&(cmd_req->ieee_addr).field_0;
      uStack_3c = *(undefined4 *)((int)&(cmd_req->ieee_addr).field_0 + 4);
      iVar1 = zmsg_append_bytes(packet._32_4_,8,&uStack_40);
      if ((((iVar1 == 0) &&
           (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,cmd_req->nwk_addr), iVar1 == 0)) &&
          (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_req->ep_id), iVar1 == 0)) &&
         (((iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,cmd_req->profile_id), iVar1 == 0 &&
           (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,cmd_req->device_id), iVar1 == 0)) &&
          (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_req->device_version & 0xf), iVar1 == 0
          )))) {
        zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
        iVar1 = zcl_status_to_err();
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}

