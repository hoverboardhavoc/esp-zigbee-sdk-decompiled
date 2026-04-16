/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_simple_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_simple_desc_req(zdo_simple_desc_req_t *req)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined1 auStack_28 [4];
  zdo_packet_t packet;
  
  memset(auStack_28,0,0x18);
  if (req == (zdo_simple_desc_req_t *)0x0) {
_L0:
    iVar1 = 2;
  }
  else {
    iVar1 = zdo_packet_init(auStack_28,4,req->dst_nwk_addr,req->cb,req->user_ctx);
    if (iVar1 == 0) {
      if (packet.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
        __assert_func(0,0,0);
        goto _L0;
      }
      eVar2 = zmsg_append_le16((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).nwk_addr_of_interest);
      if ((eVar2 == 0) &&
         (eVar2 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).endpoint), eVar2 == 0
         )) {
        zdo_packet_send(auStack_28);
        iVar1 = zdp_status_to_err();
        if (iVar1 == 0) {
          return 0;
        }
        goto _L0;
      }
    }
    iVar1 = -1;
  }
_L0:
  zdo_packet_free(auStack_28);
  return iVar1;
}

