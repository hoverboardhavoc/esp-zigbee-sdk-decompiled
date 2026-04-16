/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> ezb_plat_radio_transmit_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_transmit_done
               (ezb_radio_frame_t *frame,ezb_radio_frame_t *ack,ezb_err_t tx_error)

{
  micro_timer_stop(&s_mac_pal_ctx);
  s_mac_pal_ctx.state = '\0';
  set_state(MAC_PAL_STATE_RECEIVE);
  mac_pal_callback_tx_done(frame,ack,tx_error);
  return;
}

