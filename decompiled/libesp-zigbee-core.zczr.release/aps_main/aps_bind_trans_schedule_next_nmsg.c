/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_bind_trans_schedule_next_nmsg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_bind_trans_schedule_next_nmsg
                    (aps_bind_src_t *src,aps_bind_dst_t *dst,zmsg_t *msg,uint8_t *bind_trans_cnt)

{
  nwk_addr_ref_t nVar1;
  uint8_t uVar2;
  zmsg_t *pzVar3;
  int iVar4;
  ezb_err_t eVar5;
  zmsg_t *local_50;
  aps_bind_trans_ctx_t bt_ctx;
  aps_apsde_data_req_t req;
  
  local_50 = msg;
  memset(&bt_ctx,0,0x1c);
  zmsg_get_footer(msg,&bt_ctx,0x1c);
  uVar2 = '\0';
  while (((dst = (aps_bind_dst_t *)aps_bind_table_next_dst_by_src(src,dst),
          dst != (aps_bind_dst_t *)0x0 &&
          (pzVar3 = (zmsg_t *)zmsg_clone(msg), pzVar3 != (zmsg_t *)0x0)) &&
         (iVar4 = zmsg_add_footer(&local_50,4), iVar4 == 0))) {
    nVar1 = (dst->field_0).extaddr.addr_ref;
    pzVar3->flags = pzVar3->flags | 0x20;
    if ((dst->field_0x5 & 1) == 0) {
      req.asdu = (zmsg_t *)CONCAT31(req.asdu._1_3_,3);
      iVar4 = nwk_address_extended_by_ref((undefined1 *)((int)&req.asdu + 2));
      if (iVar4 != 0) {
        __assert_func(0,0,0,0);
      }
      req.dst_addr.u._5_1_ = (dst->field_0).extaddr.endpoint;
    }
    else {
      req.dst_addr.u.group_addr.bcast = 0;
      req.asdu = (zmsg_t *)CONCAT22(nVar1,1);
      req.dst_addr._0_4_ = 0xffff;
      req.dst_addr.u._5_1_ = '\0';
    }
    bt_ctx.orig_msg = pzVar3;
    eVar5 = aps_apsde_data_request((aps_apsde_data_req_t *)&bt_ctx);
    if (eVar5 == 0) {
      uVar2 = uVar2 + '\x01';
    }
  }
  if (uVar2 != '\0') {
    *bind_trans_cnt = uVar2;
  }
  return (uint)(uVar2 == '\0');
}

