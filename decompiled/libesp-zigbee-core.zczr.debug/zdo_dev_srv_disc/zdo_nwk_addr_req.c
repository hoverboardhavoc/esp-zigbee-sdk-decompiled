/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_nwk_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_nwk_addr_req(zdo_nwk_addr_req_t *req)

{
  zdp_status_t zVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uStack_28;
  zdo_packet_t packet;
  
  uStack_28 = 0;
  packet.tsn = '\0';
  packet._1_1_ = 0;
  packet.dst_addr = 0;
  packet.src_addr = 0;
  packet.cluster_id = 0;
  packet.ctx.mode = '\0';
  packet.ctx._1_3_ = 0;
  packet.ctx.req_ctx.cb = (zdo_packet_req_callback_t)0x0;
  packet.ctx.req_ctx.arg = (zdo_packet_user_ctx_t)0x0;
  if (req == (zdo_nwk_addr_req_t *)0x0) {
    iVar2 = 2;
  }
  else {
    iVar2 = zdo_packet_init(&uStack_28,0,req->dst_nwk_addr,req->cb,req->user_ctx);
    if (iVar2 == 0) {
      zVar1 = zdo_op_nwk_addr_req((zdo_packet_payload_t *)packet.ctx.req_ctx.arg,&req->field,true);
      if (CONCAT31(extraout_var,zVar1) == 0) {
        zdo_packet_send(&uStack_28);
        iVar2 = zdp_status_to_err();
        if (iVar2 == 0) {
          return 0;
        }
      }
      else {
        iVar2 = 1;
      }
    }
  }
  zdo_packet_free(&uStack_28);
  return iVar2;
}

