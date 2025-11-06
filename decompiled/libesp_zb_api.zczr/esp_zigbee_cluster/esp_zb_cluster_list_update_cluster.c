/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_update_cluster(short *param_1,int param_2,uint param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = esp_zb_cluster_list_check();
  uVar2 = 0x102;
  if (iVar3 == 0) {
    sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
    do {
      param_1 = *(short **)(param_1 + 8);
      if (param_1 == (short *)0x0) {
        uVar2 = esp_log_timestamp();
        esp_log(1,"ESP_ZIGBEE_CLUSTER",
                "E (%lu) %s: The requested update cluster ID (0x%4hx) is not found\n",uVar2,
                "ESP_ZIGBEE_CLUSTER",sVar1);
        return 0x105;
      }
    } while ((*param_1 != sVar1) || (*(byte *)(param_1 + 4) != param_3));
    uVar2 = 0;
    if (*(int *)(param_1 + 2) != param_2) {
      esp_zb_internal_attribute_list_free();
      *(int *)(param_1 + 2) = param_2;
    }
  }
  return uVar2;
}

