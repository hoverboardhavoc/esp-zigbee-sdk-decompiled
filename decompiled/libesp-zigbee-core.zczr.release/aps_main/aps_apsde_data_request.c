/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_apsde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: zdo_req */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t aps_apsde_data_request(aps_apsde_data_req_t *req)

{
  ushort uVar1;
  ezb_addr_t *__src;
  ezb_err_t eVar2;
  int iVar3;
  uint uVar4;
  zmsg_t *pzVar5;
  ezb_shortaddr_t local_26;
  aps_bind_src_t *paStack_24;
  ezb_shortaddr_t dst_addr;
  zdo_nwk_addr_req_t zdo_req;
  
  eVar2 = 2;
  if (req == (aps_apsde_data_req_t *)0x0) {
    return 2;
  }
  pzVar5 = req->asdu;
  if (pzVar5 == (zmsg_t *)0x0) {
    return 2;
  }
  uVar4 = (uint)(req->dst_addr).addr_mode;
  if (uVar4 == 2) {
    uVar1 = (req->dst_addr).u.short_addr;
_L0:
    local_26 = uVar1;
    eVar2 = apsde_data_request_continue(req,local_26);
    iVar3 = eVar2;
  }
  else if (uVar4 < 3) {
    if (uVar4 != 0) {
      uVar1 = (req->dst_addr).u.group_addr.bcast;
      if ((uVar1 < 0xfff8) || (uVar1 == 0xfffe)) goto _L0;
      goto _L0;
    }
    uVar4 = pzVar5->flags & 0x20;
    if ((pzVar5->flags & 0x20) != 0) {
      eVar2 = __assert_func(0,0,0,0);
      goto _L0;
    }
    paStack_24 = (aps_bind_src_t *)0x0;
    zdo_req._0_4_ = 0;
    zdo_req.field.ieee_addr_of_interest.field_0.u64._2_4_ = 0;
    zdo_req.field._6_4_ = 0;
    nwk_get_extended_address();
    eVar2 = 0x3a8;
    paStack_24 = (aps_bind_src_t *)aps_bind_table_find_src(req->src_ep,req->cluster_id);
    if (((paStack_24 == (aps_bind_src_t *)0x0) ||
        (eVar2 = zmsg_add_footer(req->asdu,req,0x1c), eVar2 != 0)) ||
       (eVar2 = aps_bind_trans_schedule_next_nmsg
                          (paStack_24,(aps_bind_dst_t *)zdo_req._0_4_,req->asdu,
                           zdo_req.field.ieee_addr_of_interest.field_0.u8 + 6), eVar2 != 0))
    goto _L0;
    eVar2 = zmsg_add_footer(req->asdu,&stack0xffffffdc,0x10);
    iVar3 = eVar2;
  }
  else {
_L0:
    if (uVar4 != 3) goto _L0;
    __src = &(req->dst_addr).u;
    iVar3 = nwk_address_short_by_extended(__src,&local_26);
    uVar1 = local_26;
    if (iVar3 == 0) goto _L0;
    zmsg_add_footer(pzVar5,req,0x1c);
    paStack_24 = (aps_bind_src_t *)CONCAT22(dst_addr,0xffff);
    zdo_req.field.ieee_addr_of_interest.field_0.u64._2_4_ =
         zdo_req.field.ieee_addr_of_interest.field_0.u64._2_4_ & 0xffff;
    memcpy(&dst_addr,__src,8);
    zdo_req.field._6_4_ = apsde_handle_nwk_addr_req_result;
    zdo_req.cb = (ezb_zdo_nwk_addr_req_callback_t)pzVar5;
    iVar3 = zdo_nwk_addr_req(&stack0xffffffdc);
    eVar2 = 0x3a9;
  }
  if (iVar3 == 0) {
    return 0;
  }
_L0:
  zmsg_free(pzVar5);
  return eVar2;
}

