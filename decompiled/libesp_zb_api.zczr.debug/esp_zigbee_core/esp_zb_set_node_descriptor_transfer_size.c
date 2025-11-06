/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
      esp_log(1,"ESP_ZIGBEE_CORE",
              "E (%lu) %s: %s(%d): The max outgoing transfer ranges from 0 to %d\n",uVar1,
              "ESP_ZIGBEE_CORE","esp_zb_set_node_descriptor_transfer_size",0x287,0x64d);
      uVar1 = 0x102;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_CORE",
            "E (%lu) %s: %s(%d): The max incoming transfer ranges from 0 to %d\n",uVar1,
            "ESP_ZIGBEE_CORE","esp_zb_set_node_descriptor_transfer_size",0x285,0x64d);
    uVar1 = 0x102;
  }
  return uVar1;
}

