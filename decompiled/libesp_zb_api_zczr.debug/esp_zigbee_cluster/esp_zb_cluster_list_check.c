/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_check(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC3,uVar2,"ESP_ZIGBEE_CLUSTER");
    uVar2 = 0x102;
  }
  else if ((param_2 == 0) || (*(int *)(param_2 + 0xc) == 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC4,uVar2,"ESP_ZIGBEE_CLUSTER");
    uVar2 = 0x102;
  }
  else {
    uVar1 = *(ushort *)(*(int *)(param_2 + 0xc) + 10);
    if ((short)param_3 < 0) {
      if (param_3 == 0x8000) {
        if ((short)uVar1 < 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC6,uVar2,"ESP_ZIGBEE_CLUSTER");
          uVar2 = 0x102;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else if (param_3 == uVar1) {
      uVar2 = 0;
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC5,uVar2,"ESP_ZIGBEE_CLUSTER",(uint)uVar1);
      uVar2 = 0x102;
    }
  }
  return uVar2;
}

