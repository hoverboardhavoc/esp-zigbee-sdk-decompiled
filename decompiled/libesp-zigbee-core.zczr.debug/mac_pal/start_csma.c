/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> start_csma
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_csma(void)

{
  uint8_t uVar1;
  _Bool _Var2;
  byte be;
  undefined3 extraout_var;
  byte bVar3;
  
  be = ((s_mac_pal_ctx.tx_frame)->info).tx.max_csma_be;
  uVar1 = ((s_mac_pal_ctx.tx_frame)->info).tx.max_csma_backoffs;
  bVar3 = s_mac_pal_ctx.csma_nb + ((s_mac_pal_ctx.tx_frame)->info).tx.min_csma_be;
  set_state(MAC_PAL_STATE_CSMA_BACKOFF);
  _Var2 = should_handle_csma_backoff();
  if ((CONCAT31(extraout_var,_Var2) == 0) || (uVar1 == '\0')) {
    start_transmit();
  }
  else {
    if (bVar3 < be) {
      be = bVar3;
    }
    start_timer_for_csma(be);
  }
  return;
}

