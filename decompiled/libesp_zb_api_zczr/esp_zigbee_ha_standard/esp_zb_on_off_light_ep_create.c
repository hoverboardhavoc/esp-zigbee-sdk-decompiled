/*
 * Last changed at upstream commit e81a64f4a72a1b96e84882b938e8d601ccb424df
 * https://github.com/espressif/esp-zigbee-sdk/commit/e81a64f4a72a1b96e84882b938e8d601ccb424df
 * Upstream date: 2023-06-30 20:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.7.0(8b8bde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ha_standard.o -> esp_zb_on_off_light_ep_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_on_off_light_ep_create(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = esp_zb_ep_list_create();
  uVar2 = esp_zb_on_off_light_clusters_create(param_2);
  esp_zb_ep_list_add_ep(uVar1,uVar2,param_1,0x104,0x100);
  return uVar1;
}

