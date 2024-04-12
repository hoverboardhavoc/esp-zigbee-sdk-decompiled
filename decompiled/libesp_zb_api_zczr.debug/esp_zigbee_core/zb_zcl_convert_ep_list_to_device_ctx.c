/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zb_zcl_convert_ep_list_to_device_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * zb_zcl_convert_ep_list_to_device_ctx(void *param_1)

{
  int iVar1;
  size_t __nmemb;
  undefined1 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  void *pvVar5;
  uint uVar6;
  
  __nmemb = 0;
  pvVar5 = param_1;
  while (pvVar5 = *(void **)((int)pvVar5 + 0x24), pvVar5 != (void *)0x0) {
    __nmemb = __nmemb + 1 & 0xff;
  }
  puVar2 = (undefined1 *)malloc(5);
  if (puVar2 == (undefined1 *)0x0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC1,uVar4,"ESP_ZIGBEE_CORE",
                  "zb_zcl_convert_ep_list_to_device_ctx",0x32b);
_L0:
    zb_zcl_device_ctx_cleanup(puVar2);
    puVar2 = (undefined1 *)0x0;
  }
  else {
    *puVar2 = (char)__nmemb;
    if (__nmemb == 0) {
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
    }
    else {
      pvVar5 = calloc(__nmemb,4);
      puVar2[1] = (char)pvVar5;
      puVar2[2] = (char)((uint)pvVar5 >> 8);
      puVar2[3] = (char)((uint)pvVar5 >> 0x10);
      puVar2[4] = (char)((uint)pvVar5 >> 0x18);
      if (pvVar5 == (void *)0x0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC2,uVar4,"ESP_ZIGBEE_CORE",
                      "zb_zcl_convert_ep_list_to_device_ctx",0x32f);
        goto _L0;
      }
      uVar6 = 0;
      pvVar5 = param_1;
      while (pvVar5 = *(void **)((int)pvVar5 + 0x24), pvVar5 != (void *)0x0) {
        iVar1 = *(int *)(puVar2 + 1);
        pvVar3 = malloc(0x24);
        *(void **)(iVar1 + uVar6 * 4) = pvVar3;
        pvVar3 = *(void **)(*(int *)(puVar2 + 1) + uVar6 * 4);
        if (pvVar3 == (void *)0x0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC3,uVar4,"ESP_ZIGBEE_CORE",
                        "zb_zcl_convert_ep_list_to_device_ctx",0x334);
          goto _L0;
        }
        memcpy(pvVar3,pvVar5,0x24);
        uVar6 = uVar6 + 1 & 0xff;
      }
    }
    zb_zcl_ep_list_free(param_1);
  }
  return puVar2;
}

