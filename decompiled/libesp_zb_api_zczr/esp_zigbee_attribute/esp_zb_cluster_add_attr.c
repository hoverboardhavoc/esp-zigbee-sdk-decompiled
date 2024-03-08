/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_add_attr
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined1 param_5,undefined4 param_6)

{
  int iVar1;
  undefined2 *__ptr;
  int iVar2;
  size_t __size;
  void *pvVar3;
  undefined4 uVar4;
  int aiStack_34 [3];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_34[0] = 0;
  iVar2 = esp_zb_attr_list_get_tail(param_1,param_2,param_3,aiStack_34);
  iVar1 = aiStack_34[0];
  if (aiStack_34[0] == 0) {
    *__ptr = (short)param_3;
    __size = esp_zb_zcl_get_attribute_size(param_4,param_6);
    if (__size == 0xffff) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC10,uVar4,"ESP_ZIGBEE_ATTRIBUTE",
                    "esp_zb_cluster_add_attr",0xcea);
      aiStack_34[0] = 0x102;
    }
    else {
      pvVar3 = malloc(__size);
      __ptr[3] = (short)pvVar3;
      __ptr[4] = (short)((uint)pvVar3 >> 0x10);
      esp_zb_zcl_put_attribute_value(param_4,param_6,__size);
      *(undefined1 *)((int)__ptr + 3) = param_5;
      *(char *)(__ptr + 1) = (char)param_4;
      __ptr[2] = 0xffff;
      __ptr[5] = (short)param_2;
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

