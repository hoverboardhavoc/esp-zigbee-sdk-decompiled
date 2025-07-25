/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_binary_value_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_binary_value_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 auStack_11 [5];
  
  uVar1 = esp_zb_zcl_attr_list_create(0x11);
  if (param_1 == (undefined1 *)0x0) {
    uStack_13 = 0;
    uStack_12 = 0;
    auStack_11[0] = 0;
  }
  else {
    uStack_13 = *param_1;
    uStack_12 = param_1[1];
    auStack_11[0] = param_1[2];
  }
  esp_zb_binary_value_cluster_add_attr(uVar1,0x51,&uStack_13);
  esp_zb_binary_value_cluster_add_attr(uVar1,0x6f,&uStack_12);
  esp_zb_binary_value_cluster_add_attr(uVar1,0x55,auStack_11);
  return uVar1;
}

