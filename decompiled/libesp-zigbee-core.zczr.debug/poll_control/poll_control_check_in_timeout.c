/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_check_in_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void poll_control_check_in_timeout(poll_control_srv_check_in_ctx_t *ctx)

{
  undefined1 auStack_28 [4];
  ezb_zcl_poll_control_check_in_cmd_t cmd_req;
  
  if (ctx != (poll_control_srv_check_in_ctx_t *)0x0) {
    auStack_28 = (undefined1  [4])0x0;
    cmd_req.cmd_ctrl.dst_addr._0_4_ = 0;
    cmd_req.cmd_ctrl._8_4_ = 0;
    cmd_req.cmd_ctrl.dis_default_rsp = false;
    cmd_req.cmd_ctrl._13_3_ = 0;
    cmd_req.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    cmd_req.cmd_ctrl.dst_addr.u._2_4_ = (uint)ctx->ep_id << 0x18;
    ezb_zcl_poll_control_check_in_cmd_req((ezb_zcl_poll_control_check_in_cmd_t *)auStack_28);
    nwk_pim_start_fast_poll(0);
    poll_control_check_in_start(ctx->ep_id);
  }
  return;
}

