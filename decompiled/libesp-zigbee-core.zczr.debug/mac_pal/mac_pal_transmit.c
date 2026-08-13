/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_pal_transmit(void)

{
  undefined4 uVar1;
  
  if (s_mac_pal_ctx == '\0') {
    uVar1 = 3;
  }
  else if (s_mac_pal_ctx == '\x05') {
    uVar1 = 3;
  }
  else {
    DAT_00010a05 = 0;
    DAT_00010a06 = 0;
    start_csma();
    uVar1 = 0;
  }
  return uVar1;
}

