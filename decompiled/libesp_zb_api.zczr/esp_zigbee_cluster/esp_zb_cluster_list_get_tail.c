/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_get_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * esp_zb_cluster_list_get_tail(short *param_1,int param_2,uint param_3,int *param_4)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = esp_zb_cluster_list_check();
  *param_4 = iVar3;
  if (iVar3 == 0) {
    sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
    do {
      psVar2 = param_1;
      param_1 = *(short **)(psVar2 + 8);
      if (param_1 == (short *)0x0) {
        return psVar2;
      }
    } while ((*param_1 != sVar1) || (*(byte *)(param_1 + 4) != param_3));
    uVar4 = esp_log_timestamp(psVar2);
    esp_log(1,"ESP_ZIGBEE_CLUSTER",
            "E (%lu) %s: The requested add cluster ID:0x%x is already existed\n",uVar4,
            "ESP_ZIGBEE_CLUSTER",sVar1);
    *param_4 = 0x102;
  }
  return (short *)0x0;
}

