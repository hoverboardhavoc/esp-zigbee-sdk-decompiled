/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_handle_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_pal_handle_tx_done(ezb_radio_frame_t *frame,ezb_radio_frame_t *ack,ezb_err_t tx_error)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  micro_timer_stop(&s_mac_pal_ctx);
  _Var1 = should_handle_csma_backoff();
  if (((CONCAT31(extraout_var,_Var1) == 0) || (tx_error != 0x1e1)) ||
     ((frame->info).tx.max_csma_backoffs <= s_mac_pal_ctx.csma_nb)) {
    s_mac_pal_ctx.csma_nb = '\0';
    _Var1 = should_handle_transmit_retries();
    if (((CONCAT31(extraout_var_00,_Var1) == 0) || (tx_error == 0)) ||
       ((frame->info).tx.max_frame_retries <= s_mac_pal_ctx.tx_retries)) {
      set_state(MAC_PAL_STATE_RECEIVE);
      mac_pal_callback_tx_done(frame,ack,tx_error);
    }
    else {
      s_mac_pal_ctx.tx_retries = s_mac_pal_ctx.tx_retries + '\x01';
      start_csma();
    }
  }
  else {
    s_mac_pal_ctx.csma_nb = s_mac_pal_ctx.csma_nb + '\x01';
    start_csma();
  }
  return;
}

