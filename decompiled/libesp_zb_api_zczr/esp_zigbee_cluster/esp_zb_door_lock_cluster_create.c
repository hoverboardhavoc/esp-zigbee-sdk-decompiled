/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_door_lock_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_door_lock_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 auStack_11 [5];
  
  uVar1 = esp_zb_zcl_attr_list_create(0x101);
  if (param_1 == (undefined1 *)0x0) {
    auStack_11[0] = 0xff;
    uStack_12 = 0xff;
    uStack_13 = 1;
  }
  else {
    auStack_11[0] = *param_1;
    uStack_12 = param_1[1];
    uStack_13 = param_1[2];
  }
  esp_zb_door_lock_cluster_add_attr(uVar1,0,auStack_11);
  esp_zb_door_lock_cluster_add_attr(uVar1,1,&uStack_12);
  esp_zb_door_lock_cluster_add_attr(uVar1,2,&uStack_13);
  return uVar1;
}

