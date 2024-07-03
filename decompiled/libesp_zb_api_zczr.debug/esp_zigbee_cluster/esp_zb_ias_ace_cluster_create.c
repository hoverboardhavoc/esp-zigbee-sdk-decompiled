/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_ias_ace_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_ace_cluster_create(byte param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  byte bStack_11;
  
  bStack_11 = param_1;
  uVar1 = esp_zb_zcl_attr_list_create(0x501);
  if (bStack_11 == 0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = calloc((uint)bStack_11,0xf);
    if (pvVar3 == (void *)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_L0,uVar2,0x10000);
      bStack_11 = 0;
    }
  }
  esp_zb_cluster_add_attr(uVar1,0x501,0xeffe,0x20,1,&bStack_11);
  esp_zb_cluster_add_attr(uVar1,0x501,0xefff,bStack_11 * '\x0f',0x40,pvVar3);
  return uVar1;
}

