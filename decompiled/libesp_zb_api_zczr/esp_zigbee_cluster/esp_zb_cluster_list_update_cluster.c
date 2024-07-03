/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_update_cluster(int param_1,int param_2,uint param_3)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = esp_zb_cluster_list_check();
  if (iVar3 == 0) {
    sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
    for (psVar2 = *(short **)(param_1 + 0x10); psVar2 != (short *)0x0;
        psVar2 = *(short **)(psVar2 + 8)) {
      if ((*psVar2 == sVar1) && (*(byte *)(psVar2 + 4) == param_3)) {
        if (param_2 == *(int *)(psVar2 + 2)) {
          return 0;
        }
        esp_zb_internal_attribute_list_free();
        *(int *)(psVar2 + 2) = param_2;
        return 0;
      }
    }
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar4,"ESP_ZIGBEE_CLUSTER",sVar1);
    iVar3 = 0x105;
  }
  return iVar3;
}

