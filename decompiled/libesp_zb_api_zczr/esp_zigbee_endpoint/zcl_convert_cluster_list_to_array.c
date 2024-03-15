/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> zcl_convert_cluster_list_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_convert_cluster_list_to_array(void *param_1)

{
  uint __nmemb;
  undefined4 uVar1;
  void *pvVar2;
  uint uVar3;
  uint unaff_s2;
  void *__src;
  undefined4 local_30;
  undefined4 uStack_28;
  
  local_30 = 0;
  if (param_1 == (void *)0x0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar1,0x10000);
    uStack_28 = 0;
  }
  else {
    __nmemb = 0;
    pvVar2 = param_1;
    while (pvVar2 = *(void **)((int)pvVar2 + 0x10), pvVar2 != (void *)0x0) {
      if (*(char *)((int)pvVar2 + 8) == '\x01') {
        local_30._0_3_ = CONCAT12(local_30._2_1_ + '\x01',(undefined2)local_30);
      }
      else {
        local_30 = CONCAT13(local_30._3_1_ + '\x01',(undefined3)local_30);
      }
      for (uVar3 = 0; uVar3 < *(ushort *)((int)pvVar2 + 2); uVar3 = uVar3 + 1 & 0xffff) {
        if ((*(byte *)(uVar3 * 10 + *(int *)((int)pvVar2 + 4) + 3) & 4) != 0) {
          local_30._0_2_ = CONCAT11(local_30._1_1_ + '\x01',(char)local_30);
        }
      }
      local_30 = CONCAT31(local_30._1_3_,(char)local_30 + '\x01');
      __nmemb = __nmemb + 1 & 0xff;
    }
    if (__nmemb == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC3,uVar1,0x10000);
    }
    else {
      __src = *(void **)((int)param_1 + 0x10);
      pvVar2 = calloc(__nmemb,0xf);
      if (pvVar2 == (void *)0x0) {
        zb_assert("/home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_endpoint.c",
                  0x82);
        goto _L0;
      }
      for (unaff_s2 = 0; unaff_s2 < __nmemb; unaff_s2 = unaff_s2 + 1 & 0xff) {
_L0:
        memcpy((void *)(unaff_s2 * 0xf + (int)pvVar2),__src,0xf);
        __src = *(void **)((int)__src + 0x10);
      }
    }
    while (param_1 != (void *)0x0) {
      pvVar2 = *(void **)((int)param_1 + 0x10);
      free(param_1);
      param_1 = pvVar2;
    }
    uStack_28 = local_30;
  }
  return uStack_28;
}

