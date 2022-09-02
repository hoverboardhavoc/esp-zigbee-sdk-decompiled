/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
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
      esp_log_write(1,0x10000,&_LC2,uVar1,0x10000);
    }
    return 0;
  }
  return 0x102;
}

