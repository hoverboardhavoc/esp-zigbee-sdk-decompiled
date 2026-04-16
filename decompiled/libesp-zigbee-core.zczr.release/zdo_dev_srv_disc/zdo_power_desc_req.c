/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_power_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_power_desc_req(zdo_power_desc_req_t *req)

{
  int iVar1;
  zdp_status_t zVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined1 auStack_28 [4];
  zdo_packet_t packet;
  
  memset(auStack_28,0,0x18);
  if (req == (zdo_power_desc_req_t *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar3 = zdo_packet_init(auStack_28,3,req->dst_nwk_addr,req->cb,req->user_ctx);
    iVar1 = -1;
    if (iVar3 == 0) {
      zVar2 = zdo_op_active_ep_req((zdo_packet_payload_t *)packet.ctx.req_ctx.arg,&req->field,true);
      iVar1 = 1;
      if (CONCAT31(extraout_var,zVar2) == 0) {
        zdo_packet_send(auStack_28);
        iVar1 = zdp_status_to_err();
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
  zdo_packet_free(auStack_28);
  return iVar1;
}

