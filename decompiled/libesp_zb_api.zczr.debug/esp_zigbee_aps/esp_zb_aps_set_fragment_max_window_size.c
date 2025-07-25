/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
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
    esp_log_write(1,"ESP_ZIGBEE_APS",&_L0,uVar1,"ESP_ZIGBEE_APS",
                  "esp_zb_aps_set_fragment_max_window_size",0xf2,8);
    uVar1 = 0x102;
  }
  return uVar1;
}

