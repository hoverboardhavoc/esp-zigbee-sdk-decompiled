/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cvc.o -> zcl_cvc_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_cvc_stop(zcl_cvc_ctx_t *cvc_ctx)

{
  int iVar1;
  
  if (cvc_ctx != (zcl_cvc_ctx_t *)0x0) {
    iVar1 = milli_timer_is_running(&cvc_ctx->timer);
    if (iVar1 != 0) {
      milli_timer_stop(&cvc_ctx->timer);
    }
    memset(cvc_ctx,0,0x3c);
  }
  return;
}

