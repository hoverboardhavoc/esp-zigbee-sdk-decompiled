/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> ezb_plat_radio_transmit_started
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_plat_radio_transmit_started(undefined4 *param_1)

{
  if (((s_mac_pal_ctx & 1) == 0) && ((*(ushort *)*param_1 & 0x20) != 0)) {
    micro_timer_start(&s_mac_pal_ctx,0x360);
    return;
  }
  return;
}

