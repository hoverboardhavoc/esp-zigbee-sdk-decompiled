/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_get_tail
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
    psVar2 = *(short **)(param_1 + 8);
    do {
      param_1 = psVar2;
      if (param_1 == (short *)0x0) {
        return (short *)0x0;
      }
      if ((*param_1 == sVar1) && (*(byte *)(param_1 + 4) == param_3)) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC6,uVar4,"ESP_ZIGBEE_CLUSTER",sVar1);
        *param_4 = 0x102;
      }
      psVar2 = *(short **)(param_1 + 8);
    } while (*(short **)(param_1 + 8) != (short *)0x0);
  }
  return param_1;
}

