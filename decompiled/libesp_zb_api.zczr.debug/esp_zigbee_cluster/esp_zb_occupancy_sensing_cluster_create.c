/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_occupancy_sensing_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_occupancy_sensing_cluster_create(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 1;
  uVar1 = esp_zb_zcl_attr_list_create(0x406);
  if (param_1 != (undefined1 *)0x0) {
    uStack_1c = *param_1;
    uStack_1b = param_1[1];
    uStack_1a = param_1[2];
    uStack_19 = param_1[3];
    uStack_18 = *(undefined4 *)(param_1 + 4);
    uStack_14 = param_1[8];
    uStack_13 = param_1[9];
    uStack_12 = param_1[10];
    uStack_11 = param_1[0xb];
  }
  esp_zb_occupancy_sensing_cluster_add_attr(uVar1,0,&uStack_1c);
  esp_zb_occupancy_sensing_cluster_add_attr(uVar1,1,&uStack_18);
  esp_zb_occupancy_sensing_cluster_add_attr(uVar1,2,&uStack_14);
  return uVar1;
}

