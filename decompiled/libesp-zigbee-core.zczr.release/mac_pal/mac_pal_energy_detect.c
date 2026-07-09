/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_energy_detect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_pal_energy_detect(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (((char)s_mac_pal_ctx != '\0') && (2 < (byte)((char)s_mac_pal_ctx - 3U))) {
    if (param_1 != 0) {
      param_3 = 0;
      param_2 = __assert_func(0,0,0,0);
    }
    uVar1 = ezb_plat_radio_energy_detect(param_2,param_3);
    return uVar1;
  }
  return 3;
}

