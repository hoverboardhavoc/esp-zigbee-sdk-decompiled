/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
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
    esp_log_write(1,0x10000,&_LC3,uVar2,0x10000,"esp_zb_cluster_list_check",0x40);
    uVar2 = 0x102;
  }
  else if ((param_2 == 0) || (*(int *)(param_2 + 0xc) == 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC4,uVar2,0x10000,"esp_zb_cluster_list_check",0x42);
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
          esp_log_write(1,0x10000,&_LC6,uVar2,0x10000,"esp_zb_cluster_list_check",0x4a);
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
      esp_log_write(1,0x10000,&_LC5,uVar2,0x10000,"esp_zb_cluster_list_check",0x47,(uint)uVar1);
      uVar2 = 0x102;
    }
  }
  return uVar2;
}

