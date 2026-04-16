/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_promiscuous
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_set_promiscuous(_Bool enable)

{
  int iVar1;
  
  iVar1 = esp_radio_spinel_set_promiscuous_mode(0);
  if (iVar1 == 0) {
    s_radio_ctx._176_1_ = s_radio_ctx._176_1_ & 0xfd | (byte)((enable & 1) << 1);
    return;
  }
  _esp_error_check_failed
            ("/build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0x60,"ezb_plat_radio_set_promiscuous",
             "esp_radio_spinel_set_promiscuous_mode(enable, ESP_RADIO_SPINEL_ZIGBEE)");
  return;
}

