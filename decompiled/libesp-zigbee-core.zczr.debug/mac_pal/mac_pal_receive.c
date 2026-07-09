/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
    iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x164,
                          "mac_pal_receive","page == 0");
  }
  log_write(2,"mac_pal.c","RadioReceive() failed, error: %d",iVar1);
  return unaff_s0;
}

