/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_add_src_match_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool ezb_plat_radio_add_src_match_entry(undefined2 *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = esp_radio_spinel_add_extended_entry(0);
  }
  else {
    iVar1 = esp_radio_spinel_add_short_entry(*param_1,0);
  }
  return iVar1 != 0;
}

