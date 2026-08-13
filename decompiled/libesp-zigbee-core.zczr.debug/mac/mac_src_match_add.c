/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_src_match_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_src_match_add(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 2;
  }
  else if (param_1 == 0) {
    iVar1 = 2;
  }
  else {
    iVar1 = mac_pal_src_match_add(param_1);
    if (iVar1 == 0) {
      *(ushort *)(param_2 + 0x16) = *(ushort *)(param_2 + 0x16) | 0x40;
    }
    else {
      mac_pal_src_match_set_enabled(0);
    }
  }
  return iVar1;
}

