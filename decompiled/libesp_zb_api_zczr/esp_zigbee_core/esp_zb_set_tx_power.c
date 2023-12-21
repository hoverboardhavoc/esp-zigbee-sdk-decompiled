/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_set_tx_power
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC71,uVar1,"ESP_ZIGBEE_CORE",param_1,0,0x7f);
  }
  else {
    zb_set_tx_power();
  }
  return;
}

