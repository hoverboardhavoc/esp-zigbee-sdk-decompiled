/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_notify_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_packet_notify_result(zdo_packet_ctx_t *ctx,ezb_err_t error,void *rsp)

{
  zdo_packet_req_callback_t p_Var1;
  ezb_err_t eStack_18;
  zdo_req_result_t result;
  
  p_Var1 = (ctx->req_ctx).cb;
  if (p_Var1 != (zdo_packet_req_callback_t)0x0) {
    eStack_18 = error;
    result.error = (ezb_err_t)rsp;
    (*p_Var1)(&eStack_18,(ctx->req_ctx).arg);
    return;
  }
  return;
}

