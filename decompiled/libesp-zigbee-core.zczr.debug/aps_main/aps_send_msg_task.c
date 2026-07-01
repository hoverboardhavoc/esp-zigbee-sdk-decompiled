/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_msg_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_send_msg_task(aps_context *ctx)

{
  bool bVar1;
  uint uVar2;
  _Bool _Var3;
  _Bool _Var4;
  uint16_t uVar5;
  zmsg_t *msg;
  int iVar6;
  undefined2 extraout_var_01;
  uint uVar7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar8;
  undefined1 auStack_4c [4];
  aps_addr_t addr;
  aps_apsde_data_req_t req;
  ezb_shortaddr_t dst_addr;
  
  msg = (zmsg_t *)zmsg_queue_get_head(&ctx->tx_q);
  if (msg == (zmsg_t *)0x0) goto _L0;
  iVar6 = core_globals_get();
  zmsg_queue_dequeue(iVar6 + 0x2c,msg);
  zmsg_get_footer(msg,&req.field_0x1a,2);
  zmsg_remove_footer(msg,2);
  zmsg_get_footer(msg,&addr.cluster_id,0x1c);
  uVar5 = aps_get_max_asdu(false,(_Bool)((byte)req._20_4_ & 1),
                           (_Bool)((byte)((uint)req._20_4_ >> 3) & 1));
  uVar2 = CONCAT22(extraout_var_01,uVar5);
  uVar7 = zmsg_get_length(msg);
  bVar1 = uVar2 < uVar7;
  if (bVar1) {
    uVar2 = uVar2 - 2 & 0xffff;
  }
  if ((req._20_4_ & 0x10) == 0) {
    req.profile_id = aps_get_shortaddr();
  }
  auStack_4c._2_2_ = req._26_2_;
  if ((char)req.asdu != '\x01') {
    req.asdu._2_2_ = 0;
  }
  addr.dst_addr._0_1_ = req.dst_addr.u._4_1_;
  addr.dst_addr._1_1_ = req.dst_addr.u._5_1_;
  addr.grp_addr = req.dst_addr.u._6_2_;
  addr.src_ep = req.src_ep;
  addr.dst_ep = req.dst_ep;
  auStack_4c._0_2_ = req.profile_id;
  addr.src_addr = req.asdu._2_2_;
  zmsg_set_offset(msg,0);
  iVar6 = aps_frame_prepend_data_hdr
                    (msg,auStack_4c,(uint)req._20_4_ >> 1 & 1,req._20_4_ & 1,bVar1,
                     (uint)req._20_4_ >> 3 & 1);
  if (iVar6 == 0) {
    _Var3 = aps_is_shortaddr_loopback(req._26_2_);
    uVar8 = (CONCAT31(extraout_var,_Var3) ^ 1) & 0xff;
    _Var4 = aps_is_in_group(addr.src_addr);
    uVar7 = CONCAT31(extraout_var_00,_Var4);
    if ((uVar7 != 0) || (uVar7 = uVar8, CONCAT31(extraout_var,_Var3) != 0)) {
      aps_send_msg_loopback((aps_addr_t *)auStack_4c,msg);
    }
    if (uVar7 == 0) goto _L0;
    if ((req._20_4_ & 2) == 0) {
      iVar6 = aps_send_frame(req._26_2_,(aps_apsde_data_req_t *)&addr.cluster_id);
    }
    else {
      iVar6 = aps_retrans_send_msg(req._26_2_,uVar2 & 0xff,&addr.cluster_id);
    }
    if (iVar6 == 0) goto _L0;
  }
  aps_send_data_confirm(msg,iVar6);
_L0:
  if (msg != (zmsg_t *)0x0) {
    tasklet_post(ctx);
  }
  return;
}

