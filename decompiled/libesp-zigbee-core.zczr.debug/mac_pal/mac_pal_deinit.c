/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_pal_deinit(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = ezb_plat_radio_is_enabled();
  if ((iVar1 != 0) && (iVar1 = mac_pal_disable(), iVar1 != 0)) {
    pcVar2 = (char *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x117,
                                   "mac_pal_deinit","(mac_pal_disable()) == 0");
    if (pcVar2 == (char *)0x0) {
      iVar1 = 0;
    }
    else if (*pcVar2 == '\x02') {
      iVar1 = ezb_plat_radio_add_src_match_entry(pcVar2 + 2,1);
    }
    else if (*pcVar2 == '\x03') {
      iVar1 = ezb_plat_radio_add_src_match_entry(pcVar2 + 2,0);
    }
    else {
      iVar1 = 2;
    }
    return iVar1;
  }
  DAT_00010a08 = 0;
  return iVar1;
}

