/*
 * Last changed at upstream commit 6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * https://github.com/espressif/esp-zigbee-sdk/commit/6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * Upstream date: 2023-04-06 16:02:34 +0800
 * Upstream subject: example: support single C6 gateway example and other API support(a1884f9)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_check(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC1,uVar2,"ESP_ZIGBEE_CLUSTER");
    uVar2 = 0x102;
  }
  else if ((param_2 == 0) || (*(int *)(param_2 + 0xc) == 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC2,uVar2,"ESP_ZIGBEE_CLUSTER");
    uVar2 = 0x102;
  }
  else {
    uVar1 = (uint)*(ushort *)(*(int *)(param_2 + 0xc) + 10);
    if (param_3 < 0xfc00) {
      if (param_3 == uVar1) {
        uVar2 = 0;
      }
      else {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC3,uVar2,"ESP_ZIGBEE_CLUSTER",uVar1);
        uVar2 = 0x102;
      }
    }
    else if (param_3 == 0xfc00) {
      if (uVar1 < 0xfc00) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC4,uVar2,"ESP_ZIGBEE_CLUSTER");
        uVar2 = 0x102;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

