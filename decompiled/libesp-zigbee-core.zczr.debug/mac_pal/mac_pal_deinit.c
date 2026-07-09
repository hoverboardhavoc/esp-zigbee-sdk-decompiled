/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void mac_pal_deinit(void)

{
  int iVar1;
  
  iVar1 = ezb_plat_radio_is_enabled();
  if ((iVar1 != 0) && (iVar1 = mac_pal_disable(), iVar1 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x116,"mac_pal_deinit",
                  "(mac_pal_disable()) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  DAT_00010918 = 0;
  return;
}

