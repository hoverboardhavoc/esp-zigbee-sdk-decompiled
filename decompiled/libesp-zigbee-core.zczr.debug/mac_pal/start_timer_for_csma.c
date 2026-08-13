/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> start_timer_for_csma
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void start_timer_for_csma(uint param_1)

{
  int iVar1;
  
  iVar1 = random_noncrypto_range_u32(0,1 << (param_1 & 0x1f));
  if ((DAT_00010a1e & 1) == 0) {
    ezb_plat_radio_sleep();
  }
  else {
    ezb_plat_radio_receive(*(undefined1 *)(DAT_00010a08 + 5));
  }
  start_timer(iVar1 * 0x14);
  return;
}

