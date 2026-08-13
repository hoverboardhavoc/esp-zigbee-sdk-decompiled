/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> ezb_plat_radio_transmit_started
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ezb_plat_radio_transmit_started(undefined4 *param_1)

{
  if (((_s_mac_pal_ctx & 1) == 0) && ((*(ushort *)*param_1 & 0x20) != 0)) {
    micro_timer_start(&s_mac_pal_ctx,0x360);
    return;
  }
  return;
}

