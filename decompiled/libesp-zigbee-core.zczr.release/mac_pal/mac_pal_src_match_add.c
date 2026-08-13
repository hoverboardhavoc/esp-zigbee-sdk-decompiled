/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_src_match_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_pal_src_match_add(char *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (*param_1 == '\x02') {
    uVar1 = 1;
  }
  else {
    if (*param_1 != '\x03') {
      return 2;
    }
    uVar1 = 0;
  }
  uVar1 = ezb_plat_radio_add_src_match_entry(param_1 + 2,uVar1);
  return uVar1;
}

