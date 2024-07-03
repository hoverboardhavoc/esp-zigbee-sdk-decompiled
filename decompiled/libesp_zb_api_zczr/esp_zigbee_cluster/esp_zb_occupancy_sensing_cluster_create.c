/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_occupancy_sensing_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_occupancy_sensing_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined1 auStack_14 [12];
  
  auStack_1c[0] = 0;
  uStack_18 = 0;
  auStack_14[0] = 1;
  uVar1 = esp_zb_zcl_attr_list_create(0x406);
  if (param_1 != (void *)0x0) {
    memcpy(auStack_1c,param_1,0xc);
  }
  esp_zb_occupancy_sensing_cluster_add_attr(uVar1,0,auStack_1c);
  esp_zb_occupancy_sensing_cluster_add_attr(uVar1,1,&uStack_18);
  esp_zb_occupancy_sensing_cluster_add_attr(uVar1,2,auStack_14);
  return uVar1;
}

