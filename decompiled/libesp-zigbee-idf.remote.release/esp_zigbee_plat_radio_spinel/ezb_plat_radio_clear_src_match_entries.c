/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_clear_src_match_entries
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_clear_src_match_entries(_Bool is_short)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  if (CONCAT31(in_register_00002029,is_short) == 0) {
    iVar1 = esp_radio_spinel_clear_extended_entries();
  }
  else {
    iVar1 = esp_radio_spinel_clear_short_entries(0);
  }
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return;
}

