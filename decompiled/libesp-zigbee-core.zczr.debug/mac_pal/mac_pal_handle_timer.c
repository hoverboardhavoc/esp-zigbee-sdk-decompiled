/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mac_pal_handle_timer(void)

{
  _Bool _Var1;
  undefined3 extraout_var;
  
  if (s_mac_pal_ctx.state == '\x03') {
    start_transmit();
  }
  else if ((s_mac_pal_ctx.state == '\x04') &&
          (_Var1 = should_handle_ack_timeout(), CONCAT31(extraout_var,_Var1) != 0)) {
    mac_pal_handle_tx_done(s_mac_pal_ctx.tx_frame,(ezb_radio_frame_t *)0x0,0x1e9);
  }
  return;
}

