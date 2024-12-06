/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_set_tx_power
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_set_tx_power(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC20,uVar1,"ESP_ZIGBEE_CORE",param_1,0,0x7f);
  }
  else {
    zb_set_tx_power();
  }
  return;
}

