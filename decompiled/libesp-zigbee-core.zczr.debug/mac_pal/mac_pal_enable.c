/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_pal_enable(void)

{
  int iVar1;
  
  if (s_mac_pal_ctx == '\0') {
    iVar1 = ezb_plat_radio_enable();
    if ((iVar1 != 0) || (iVar1 = ezb_plat_radio_sleep(), iVar1 != 0)) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x144,
                    "mac_pal_enable","error == 0");
      micro_timer_stop(&s_mac_pal_ctx);
      iVar1 = ezb_plat_radio_sleep();
      if ((iVar1 == 0) && (iVar1 = ezb_plat_radio_disable(), iVar1 == 0)) {
        set_state(0);
      }
      return iVar1;
    }
    set_state(1);
  }
  return 0;
}

