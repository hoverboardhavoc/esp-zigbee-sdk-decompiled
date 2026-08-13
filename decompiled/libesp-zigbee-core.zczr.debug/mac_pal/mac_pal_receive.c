/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_receive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_pal_receive(int param_1,undefined4 param_2)

{
  int unaff_s0;
  int iVar1;
  
  if (param_1 == 0) {
    unaff_s0 = ezb_plat_radio_receive(param_2);
    iVar1 = unaff_s0;
    if (unaff_s0 == 0) {
      set_state(2);
      return 0;
    }
  }
  else {
    iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x16d,
                          "mac_pal_receive","page == 0");
  }
  log_write(2,"mac_pal.c","RadioReceive() failed, error: %d",iVar1);
  return unaff_s0;
}

