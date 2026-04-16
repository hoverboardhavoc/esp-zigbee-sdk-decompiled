/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_src_match
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_set_src_match(_Bool enable)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined2 *puVar2;
  int extraout_a1;
  
  iVar1 = esp_radio_spinel_set_pending_mode(CONCAT31(in_register_00002029,enable),0);
  if (iVar1 == 0) {
    return;
  }
  puVar2 = (undefined2 *)
           _esp_error_check_failed
                     ("/build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
                      ,0xb6,"ezb_plat_radio_set_src_match",
                      "esp_radio_spinel_set_pending_mode(mode, ESP_RADIO_SPINEL_ZIGBEE)");
  if (extraout_a1 == 0) {
    esp_radio_spinel_add_extended_entry(0);
  }
  else {
    esp_radio_spinel_add_short_entry(*puVar2,0);
  }
  return;
}

