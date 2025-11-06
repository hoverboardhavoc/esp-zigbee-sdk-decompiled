/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_meter_identification_cluster_create
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
  
  memcpy(auStack_40,&_LANCHOR0,0x2e);
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

