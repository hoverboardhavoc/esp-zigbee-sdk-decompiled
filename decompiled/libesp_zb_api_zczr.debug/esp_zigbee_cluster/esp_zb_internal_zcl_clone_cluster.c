/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_internal_zcl_clone_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010a72) */

undefined4 esp_zb_internal_zcl_clone_cluster(void *param_1,void *param_2)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint __nmemb;
  undefined4 uVar4;
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC13,uVar4,"ESP_ZIGBEE_CLUSTER",
                  "esp_zb_internal_zcl_clone_cluster",0x5c,"esp_zb_internal_zcl_clone_cluster");
    uVar4 = 0x102;
  }
  else {
    memcpy(param_1,param_2,0xf);
    __nmemb = (uint)*(ushort *)((int)param_2 + 2);
    if (__nmemb == 0) {
      *(undefined1 *)((int)param_1 + 4) = 0;
      *(undefined1 *)((int)param_1 + 5) = 0;
      *(undefined1 *)((int)param_1 + 6) = 0;
      *(undefined1 *)((int)param_1 + 7) = 0;
      uVar4 = 0;
    }
    else {
      pvVar2 = calloc(__nmemb,10);
      *(char *)((int)param_1 + 4) = (char)pvVar2;
      *(char *)((int)param_1 + 5) = (char)((uint)pvVar2 >> 8);
      *(char *)((int)param_1 + 6) = (char)((uint)pvVar2 >> 0x10);
      *(char *)((int)param_1 + 7) = (char)((uint)pvVar2 >> 0x18);
      if (pvVar2 == (void *)0x0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC14,uVar4,"ESP_ZIGBEE_CLUSTER",
                      "esp_zb_internal_zcl_clone_cluster",0x61);
_L0:
        uVar4 = 0x101;
        if (*(int *)((int)param_1 + 4) != 0) {
          for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)((int)param_1 + 2); iVar3 = iVar3 + 1) {
            free(*(void **)(*(int *)((int)param_1 + 4) + iVar3 * 10 + 6));
          }
          free(*(void **)((int)param_1 + 4));
          *(undefined1 *)((int)param_1 + 4) = 0;
          *(undefined1 *)((int)param_1 + 5) = 0;
          *(undefined1 *)((int)param_1 + 6) = 0;
          *(undefined1 *)((int)param_1 + 7) = 0;
        }
      }
      else {
        for (uVar1 = 0; uVar4 = 0, uVar1 < __nmemb; uVar1 = uVar1 + 1 & 0xffff) {
          iVar3 = esp_zb_internal_zcl_clone_attribute
                            (*(int *)((int)param_1 + 4) + uVar1 * 10,
                             *(int *)((int)param_2 + 4) + uVar1 * 10);
          if (iVar3 != 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_LC15,uVar4,"ESP_ZIGBEE_CLUSTER",
                          "esp_zb_internal_zcl_clone_cluster",100);
            goto _L0;
          }
        }
      }
    }
  }
  return uVar4;
}

