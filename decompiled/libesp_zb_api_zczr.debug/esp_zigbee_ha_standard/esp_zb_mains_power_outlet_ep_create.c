/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_ha_standard.o -> esp_zb_mains_power_outlet_ep_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_mains_power_outlet_ep_create(undefined1 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar1 = esp_zb_ep_list_create();
  uStack_18 = CONCAT13(9,CONCAT12(1,CONCAT11(4,param_1)));
  uStack_14 = (uint)((uint3)((uint)uStack_14 >> 8) & 0xfffff0) << 8;
  uVar2 = esp_zb_mains_power_outlet_clusters_create(param_2);
  esp_zb_ep_list_add_ep(uVar1,uVar2,uStack_18,uStack_14);
  return uVar1;
}

