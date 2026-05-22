/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_get_tx_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_radio_frame_t * mac_pal_get_tx_frame(void)

{
  ezb_radio_frame_t *frame;
  ezb_radio_frame_t *extraout_a0;
  
  if (s_mac_pal_ctx.tx_frame != (ezb_radio_frame_t *)0x0) {
    return s_mac_pal_ctx.tx_frame;
  }
  frame = (ezb_radio_frame_t *)
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x1a0,
                        "mac_pal_get_tx_frame","s_mac_pal_ctx.tx_frame != ((void *)0)");
  mac_pal_handle_tx_started(frame);
  return extraout_a0;
}

