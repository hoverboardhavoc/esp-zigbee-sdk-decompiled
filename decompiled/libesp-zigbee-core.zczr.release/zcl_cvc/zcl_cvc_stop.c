/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cvc.o -> zcl_cvc_stop
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
    memset(cvc_ctx,0,0x40);
    return;
  }
  return;
}

