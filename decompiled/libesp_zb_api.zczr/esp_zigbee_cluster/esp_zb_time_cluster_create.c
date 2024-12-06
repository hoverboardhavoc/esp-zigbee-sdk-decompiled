/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_time_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_time_cluster_create(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_15;
  undefined4 auStack_14 [2];
  
  uVar1 = esp_zb_zcl_attr_list_create(10);
  if (param_1 == (undefined4 *)0x0) {
    auStack_14[0] = 0xffffffff;
    uStack_15 = 0;
  }
  else {
    auStack_14[0] = *param_1;
    uStack_15 = *(undefined1 *)(param_1 + 1);
  }
  esp_zb_time_cluster_add_attr(uVar1,0,auStack_14);
  esp_zb_time_cluster_add_attr(uVar1,1,&uStack_15);
  return uVar1;
}

