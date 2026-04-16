/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t zdo_nwk_mgmt_leave_req(zdo_nwk_mgmt_leave_req_t *req)

{
  int iVar1;
  int iVar2;
  ezb_err_t eVar3;
  ezb_zdp_nwk_mgmt_leave_req_field_t *peVar4;
  uint unaff_s2;
  undefined1 auStack_28 [4];
  zdo_packet_t packet;
  
  memset(auStack_28,0,0x18);
  if (req == (zdo_nwk_mgmt_leave_req_t *)0x0) {
    iVar1 = 2;
    goto _L0;
  }
  iVar2 = zdo_packet_init(auStack_28,0x34,req->dst_nwk_addr,req->cb,req->user_ctx);
  iVar1 = -1;
  if (iVar2 != 0) goto _L0;
  peVar4 = &req->field;
  if (packet.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
    __assert_func(0,0,0);
_L0:
    eVar3 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,
                           (byte)((int)req << 7) | (byte)(unaff_s2 << 6));
    if (eVar3 == 0) {
      zdo_packet_send(auStack_28);
      iVar1 = zdp_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
      goto _L0;
    }
  }
  else {
    unaff_s2 = (uint)(req->field).remove_children;
    req = (zdo_nwk_mgmt_leave_req_t *)(uint)(req->field).rejoin;
    iVar1 = zmsg_append_bytes(packet.ctx.req_ctx.arg,8,peVar4);
    if (iVar1 == 0) goto _L0;
  }
  iVar1 = 1;
_L0:
  zdo_packet_free(auStack_28);
  return iVar1;
}

