/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cli_stop_fast_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void poll_control_cli_stop_fast_poll(zcl_packet_t *packet)

{
  undefined1 auStack_28 [4];
  ezb_zcl_poll_control_fast_poll_stop_cmd_t cmd_req;
  
  cmd_req.cmd_ctrl._8_4_ = 0;
  cmd_req.cmd_ctrl.dis_default_rsp = false;
  cmd_req.cmd_ctrl._13_3_ = 0;
  cmd_req.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  memcpy(auStack_28,packet,10);
  cmd_req.cmd_ctrl.dst_addr.u._4_1_ = (packet->header).src_ep;
  cmd_req.cmd_ctrl.dst_addr.u._5_1_ = (packet->header).dst_ep;
  ezb_zcl_poll_control_fast_poll_stop_cmd_req
            ((ezb_zcl_poll_control_fast_poll_stop_cmd_t *)auStack_28);
  mm_free(packet->payload);
  mm_free(packet);
  return;
}

