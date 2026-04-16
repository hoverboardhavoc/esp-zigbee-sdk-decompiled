/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_parent_annce_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_parent_annce_req(zdo_parent_annce_req_t *req)

{
  ezb_err_t eVar1;
  char cVar2;
  int iVar3;
  undefined4 local_40;
  ezb_extaddr_t nbr_ieee_addr;
  zdo_packet_t packet;
  
  memset((void *)((int)&nbr_ieee_addr.field_0 + 4),0,0x18);
  if ((req == (zdo_parent_annce_req_t *)0x0) ||
     ((req->dst_nwk_addr != 0xfffc && (0xfff7 < req->dst_nwk_addr)))) {
    eVar1 = 2;
  }
  else {
    iVar3 = zdo_packet_init((undefined1 *)((int)&nbr_ieee_addr.field_0 + 4),0x1f,req->cb,
                            req->user_ctx);
    eVar1 = -1;
    if (iVar3 == 0) {
      iVar3 = nwk_is_device_zczr();
      if (iVar3 != 0) {
        eVar1 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,'\0');
        if (eVar1 != 0) goto _L0;
        iVar3 = 0;
        cVar2 = '\0';
        while (iVar3 = nwk_neighbor_table_next(iVar3), iVar3 != 0) {
          if ((*(uint *)(iVar3 + 0xc) & 3) == 2) {
            local_40 = 0;
            nbr_ieee_addr.field_0.u64._0_4_ = 0;
            nwk_neighbor_get_extaddr(&local_40);
            eVar1 = zmsg_append_bytes(packet.ctx.req_ctx.arg,8,&local_40);
            if (eVar1 != 0) goto _L0;
            cVar2 = cVar2 + '\x01';
          }
        }
        local_40 = CONCAT31(local_40._1_3_,cVar2);
        zmsg_write_bytes(packet.ctx.req_ctx.arg,0,1,&local_40);
        if (cVar2 != '\0') {
          zdo_packet_send((undefined1 *)((int)&nbr_ieee_addr.field_0 + 4));
          eVar1 = zdp_status_to_err();
          if (eVar1 == 0) {
            return 0;
          }
          goto _L0;
        }
      }
      eVar1 = 5;
    }
  }
_L0:
  zdo_packet_free((undefined1 *)((int)&nbr_ieee_addr.field_0 + 4));
  return eVar1;
}

