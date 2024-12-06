/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_nwk.o -> esp_zb_set_network_device_role
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_set_network_device_role(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_zdo_joined();
  if (iVar1 == 0) {
    if (param_1 == 1) {
      zb_get_channel_mask();
      zb_set_network_router_role();
    }
    else if (param_1 == 2) {
      zb_get_channel_mask();
      zb_set_network_ed_role();
    }
    else {
      if (param_1 != 0) {
        return 0x102;
      }
      zb_get_channel_mask(0x102);
      zb_set_network_coordinator_role();
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x103;
  }
  return uVar2;
}

