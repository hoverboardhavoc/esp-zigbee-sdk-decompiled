/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_device_annce_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_device_annce_req(zdo_device_annce_req_t *req)

{
  zdo_packet_user_ctx_t msg;
  ezb_err_t eVar1;
  uint16_t val;
  int iVar2;
  int iVar3;
  undefined1 auStack_28 [4];
  zdo_packet_t packet;
  
  memset(auStack_28,0,0x18);
  if (req == (zdo_device_annce_req_t *)0x0) {
    eVar1 = 2;
    goto _L0;
  }
  iVar2 = zdo_packet_init(auStack_28,0x13,0xfffd,req->cb,req->user_ctx);
  if (iVar2 == 0) {
    iVar2 = af_get_node_desc();
    if (iVar2 == 0) {
      eVar1 = 5;
      goto _L0;
    }
    iVar3 = nwk_get_extended_address();
    msg = packet.ctx.req_ctx.arg;
    if (iVar3 != 0) {
      val = nwk_get_short_address();
      eVar1 = zmsg_append_le16((zmsg_t *)msg,val);
      if (((eVar1 == 0) && (eVar1 = zmsg_append_bytes(packet.ctx.req_ctx.arg,8,iVar3), eVar1 == 0))
         && (eVar1 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,*(uint8_t *)(iVar2 + 2)),
            eVar1 == 0)) {
        zdo_packet_send(auStack_28);
        eVar1 = zdp_status_to_err();
        if (eVar1 == 0) {
          return 0;
        }
      }
      goto _L0;
    }
  }
  eVar1 = -1;
_L0:
  zdo_packet_free(auStack_28);
  return eVar1;
}

