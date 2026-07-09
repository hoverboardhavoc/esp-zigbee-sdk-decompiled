/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_pal_transmit(void)

{
  if (((char)s_mac_pal_ctx != '\0') && ((char)s_mac_pal_ctx != '\x05')) {
    s_mac_pal_ctx._1_1_ = 0;
    DAT_0001057a = 0;
    start_csma(3);
    return 0;
  }
  return 3;
}

