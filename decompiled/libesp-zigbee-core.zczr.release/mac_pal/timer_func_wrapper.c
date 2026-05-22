/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> timer_func_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void timer_func_wrapper(void *ctx)

{
  if (s_mac_pal_ctx.state == '\x03') {
    start_transmit();
    return;
  }
  if (s_mac_pal_ctx.state != '\x04') {
    return;
  }
  if ((s_mac_pal_ctx.radio_caps & 1) == 0) {
    mac_pal_handle_tx_done(s_mac_pal_ctx.tx_frame,(ezb_radio_frame_t *)0x0,0x1e9);
    return;
  }
  return;
}

