/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_endpoint.o -> zcl_get_cluster_lists
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * zcl_get_cluster_lists(int param_1)

{
  uint uVar1;
  uint __nmemb;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  void *__src;
  
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
    pvVar2 = (void *)0x0;
  }
  else {
    __nmemb = 0;
    iVar4 = param_1;
    while (iVar4 = *(int *)(iVar4 + 0x10), iVar4 != 0) {
      __nmemb = __nmemb + 1 & 0xff;
    }
    if (__nmemb == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_L0,uVar3,0x10000);
      pvVar2 = (void *)0x0;
    }
    else {
      __src = *(void **)(param_1 + 0x10);
      pvVar2 = calloc(__nmemb,0xf);
      for (uVar1 = 0; uVar1 < __nmemb; uVar1 = uVar1 + 1 & 0xff) {
        memcpy((void *)(uVar1 * 0xf + (int)pvVar2),__src,0xf);
        __src = *(void **)((int)__src + 0x10);
      }
    }
  }
  return pvVar2;
}

