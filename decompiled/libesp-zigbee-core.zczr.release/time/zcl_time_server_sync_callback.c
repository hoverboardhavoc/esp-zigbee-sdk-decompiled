/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> zcl_time_server_sync_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_time_server_sync_callback(ezb_zdo_match_desc_req_result_t *rsp,void *user_ctx)

{
  uint uVar1;
  undefined1 extraout_a1;
  ezb_zdp_match_desc_rsp_field_t *peVar2;
  undefined4 uStack_48;
  undefined1 auStack_44 [2];
  ezb_shortaddr_t eStack_42;
  ezb_zcl_read_attr_cmd_t cmd;
  
  cmd.cmd_ctrl.dst_addr.u._5_1_ = SUB41(user_ctx,0);
  if (rsp == (ezb_zdo_match_desc_req_result_t *)0x0) {
    rsp = (ezb_zdo_match_desc_req_result_t *)__assert_func(0,0,0);
    cmd.cmd_ctrl.dst_addr.u._5_1_ = extraout_a1;
  }
  peVar2 = rsp->rsp;
  if (((peVar2 != (ezb_zdp_match_desc_rsp_field_t *)0x0) && (peVar2->status == '\0')) &&
     (peVar2->match_length != '\0')) {
    memset(auStack_44,0,0x20);
    eStack_42 = peVar2->nwk_addr_of_interest;
    auStack_44[0] = 2;
    cmd.cmd_ctrl.cnf_ctx.user_ctx._0_1_ = 2;
    uStack_48 = 0x10000;
    cmd.payload._0_4_ = &uStack_48;
    cmd.cmd_ctrl.dst_addr.u._6_2_ = 10;
    uVar1 = 0;
    while( true ) {
      if (rsp->rsp->match_length <= uVar1) break;
      cmd.cmd_ctrl.dst_addr.u._4_1_ = rsp->rsp->match_list[uVar1];
      uVar1 = uVar1 + 1 & 0xff;
      ezb_zcl_read_attr_cmd_req(auStack_44);
    }
  }
  return;
}

