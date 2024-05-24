/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
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
      esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar2,"ESP_ZIGBEE_CLUSTER");
      bStack_11 = 0;
    }
  }
  esp_zb_cluster_add_attr(uVar1,0x501,0xeffe,0x20,1,&bStack_11);
  esp_zb_cluster_add_attr(uVar1,0x501,0xefff,0,0x40,pvVar3);
  return uVar1;
}

