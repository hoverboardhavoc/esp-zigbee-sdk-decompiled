/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mac_pal_deinit(void)

{
  int iVar1;
  
  iVar1 = ezb_plat_radio_is_enabled();
  if ((iVar1 != 0) && (iVar1 = mac_pal_disable(), iVar1 != 0)) {
    __assert_func(0,0,0,0);
  }
  _s_mac_pal_ctx = 0;
  return;
}

