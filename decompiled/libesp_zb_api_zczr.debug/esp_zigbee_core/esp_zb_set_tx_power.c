/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_set_tx_power
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

