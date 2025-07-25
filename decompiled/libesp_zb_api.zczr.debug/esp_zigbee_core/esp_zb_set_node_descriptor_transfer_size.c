/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_set_node_descriptor_transfer_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_set_node_descriptor_transfer_size(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 0x64e) {
    if (param_2 < 0x64e) {
      _DAT_000122d6 = (undefined2)param_1;
      _DAT_000122da = (undefined2)param_2;
      uVar1 = 0;
    }
    else {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC8,uVar1,"ESP_ZIGBEE_CORE",
                    "esp_zb_set_node_descriptor_transfer_size",0x287,0x64d);
      uVar1 = 0x102;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar1,"ESP_ZIGBEE_CORE",
                  "esp_zb_set_node_descriptor_transfer_size",0x285,0x64d);
    uVar1 = 0x102;
  }
  return uVar1;
}

