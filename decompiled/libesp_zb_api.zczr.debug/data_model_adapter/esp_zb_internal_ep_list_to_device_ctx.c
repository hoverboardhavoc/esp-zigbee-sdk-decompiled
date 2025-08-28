/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> data_model_adapter.o -> esp_zb_internal_ep_list_to_device_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * esp_zb_internal_ep_list_to_device_ctx(int param_1)

{
  size_t __nmemb;
  undefined1 *puVar1;
  void *pvVar2;
  void *__dest;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC13,uVar3,"ESP_ZIGBEE_DM_ADAPTER",
                  "esp_zb_internal_ep_list_to_device_ctx",0x123);
    return (undefined1 *)0x0;
  }
  __nmemb = 0;
  for (iVar4 = *(int *)(param_1 + 0x24); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x24)) {
    __nmemb = __nmemb + 1 & 0xff;
  }
  puVar1 = (undefined1 *)malloc(5);
  if (puVar1 == (undefined1 *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC14,uVar3,"ESP_ZIGBEE_DM_ADAPTER",
                  "esp_zb_internal_ep_list_to_device_ctx",0x129);
_L0:
    zb_af_device_ctx_cleanup(puVar1);
    puVar1 = (undefined1 *)0x0;
  }
  else {
    *puVar1 = (char)__nmemb;
    if (__nmemb == 0) {
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
    }
    else {
      pvVar2 = calloc(__nmemb,4);
      puVar1[1] = (char)pvVar2;
      puVar1[2] = (char)((uint)pvVar2 >> 8);
      puVar1[3] = (char)((uint)pvVar2 >> 0x10);
      puVar1[4] = (char)((uint)pvVar2 >> 0x18);
      if (pvVar2 == (void *)0x0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC15,uVar3,"ESP_ZIGBEE_DM_ADAPTER",
                      "esp_zb_internal_ep_list_to_device_ctx",0x12d);
        goto _L0;
      }
      pvVar2 = *(void **)(param_1 + 0x24);
      for (iVar4 = 0; iVar4 < (int)__nmemb; iVar4 = iVar4 + 1) {
        __dest = malloc(0x24);
        *(void **)(*(int *)(puVar1 + 1) + iVar4 * 4) = __dest;
        if (__dest == (void *)0x0) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_DM_ADAPTER",&_LC16,uVar3,"ESP_ZIGBEE_DM_ADAPTER",
                        "esp_zb_internal_ep_list_to_device_ctx",0x132);
          goto _L0;
        }
        memcpy(__dest,pvVar2,0x24);
        esp_zb_endpoint_populate_clusters(__dest);
        pvVar2 = *(void **)((int)pvVar2 + 0x24);
      }
    }
    esp_zb_internal_ep_list_free(param_1);
  }
  return puVar1;
}

