/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> esp_zb_set_network_channel
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
      esp_log_write(1,"ESP_ZIGBEE_API_CORE",&_L0,uVar1,"ESP_ZIGBEE_API_CORE");
    }
    return 0;
  }
  return 0x102;
}

