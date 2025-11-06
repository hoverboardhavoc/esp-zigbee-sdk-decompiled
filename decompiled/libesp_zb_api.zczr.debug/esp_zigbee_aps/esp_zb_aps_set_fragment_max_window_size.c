/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_aps.o -> esp_zb_aps_set_fragment_max_window_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_aps_set_fragment_max_window_size(char param_1)

{
  undefined4 uVar1;
  
  if ((byte)(param_1 - 1U) < 8) {
    uVar1 = 0;
    DAT_000116fc = param_1;
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_APS",
            "E (%lu) %s: %s(%d): The fragment window size ranges from 1 to %d, size: %d\n",uVar1,
            "ESP_ZIGBEE_APS","esp_zb_aps_set_fragment_max_window_size",0xf2,8);
    uVar1 = 0x102;
  }
  return uVar1;
}

