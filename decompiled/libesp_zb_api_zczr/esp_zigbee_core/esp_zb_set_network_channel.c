/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_set_network_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_set_network_channel(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((param_1 - 0xb & 0xff) < 0x10) {
    uVar2 = zb_nwk_type & 0xff;
    if (uVar2 == 1) {
      zb_set_network_router_role(1 << (param_1 & 0x1f));
    }
    else if (uVar2 == 2) {
      zb_set_network_ed_role(1 << (param_1 & 0x1f));
    }
    else if (uVar2 == 0) {
      zb_set_network_coordinator_role(1 << (param_1 & 0x1f));
    }
    else {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar1,"ESP_ZIGBEE_CORE");
    }
    return 0;
  }
  return 0x102;
}

