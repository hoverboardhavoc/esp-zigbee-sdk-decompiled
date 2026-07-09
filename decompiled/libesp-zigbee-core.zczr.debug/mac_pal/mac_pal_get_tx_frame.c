/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_get_tx_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_get_tx_frame(void)

{
  if (DAT_00010918 != 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x1a0,
                "mac_pal_get_tx_frame","s_mac_pal_ctx.tx_frame != ((void *)0)");
  mac_pal_handle_tx_started();
  return;
}

