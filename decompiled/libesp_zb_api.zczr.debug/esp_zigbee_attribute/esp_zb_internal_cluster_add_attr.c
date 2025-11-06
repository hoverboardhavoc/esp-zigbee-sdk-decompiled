/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_internal_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_internal_cluster_add_attr
              (int param_1,undefined2 param_2,size_t param_3,byte param_4,void *param_5,int param_6)

{
  int iVar1;
  undefined2 *__ptr;
  size_t __size;
  undefined4 uVar2;
  void *__dest;
  int aiStack_34 [2];
  
  aiStack_34[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_6,aiStack_34);
  if (aiStack_34[0] != 0) {
    return aiStack_34[0];
  }
  __ptr = (undefined2 *)malloc(0x10);
  if (__ptr == (undefined2 *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): No memory for attribute\n",uVar2,0x10000,
            "esp_zb_internal_cluster_add_attr",0x62);
    return 0x102;
  }
  if ((param_4 & 0x40) == 0) {
_L0:
    __size = esp_zb_zcl_get_attribute_size(param_3,param_5);
  }
  else {
    __size = param_3;
    if ((param_5 == (void *)0x0) && (param_3 != 0)) {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c",
                0x68);
      goto _L0;
    }
  }
  if (param_6 == 0xffff) {
    param_4 = param_4 & 0xdf;
  }
  else {
    param_4 = param_4 | 0x20;
  }
  if (__size == 0xffff) {
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Failed to get attribute size\n",uVar2,0x10000,
            "esp_zb_internal_cluster_add_attr",0x71);
    aiStack_34[0] = 0x102;
  }
  else {
    if (__size == 0) {
      __dest = (void *)0x0;
    }
    else {
      __dest = malloc(__size);
      if (__dest == (void *)0x0) {
        uVar2 = esp_log_timestamp();
        esp_log(1,0x10000,"E (%lu) %s: %s(%d): No memory for attribute data\n",uVar2,0x10000,
                "esp_zb_internal_cluster_add_attr",0x74);
        aiStack_34[0] = 0x102;
        goto _L0;
      }
      memcpy(__dest,param_5,__size);
    }
    *__ptr = param_2;
    *(byte *)((int)__ptr + 3) = param_4;
    *(char *)(__ptr + 1) = (char)param_3;
    __ptr[3] = (short)__dest;
    __ptr[4] = (short)((uint)__dest >> 0x10);
    __ptr[2] = (short)param_6;
    __ptr[5] = *(undefined2 *)(*(int *)(param_1 + 0xc) + 10);
    *(undefined4 *)(__ptr + 6) = 0;
    *(undefined2 **)(iVar1 + 0xc) = __ptr;
  }
_L0:
  if (aiStack_34[0] != 0) {
    free(__ptr);
  }
  return aiStack_34[0];
}

