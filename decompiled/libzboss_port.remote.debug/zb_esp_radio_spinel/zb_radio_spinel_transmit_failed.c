/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> zb_radio_spinel_transmit_failed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_radio_spinel_transmit_failed(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 2) {
    esp_mac_transmit_failed_error(1);
  }
  else if (param_1 == 3) {
    esp_mac_transmit_failed_error(4);
  }
  else if (param_1 == 1) {
    esp_mac_transmit_failed_error(1);
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ZB_ESP_SPINEL",&_LC1,uVar1,"ZB_ESP_SPINEL",param_1);
    esp_mac_transmit_failed_error(1);
  }
  return;
}

