/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> ezb_plat_radio_transmit_started
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_transmit_started(ezb_radio_frame_t *frame)

{
  if (((s_mac_pal_ctx._0_2_ & 1) == 0) && ((*(ushort *)frame->psdu & 0x20) != 0)) {
    micro_timer_start(&s_mac_pal_ctx,0x360);
    return;
  }
  return;
}

