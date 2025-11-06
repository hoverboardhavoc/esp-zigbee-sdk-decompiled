/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_check
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
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Uninitialized cluster linked list!\n",uVar2,0x10000,
            "esp_zb_cluster_list_check",0x40);
    uVar2 = 0x102;
  }
  else if ((param_2 == 0) || (*(int *)(param_2 + 0xc) == 0)) {
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Empty attribute linked list!\n",uVar2,0x10000,
            "esp_zb_cluster_list_check",0x42);
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
          esp_log(1,0x10000,"E (%lu) %s: %s(%d): Custom cluster id is not within specified range!\n"
                  ,uVar2,0x10000,"esp_zb_cluster_list_check",0x4a);
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
      esp_log(1,0x10000,"E (%lu) %s: %s(%d): Wrong 0x%x cluster to update to cluster list\n",uVar2,
              0x10000,"esp_zb_cluster_list_check",0x47,(uint)uVar1);
      uVar2 = 0x102;
    }
  }
  return uVar2;
}

