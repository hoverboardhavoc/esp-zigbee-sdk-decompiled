/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_level_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_level_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_11 [5];
  
  uVar1 = esp_zb_zcl_attr_list_create(8);
  if (param_1 == (undefined1 *)0x0) {
    auStack_11[0] = 0xff;
  }
  else {
    auStack_11[0] = *param_1;
  }
  esp_zb_level_cluster_add_attr(uVar1,0,auStack_11);
  return uVar1;
}

