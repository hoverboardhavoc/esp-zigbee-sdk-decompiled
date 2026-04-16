/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_add_src_match_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_radio_add_src_match_entry(uint8_t *addr,_Bool is_short)

{
  int iVar1;
  undefined3 in_register_0000202d;
  
  if (CONCAT31(in_register_0000202d,is_short) == 0) {
    iVar1 = esp_radio_spinel_add_extended_entry();
  }
  else {
    iVar1 = esp_radio_spinel_add_short_entry(*(undefined2 *)addr,0);
  }
  return (uint)(iVar1 != 0);
}

