/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_clear_src_match_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_plat_radio_clear_src_match_entry(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_a1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_2 == 0) {
    uStack_18 = __bswapdi2(*param_1,param_1[1]);
    uStack_14 = extraout_a1;
    iVar1 = esp_radio_spinel_clear_extended_entry(&uStack_18,0);
  }
  else {
    iVar1 = esp_radio_spinel_clear_short_entry(*(undefined2 *)param_1,0);
  }
  if (iVar1 != 0) {
    iVar1 = 5;
  }
  return iVar1;
}

