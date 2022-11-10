/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
 * Source: libesp_zb_api_zczr -> esp_zigbee_ha_standard.o -> esp_zb_configuration_tool_ep_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_configuration_tool_ep_create(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = esp_zb_ep_list_create();
  uVar2 = esp_zb_configuration_tool_clusters_create(param_2);
  esp_zb_ep_list_add_ep(uVar1,uVar2,param_1,0x104,5);
  return uVar1;
}

