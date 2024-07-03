/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_meter_identification_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_meter_identification_cluster_create(void *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_40 [18];
  undefined1 auStack_2e [2];
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [17];
  undefined1 auStack_19 [3];
  undefined1 auStack_16 [10];
  
  memcpy(auStack_40,&_L0,0x2e);
  uVar1 = esp_zb_zcl_attr_list_create(0xb01);
  if (param_1 != (void *)0x0) {
    memcpy(auStack_40,param_1,0x2e);
  }
  esp_zb_meter_identification_cluster_add_attr(uVar1,0,auStack_40);
  esp_zb_meter_identification_cluster_add_attr(uVar1,1,auStack_2e);
  esp_zb_meter_identification_cluster_add_attr(uVar1,4,auStack_2c);
  esp_zb_meter_identification_cluster_add_attr(uVar1,0xc,auStack_2a);
  esp_zb_meter_identification_cluster_add_attr(uVar1,0xd,auStack_19);
  esp_zb_meter_identification_cluster_add_attr(uVar1,0xe,auStack_16);
  return uVar1;
}

