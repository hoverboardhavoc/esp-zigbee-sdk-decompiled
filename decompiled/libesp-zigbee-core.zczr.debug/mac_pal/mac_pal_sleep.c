/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_sleep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_pal_sleep(void)

{
  int iVar1;
  
  iVar1 = ezb_plat_radio_sleep();
  if (iVar1 == 0) {
    set_state(1);
  }
  else {
    log_write(2,"mac_pal.c","RadioSleep() failed, error: %d",iVar1);
  }
  return iVar1;
}

