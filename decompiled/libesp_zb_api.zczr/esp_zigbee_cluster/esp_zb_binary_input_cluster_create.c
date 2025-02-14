/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_binary_input_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_binary_input_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 auStack_11 [5];
  
  uVar1 = esp_zb_zcl_attr_list_create(0xf);
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
  esp_zb_binary_input_cluster_add_attr(uVar1,0x51,&uStack_13);
  esp_zb_binary_input_cluster_add_attr(uVar1,0x6f,&uStack_12);
  esp_zb_binary_input_cluster_add_attr(uVar1,0x55,auStack_11);
  return uVar1;
}

