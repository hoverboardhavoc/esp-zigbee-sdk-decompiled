/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_update_cluster
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
      if ((sVar1 == *psVar2) && (param_3 == *(byte *)(psVar2 + 4))) {
        if (*(int *)(psVar2 + 2) == param_2) {
          return 0;
        }
        esp_zb_internal_attribute_list_free();
        *(int *)(psVar2 + 2) = param_2;
        return 0;
      }
    }
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC20,uVar4,0x10000,sVar1);
    iVar3 = 0x105;
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC19,uVar4,0x10000,"esp_zb_cluster_list_update_cluster",0xadc);
  }
  return iVar3;
}

