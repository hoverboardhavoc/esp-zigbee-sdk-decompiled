/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_core.o -> zdo_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_confirm_handler(af_data_cnf_t *cnf,af_user_cnf_ctx_t *ctx)

{
  undefined1 auStack_24 [4];
  zdo_cmd_cnf_t info;
  
  if (((cnf != (af_data_cnf_t *)0x0) && (ctx != (af_user_cnf_ctx_t *)0x0)) &&
     (ctx->cb != (ezb_af_user_cnf_callback_t)0x0)) {
    info._0_4_ = (cnf->dst_addr).u.group_addr;
    info.dst_addr.u.group_addr = *(ezb_grpaddr_t *)((int)&(cnf->dst_addr).u + 4);
    auStack_24[1] = 0;
    auStack_24[0] = cnf->status;
    auStack_24._2_2_ = *(undefined2 *)&cnf->dst_addr;
    info._12_2_ = cnf->profile_id;
    info.dst_addr.u._4_1_ = cnf->src_ep;
    info.dst_addr.u._5_1_ = cnf->dst_ep;
    info.dst_addr.u._6_2_ = cnf->cluster_id;
    zmsg_read_bytes(cnf->asdu,0,1,auStack_24 + 1);
    (*ctx->cb)((ezb_af_user_cnf_t *)auStack_24,ctx->user_ctx);
  }
  return;
}

