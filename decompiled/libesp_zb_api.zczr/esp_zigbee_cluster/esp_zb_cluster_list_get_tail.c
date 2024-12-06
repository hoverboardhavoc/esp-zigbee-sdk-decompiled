/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_get_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * esp_zb_cluster_list_get_tail(short *param_1,int param_2,uint param_3,int *param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short *psVar4;
  
  iVar2 = esp_zb_cluster_list_check();
  *param_4 = iVar2;
  if (iVar2 == 0) {
    sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 10);
    do {
      psVar4 = *(short **)(param_1 + 8);
      if (psVar4 == (short *)0x0) {
        return param_1;
      }
      param_1 = psVar4;
    } while ((*psVar4 != sVar1) || (*(byte *)(psVar4 + 4) != param_3));
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC11,uVar3,"ESP_ZIGBEE_CLUSTER",sVar1);
    *param_4 = 0x102;
  }
  return (short *)0x0;
}

