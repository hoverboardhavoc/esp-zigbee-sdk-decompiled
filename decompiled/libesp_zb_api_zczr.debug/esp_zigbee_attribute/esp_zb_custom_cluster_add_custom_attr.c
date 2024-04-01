/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_custom_cluster_add_custom_attr
              (int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  size_t __size;
  void *pvVar3;
  undefined4 uVar4;
  int aiStack_34 [4];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_34[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,0x8000,param_2,aiStack_34);
  iVar1 = aiStack_34[0];
  if (aiStack_34[0] == 0) {
    *__ptr = (short)param_2;
    *(char *)(__ptr + 1) = (char)param_3;
    *(undefined1 *)((int)__ptr + 3) = param_4;
    __ptr[2] = 0xffff;
    __size = esp_zb_zcl_get_attribute_size(param_3,param_5);
    if (__size == 0xffff) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC13,uVar4,0x10000,"esp_zb_custom_cluster_add_custom_attr",0xdeb);
      aiStack_34[0] = 0xff;
    }
    else {
      pvVar3 = malloc(__size);
      __ptr[3] = (short)pvVar3;
      __ptr[4] = (short)((uint)pvVar3 >> 0x10);
      esp_zb_zcl_put_attribute_value(param_3,param_5,__size);
      __ptr[5] = *(undefined2 *)(iVar2 + 10);
      *(undefined4 *)(__ptr + 6) = 0;
      aiStack_34[0] = iVar1;
      if (iVar2 == 0) {
        *(undefined2 **)(param_1 + 0xc) = __ptr;
      }
      else {
        *(undefined2 **)(iVar2 + 0xc) = __ptr;
      }
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_34[0];
}

