/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_get_tx_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_radio_frame_t * mac_pal_get_tx_frame(void)

{
  ezb_radio_frame_t *peVar1;
  
  peVar1 = s_mac_pal_ctx.tx_frame;
  if (s_mac_pal_ctx.tx_frame == (ezb_radio_frame_t *)0x0) {
    peVar1 = (ezb_radio_frame_t *)__assert_func(0,0,0);
  }
  return peVar1;
}

