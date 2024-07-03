/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_ias_ace_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_ace_cluster_create(byte param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  byte bStack_11;
  
  bStack_11 = param_1;
  uVar1 = esp_zb_zcl_attr_list_create(0x501);
  if (bStack_11 != 0) {
    pvVar2 = calloc((uint)bStack_11,0xf);
    if (pvVar2 != (void *)0x0) goto _L0;
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC11,uVar3,"ESP_ZIGBEE_CLUSTER");
    bStack_11 = 0;
  }
  pvVar2 = (void *)0x0;
_L0:
  esp_zb_cluster_add_attr(uVar1,0x501,0xeffe,0x20,1,&bStack_11);
  esp_zb_cluster_add_attr(uVar1,0x501,0xefff,bStack_11 * '\x0f',0x40,pvVar2);
  return uVar1;
}

