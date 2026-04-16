/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_parent_annce_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t zdo_parent_annce_req(zdo_parent_annce_req_t *req)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint local_30;
  ezb_extaddr_t nbr_ieee_addr;
  zdo_packet_t packet;
  
  nbr_ieee_addr.field_0.u64._4_4_ = 0;
  if (req == (zdo_parent_annce_req_t *)0x0) {
    iVar2 = 2;
  }
  else if ((req->dst_nwk_addr == 0xfffc) || (req->dst_nwk_addr < 0xfff8)) {
    iVar2 = zdo_packet_init((undefined1 *)((int)&nbr_ieee_addr.field_0 + 4),0x1f,req->cb,
                            req->user_ctx);
    if (iVar2 == 0) {
      iVar2 = nwk_is_device_zczr();
      if (iVar2 == 0) {
        iVar2 = 5;
      }
      else {
        local_30 = local_30 & 0xffffff00;
        iVar2 = zmsg_append_bytes(0,1,&local_30);
        if (iVar2 != 0) goto _L0;
        iVar1 = 0;
        cVar3 = '\0';
        while (iVar1 = nwk_neighbor_table_next(iVar1), iVar1 != 0) {
          if ((*(uint *)(iVar1 + 0xc) & 3) == 2) {
            local_30 = 0;
            nbr_ieee_addr.field_0.u64._0_4_ = 0;
            nwk_neighbor_get_extaddr(iVar1,&local_30);
            iVar2 = zmsg_append_bytes(0,8,&local_30);
            if (iVar2 != 0) goto _L0;
            cVar3 = cVar3 + '\x01';
          }
        }
        local_30 = CONCAT31(local_30._1_3_,cVar3);
        zmsg_write_bytes(0,0,1,&local_30);
        if (cVar3 == '\0') {
          iVar2 = 5;
          goto _L0;
        }
        zdo_packet_send((undefined1 *)((int)&nbr_ieee_addr.field_0 + 4));
        iVar2 = zdp_status_to_err();
      }
_L0:
      if (iVar2 == 0) {
        return 0;
      }
    }
    else {
      iVar2 = -1;
    }
  }
  else {
    iVar2 = 2;
  }
_L0:
  zdo_packet_free((undefined1 *)((int)&nbr_ieee_addr.field_0 + 4));
  return iVar2;
}

