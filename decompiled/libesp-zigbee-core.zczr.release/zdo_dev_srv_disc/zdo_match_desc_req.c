/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_match_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_match_desc_req(zdo_match_desc_req_t *req)

{
  int iVar1;
  ezb_err_t eVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_38 [4];
  zdo_packet_t packet;
  
  memset(auStack_38,0,0x18);
  if ((req == (zdo_match_desc_req_t *)0x0) || ((req->field).cluster_list == (uint16_t *)0x0)) {
    iVar3 = 2;
    goto _L0;
  }
  iVar1 = zdo_packet_init(auStack_38,6,req->dst_nwk_addr,req->cb,req->user_ctx);
  iVar3 = -1;
  if (iVar1 != 0) goto _L0;
  if (packet.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
    __assert_func(0,0,0);
_L0:
    eVar2 = zmsg_append_le16((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).profile_id);
    if (eVar2 == 0) {
      uVar4 = 0;
      eVar2 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).num_in_clusters);
      if (eVar2 == 0) {
        for (; uVar4 < (req->field).num_in_clusters; uVar4 = uVar4 + 1 & 0xff) {
          eVar2 = zmsg_append_le16((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).cluster_list[uVar4]
                                  );
          if (eVar2 != 0) goto _L0;
        }
        eVar2 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).num_out_clusters);
        uVar4 = 0;
        if (eVar2 == 0) {
          for (; uVar4 < (req->field).num_out_clusters; uVar4 = uVar4 + 1 & 0xff) {
            eVar2 = zmsg_append_le16((zmsg_t *)packet.ctx.req_ctx.arg,
                                     (req->field).cluster_list[(req->field).num_in_clusters + uVar4]
                                    );
            if (eVar2 != 0) goto _L0;
          }
          zdo_packet_send(auStack_38);
          iVar3 = zdp_status_to_err();
          if (iVar3 == 0) {
            return 0;
          }
          goto _L0;
        }
      }
    }
  }
  else {
    eVar2 = zmsg_append_le16((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).nwk_addr_of_interest);
    if (eVar2 == 0) goto _L0;
  }
_L0:
  iVar3 = 1;
_L0:
  zdo_packet_free(auStack_38);
  return iVar3;
}

