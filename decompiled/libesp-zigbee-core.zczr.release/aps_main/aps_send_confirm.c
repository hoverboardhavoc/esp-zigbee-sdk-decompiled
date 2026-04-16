/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_send_confirm(zmsg_t *msg,ezb_err_t error)

{
  undefined4 uVar1;
  uint uVar2;
  zmsg_t *pzStack_48;
  aps_bind_trans_ctx_t bind_trans;
  aps_apsde_data_cnf_t cnf;
  aps_apsde_data_req_t req;
  
  zmsg_get_footer(&cnf.asdu,0x1c);
  zmsg_remove_footer(msg,0x1c);
  if ((msg->flags & 0x20) == 0) {
    uVar1 = zmsg_get_offset(msg);
    zmsg_remove_header(msg,uVar1);
    memcpy(&bind_trans,&req,10);
    cnf.cluster_id._0_1_ = (undefined1)error;
    cnf.dst_addr.u._4_2_ = req.dst_addr.u._4_2_;
    cnf._8_4_ = req._12_4_;
    cnf._16_4_ = msg;
    if ((req.radius & 0x20) == 0) {
      aps_apsde_data_confirm((aps_apsde_data_cnf_t *)&bind_trans);
    }
    else {
      aps_apsde_user_data_confirm((aps_apsde_data_cnf_t *)&bind_trans);
    }
  }
  else {
    pzStack_48 = (zmsg_t *)0x0;
    zmsg_get_footer(msg,&pzStack_48,4);
    zmsg_free(msg);
    if ((pzStack_48->flags & 0x20) == 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      bind_trans.orig_msg = (zmsg_t *)0x0;
      cnf.dst_addr._0_4_ = 0;
      cnf.dst_addr.u._2_4_ = 0;
      cnf._8_4_ = 0;
      zmsg_get_footer(&bind_trans,0x10);
    } while ((cnf._8_4_ & 0xff) == 0);
    uVar2 = (cnf._8_4_ & 0xff) - 1;
    cnf.dst_addr.u._6_1_ = (char)uVar2;
    if (error != 0) {
      cnf.dst_addr.u._2_4_ = error;
    }
    if ((((uVar2 & 0xff) == 0) && (cnf.dst_addr._0_4_ != 0)) &&
       (error = aps_bind_trans_schedule_next_nmsg
                          ((aps_bind_src_t *)bind_trans.orig_msg,
                           (aps_bind_dst_t *)cnf.dst_addr._0_4_,pzStack_48,
                           (uint8_t *)((int)&cnf.dst_addr.u + 6)), error != 0)) {
      cnf.dst_addr.u._2_4_ = 1;
    }
    if ((cnf._8_4_ & 0xff) == 0) {
      zmsg_remove_footer(pzStack_48,0x10);
      aps_send_confirm(pzStack_48,error);
    }
    else {
      zmsg_update_footer(&bind_trans,0x10);
    }
  }
  return;
}

