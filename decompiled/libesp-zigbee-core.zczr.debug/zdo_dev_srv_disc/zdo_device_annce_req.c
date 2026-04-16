/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_device_annce_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t zdo_device_annce_req(zdo_device_annce_req_t *req)

{
  zdo_packet_user_ctx_t pvVar1;
  ezb_err_t eVar2;
  int iVar3;
  int iVar4;
  undefined2 uStack_2a;
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
  if (req == (zdo_device_annce_req_t *)0x0) {
    eVar2 = 2;
  }
  else {
    iVar3 = zdo_packet_init(&uStack_28,0x13,0xfffd,req->cb,req->user_ctx);
    if (iVar3 == 0) {
      iVar3 = af_get_node_desc();
      if (iVar3 == 0) {
        eVar2 = 5;
      }
      else {
        iVar4 = nwk_get_extended_address();
        pvVar1 = packet.ctx.req_ctx.arg;
        if (iVar4 == 0) {
          eVar2 = -1;
        }
        else {
          uStack_2a = nwk_get_short_address();
          eVar2 = zmsg_append_bytes(pvVar1,2,&uStack_2a);
          if ((eVar2 == 0) &&
             (eVar2 = zmsg_append_bytes(packet.ctx.req_ctx.arg,8,iVar4), eVar2 == 0)) {
            uStack_2a = CONCAT11(uStack_2a._1_1_,*(undefined1 *)(iVar3 + 2));
            eVar2 = zmsg_append_bytes(packet.ctx.req_ctx.arg,1,&uStack_2a);
            if (eVar2 == 0) {
              zdo_packet_send(&uStack_28);
              eVar2 = zdp_status_to_err();
              if (eVar2 == 0) {
                return 0;
              }
            }
          }
        }
      }
    }
    else {
      eVar2 = -1;
    }
  }
  zdo_packet_free(&uStack_28);
  return eVar2;
}

