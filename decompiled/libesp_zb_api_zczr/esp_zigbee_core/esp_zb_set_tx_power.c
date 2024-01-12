/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar1,"ESP_ZIGBEE_CORE",param_1,0,0x7f);
  }
  else {
    zb_set_tx_power();
  }
  return;
}

