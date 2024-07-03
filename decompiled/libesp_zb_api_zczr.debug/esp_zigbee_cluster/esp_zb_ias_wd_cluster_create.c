/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_ias_wd_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_wd_cluster_create(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 auStack_14 [4];
  
  auStack_14[0] = 0xf0;
  uVar1 = esp_zb_zcl_attr_list_create(0x502);
  if (param_1 != (undefined2 *)0x0) {
    auStack_14[0] = *param_1;
  }
  esp_zb_ias_wd_cluster_add_attr(uVar1,0,auStack_14);
  return uVar1;
}

