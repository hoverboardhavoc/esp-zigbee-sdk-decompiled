/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_time_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_time_cluster_create(ushort *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_15;
  uint auStack_14 [2];
  
  uVar1 = esp_zb_zcl_attr_list_create(10);
  if (param_1 == (ushort *)0x0) {
    auStack_14[0] = 0xffffffff;
    uStack_15 = 0;
  }
  else {
    auStack_14[0] = (uint)*param_1;
    uStack_15 = (undefined1)param_1[1];
  }
  esp_zb_time_cluster_add_attr(uVar1,0,auStack_14);
  esp_zb_time_cluster_add_attr(uVar1,1,&uStack_15);
  return uVar1;
}

