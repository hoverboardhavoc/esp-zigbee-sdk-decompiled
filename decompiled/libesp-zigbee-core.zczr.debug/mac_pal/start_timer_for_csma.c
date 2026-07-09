/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  if ((DAT_00010917 & 1) == 0) {
    ezb_plat_radio_sleep();
  }
  else {
    ezb_plat_radio_receive(*(undefined1 *)(DAT_00010918 + 5));
  }
  start_timer(iVar1 * 0x14);
  return;
}

