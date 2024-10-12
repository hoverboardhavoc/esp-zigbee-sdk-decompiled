/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_drlc_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_drlc_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined2 uStack_18;
  undefined1 auStack_16 [2];
  undefined2 auStack_14 [6];
  
  uStack_18 = 0x1e00;
  auStack_16[0] = 0;
  auStack_14[0] = 0;
  uVar1 = esp_zb_zcl_attr_list_create(0x701);
  if (param_1 != (void *)0x0) {
    memcpy(&uStack_18,param_1,6);
  }
  esp_zb_drlc_cluster_add_attr(uVar1,0,&uStack_18);
  esp_zb_drlc_cluster_add_attr(uVar1,1,(int)&uStack_18 + 1);
  esp_zb_drlc_cluster_add_attr(uVar1,2,auStack_16);
  esp_zb_drlc_cluster_add_attr(uVar1,3,auStack_14);
  return uVar1;
}

