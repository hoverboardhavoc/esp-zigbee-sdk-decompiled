/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_handle_timer(void)

{
  int iVar1;
  
  if (s_mac_pal_ctx == '\x03') {
    start_transmit();
  }
  else if ((s_mac_pal_ctx == '\x04') && (iVar1 = should_handle_ack_timeout(), iVar1 != 0)) {
    mac_pal_handle_tx_done(DAT_00010a08,0,0x1e9);
  }
  return;
}

